/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:48:22 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/06 18:18:37 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCHR_H
#define STRCHR_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int strchr_launcher(void);

int ok_test_strchr(void);
int ko_test_strchr(void);
int segfault_test_strchr(void);
int sigbus_test_strchr(void);
int	sigfpe_test_strchr(void);
int sigabrt_test_strchr(void);
int sigpipe_test_strchr(void);
int sigill_test_strchr(void);

#endif
