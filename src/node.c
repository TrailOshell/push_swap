/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:05:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 22:35:29 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_node_last(t_stack *stack, char stack_name, t_node *add)
{
	t_node	**head;
	t_node	*tmp;

	if (stack_name == 'a')
		head = &(stack->a);
	else
		head = &(stack->b);
	if (!*head)
		*head = add;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add;
	}
}

void	add_node_head(t_stack *stack, char stack_name, t_node *add)
{
	
}

void	del_node_head(t_stack *stack, char stack_name, t_node *add)
{
	
}

t_node	*nodenew(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = num;
	new->next = NULL;
	return (new);
}

/* nodenew()
	//printf("nodenew %d\n", new->val);
*/

/* add_node_last() 
void	add_node_last(t_stack *stack, char stack_name, t_node *add)
	t_node	**head;
	t_node	**last;
	t_node	*tmp;

	if (stack_name == 'a')
	{
		head = &(stack->a);
		last = &(stack->last_a);
		stack->last_a = add;
	}
	else
	{
		head = &(stack->b);
		tmp = stack->last_b;
		stack->last_b = add;
	}
	if (!*head)
	{
		*head = add;
		*last = add;
		return ;
	}
	else
	{
		if (!(*head)->next)
			(*head)->next = add;
		//tmp = *last;
		(*last)->next = add;
		printf("add = %d\n", (*last)->next->val);
		*last = add;
		//tmp = *head;
		//while (tmp->next)
		//	tmp = tmp->next;
		//tmp->next = add;
	}
	//printf("last_a = %d\n", stack->last_a->val);
*/