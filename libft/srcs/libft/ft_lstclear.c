/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:08:58 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:05:24 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		n = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = n;
	}
}

// static void	del_content(void *ptr)
// {
// 	free(ptr);
// }

// int main(void)
// {
//     t_list *lst;
//     t_list *n1 = ft_lstnew(ft_strdup("A"));
//     t_list *n2 = ft_lstnew(ft_strdup("B"));
//     t_list *n3 = ft_lstnew(ft_strdup("C"));

//     n1->next = n2;
//     n2->next = n3;
//     lst = n1;

//     ft_lstclear(&lst, del_content);

//     printf("%s\n", lst == NULL ? "OK" : "ERROR");
//     return 0;
// }