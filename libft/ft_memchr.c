/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:14:03 by havhib            #+#    #+#             */
/*   Updated: 2024/11/15 19:08:26 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;
	unsigned char		val;

	p = (const unsigned char *)ptr;
	val = (unsigned char)value;
	while (num--)
	{
		if (*p == val)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
