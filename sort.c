/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:37:43 by luprevos          #+#    #+#             */
/*   Updated: 2025/01/20 17:42:33 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"


void	sort_stack_2E(t_list **stack)
{
	t_list	*temp;

	if(stack_len(*stack)!= 2)
		return ;
	temp = *stack;
	temp = temp->next;
	if(temp->value > (*stack)->value && temp->next == NULL)
		rrb(stack, 0);		
}

void    sort_stack_3E(t_list **stack)
{
	t_list  *temp;
	t_list  *temp2;
	
	if(stack_len(*stack)!= 3)
		return ;
	temp = *stack;
	if((*stack)->next != NULL)
	{
		temp = temp->next;
		if((*stack)->value > temp->value)
			sa(stack, 0);
		temp2 = temp->next;
		if(temp2->value < (*stack)->value && temp2->value < temp->value)
		{
			sa(stack, 0);
			rra(stack, 0);
		}
		if(temp->value > temp2->value)
		{
			rra(stack, 0);
			sa(stack, 0);
		}
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *min)
{
	while (*stack_b != min->target_node && *stack_a != min)
		rr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *min)
{
	while (*stack_b != min->target_node && *stack_a != min)
		rrr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void	min_go_top(t_list **stack_a)
{
	while ((*stack_a)->value != get_min(*stack_a)->value)
	{
		if (get_min(*stack_a)->above_median)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}
