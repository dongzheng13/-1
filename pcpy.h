#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>


int checkarg(const char* srcFile,int argc,int pronum);
int calblock(const char* srcFile,int pronum);
int procreate(const char* srcFile,const char* destFile,int pronum,int blocksize);
