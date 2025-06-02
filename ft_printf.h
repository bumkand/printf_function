/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:04:25 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/18 21:30:32 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printdig(int dig);
char	*ft_string(unsigned long digid, int *number);
int		ft_printunsdec(unsigned int dig);
void	u_putnbr(unsigned int n);

#endif