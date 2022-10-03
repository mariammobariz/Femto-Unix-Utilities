#include<stdio.h>
#include <unistd.h>

int main()
{
	char *buf[50];
	char *mypwd = getwd(buf);
	if(mypwd != "NULL")
		{
			printf("%s\n",mypwd);
		}
	else
		{
			printf("error!");
		}
	return 0;
	

}
