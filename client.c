#include "minitalk.h"

int	send_bit(char c, pid_t s_pid)
{
	unsigned char	bit;

	bit = 0b10000000;	
	while (bit)
	{
		if (bit & c)
		{
			if(kill(s_pid, SIGUSR1) == -1)
				return (write(2, "Erghjhgjghjghror\n", 6));
		}
		else 
		{
			if (kill(s_pid, SIGUSR2) == -1)
				return (write(2, "Error\n", 6));
		}
		bit >>= 1;
		usleep(100);
	}
	return (1);
}
int	main(int argc, char **argv)
{
	pid_t	s_pid;
	int		index;

	//handle arguments 
	s_pid = atoi(argv[1]);
	if (argc != 3 || !s_pid )
		return (write(2, "Error\n", 6));
	index = 0; 
	while(argv[2][index])
	{
		send_bit(argv[2][index], s_pid);
		index++;
	}
	return (0);
}