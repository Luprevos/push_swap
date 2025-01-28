/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2nd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:40 by luprevos          #+#    #+#             */
/*   Updated: 2025/01/20 15:43:40 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	prep_for_push(t_list **stack, t_list *top, char stack_name)
{
	while (*stack != top)
	{
		if(stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
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
	while(stack)
	{
		if(stack->cheapest)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

