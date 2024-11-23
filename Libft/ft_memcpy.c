/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:33:20 by kafortin          #+#    #+#             */
/*   Updated: 2024/11/12 17:38:39 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*altdst;
	unsigned char	*altsrc;
	size_t			i;

	altdst = (unsigned char *)dst;
	altsrc = (unsigned char *)src;
	if (!altdst && !altsrc)
		return (0);
	i = 0;
	while (i < n)
	{
		altdst[i] = altsrc[i];
		i++;
	}
	return (dst);
}
