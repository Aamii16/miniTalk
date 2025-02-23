#include <signal.h> 
#include <unistd.h>
#include <sys/types.h>
#include "minitalk.h"

char c = 0;
void	sig_handler(int sig_num)
{
	static char	bit;

	bit = 0b10000000;
	if (sig_num = SIGUSR1)
		c = c | bit;	
	else if (sig_num = SIGUSR2)
		;
	bit >> 1;
}
int main()
{
	printf("server pid %u\n", getpid());
	int	i;

	i = 8;
	while (1)
	{
		pause();
		while(i--)
		{
			signal(SIGUSR1, sig_handler);
			signal(SIGUSR2, sig_handler);
		}
		write(1, &c, 1);
		sleep(100);
		c = 0;
		c = 0b1000000;
	}
}
