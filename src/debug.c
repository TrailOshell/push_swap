/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:58:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/06 14:14:01 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_node(t_node *node, char *text)
{
	t_node	*head;
	t_node	*tmp;

	head = node;
	tmp = node;
	printf("%s", text);
	printf(": [");
	while (tmp)
	{
		printf("%d", tmp->val);
		if (tmp->next != head)
			printf(", ");
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	printf("]");
	printf("\n");
}

void	set_color(char *color)
{
	printf("%s", color);
}

void	printcolor(char *s, char *color)
{
	set_color(color);
	printf("%s", s);
	set_color(RESET_C);
}

void	print_stack(t_data *data)
{
	set_color(RED);
	print_node(data->a, "stack a");
	set_color(BLUE);
	print_node(data->b, "stack b");
	set_color(PURPLE);
	printf("-------- ---- ---- --- - - -- - --\n");
	set_color(RESET_C);
}

void	debug_title(char *s)
{
	set_color(GREEN);
	if (!s)
		printf("| OPERATIONS |\n");
	else
		printf("| %s |\n", s);
	set_color(RESET_C);
}

void	debug_op(t_data *data, void (*do_f)(t_data *))
{
	do_f(data);
	print_stack(data);
}

void	debug_operations(t_data *data)
{
	debug_title("| OPERATIONS |\n");
	while (data->b)
		nodedel(&data->b);
	input_stack(data, &(data->b), (char *[4]){(char [99]){"6"},
		(char [99]){"13"}, (char [99]){"-2147483648"}, NULL});
	print_stack(data);
	debug_op(data, &do_sa);
	debug_op(data, &do_sb);
	debug_op(data, &do_ss);
	debug_op(data, &do_pa);
	debug_op(data, &do_pb);
	debug_op(data, &do_ra);
	debug_op(data, &do_rb);
	debug_op(data, &do_rr);
	debug_op(data, &do_rra);
	debug_op(data, &do_rrb);
	debug_op(data, &do_rrr);
}

void	debug_operations_1_node(t_data *data)
{
	debug_title("| OPERATIONS 1 NODE |\n");
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	input_stack(data, &(data->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(data, &(data->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(data);
	debug_op(data, &do_sa);
	debug_op(data, &do_sb);
	debug_op(data, &do_ss);
	debug_op(data, &do_ra);
	debug_op(data, &do_rb);
	debug_op(data, &do_rr);
	debug_op(data, &do_rra);
	debug_op(data, &do_rrb);
	debug_op(data, &do_rrr);
}

void	debug_push_empty_a(t_data *data)
{
	debug_title("| PUSH EMPTY A |\n");
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	input_stack(data, &(data->a), (char *[4]){NULL});
	input_stack(data, &(data->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(data);
	debug_op(data, &do_pb);
}

void	debug_push_empty_b(t_data *data)
{
	debug_title("| PUSH EMPTY B |\n");
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	input_stack(data, &(data->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(data, &(data->b), (char *[4]){NULL});
	print_stack(data);
	debug_op(data, &do_pa);
}

void	debug_push_1_a(t_data *data)
{
	debug_title("| PUSH 1 A |\n");
	while (data->a)
		nodedel(&data->a);
	while (data->b)
		nodedel(&data->b);
	input_stack(data, &(data->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(data, &(data->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(data);
	debug_op(data, &do_pb);
}

void	print_node_connect(t_node *node, char *node_text)
{
	printf("%s->val = %d ", node_text, node->val);
	printf("%s->next = %d ", node_text, node->next->val);
	printf("%s->prev = %d\n", node_text, node->prev->val);
}

int	debug_check_ordered(t_node *a)
{
	t_node	*head;

	head = a;
	while (a)
	{
		//printf("val = %d ", a->val);
		if (a->next == head)
			break ;
		if (a->val > a->next->val)
		{
			printf("found %d > %d:", a->val, a->next->val);
			return (0);
		}
		a = a->next;
	}
	printf("\n");
	return (1);
}

void	debug_ordered(t_data *data)
{
	if (debug_check_ordered(data->a) == 1)
		printcolor("Ordered\n", GREEN);
	else
		printcolor("NOT Ordered\n", RED);
}
