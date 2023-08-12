#if 0

//动态库的动态加载,啥时候用库,啥时候把库加载到内存
#include<stdio.h>
#include<dlfcn.h>

int main(void){
    printf("我要做动态库的动态加载\n");

    //将动态库载入内存
    void* handle = dlopen("/Users/wyl/C++_Projects/UC_learning/day02/shared/libmath.so",RTLD_NOW);
    if(handle == NULL){//dlopen 失败
        fprintf(stderr,"dlopen:%s\n",dlerror());
        return -1;
    }
    //获取库中函数的地址 int add(int a,int b);

    int (*add)(int,int) = dlsym(handle,"add");
    if(add == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    int (*sub)(int,int) = dlsym(handle,"sub");
    if(sub == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    // void show(int l,char op,int r,int res){
    //  printf("%d %c %d = %d\n",l,op,r,res);
    // }
    void (*show)(int,char,int,int) = dlsym(handle,"show");
    if(show == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }

    //使用库中的的函数
    int a = 123,b = 456;
    show(a,'+',b,add(a,b));
    show(a,'-',b,sub(a,b));
    //卸载动态库
    //int ret = dlclose(handle);
    //if(ret){....}
    if(dlclose(handle)){
        fprintf(stderr,"dlclose:%s\n",dlerror());
        return -1;
    }

    printf("我对动态库的使用结束了\n");
    return 0;
}

#endif





