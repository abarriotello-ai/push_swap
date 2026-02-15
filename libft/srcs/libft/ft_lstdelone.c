/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:51:08 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/21 20:08:16 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free (lst);
}

// static void	del_content(void *ptr)
// {
// 	free(ptr);
// }

// int main ()
// {
// 	// (el nodo ya debe estar desenlazado de la lista)
// 	t_list *node = ft_lstnew(malloc(10));
// // ... desconectar 'node' de la lista si estaba dentro ...
// 	ft_lstdelone(node, del_content);
// }