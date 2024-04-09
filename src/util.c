/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:39:54 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 13:10:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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

int	atoi_push_swap(char *str)
{
	int	nbr;
	int	len;
	int	isnegative;

	if (ps_strcmp(str, "-2147483648"))
		return (-2147483648);
	nbr = 0;
	len = 0;
	isnegative = 1;
	if (str[0] == '-')
	{
		isnegative = -1;
		len++;
	}
	while (str[len])
	{
		nbr = nbr * 10;
		nbr = nbr + str[len] - '0';
		len++;
	}
	return (nbr * isnegative);
}
