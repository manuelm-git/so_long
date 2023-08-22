/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:50 by manumart          #+#    #+#             */
/*   Updated: 2023/07/27 18:54:28 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len) += 1;
}

void	ft_putstr(const char *s, int *len)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", len);
	}
	else
		while (s[i])
			ft_putchar(s[i++], len);
}
