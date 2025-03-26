/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:59:56 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/26 02:54:17 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig_num, siginfo_t *info, void *ucontext)
{
	static int	client_pid;

	static unsigned char (bit), (c);
	if (!client_pid)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		c = 0;
		bit = 0;
		client_pid = info->si_pid;
	}
	(void)(ucontext);
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
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
