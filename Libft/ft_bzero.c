/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:52:15 by kafortin          #+#    #+#             */
/*   Updated: 2024/11/12 17:36:25 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Erases the data of the memory location pointed by "*s" by writing zeros
for "n" number of bytes.*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
