#include <unistd.h>

int main(int argc,char**argv)
{
	int i = 0;
	if(argc >= 2)
	{
		char *str = argv[argc - 1];
		while(str[i] != '\0')
		{
			write(1,&str[i++],1);
		}
	}
	write(1,"\n",1);
}
