/*
 汇合线程
     #include <pthread.h>
     int pthread_join(pthread_t tid, void** retval);
     功能:等待子线程终止，即其线程过程函数返回，并与之会合，同时回收该线程的资源
     参数:tid:线程ID.
         retval:输出线程过程函数的返回值  //获取子线程的返回值 //给哪个一级指针的地址，就将线程过程函数的的返回值存入哪个一级指针
     返回值:成功返回0，失败返回错误码。
     //主要目的是回收子线程资源，获取子线程的返回值
     
     ●在父线程中调用pthread_join函数等待子线程的终止，并回收其资源。如果调用该函数时子线程已经终止,该函数会立即返回，
      如果调用该函数时子线程尚在运行中，该函数会阻塞，直至子线程终止。该函数在返回成功的同时通过其retval参数向调用者输出
      子线程线程过程函数的返回值。
 */

#if 0
//线程的汇入
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define PI 3.14 
//线程过程函数,计算圆的面积
void* pthread_area(void* arg){
    //sleep(3);
    double r = *(double*)arg;
    /*double s = PI * r * r;         //error，不能返回局部变量的地址,函数结束后，局部变量存储区会失效
    return &s;*/
    
    //static double s = PI * r * r;  //error，静态变量的生命周期是进程级的（可能main函数还没执行就已经有s了）,s是进程还没启动就有了，此时还没有r，r开线程的时候才有，无法给s赋值进行计算
    
    /*
    static double s; //ok,把static的声明和赋值分开，声明静态变量表示进程还没启动已经有s了
    s = PI * r * r;  //执行到这里再赋值
    return &s; //多个线程都会将数据存入s中，结果会发生覆盖（替换）
     */

    double* s = malloc(sizeof(double));//动态内存分配，每个线程各有各的存储区，使用完后，每个线程手动释放内存
    *s = PI * r * r;
    return s;
}

int main(void){
    double r = 10;
    pthread_t tid;
    pthread_create(&tid,NULL,pthread_area,&r);
    
    double r2 = 20;
    pthread_t tid2;
    pthread_create(&tid2,NULL,pthread_area,&r2);
    
    //等待并回收子线程,获取线程函数的返回值
    double* area;//输出型参数,用来输出线程过程函数的返回值
    pthread_join(tid,(void**)&area);
    printf("圆的面积是%lg\n",*area); //如果线程过程函数的返回值是静态内存区域，多个线程都会往这一块内存写数据，会发生覆盖，解决方法：使用动态内存
    free(area);

    double* area2;
    pthread_join(tid2,(void**)&area2);
    printf("圆的面积是%lg\n",*area2);//如果线程过程函数的返回值是静态内存区域，多个线程都会往这一块内存写数据，会发生覆盖，解决方法：使用动态内存
    free(area2);
    return 0;
}

#endif

/*
 (base) 176x212x32x33:day25 wyl$ gcc 01_join.c
 (base) 176x212x32x33:day25 wyl$ ./a.out
 圆的面积是314
 圆的面积是1256
 */
