#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"
#define MAX_LEN 80

int main(int argc, char * argv[])
{
	char buff[MAX_LEN];
	int  retval;
	int  fifo = open(FIFO_NAME, O_WRONLY);
	
	printf("Pipe is open for write\n");

	for(;;)
	{
		fflush(stdin);
		char * str = fgets(buff, MAX_LEN, stdin);
		if(NULL == str)
		{
			break;
		}
		int ret = write(fifo, buff, MAX_LEN);
	}
	close(fifo);
	return 0;
}
