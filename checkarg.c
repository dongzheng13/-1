#include"pcpy.h"

int checkarg(const char * srcFile, int argc, int pronum)
{
	if(access(srcFile,F_OK)!=0)
	{
		printf("原文件不存在\n");
		exit(-1);
	}
	if(argc <3)
	{
		printf("参数数量错误\n");
		exit(-1);
	}
	if(pronum<=0 || pronum>100)
	{
		printf("进程数量必须在0到100之间\n");
		exit(-1);
	}
	return 0;
}
