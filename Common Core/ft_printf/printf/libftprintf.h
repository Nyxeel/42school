/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:21:08 by netrunner         #+#    #+#             */
/*   Updated: 2025/05/13 10:16:18 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_va_start(const char *str, va_list ap);
void	find_arg(char c, va_list ap, int *count);

void	*ft_arg_string(char	*str, int *count);
void ft_putnbr_base(size_t hexanum, size_t basedivider, int *counter, char Xx);
void	ft_arg_pointer(void *p, int *count, char c);
void	ft_putchar_counter(char c, int *counter);
void	ft_putstr_counter(char *s, int *count);
void	ft_int_check(int nb, int *count);

#endif
