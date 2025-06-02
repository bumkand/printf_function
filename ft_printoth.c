/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:10:32 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/18 21:29:58 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print Character

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// Print Digit

int	ft_printdig(int dig)
{
	int				cal;
	unsigned int	number;

	cal = dig;
	number = 0;
	if (dig == -2147483648)
		number = 10;
	else
	{
		if (dig < 0)
		{
			cal = -dig;
			number++;
		}
		while (cal > 9)
		{
			cal = cal / 10;
			number++;
		}
	}
	number++;
	ft_putnbr_fd(dig, 1);
	return (number);
}

// Make String

char	*ft_string(unsigned long digid, int *number)
{
	char			*str;
	int				i;
	unsigned long	temp;

	i = 0;
	temp = digid;
	if (digid == 0)
		i = 1;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	*number = i - 1;
	return (str);
}

// Print Unsigned

void	u_putnbr(unsigned int n)
{
	if (n > 9)
		u_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_printunsdec(unsigned int dig)
{
	unsigned int	cal;
	unsigned int	number;

	cal = dig;
	number = 0;
	while (cal > 9)
	{
		cal = cal / 10;
		number++;
	}
	if (cal < 10)
		number++;
	u_putnbr(dig);
	return (number);
}
