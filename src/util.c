/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:39:54 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 16:12:35 by tsomchan         ###   ########.fr       */
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
	while (str[len] == ' ')
		len++;
	if (str[len] == '-')
	{
		isnegative = -1;
		len++;
	}
	if (str[len] == '+')
		len++;
	//while (str[len])
	while (str[len] >= '0' && str[len] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[len] - '0';
		len++;
	}
	return (nbr * isnegative);
}
