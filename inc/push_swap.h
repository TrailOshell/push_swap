/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:52 by tsomchan          #+#    #+#             */
/*   Updated: 2024/04/09 12:18:54by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

//	ONLY for testing
//# include <stdio.h>

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET_C "\033[0m"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
	int				chunk_order;
}	t_node;

typedef struct s_data
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*order;
	struct s_node	*target;
	int				iserror;
	int				median;
	int				quarter;
	int				half_quarter;
	void			(*swap)(struct s_data *);
	void			(*rotate)(struct s_data *);
	void			(*reverse)(struct s_data *);
	void			(*push)(struct s_data *);
}	t_data;

//	push_swap.c
t_data	*start_data(t_data *data);
void	end_data(t_data *data);
void	push_swap(char **argv);

// util.c
size_t	ps_strlen(char *s);
int		ps_strcmp(char *s1, char *s2);
char	*ps_strdup(char *str);
long	atoi_push_swap(char *str);

// stack.c
void	input_stack(t_data *data, char **input);
void	dupe_stack(t_node *stack_origin, t_node **stack_dupe);
t_node	*current_stack_order(t_data *data, t_node *stack);

// node.c
t_node	*nodenew(int num, int chunk_order);
void	nodedel(t_node **node);
int		count_nodes(t_node *head);
void	swap_nodes_value(t_node **node_1, t_node **node_2);
void	add_node_last(t_node **stack, t_node *add);

// do_swap.c
void	do_sa(t_data *data);
void	do_sb(t_data *data);
void	do_ss(t_data *data);

// do_push.c
void	do_pa(t_data *data);
void	do_pb(t_data *data);

// do_rotate.c
void	do_ra(t_data *data);
void	do_rb(t_data *data);
void	do_rr(t_data *data);

// do_reverse.c
void	do_rra(t_data *data);
void	do_rrb(t_data *data);
void	do_rrr(t_data *data);

// do_operations.c
void	set_operations(t_data *data, t_node *stack);
void	do_swap_push(t_data *data);
void	do_r_till_target_push(t_data *data, t_node *head);
void	do_rr_till_target_push(t_data *data, t_node *head);
void	do_condition_then_push(t_data *data, t_node *stack, int chunk_order);

// find_value.c
int		find_max(t_node *stack);
int		find_min(t_node *stack);
void	find_median(t_data *data, t_node *stack);
void	find_quarter(t_data *data, t_node *stack);
void	find_half_quarter(t_data *data, t_node *stack);

// check.c
int		check_rotate_median_push(t_data *data);
int		check_rotate_quarter_push(t_data *data);
int		check_median_push(t_data *data, t_node *stack, int median);
int		check_ordered(t_node *a);
int		isnear_head(t_node *stack, t_node *node);

// sort_5.c
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);
void	sort_in_5(t_data *data);

// sorting.c
void	push_till_median(t_data *data, int chunk_order);
void	push_till_quarter(t_data *data, int chunk_order);
void	push_min_max_chunk(t_data *data, int chunk_order);
void	final_ordering(t_data *data);

// chunk.c
int		check_has_chunk(t_node *stack, int chunk_order);
void	set_target_chunk(t_data *data, int *ismin, int *isnear_head, int order);

// error.c
void	write_error(void);
int		empty_error(t_data *data, char *input);
int		input_error(t_data *data, char *input);
int		dupnbr_error(t_data *data, int num);
int		overflow_error(t_data *data, long num);

// debug.c
void	set_color(char *color);
void	write_color(char *s, char *color);
void	ps_itoa(int num);
void	write_stack(t_node *node, char *text);
void	final_check(t_data *data);

#endif