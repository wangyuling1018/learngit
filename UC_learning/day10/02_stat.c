/*
 文件元数据的获取
     #include <sys/stat.h>
     int stat(char const* path, struct stat* buf);
     int fstat(int fd, struct stat* buf);
     int lstat(char const* path, struct stat* buf);
         功能:从i节点中提取文件的元数据，即文件的属性信息
         参数:path：文件路径
             buf：文件元数据结构 //输出型参数
             fd：文件描述符
         返回值:成功返回0，失败返回-1

 文件元数据的获取
     lstat()函数与另外两个函数的区别在于它不跟踪符号链接。
         例:
         abc.txt --->xyz.txt abc.txt文件是xyz.txt文件的符号链接
         stat( “abc.txt”，...);   //得到xyz.txt文件的元数据
         lstat( “abc.txt”，...);  //得到abc.txt文件的元数据
         
 文件元数据结构
     ●stat函数族通过stat结构体，向调用者输出文件的元数据
         struct stat{
             dev_t st_dev;        //设备ID
             ino_t st_ino;        //i节点号
             mode_t st_mode;      //文件的类型和权限 //unsigned int: 4字节
             nlink_t st_nlink;    //硬链接数
             uid_t st_uid;        //拥有者用户ID
             gid_t st_gid;        // 拥有者组ID
             dev_t st_rdev;       //特殊设备ID
             off_t st_size;       //总字节数
             blksize_t st_blksize;//I/O块字节数
             blkcnt_t st_blocks;  //存储块数time_t
             time_t st_atime,     //最后访问时间
             time_t st_mtime;     //最后修改时间
             time_t st_ctime;     // 最后状态改变时间
             }

     ●stat结构的st_mode成员表示文件的类型和权限，该成员在stat结构中被声明为mode谈型，其原始类型在32位系统中被定义
      为unsigned int,即32位无符号整数，但到目前为止，只有其中的低16位有意义
     ●用16位二进制数(B15..B0)表示的文件类型和权限，从高到低可被分为五组
         ➢B15 - B12:文件类型
         ➢B11 - B9 :设置用户ID，设置组ID,粘滞
         ➢B8 -  B6 :拥有者用户的读、写和执行权限
         ➢B5 -  B3 :拥有者组的读、写和执行权限
         ➢B2 -  BO :其它用户的读、写和执行权限

     辅助分析文件类型的实用宏
         ➢S_ISREG()  :是否普通文件
         ➢S_ISDIR()  :是否目录
         ➢S_ISSOCK() :是否本地套接字
         ➢S_ISCHR()  :是否字符设备
         ➢S_ISBLK()  :是否块设备
         ➢S_ISLNK()  :是否符号链接
         ➢S_ISFIFO() :是否有名管道
         
 */

#if 0
//文件的元数据
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>

//buf.st_mode  --> "-rwxrwxr-x"  //将一个整数转换成字符串
char* mtos(mode_t m){
    static char s[11];
    if(S_ISDIR(m)){
        strcpy(s,"d");
    }else
    if(S_ISSOCK(m)){
        strcpy(s,"s");
    }else
    if(S_ISCHR(m)){
        strcpy(s,"c");
    }else
    if(S_ISBLK(m)){
        strcpy(s,"b");
    }else
    if(S_ISLNK(m)){
        strcpy(s,"l");
    }else
    if(S_ISFIFO(m)){
        strcpy(s,"p");
    }else{
        strcpy(s,"-");
    }
    //man 2 stat ,查看宏，然后&
    strcat(s,m & S_IRUSR ? "r" : "-");
    strcat(s,m & S_IWUSR ? "w" : "-");
    strcat(s,m & S_IXUSR ? "x" : "-");
    strcat(s,m & S_IRGRP ? "r" : "-");
    strcat(s,m & S_IWGRP ? "w" : "-");
    strcat(s,m & S_IXGRP ? "x" : "-");
    strcat(s,m & S_IROTH ? "r" : "-");
    strcat(s,m & S_IWOTH ? "w" : "-");
    strcat(s,m & S_IXOTH ? "x" : "-");
    
    // -rwsrwxr-x
    if(m & S_ISUID){//有设置用户ID位的，是s，没有S，-rwsrwxr-x
        s[3] = (s[3] == 'x') ? 's' : 'S'; //
    }
    if(m & S_ISGID){//有设置组ID位的，是s，没有S，-rwsrwsr-x
        s[6] = (s[6] == 'x') ? 's' : 'S';
    }
    if(m & S_ISVTX){//有粘滞位的，是t，没有T，-rwsrwsr-t
        s[9] = (s[9] == 'x') ? 't' : 'T';
    }

    return s;
}

// time_t --> "2022-9-1 20:14:08" //将一个整数转换成串
//man 3 localtime
char* ttos(time_t t){
    static char time[20];
    struct tm* local = localtime(&t);
    sprintf(time,"%04d-%02d-%02d %02d:%02d:%02d",local->tm_year+1900,
                            local->tm_mon+1,local->tm_mday,local->tm_hour,local->tm_min,local->tm_sec);
    return time;
}
//"%04d", 不足4位补0，例如:202 -> 2020
//“%02d”，不足2位补0，例如：8 -> 08

int main(int argc,char* argv[]){
    // ./a.out hello.c
    if(argc < 2){
        fprintf(stderr,"用法:./a.out <文件名>\n");
        return -1;
    }

    struct stat buf;//用来输出文件的元数据
    if(stat(argv[1],&buf) == -1){
        perror("stat");
        return -1;
    }
    
    printf("          设备ID:%lu\n",buf.st_dev);
    printf("         i节点号:%ld\n",buf.st_ino);
    printf("      类型和权限:%s\n",mtos(buf.st_mode));
    printf("        硬链接数:%lu\n",buf.st_nlink);
    printf("          用户ID:%u\n",buf.st_uid);
    printf("            组ID:%u\n",buf.st_gid);
    printf("      特殊设备ID:%lu\n",buf.st_rdev);
    printf("        总字节数:%ld\n",buf.st_size);
    printf("     I/O块字节数:%ld\n",buf.st_blksize);
    printf("        存储块数:%ld\n",buf.st_blocks);
    printf("    最后访问时间:%s\n",ttos(buf.st_atime));
    printf("    最后修改时间:%s\n",ttos(buf.st_mtime));
    printf("    最后改变事假:%s\n",ttos(buf.st_ctime));
    return 0;
}
#endif

/*
 (base) wangyulingdeMacBook-Pro:day10 wyl$ gcc 02_stat.c  -o stat
 (base) wangyulingdeMacBook-Pro:day10 wyl$ ./stat mmap.txt
           设备ID:16777223
          i节点号:103489909
       类型和权限:-rw-rw-r--
         硬链接数:1
           用户ID:501
             组ID:20
       特殊设备ID:0
         总字节数:4096
      I/O块字节数:4096
         存储块数:8
     最后访问时间:2022-09-01 19:36:12
     最后修改时间:2022-09-01 19:36:12
     最后改变事假:2023-05-29 10:32:13
 */
