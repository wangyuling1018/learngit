/*
 条件变量
     ●一个线程在某种条件不满足的情况下，无法进行后续工作，这时它就可以睡入某个条件变量，这时会有其它线程为其创建条件，
     一旦条件满足可以唤醒那些在相应条件变量中睡眠的线程继续运行。
     ●通过pthread_cond_t 类型来表示条件变量
     
     笔记：
     1、实现线程同步的方式二：条件变量。
     2、条件变量是睡觉的地方。

     ●初始化条件变量
         #include < pthread.h>
         int pthread_cond_init (pthread_cond_t* cond,const pthread_condattr t* attr);
             功能:初始化条件变量
             参数: cond 条件变量
                  attr 条件变量属性
             返回值:成功返回0，失败返回错误码
         也可以静态方式初始化条件变量：
             pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  //常用静态方式初始化
             
     ●销毁条件变量
         #include <pthread.h>
         int pthread_cond_destroy(pthread_cond_t*cond
             功能:销毁条件变量
             参数:cond 条件变量返回值:
             成功:返回0，失败返回错误码


     ●睡入条件变量
         #include <pthread.h>
         int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
             功能:睡入条件变量
             参数:cond 条件变量
                 mutex 互斥锁
             返回值:成功返回0，失败返回错误码
             //条件变量一定配合互斥锁使用。
             //睡觉之前先解锁共享变量，以便其他线程使用共享变量，睡醒之前先加锁，以便唤醒之后我能使用共享变量

             ●pthread_cond_wait函数会令调用线程进入阻塞状态，直到条件变量cond收到信号为止，阻塞期间互斥体mutex被解锁
             ●条件变量必须与互斥体配合使用，以防止多个线程同时进入条件等待队列时发生竞争
                 ➢线程在调用pthread_cond_wait函数前必须先通过pthread_mutex_lock函数锁定mutex互斥体
                 ➢在调用线程进入条件等待队列之前，mutex互斥体一直处于锁定状态 ，直到调用线程进入条件等待队列后才被解锁
                 ➢当调用线程即将从pthread_cond_wait函数返回时，mutex互斥体会被重新锁定，回到调用该函数之前的状态

     
     ●唤醒条件变量
         #include < pthread.h>
         int pthread_cond_signal(pthread_cond_t* cond);
             功能:唤醒在条件变量中睡眠的一个线程
             参数: cond条件变量
             返回值:成功返回0，失败返回错误码
         ●一个线程调用pthread_cond_wait函数进入阻塞状态，直到条件变量cond收到信号为止，阻塞期间互斥锁mutex会被释放。
          另一个线程通过pthread_cond_signal函数向条件变量cond发送信号，唤醒在其中睡眠的一个线程，
          该线程即从pthread_cond_wait函数中返回，同时重新获得互斥锁mutex。


 生产者消费者问题
     ●生产者消费者(Producer-Consumer)问题，亦称有界缓冲区(Bounded-Buffer)问题
     ●两个线程共享一个公共的固定大小的缓冲区，其中一个线程作为生产者，负责将消息放入缓冲区;而另一个线程则作为消费者，负责从缓冲区中提取消息
     ●假设缓冲区已满，若生产者线程还想放入消息，就必须等待消费者线程从缓冲区中提取消息以产生足够的空间
     ●假设缓冲区已空，若消费者线程还想提取消息，就必须等待生产者线程向缓冲区中放入消息以产生足够的数据
     ●生产者和消费者线程之间必须建立某种形式的同步，以确保为其所共享的缓冲区既不发生上溢，也不发生下溢
     
     //在一个固定大小缓冲区中，2个线程，一个线程不停往里面放数据，一个线程不停的拿数据，当缓冲区满了，生产者不能将数据存入到缓冲区之外（上溢），
     当缓冲区空了，消费者不能拿有限缓冲区之外的数据（下溢）。
     //方案：
         当仓库满，生产者睡入条件变量，等待消费者的消费，然后唤醒生产者继续生产
         当仓库空，消费者睡入条件变量，等待生产者的生产，让后唤醒消费者继续消费
         保证缓冲区既不上溢，也不下溢。

 */
//#if 0

//条件变量解决生产者和消费者问题
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#define MAX_STOCK 10
char g_storage[MAX_STOCK];//仓库
int g_stock = 0;//库存量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//互斥锁
pthread_cond_t pcond = PTHREAD_COND_INITIALIZER;//生产者卧室
pthread_cond_t ccond = PTHREAD_COND_INITIALIZER;//消费者卧室

//显示库存情况  生产者:ABC<--X      消费者:ABC-->X
void show(char* who,char* op,char prod){
    printf("%s:",who);
    for(int i = 0;i < g_stock;i++){
        printf("%c",g_storage[i]);
    }
    printf("%s%c\n",op,prod);
}

//生产者线程的线程过程函数
void* producer(void* arg){
    char* who = (char*)arg;
    for(;;){
        //加锁
        pthread_mutex_lock(&mutex);
        //仓库满,则睡入条件变量
        if(g_stock == MAX_STOCK){
            printf("\033[;;31m%s:满仓!\033[0m\n",who);
            pthread_cond_wait(&pcond,&mutex);
        }
        //生产
        char prod = 'A' + rand() % 26;  //A+(0~25)的随机数，就是A～Z
        show(who,"<--",prod);
        g_storage[g_stock] = prod;
        g_stock++;
        //唤醒消费者
        pthread_cond_signal(&ccond);
        //解锁
        pthread_mutex_unlock(&mutex);
        usleep((rand() % 100) * 1000);
    }
    return NULL;
}

//消费者线程的线程过程函数
void* customer(void* arg){
    char* who = (char*)arg;
    for(;;){
        //加锁
        pthread_mutex_lock(&mutex);
        //仓库空,则睡入条件变量
        if(g_stock == 0){
            //printf("%s:空仓！\n",who);
            printf("\033[;;32m%s:空仓!\033[0m\n",who); //\033[ --- \033[0m ，控制由\033[包含起来的中间文本的字体色、背景色等。2个；；分成3部分，1;41;31表示 0～8表示字体斜体或加粗等，背景色是41（7种颜色40～46），字体颜色是31（7种颜色30～36） //https://blog.csdn.net/qq_40342400/article/details/127448154
            
            pthread_cond_wait(&ccond,&mutex);
        }
        //消费
        char prod = g_storage[--g_stock];
        show(who,"-->",prod);
        //唤醒生产者
        pthread_cond_signal(&pcond);
        //解锁
        pthread_mutex_unlock(&mutex);
        usleep((rand() % 100) * 1000);
    }
    return NULL;
}
int main(void){
    pthread_t tid;
    pthread_create(&tid,NULL,producer,"生产者");
    pthread_create(&tid,NULL,customer,"消费者");

    getchar();
    return 0;
}

//#endif

/*
 (base) 176x212x32x33:day26 wyl$ gcc 02_cond.c -o c
 (base) 176x212x32x33:day26 wyl$ ./c
 生产者:<--L
 消费者:-->L
 生产者:<--K
 消费者:-->K
 生产者:<--U
 消费者:-->U
 生产者:<--J
 消费者:-->J
 生产者:<--Y
 消费者:-->Y
 生产者:<--N
 生产者:N<--T
 生产者:NT<--S
 生产者:NTS<--R
 消费者:NTS-->R
 生产者:NTS<--M
 生产者:NTSM<--L
 消费者:NTSM-->L
 消费者:NTS-->M
 消费者:NT-->S
 生产者:NT<--E
 生产者:NTE<--L
 生产者:NTEL<--F
 消费者:NTEL-->F
 生产者:NTEL<--B
 生产者:NTELB<--L
 消费者:NTELB-->L
 生产者:NTELB<--Q
 消费者:NTELB-->Q
 消费者:NTEL-->B
 生产者:NTEL<--R
 消费者:NTEL-->R
 消费者:NTE-->L
 消费者:NT-->E
 生产者:NT<--E
 消费者:NT-->E
 生产者:NT<--Q
 生产者:NTQ<--E
 生产者:NTQE<--L
 消费者:NTQE-->L
 生产者:NTQE<--T
 生产者:NTQET<--D
 消费者:NTQET-->D
 生产者:NTQET<--C
 生产者:NTQETC<--P
 消费者:NTQETC-->P
 生产者:NTQETC<--T
 消费者:NTQETC-->T
 生产者:NTQETC<--S
 消费者:NTQETC-->S
 生产者:NTQETC<--F
 消费者:NTQETC-->F
 消费者:NTQET-->C
 生产者:NTQET<--D
 生产者:NTQETD<--P
 消费者:NTQETD-->P
 消费者:NTQET-->D
 消费者:NTQE-->T
 生产者:NTQE<--K
 消费者:NTQE-->K
 消费者:NTQ-->E
 消费者:NT-->Q
 生产者:NT<--Q
 消费者:NT-->Q
 生产者:NT<--Z
 消费者:NT-->Z
 生产者:NT<--X
 消费者:NT-->X
 消费者:N-->T
 生产者:N<--F
 消费者:N-->F
 生产者:N<--F
 消费者:N-->F
 消费者:-->N
 消费者:空仓!
 生产者:<--H
 消费者:-->H
 生产者:<--F
 消费者:-->F
 消费者:空仓!
 生产者:<--B
 消费者:-->B
 消费者:空仓!
 生产者:<--Q
 消费者:-->Q
 生产者:<--O
 消费者:-->O
 生产者:<--T
 消费者:-->T
 消费者:空仓!
 生产者:<--S
 消费者:-->S
 生产者:<--E
 消费者:-->E
 生产者:<--T
 消费者:-->T
 消费者:空仓!
 生产者:<--J
 消费者:-->J
 生产者:<--N
 生产者:N<--B
 生产者:NB<--Q
 消费者:NB-->Q
 生产者:NB<--X
 生产者:NBX<--C
 消费者:NBX-->C
 生产者:NBX<--T
 生产者:NBXT<--H
 消费者:NBXT-->H
 消费者:NBX-->T
 消费者:NB-->X
 生产者:NB<--D
 生产者:NBD<--F
 消费者:NBD-->F
 消费者:NB-->D
 生产者:NB<--S
 生产者:NBS<--Y
 消费者:NBS-->Y
 生产者:NBS<--C
 消费者:NBS-->C
 消费者:NB-->S
 生产者:NB<--W
 消费者:NB-->W
 生产者:NB<--B
 生产者:NBB<--F
 消费者:NBB-->F
 生产者:NBB<--D
 ^C

 */
