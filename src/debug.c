/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:58:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/19 04:06:26 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_node(t_node *node, char *text)
{
	t_node	*head;
	t_node	*tmp;

	head = node;
	tmp = node->prev;
	printf("%s", text);
	printf(": [");
	while (tmp->next != head->prev)
	{
		tmp = tmp->next;
		printf("%d", tmp->val);
		if (tmp->next != head->prev)
			printf(", ");
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

void	print_stack(t_stack *stack)
{
	set_color(RED);
	print_node(stack->a, "stack a");
	set_color(BLUE);
	print_node(stack->b, "stack b");
	set_color(PURPLE);
	printf("-------- ---- ---- --- - - -- - --\n");
	set_color(RESET_C);
}

void	debug_title(char *s)
{
	set_color(GREEN);
	printf("| OPERATIONS |\n");
	set_color(RESET_C);
}

void	debug_op(t_stack *stack, void (*do_f)(t_stack *))
{
	do_f(stack);
	print_stack(stack);
}

void	debug_operations(t_stack *stack)
{
	debug_title("| OPERATIONS |\n");
	while (stack->b)
		nodedel(&stack->b);
	input_stack(stack, &(stack->b), (char *[4]){(char [99]){"6"},
		(char [99]){"13"}, (char [99]){"-2147483648"}, NULL});
	print_stack(stack);
	debug_op(stack, &do_sa);
	debug_op(stack, &do_sb);
	debug_op(stack, &do_ss);
	debug_op(stack, &do_pa);
	debug_op(stack, &do_pb);
	debug_op(stack, &do_ra);
	debug_op(stack, &do_rb);
	debug_op(stack, &do_rr);
	debug_op(stack, &do_rra);
	debug_op(stack, &do_rrb);
	debug_op(stack, &do_rrr);
}

void	debug_operations_1_node(t_stack *stack)
{
	debug_title("| OPERATIONS 1 NODE |\n");
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	input_stack(stack, &(stack->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(stack, &(stack->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(stack);
	debug_op(stack, &do_sa);
	debug_op(stack, &do_sb);
	debug_op(stack, &do_ss);
	debug_op(stack, &do_ra);
	debug_op(stack, &do_rb);
	debug_op(stack, &do_rr);
	debug_op(stack, &do_rra);
	debug_op(stack, &do_rrb);
	debug_op(stack, &do_rrr);
}

void	debug_push_empty_a(t_stack *stack)
{
	debug_title("| PUSH EMPTY A |\n");
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	input_stack(stack, &(stack->a), (char *[4]){NULL});
	input_stack(stack, &(stack->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(stack);
	debug_op(stack, &do_pb);
}

void	debug_push_empty_b(t_stack *stack)
{
	debug_title("| PUSH EMPTY B |\n");
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	input_stack(stack, &(stack->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(stack, &(stack->b), (char *[4]){NULL});
	print_stack(stack);
	debug_op(stack, &do_pa);
}

void	debug_push_1_a(t_stack *stack)
{
	debug_title("| PUSH 1 A |\n");
	while (stack->a)
		nodedel(&stack->a);
	while (stack->b)
		nodedel(&stack->b);
	input_stack(stack, &(stack->a), (char *[4]){(char [99]){"1"}, NULL});
	input_stack(stack, &(stack->b), (char *[4]){(char [99]){"6"}, NULL});
	print_stack(stack);
	debug_op(stack, &do_pb);
}

void	print_node_connect(t_node *node, char *node_text)
{
	printf("%s->val = %d ", node_text, node->val);
	printf("%s->next = %d ", node_text, node->next->val);
	printf("%s->prev = %d\n", node_text, node->prev->val);
}

int	check_ordered(t_node *a)
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

void	debug_ordered(t_stack *stack)
{
	if (check_ordered(stack->a) == 1)
		printcolor("Ordered\n", GREEN);
	else
		printcolor("NOT Ordered\n", RED);
}
