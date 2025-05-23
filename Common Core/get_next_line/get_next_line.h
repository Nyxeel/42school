/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:41:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/21 13:22:08 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42000
#endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
ssize_t	find_line(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*trim_the_line(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif

