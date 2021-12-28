#include"pcpy.h"

int main(int argc, char** argv)
{
	int blockSize = atoi(argv[3]);
	int pos = atoi(argv[4]);
	int srcFile = open(argv[1],O_RDONLY);
	int destFile = open(argv[2],O_WRONLY|O_CREAT,0664);
	lseek(srcFile,pos,SEEK_SET);
	lseek(destFile,pos,SEEK_SET);
	printf("Copy Pid[%d] Pos[%d] block[%d]\n",getpid(),pos,blockSize);
	char buf[blockSize];
	bzero(buf,sizeof(buf));
	int res = read(srcFile,buf,sizeof(buf));
	write(destFile,buf,res);
	printf("拷贝完成\n");
	return 0;
}
