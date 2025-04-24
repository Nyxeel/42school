/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhegewal <linus.hegewald8@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:11:29 by lhegewal          #+#    #+#             */
/*   Updated: 2025/02/23 23:11:59 by lhegewal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_str(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != 0)
	{
		write (1, &str[counter], 1);
		counter++;
	}
}

void	ft_error(int c)
{
	if (c == 1)
		write(2, "Error\n", 6);
	if (c == 2)
		write(2, "Dict Error", 10);
}

int	ft_number_check(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9') || (c[0] == '0' && c[1] >= '0'
				&& c[1] <= '9'))
		{
			ft_error(1);
			return (1);
		}
		i++;
	}
	return (0);
}
