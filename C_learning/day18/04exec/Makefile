#目标main,依赖文件:main.o cal.o arr.o
main:main.o cal.o arr.o
	gcc main.o cal.o arr.o -o main
#目标:main.o 依赖main.c
main.o:main.c
	gcc -c main.c -o main.o
cal.o:cal.c
	gcc -c cal.c -o cal.o
arr.o:arr.c
	gcc -c arr.c -o arr.o

clean:
	rm *.o main

