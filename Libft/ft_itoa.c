/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:46:34 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/12 17:22:02 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;

	len = ft_intlen(n);
	a = malloc(len + 1 * sizeof(char));
	if (a == 0)
		return (NULL);
	a[len] = 0;
	if (n == -2147483648)
	{
		n = n / 10;
		a[len - 1] = '8';
		len = len - 1;
	}
	if (n < 0)
		a[0] = '-';
	n = ft_abs(n);
	while (n > 9)
	{
		a[--len] = n % 10 + 48;
		n = n / 10;
	}
	a[--len] = n + 48;
	return (a);
}
