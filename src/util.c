/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:39:54 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 18:37:53 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ps_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ps_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}

char	*ps_strdup(char *str)
{
	char	*dupe;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dupe = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

long	atoi_push_swap(char *str)
{
	long	nbr;
	int		len;
	int		sign;

	nbr = 0;
	len = 0;
	sign = 1;
	while (str[len] == ' ')
		len++;
	if (str[len] == '-' || str[len] == '+')
	{
		if (str[len] == '-')
			sign = -1;
		len++;
	}
	while (str[len] >= '0' && str[len] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[len] - '0';
		if (nbr < -2147483648 || nbr > 2147483647)
			break ;
		len++;
	}
	return (nbr * sign);
}
