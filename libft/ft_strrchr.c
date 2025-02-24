/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:15:03 by havhib            #+#    #+#             */
/*   Updated: 2024/11/16 00:13:56 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*res;
	size_t	i;
	char	ch;

	ch = (char)c;
	res = NULL;
	if (c == '\0')
		return (str + ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			res = &str[i];
		i++;
	}
	return (res);
}
