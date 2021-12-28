#include"pcpy.h"

int main(int argc, char ** argv)
{
	int pronum;
	if(argv[3] == 0)
		pronum = 5;
	else
		pronum = atoi(argv[3]);
	checkarg(argv[1],argc,pronum);
	int blocksize = calblock(argv[1],pronum);
	procreate(argv[1],argv[2],pronum,blocksize);
	
	return 0;	
}
