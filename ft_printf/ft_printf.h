/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:25:06 by manumart          #+#    #+#             */
/*   Updated: 2023/07/27 18:54:28 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int				ft_printf(const char *str, ...);
void			ft_putchar(char c, int *len);
void			ft_putstr(const char *s, int *len);
void			ft_putnbr(int nbr, int *len);
void			ft_unsignedputnbr(unsigned int n, int *len);
void			ft_hexa(unsigned int nbr, char cs, int *len);
void			ft_print_memory(unsigned long ptr, int *len);

#endif