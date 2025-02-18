/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2nd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:40 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 17:38:03 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	prep_for_push(t_list **stack, t_list *top, char stack_name)
{
	int	mediane;

	mediane = stack_mediane(*stack);
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->value > mediane)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top->value > mediane)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

t_list	*get_cheapest(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}
