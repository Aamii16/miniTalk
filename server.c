#include "minitalk.h"

void	sig_handler(int sig_num)
{
	static unsigned char	bit;
	static unsigned char	c;

	if (bit == 0)
		bit = 0b10000000;
	if (sig_num == SIGUSR1)
		c = c | bit;
	bit >>= 1;
	if (bit == 0)
	{
		write(1, &c, 1);
		c = 0;
	}	
}
int main()
{
	printf("%u\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
		usleep(100);
	}
}
