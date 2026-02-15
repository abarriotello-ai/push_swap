/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:13:17 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:56:42 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)(sign * num));
}

// int main(void)
// {
// 	printf("%d\n", ft_atoi("   -42"));
// 	printf("%d\n", ft_atoi("+2147483647"));
// 	return (0);
// }