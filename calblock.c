#include"pcpy.h"

int calblock(const char* srcFile, int pronum)
{
	int fileSize;
	int fd = open(srcFile,O_RDONLY);
	fileSize = lseek(fd,0,SEEK_END);
	if(fileSize % pronum == 0)
		return fileSize / pronum;
	else
		return fileSize / pronum + 1;
	
}
