/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:26:23 by manumart          #+#    #+#             */
/*   Updated: 2023/01/12 12:18:41 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
		ft_putnbr(n, len);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
}

void	ft_unsignedputnbr(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_unsignedputnbr(n / 10, len);
		ft_unsignedputnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}

void	ft_hexa(unsigned int n, char cs, int *len)
{
	char	*base;

	if (cs == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hexa((n / 16), cs, len);
		ft_hexa((n % 16), cs, len);
	}
	else
		ft_putchar(base[n % 16], len);
}

static void	ft_puthex(unsigned long int n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n % 16], len);
	else
	{
		ft_puthex(n / 16, len);
		ft_puthex(n % 16, len);
	}
}

void	ft_print_memory(unsigned long ptr, int *len)
{
	unsigned long int	add;

	add = (unsigned long int)ptr;
	if (add == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	ft_putstr("0x", len);
	ft_puthex(add, len);
}
