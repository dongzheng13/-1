#include"pcpy.h"

int procreate(const char* srcFile,const char* destFile,int pronum,int blocksize)
{
	pid_t pid;
	int pos;
	int flag;
	char cblocksize[10];
	char cpos[10];
	bzero(cblocksize,sizeof(cblocksize));
	bzero(cpos,sizeof(cpos));
	for(flag = 0 ; flag < pronum ; flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0)
	{
		pid_t zpid;
		printf("父进程运行，pid:%d\n",getpid());	
		while((zpid = waitpid(-1,NULL,WNOHANG)) != -1)
		{
			if(zpid > 0)
			{
				printf("成功回收子进程，zpid:%d\n",zpid);	
			}
		}
	}
	else if(pid == 0)
	{
		printf("子进程运行，pid；%d\n",getpid());
		pos = flag * blocksize;
		sprintf(cblocksize,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		execl("/home/dz/colin1020/1228/copyText1/copy","./copy",srcFile,destFile,cblocksize,cpos,NULL);
	}
	else
	{
		perror("进程创建失败\n");
		exit(-1);
	}
}
