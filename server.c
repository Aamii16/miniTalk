/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:59:56 by amzahir           #+#    #+#             */
/*   Updated: 2025/02/28 23:59:57 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		usleep(100);
		c = 0;
	}
}

int	main(void)
{
	printf("%u\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
}
