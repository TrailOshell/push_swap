/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:05:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/04 17:28:20tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//currently not using t_stack *stack
void	add_node_last(t_stack *stack, t_node **stack_name, t_node *add)
{
	t_node	**head;
	t_node	*tmp;

	head = stack_name;
	if (!*head)
	{
		*head = add;
		tmp = add;
	}
	else
	{
		head = stack_name;
		tmp = (*head)->prev;
		tmp->next = add;
		(*head)->prev = add;
	}
	add->next = *head;
	add->prev = tmp;
}

t_node	*nodenew(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	nodedel(t_node **node)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *node;
	last = (*node)->prev;
	if ((*node)->next == *node)
	{
		free(*node);
		*node = NULL;
	}
	else
	{
		*node = (*node)->next;
		last->next = *node;
		(*node)->prev = last;
		free(tmp);
		tmp = NULL;
	}
}

void	swap_nodes_value(t_node **node_1, t_node **node_2)
{
	int		tmp_val;

	tmp_val = (*node_1)->val;
	(*node_1)->val = (*node_2)->val;
	(*node_2)->val = tmp_val;
}

int	count_nodes(t_node *node)
{
	t_node	*tmp;
	int		count;	

	tmp = node;
	if (!tmp)
		return (0);
	count = 1;
	while (tmp->next != node)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

//	printf("%d\n", (*node)->val);
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