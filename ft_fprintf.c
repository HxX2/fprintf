/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:51:32 by zlafou            #+#    #+#             */
/*   Updated: 2022/04/16 20:00:22 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "stdio.h"

void	ft_fselector(va_list ap, const char *str, int *len, int fd)
{
	if (str[0] == 'c')
		*len += ft_putchar(va_arg(ap, int), fd);
	else if (str[0] == 's')
		ft_putstr(va_arg(ap, char *), len, fd);
	else if (str[0] == 'd')
		ft_putnbr(va_arg(ap, int), len, fd);
	else if (str[0] == 'i')
		ft_putnbr(va_arg(ap, int), len, fd);
	else if (str[0] == 'u')
		ft_putnbr(va_arg(ap, unsigned int), len, fd);
	else if (str[0] == 'x')
		ft_puthexx(va_arg(ap, unsigned int), str[0], len, fd);
	else if (str[0] == 'X')
		ft_puthexx(va_arg(ap, unsigned int), str[0], len, fd);
	else if (str[0] == 'p')
		ft_puthexx(va_arg(ap, unsigned long long), str[0], len, fd);
	else if (str[0] == '%')
		*len += ft_putchar(str[0], fd);
}

int	ft_fprintf(const char *str,int fd, ...)
{
	int		ret;
	va_list	ap;
	int		len;

	len = 0;
	va_start (ap, str);
	while (*str)
	{
		ret = 0;
		if (*str == '%')
		{	
			str++;
			ft_fselector(ap, str, &len, fd);
			++str;
		}
		else
			len += ft_putchar(*(str++), fd);
	}
	va_end(ap);
	return (len);
}
