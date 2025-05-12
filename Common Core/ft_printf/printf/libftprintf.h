/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:21:08 by netrunner         #+#    #+#             */
/*   Updated: 2025/05/12 17:21:18 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_va_start(const char *str, va_list ap);
int	find_arg(char c, va_list ap);

int	ft_arg_string(char	*str);
int	ft_hexa_base(size_t hexanum, char Xx, int count);
int	ft_arg_pointer(void *p);

int	ft_arg_unsigned(unsigned int i);
int	ft_arg_int(int i);

#endif
