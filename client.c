/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:59:42 by amzahir           #+#    #+#             */
/*   Updated: 2025/02/28 23:59:45 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(char c, pid_t s_pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				write(2, "Error\n", 6);
				exit (1);
			}
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				write(2, "Error\n", 6);
				exit (1);
			}
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

	s_pid = ft_atoi(argv[1]);
	if (argc != 3 || s_pid <= 0)
		return (write(2, "Wrong arguments\n", 16));
	index = 0;
	while (argv[2][index])
	{
		send_bit(argv[2][index], s_pid);
		index++;
	}
	send_bit(argv[2][index], s_pid);
	return (0);
}
