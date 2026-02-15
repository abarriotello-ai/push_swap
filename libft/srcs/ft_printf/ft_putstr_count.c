/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:14 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:51 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = (int)ft_strlen(s);
	write(1, s, len);
	return (len);
}
