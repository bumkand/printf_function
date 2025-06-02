/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:15:37 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/18 21:25:34 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print string

int	ft_printstr(char *s)
{
	int	number;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	number = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		number++;
	}
	return (number);
}
