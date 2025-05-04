/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:31:56 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/04 14:47:24 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	letter;
	char			*last;
	char			*tmp;
	size_t			i;

	*last = NULL;
	*tmp = (char *) str;
	letter = (unsigned char) c;
	i = 0;
	if (tmp == NULL)
		return (NULL);
	if (letter == '\0')
		return (tmp + (ft_strlen(tmp)));
	while (tmp[i])
	{
		if (tmp[i] == letter)
			last = tmp + i;
		if (tmp[i + 1] == '\0')
			return (last);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
    char str[] = "hahahahabcgcgedjdk";
    char suche = 'a';

    char *p = ft_strrchr(str, suche);
    if (p != NULL)
    {
        printf("Gefunden: '%c'\n", *p);                → s
        printf("Ab hier: \"%s\"\n", p);                 → s wort das ich suche
        printf("Index im String: %ld\n", p - str); 2 (weil p zeigt auf str[2])
    }
    else
        printf("Nicht gefunden.\n");
} */
