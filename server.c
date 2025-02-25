#include "minitalk.h"

char c = 0;
void	sig_handler(int sig_num)
{
	static char	bit;
	static char	c;

	if (bit == 0)
		bit = 0b10000000;
	if (SIGUSR1)
		c = c | bit;
	bit >> 1;
	if (bit == 0b1)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}	
}
int main()
{
	printf("%u\n", getpid());
	while (1)
	{
		pause();
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		usleep(100);
	}
}
