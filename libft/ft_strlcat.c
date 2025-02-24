/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:14:48 by havhib            #+#    #+#             */
/*   Updated: 2024/11/15 18:15:36 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	d_size = 0;
	while (d_size < dstsize && dst[d_size] != '\0')
		d_size++;
	s_size = 0;
	while (src[s_size] != '\0')
		s_size++;
	if (dstsize <= d_size)
		return (dstsize + s_size);
	i = 0;
	while (i < s_size && d_size + i < dstsize - 1)
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}
