/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:50:45 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/18 17:01:51 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_list	*get_max(t_list *stack)
{
	t_list	*temp;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

t_list	*get_min(t_list *stack)
{
	t_list	*temp;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

int	stack_len(t_list *stack_a)
{
	int	size;

	size = 0;
	if (is_empty(stack_a) == 1)
	{
		while (stack_a != NULL)
		{
			++size;
			stack_a = stack_a->next;
		}
	}
	return (size);
}

t_list	*go_last(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

bool	stack_already_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
