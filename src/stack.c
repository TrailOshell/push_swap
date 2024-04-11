/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/11 16:53:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	nbrlen(char *input)
{
	int	len;

	if (ps_strcmp(input, "-2147483648"))
		return (11);
	len = 0;
	while (input[len] == ' ')
		len++;
	if (input[len] == '-' || input[len] == '+')
		len++;
	while (input[len] >= '0' && input[len] <= '9')
		len++;
	while (input[len] == ' ')
		len++;
	return (len);
}

void	input_stack(t_data *data, char **input)
{
	long	num;
	int		len;

	while (*input)
	{
		if (nbr_error(data, *input) == 1)
			return ;
		while (**input)
		{
			if (nbr_error(data, *input) == 1)
				return ;
			len = nbrlen(*input);
			//printf("len = %d\t", len);
			//printf("%s*input = \"%s\"\n%s", PURPLE, *input, RESET_C);
			num = atoi_push_swap(*input);
			//printf("%snum = \"%ld\"\n%s", PURPLE, num, RESET_C);
			if (num < -2147483648 || num > 2147483647)
			{
				data->iserror = 1;
				return ;
			}
			add_node_last(&(data->a), nodenew(num, 0));
			if (data->a && dupnbr_error(data, num) == 1)
				return ;
			*input += len;
		}
		input++;
	}
}

void	dupe_stack(t_node *origin, t_node **dupe)
{
	t_node	*head;
	t_node	*new;

	head = origin;
	while (*dupe)
		nodedel(dupe);
	while (origin)
	{
		new = nodenew(origin->val, origin->chunk_order);
		add_node_last(dupe, new);
		origin = origin->next;
		if (origin == head)
			break ;
	}
}

t_node	*current_stack_order(t_data *data, t_node *stack)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*min_prev;
	t_node	*tmp;

	dupe_stack(stack, &(data->order));
	min_prev = NULL;
	head = data->order;
	while (head->next != data->order)
	{
		min_node = head;
		tmp = head;
		while (tmp->next != head)
		{
			tmp = tmp->next;
			if (tmp->val < min_node->val
				&& (!min_prev || tmp->val > min_prev->val))
				min_node = tmp;
		}
		swap_nodes_value(&(min_node), &(head));
		min_prev = head;
		head = head->next;
	}
	return (data->order);
}
