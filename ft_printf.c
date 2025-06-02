/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:03:37 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/18 21:29:21 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int digid, int ascii)
{
	char			*str;
	unsigned int	i;
	int				number;

	str = ft_string(digid, &number);
	if (!str)
		return (0);
	i = digid;
	if (i == 0)
		str[0] = '0';
	while (i != 0)
	{
		if ((i % 16) < 10)
			str[number] = (i % 16) + 48;
		else
			str[number] = (i % 16) + ascii;
		i = i / 16;
		number--;
	}
	number = ft_printstr(str);
	free(str);
	return (number);
}

char	*ft_makecal(char *str, int *number, unsigned long calculate, int ascii)
{
	while (calculate != 0 && number >= 0)
	{
		if ((calculate % 16) < 10)
			str[*number] = (calculate % 16) + '0';
		else
			str[*number] = (calculate % 16) + ascii;
		calculate /= 16;
		(*number)--;
	}
	return (str);
}

int	ft_voidpoint(unsigned long point, int ascii)
{
	unsigned long	calculate;
	char			*str;
	int				number;

	if (point == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	str = ft_string(point, &number);
	if (!str)
		return (0);
	calculate = point;
	if (calculate == 0)
		str[0] = '0';
	ft_makecal(str, &number, calculate, ascii);
	number = ft_printstr("0x");
	number += ft_printstr(str);
	free(str);
	if (point == 0)
		number += ft_printchar('0');
	return (number);
}

// List of arguments

int	ft_cspdiux(char format, va_list args)
{
	int	number;

	number = 0;
	if (format == 'c')
		number += ft_printchar(va_arg(args, int));
	else if (format == 's')
		number += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		number += ft_voidpoint(va_arg(args, unsigned long), 87);
	else if (format == 'd' || format == 'i')
		number += ft_printdig(va_arg(args, int));
	else if (format == 'u')
		number += ft_printunsdec(va_arg(args, unsigned int));
	else if (format == 'x')
		number += ft_printhex(va_arg(args, unsigned int), 87);
	else if (format == 'X')
		number += ft_printhex(va_arg(args, unsigned int), 55);
	else if (format == '%')
		number += write(1, "%", 1);
	else
		number += write(1, &format, 1);
	return (number);
}

// Main function PRINTF

int	ft_printf(const char *format, ...)
{
	int		number;
	va_list	args;

	number = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			number += ft_cspdiux(*format, args);
		}
		else
			number += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (number);
}

// int	main(void)
// {
// 	int	result;

// 	result = printf("Sentence to know how many %s were wr%c%c%citten%p \n",
// 			"characters", 'F', 'F', 'F', "28");
// 	printf("%d%d\n%d,%X,%x, %p\n", result, 0, 22, -43, -43, "asdf123");

// 	result = ft_printf("Sentence to know how many %s were wr%c%c%citten%p \n",
// 			"characters", 'F', 'F', 'F', "28");
// 	ft_printf("%d%d\n%d,%X,%x, %p\n", result, 0, 22, -43, -43, "asdf123");
// 	printf("%d", ft_printf("%d\n", 12));
// 	printf("\n===============\n");
// 	printf("%d", printf("%d\n", 12));

// 	result = printf("\n%u:%u\n", -22, 10);
// 	printf("%d\n", result);
// 	result = ft_printf("\n%u:%u\n", -22, 10);
// 	ft_printf("%d\n", result);
// 	return (0);
// }
