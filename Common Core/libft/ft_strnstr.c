/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:31:10 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 11:31:52 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
    if (needle[0] == '\0')
        return ((char *)haystack);
    while(i < n && haystack[i] != '\0')
    {
		j = 0;
        while (haystack[i + j] == needle[j] && i + j < n)
        {
            if (needle[j + 1] == '\0')
                return ((char *)&haystack[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(void)
{

    const char big[] = "Hi we schönewea welt";
    const char little[] = "wel";

    printf("%s", ft_strnstr(big, little, 100));
}
