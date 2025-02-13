/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:59:59 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/13 15:33:34 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				index;
	int 			rank;
	int				push_cost;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}							t_list;

void	sa(t_list **stack_a, int n);
void	sb(t_list **stack_a, int n);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a, int n);
void	rb(t_list **stack_b, int n);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int n);
void	rrb(t_list **stack_b, int n);

void	rrr(t_list **stack_a, t_list **stack_b);

long     ft_atoi(const char *str);
void	add_last(t_list	**stack, int n);
int	ft_isdigit(int c);
void	init_stack_a(t_list **stack_a , char **av);

int	syntax_error(char *str);
int check_double(t_list *a, int n);
void    free_stack(t_list **stack);
void    free_errors(t_list **stack);

//void	ft_index(t_list *stack_a);
//void set_target_a(t_list *stack_a, t_list *stack_b);
static void 	set_target_a(t_list *a, t_list *b);
static void	cost_for_a(t_list **a, t_list *b);
void	set_cheapest(t_list *stack);
void	init_nodes_a(t_list *a, t_list *b);

void    set_target_b(t_list *a, t_list *b);
void    init_nodes_b(t_list *a, t_list *b);

t_list	*get_max(t_list *stack);
t_list	*get_min(t_list *stack);
int		stack_len(t_list *stack_a);
t_list	*go_last(t_list **stack);
bool	stack_already_sorted(t_list *stack);

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *min);
void	sort_stack_2E(t_list **stack);
void    sort_stack_3E(t_list **stack);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *min);
void	min_go_top(t_list **stack_a);

void	move_a_to_b(t_list **a, t_list **b);
void	move_b_to_a(t_list **a, t_list **b);
void	sort_stacks(t_list **a, t_list **b);

int	count_words(char *s, char c);
char	*get_next_word(char *s, char c);
char **ft_split(char *s, char c);

void	prep_for_push(t_list **stack, t_list *top, char stack_name);
t_list	*get_cheapest(t_list *stack);


int stack_mediane(t_list *stack);
void mediane_check(t_list **stack_a, t_list **stack_b);
void set_rank(t_list **stack_a);



int		is_empty(t_list *stack_a);
void	print_list(t_list *stack_a);
t_list	*push_back_list(t_list *stack_a, int x);
t_list	*push_front_list(t_list *stack_a, int x);
t_list	*pop_back_list(t_list *stack_a);
t_list	*pop_front_list(t_list *stack_a);
t_list	*clear_list(t_list *stack_a);

#endif