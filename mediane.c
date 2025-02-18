/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:36 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 17:19:13 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	stack_index(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

int	stack_mediane(t_list *stack)
{
	int	mediane;
	int	len;

	mediane = 0;
	len = 0;
	stack_index(stack);
	set_rank(&stack);
	if (stack)
	{
		len = stack_len(stack);
		while (stack->rank != len / 2)
			stack = stack->next;
		mediane = stack->value;
	}
	return (mediane);
}

void	mediane_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*start;
	int		mediane;

	if (!(*stack_a))
		return ;
	start = *stack_a;
	while (stack_len(*stack_a) > 3)
	{
		mediane = stack_mediane(*stack_a);
		while (*stack_a)
		{
			if ((*stack_a)->value < mediane)
				pb(stack_a, stack_b);
			else
				*stack_a = (*stack_a)->next;
		}
		*stack_a = start;
	}
}

void	set_rank(t_list **stack_a)
{
	t_list	*stack_a_copy;
	t_list	*start;
	int		rank;

	stack_index(*stack_a);
	stack_a_copy = *stack_a;
	start = stack_a_copy;
	while (*stack_a)
	{
		rank = 0;
		while (stack_a_copy)
		{
			if ((*stack_a)->value > stack_a_copy->value
				&& (*stack_a)->index != stack_a_copy->index)
			{
				rank++;
			}
			stack_a_copy = stack_a_copy->next;
		}
		(*stack_a)->rank = rank;
		stack_a_copy = start;
		(*stack_a) = (*stack_a)->next;
	}
}
