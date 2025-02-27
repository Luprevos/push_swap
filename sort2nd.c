/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2nd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:33:37 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 18:05:19 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;
	int		mediane;

	mediane = stack_mediane(*a);
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->value > mediane
		&& cheapest_node->target_node->value > mediane)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->value > mediane)
		&& !(cheapest_node->target_node->value > mediane))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_already_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !stack_already_sorted(*stack_a))
		pb (stack_a, stack_b);
	while (len_a-- > 3 && !stack_already_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_stack_3e(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	stack_mediane(*stack_a);
	min_go_top(stack_a);
}
