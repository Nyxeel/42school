/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_SIGPIPE_strchr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:44:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 18:13:22 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"
#include "strchr.h"

int sigpipe_test_strchr(void)
{
    int fd[2];
	pipe(fd);
	close(fd[0]);
	write(fd[1], "text", 4);
	ft_strchr("CEASER", 'c');
    return (-1);
}
