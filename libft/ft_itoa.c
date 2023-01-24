/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:50:49 by dyunta            #+#    #+#             */
/*   Updated: 2023/01/10 16:51:31 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. */

static int	get_int_len(long long n);
static char	*reverse_str(char *str);
static int	checkers(long long n, char *buffer);

char	*ft_itoa(int n)
{
	int			is_neg;
	int			i;
	char		*buffer;
	long long	long_n;

	long_n = (long long)n;
	is_neg = 0;
	i = 0;
	if (long_n < 0)
		is_neg = 1;
	buffer = (char *)malloc(sizeof(char) * get_int_len(long_n) + 1 + is_neg);
	if (!buffer)
		return (NULL);
	if (is_neg)
		long_n *= -1;
	if (checkers(long_n, buffer))
		return (buffer);
	while (long_n)
	{
		buffer[i++] = (long_n % 10) + '0';
		long_n /= 10;
	}
	if (is_neg)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (reverse_str(buffer));
}

static int	get_int_len(long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*reverse_str(char *str)
{
	char	aux;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = ft_strlen(str) - 1;
	len = j;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}

static int	checkers(long long n, char *buffer)
{
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}
	return (0);
}