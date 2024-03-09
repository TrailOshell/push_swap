/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/01 16:18:48by tsomchan         ###   ########.fr       */
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
		tmp = tmp->next;
		if (tmp == head)
			break ;
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

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	input_stack(stack, &(stack->a), ++argv);
	//print_node(stack->a, "print a");
	//printf("stack->a->next = %d", stack->a->next->val);
	if (!stack->iserror)
	{
		//debug_operations(stack);
		//debug_operations_1_node(stack);
		//debug_push_empty_a(stack);
		//debug_push_empty_b(stack);
		//debug_push_1_a(stack);
	}
	else
		write(1, "Error\n", 7);
	current_stack_order(stack, &(stack->a));
	//get_order_stack(stack, argv);
	set_color(YELLOW);
	print_node(stack->order, "print order");
	set_color(RESET_C);
	find_median(stack, &(stack->a));
	printf("median val = %d\n", stack->median);
	push_till_median(stack, &(stack->a), 'a');
	print_stack(stack);
	sort_3_ascend(stack, &(stack->a));
	print_stack(stack);
	sort_3_descend(stack, &(stack->b));
	print_stack(stack);
	while (stack->b)
		push_max(stack, &(stack->b));
	print_stack(stack);
	//print_node_connect(stack->median, "median_node");
	end_stack(stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
}
