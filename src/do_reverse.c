/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:06:17 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 11:44:41 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_reverse(t_node **node)
{
	*node = (*node)->prev;
}

void	do_rra(t_data *data)
{
	do_reverse(&data->a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_data *data)
{
	do_reverse(&data->b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_data *data)
{
	do_reverse(&data->a);
	do_reverse(&data->b);
	write(1, "rrr\n", 4);
}
