/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:48:43 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/05 22:48:45 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRDUP_H
#define STRDUP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int strdup_launcher(void);

int ok_test_strdup(void);
int ko_test_strdup(void);
int segfault_test_strdup(void);
int sigbus_test_strdup(void);

#endif
