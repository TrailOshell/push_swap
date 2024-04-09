/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 11:44:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_rotate(t_node **node)
{
	*node = (*node)->next;
}

void	do_ra(t_data *data)
{
	do_rotate(&data->a);
	write(1, "ra\n", 3);
}

void	do_rb(t_data *data)
{
	do_rotate(&data->b);
	write(1, "rb\n", 3);
}

void	do_rr(t_data *data)
{
	do_rotate(&data->a);
	do_rotate(&data->b);
	write(1, "rr\n", 3);
}
