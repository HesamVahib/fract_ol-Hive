/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havhib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:16 by havhib            #+#    #+#             */
/*   Updated: 2024/11/15 21:27:24 by havhib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*calculation_num(char *num, int len, int n, int sign)
{
	num[len] = '\0';
	while (len > 0)
	{
		num[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
		if (len == 0 && sign == -1)
			num[0] = '-';
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		sign;
	int		mock_n;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		len = 2;
	}
	mock_n = n;
	while (mock_n > 9)
	{
		mock_n /= 10;
		len++;
	}
	num = (char *)malloc((len + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	return (calculation_num(num, len, n, sign));
}
