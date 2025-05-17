/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:41:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/17 00:06:09 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

# include <fcntl.h>   // open
# include <stdlib.h>  // free
# include <stdio.h>   // printf
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>



void	*ft_calloc(size_t nmemb, size_t size);

#endif
#endif

