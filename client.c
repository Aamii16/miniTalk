#include "minitalk.h"

char c = 0;
int	send_bit(char c, pid_t s_pid)
{
	unsigned char	bit;

	bit = 0b10000000;	
	while (bit)
	{
		if (bit & c)
		{
			kill(s_pid, SIGUSR1);// == -1)
				//return (write(2, "Error\n", 6));
		}
		else 
		{
			kill(s_pid, SIGUSR2); //== -1)
			//	return (write(2, "Error\n", 6));
		}
		//printf("%d\n", bit);
		bit >>= 1;
		usleep(100);
	}
	return (1);
}
int	main(int argc, char **argv)//gfdgdfgdfg ///////////////////// 
{
	char	c;
	int		index;
	int		bit;
	pid_t	s_pid;

	//handle arguments 
	s_pid = atoi(argv[1]);
	index = 0; 
	while(argv[2][index])
	{
		send_bit(argv[2][index], s_pid);
		index++;
	}

}