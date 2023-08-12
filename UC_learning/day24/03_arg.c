/*
 线程参数
     ●传递给线程过程函数的参数是一个泛型指针void*，它可以指向任何类型的数据:基本类型的变量、结构体类型的变量或
     者数组类型的变量等等，但必须保证在线程过程函数执行期间，该指针所指向的内存空间持久有效，直到线程过程函数不再使用它为止。
     ●调用pthread_create函数的代码在用户空间，线程过程函数的代码也在用户空间，但偏偏创建线程的动作由系统内核完成。
     因此传递给线程过程函数的参数也不得不经由系统内核传递给线程过程函数。pthread_create函数的arg参数负责将线程过程函数的参数带入系统内核。
 */

#if 0
//线程过程函数的参数
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define PI 3.14
//double s ;

//线程过程函数,计算圆的面积
void* area(void* arg){
    double r = *(double*)arg; //*arg是局部变量r的值->r是int，转成double ->(double*)
    double s = PI * r * r;
    *(double*)arg = s; //将计算的结果存回arg中，可以将计算结果回传给主线程main //arg是指针，转成(double*)指针，再取值*，就是arg指向的变量
    return NULL;
}
//线程过程函数,计算平均数
void* aver(void* arg){
    int* data = (int*)arg;
    data[2] = (data[0] + data[1]) / 2; //计算的结果存入第3个元素
    //*data + *(data+1)
    
}

int main(void){
    double r = 10;//半径
    pthread_t tid;
    pthread_create(&tid,NULL,area,&r);
    sleep(1);
    printf("圆的面积是%lg\n",r);
 
    int data[3] = {3,5};
    pthread_create(&tid,NULL,aver,data);
    sleep(1);
    printf("平均数是%d\n",data[2]);
    return 0;
}
#endif
/*
 (base) 176x212x32x15:day24 wyl$ gcc 03_arg.c
 (base) 176x212x32x15:day24 wyl$ ./a.out
 圆的面积是314
 平均数是4

 */
