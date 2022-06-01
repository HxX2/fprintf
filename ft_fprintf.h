/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:09:30 by zlafou            #+#    #+#             */
/*   Updated: 2022/04/16 20:00:47 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_puthexx(unsigned long long nb, char c, int *len, int fd);
void	ft_putnbr(long long nb, int *len, int fd);
int		ft_fprintf(int fd, const char *str, ...);
void	ft_putstr(char *str, int *len, int fd);
int		ft_putchar(int c, int fd);
#endif