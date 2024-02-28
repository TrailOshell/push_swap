/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:52 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 19:16:04 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

//ONLY for testing
# include <stdio.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	//struct	s_node *prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
}	t_stack;

//push_swap.c
void	push_swap(char **argv);

//stack files
//stack.c
t_stack	*start_stack(t_stack *stack);
void	input_stack(t_stack *stack, char **argv);

//node files
//node.c
t_node	*nodenew(int num);

//operations files
//do_swap.c
//void do_sa(t_stack *stack);
//void do_sb(t_stack *stack);
//void do_ss(t_stack *stack);
//do_push.c
//void do_pa(t_stack *stack);
//void do_pb(t_stack *stack);
//do_rotate.c
//void do_ra(t_stack *stack);
//void do_rb(t_stack *stack);
//void do_rr(t_stack *stack);
//do_reverse.c
//void do_rra(t_stack *stack);
//void do_rrb(t_stack *stack);
//void do_rrr(t_stack *stack);

//test files
//void	printNode(t_node *node, char *text)

#endif