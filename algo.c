/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:41 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 18:27:59 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = get_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	cost_for_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;
	int	mediane;

	mediane = stack_mediane(a);
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		(a)->push_cost = (a)->index;
		if (!((a)->value > mediane))
			(a)->push_cost = len_a - (a)->index;
		if ((a)->target_node)
		{
			if ((a)->target_node->value > mediane)
				(a)->push_cost += (a)->target_node->index;
			else
				(a)->push_cost += len_b - ((a)->target_node->index);
		}
		(a) = (a)->next;
	}
}

void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_nodes_a(t_list *a, t_list *b)
{
	stack_mediane(a);
	stack_mediane(b);
	set_target_a(a, b);
	cost_for_a(a, b);
	set_cheapest(a);
}
