/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:09:38 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/29 18:41:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_node(t_node *node, char *text)
{
	printf("%s", text);
	printf(": [");
	while (node)
	{
		printf("%d", node->val);
		if (node->next)
			printf(",");
		node = node->next;
	} printf("]");
	printf("\n");
}

void	input_stack_b(t_stack *stack, char **input)
{
	int		num;

	while (*input)
	{
		num = atoi_push_swap(*input);
		add_node_last(stack, 'b', nodenew(num));
		input++;
	}
}

void	debug_operations(t_stack *stack)
{
	printf("| OPERATIONS |\n");
	input_stack_b(stack, (char *[4]){(char [99]){"6"},
		(char [99]){"13"}, (char [99]){"-2147483648"}, NULL});
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	//do_sa(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_sb(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_ss(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	do_pa(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_pb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	//do_ra(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_rb(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_rr(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_rra(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_rrb(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
	//do_rrr(stack);
	//print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	//printf("-------- ---- ---- --- - - -- - --\n");
}

void	debug_operations_1_node(t_stack *stack)
{
	printf("| OPERATIONS 1 NODE |\n");
	input_stack(stack, (char *[4]){(char [99]){"argv[0]"}, (char [99]){"1"}, NULL});
	input_stack_b(stack, (char *[4]){(char [99]){"6"}, NULL});
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_sa(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_sb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_ss(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_ra(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_rb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_rr(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_rra(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_rrb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_rrr(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
}

void	debug_push_empty_a(t_stack *stack)
{
	printf("| PUSH EMPTY A |\n");
	input_stack(stack, (char *[4]){(char [99]){"argv[0]"}, NULL});
	input_stack_b(stack, (char *[4]){(char [99]){"6"}, NULL});
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_pb(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
}

void	debug_push_empty_b(t_stack *stack)
{
	printf("| PUSH EMPTY B |\n");
	input_stack(stack, (char *[4]){(char [99]){"argv[0]"}, (char [99]){"1"}, NULL});
	input_stack_b(stack, (char *[4]){NULL});
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
	do_pa(stack);
	print_node(stack->a, "stack a"); print_node(stack->b, "stack b");
	printf("-------- ---- ---- --- - - -- - --\n");
}

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*node;

	stack = NULL;
	stack = start_stack(stack);
	//input_stack(stack, argv);
	//debug_operations(stack);
	//debug_operations_1_node(stack);
	//debug_push_empty_a(stack);
	//debug_push_empty_b(stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2) return (0);
	push_swap(argv);
}

/*
	//printf("%p\n", stack);
	//node = malloc(sizeof(t_node));
	//write(1, "test\n", 6);
	//stack->a = node;
	//write(1, "test\n", 6);
	write(1, "test\n", 6);
	stack->a = malloc(sizeof(t_node));
	stack->a->val = 42;
	printf("%d", stack->a->val);
	//printf("last_a = %d\n", stack->last_a->val);
*/