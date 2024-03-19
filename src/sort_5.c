/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:23:03 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/19 06:28:06 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->a->val > (stack->a->next->val))
		do_sa(stack);
}

void	sort_3(t_stack *stack)
{
	int	max;

	max = find_max(stack, &(stack->a));
	if (stack->a->val == max)
		stack->rotate(stack);
	else if (stack->a->next->val == max)
		stack->reverse(stack);
	sort_2(stack);
}

void	sort_4(t_stack *stack)
{
	int	min;

	min = find_min(stack, &(stack->a));
	while (stack->a->val != min)
	{
		do_ra(stack);
		stack->a = stack->a->next;
	}
	do_pb(stack);
	sort_3(stack);
	do_pa(stack);
}

void	sort_5(t_stack *stack)
{
	int	count;

	count = 5;
	find_median(stack, &(stack->a));
	while (count > 3)
	{
		if (stack->a->val < stack->median)
		{
			do_pb(stack);
			count--;
		}
		else
			do_ra(stack);
	}
	sort_3(stack);
	if (stack->b->val < (stack->b->next->val))
		do_sb(stack);
	do_pa(stack);
	do_pa(stack);
}

void	sort_in_5(t_stack *stack)
{
	int	count;

	count = count_nodes(stack->a);
	//printf("count = %d\n\n\n", count);
	if (count == 2)
		sort_2(stack);
	else if (count == 3)
		sort_3(stack);
	else if (count == 4)
		sort_4(stack);
	else if (count == 5)
		sort_5(stack);
	//else
		//error
}

/*
void	sort_2(t_stack *stack)
{
	int	do_swap_a;	
	int	do_swap_b;	

	do_swap_a = stack->a->val > (stack->a->next->val);
	do_swap_b = stack->b->val < (stack->b->next->val);
	if (do_swap_a && do_swap_b)
		do_ss(stack);
	else if (do_swap_a)
		do_sa(stack);
	else if (do_swap_b)
		do_sb(stack);
}
*/