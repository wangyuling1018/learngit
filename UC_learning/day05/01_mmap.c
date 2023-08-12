#if 0
//内存映射
#include<stdio.h>
#include<string.h>
#include<sys/mman.h> // mmap  munmap

int main(void){
    //建立虚拟地址到物理地址的映射关系
    
    char* p1 = mmap(NULL,8192,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,0,0);
    if(p1 == MAP_FAILED){
        perror("mmap");
        return -1;
    }

    strcpy(p1,"第一个内存页");
    printf("%s\n",p1);

    //解除第一个页映射关系
    if(munmap(p1,4096) == -1){
        perror("munmap");
        return -1;
    }
    //printf("%s\n",p1);  //解除映射后 找不到p1对应的物理地址,则段错误

    char* p2 = p1 + 4096;//第二个页起始虚拟地址
    strcpy(p2,"第二个内存页");
    printf("%s\n",p2);

    //接触第二个页的映射
    if(munmap(p2,4096) == -1){
        perror("munmap");
        return -1;
    }
    
    //printf("%s\n",p2);//段错,同上
    return 0;
}
#endif

