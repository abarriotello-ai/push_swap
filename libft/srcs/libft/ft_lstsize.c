/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:55:15 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/21 19:08:20 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst -> next;
	}
	return (n);
}

// int main ()
// {
// 	t_list	*n1, *n2, *n3;

// 	n1=ft_lstnew("A");
// 	n2=ft_lstnew("B");
// 	n3=ft_lstnew("C");

// 	ft_lstadd_front(&n3, n2);
// 	ft_lstadd_front(&n2, n1);
// 	printf("%d\n", ft_lstsize(n1));
// 	return 0;
// }