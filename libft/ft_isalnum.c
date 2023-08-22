/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:02:48 by manumart          #+#    #+#             */
/*   Updated: 2022/10/28 18:53:29 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x >= 'a' && x <= 'z')
		|| (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
		return (1);
	else
		return (0);
}