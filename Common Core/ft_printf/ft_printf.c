/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:45:21 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/08 20:54:42 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_arg(unsigned char c, va_list ap)
{
	if (c == 'c')
		return (ar_arv(ap, char));
	if (c == 's')
		return (ft_putstr_fd(ar_arv(ap, char *)));
	if (c == 'p')
			return ("Hex"));
	if (c == 'd' || c == 'i')
	if (c == 'u')
	if (c == 'x'|| c == 'X')
	if (c == '%')

	%ü

}

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	if (!str)
		return (0);
	format_len = ft_strlen(str)
	while (str[i])
	{
		if (str[i] == '%')
			find_arg(str[i + 1], ap);
		i++;
	}
	va_end(ap);
	return	();
}


va_start va_end va_arg va_copy
/*


%c – einzelnes Zeichen

%s – String (Text)

%p – Pointer (Adresse als Hex)

%d / %i – dezimale Zahl (auch negativ)

%u – unsigned dezimale Zahl

%x / %X – Hexadezimal (klein/groß)

%% – nur ein Prozentzeichen


 */
