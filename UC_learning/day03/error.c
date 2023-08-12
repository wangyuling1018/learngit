
#if 0
//错误获取,获取具体的出错信息
#include<stdio.h>
#include<string.h>
#include<stdlib.h> //malloc
#include<errno.h> // 全局变量errno

int main(void){
    void* p = malloc(0xfffffffffffffffff);
    if(p == NULL){
        fprintf(stderr,"errno = %d\n",errno);
        fprintf(stderr,"malloc:%s\n",strerror(errno));
        perror("malloc");
        return -1;
    }        
    free(p);
    p = NULL;
    return 0;
}
#endif

