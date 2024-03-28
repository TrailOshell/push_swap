/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:48:51 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/25 16:43:27 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_5_chunk(t_stack *stack, t_node **stack_name)
{
	set_operations(stack, *stack_name);
	// sort 2
	if ((*stack_name)->val > ((*stack_name)->next->val))
	{
		stack->swap(stack);
		return ;
	}
	// sort 3
	
}
