/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:12:32 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/21 18:32:56 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n -> content = content;
	n -> next = NULL;
	return (n);
}
/*
int main ()
{
	t_list *n1;
	t_list *n2;
	
	n1 = ft_lstnew("Buenos");
	n2 = ft_lstnew("dias");

	printf("%s\n", (char *)n1->content);
	printf("%s\n", (char *)n2->content);

	free (n1); free (n2);
	return 0;
}
*/