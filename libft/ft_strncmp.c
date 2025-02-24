/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:14:58 by havhib            #+#    #+#             */
/*   Updated: 2024/11/15 18:20:27 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	len;

	if (n == 0)
		return (0);
	len = 0;
	while (((s1[len] != '\0') || (s2[len] != '\0'))
		&& (len + 1 < n) && (s1[len] == s2[len]))
	{
		len++;
	}
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}
