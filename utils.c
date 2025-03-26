/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:04:11 by amzahir           #+#    #+#             */
/*   Updated: 2025/03/26 02:26:12 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	count_digits(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	long	nb;
	int		len;
	char	digits[11];
	int		i;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	len = count_digits(nb);
	while (len--)
	{
		digits[len] = nb % 10 + 48;
		nb /= 10;
	}
	while (i < count_digits(n))
		write(1, &digits[i++], 1);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (!str)
		return (0);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (*str > '9' || *str < '0')
			return (0);
		num = (*str - '0') + (num * 10);
		str++;
	}
	return (num);
}
