/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:01 by havhib            #+#    #+#             */
/*   Updated: 2024/11/15 15:34:14 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*s;
	int		len;
	int		i;

	len = num * size;
	s = (char *)malloc(len);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
