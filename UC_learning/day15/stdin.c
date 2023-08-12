#if 0

#include<stdio.h>
#include<unistd.h>

int main(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    
    if(pid == 0){
        int a = 0;
        scanf("%d",&a);
        printf("%d进程:a = %d\n",getpid(),a);
        return 0;
    }

    sleep(3);
    int b = 0;
    scanf("%d",&b);
    printf("%d进程:b = %d\n",getpid(),b);
    for(;;);
    return 0;
}

#endif

