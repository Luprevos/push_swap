/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:37:41 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/12 18:45:37 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

// void ft_index(t_list *stack)
// {
// 	int	i;
// 	int	median;
	
// 	i = 0;
// 	if (!stack)
// 		return ;
// 	median = stack_len(stack) / 2;
// 	while (stack)
// 	{
// 		stack->index = i;
// 		if (i <= median)
// 			stack->above_median = true;
// 		else
// 			stack->above_median = false;
// 		stack = stack->next;
// 		i++;
// 	}
// }

// void	set_target_a(t_list *stack_a, t_list *stack_b)
// {
// 	t_list	*current_b;
// 	t_list	*target_node;
// 	long	best_match_index;

// 	target_node = NULL;
	
// 	printf("Printing :\n");
// 		t_list *toPrint = stack_b;
// 		while (toPrint != NULL)
// 		{
// 			printf("%p ===> value: %d, target_node: %p, next: %p, prev: %p\n", &(*toPrint), toPrint->value, &*toPrint->target_node, &*toPrint->next, &*toPrint->prev);
// 			toPrint = toPrint->next;
// 		}
// 	printf("Done printing\n");

// 	while(stack_a != NULL)
// 	{
// 		best_match_index = LONG_MIN;
// 		current_b = stack_b;

// 		if (!stack_b)
// 		{
// 			printf("Here - pas de stack_b\n");
// 			stack_a->target_node = NULL;
// 			if (stack_a->next == NULL)
// 				break ;
// 			stack_a = stack_a->next; // ici pblm de segfault 
// 			continue ;
// 		}
			
// 		while (current_b != NULL)
// 		{
// 			if (current_b->value < stack_a->value && current_b->value > best_match_index)
// 			{
// 				best_match_index = current_b->value;
// 				printf("ehre\n");
// 				target_node = current_b;
// 			}
// 			current_b = current_b->next;
// 		}
// 		if (best_match_index == LONG_MIN)
// 		{
// 			stack_a->target_node = get_max(stack_b);
// 			printf("ehre1\n");
// 		}
// 		else
// 		{
// 			stack_a->target_node = target_node;
// 			printf("ehre2\n");
// 		}
// 	printf("je ne segfault pas bg");
// 		stack_a = stack_a->next;
// 	}
// }

static void set_target_a(t_list *a, t_list *b)
{
	t_list *current_b;
	t_list *target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
		{
			if (b)
				a->target_node = get_max(b);
			else
				a->target_node = NULL;
		}
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_for_a(t_list **a, t_list *b)
{
	int len_a;
	int len_b;
	int mediane;

	if (!(*a) || !b)
		return ;
	
	mediane = stack_mediane(&a);
	len_a = stack_len(*a);
	len_b = stack_len(b);

	
	while (*a)
	{
		if (!(*a)->target_node)
		{
			printf("erreur targetnode est NULL");
			printf("push_cost 1: %d\n", (*a)->push_cost);
			*a = (*a)->next;
			continue;
		}
		// printf("a->value = %d\n", a->value);
		// printf("a->index = %d\n", a->index);
		// printf("a->push_cost = %d\n", a->push_cost);
		// printf("a->above_median = %d\n", a->above_median);
		// printf("a->cheapest = %d\n", a->cheapest);
		(*a)->push_cost = (*a)->index;
		if (!(*a)->value > mediane)
			(*a)->push_cost = len_a - (*a)->index;

		// t_list *toPrint = a;
		// while (toPrint != NULL)
		// {
		// 	printf("%p ===> value: %d, target_node: %p, next: %p, prev: %p\n", &(*toPrint), toPrint->value, &*toPrint->target_node, &*toPrint->next, &*toPrint->prev);
			// si segfault, target_node->above_median n'a jamais ete init
			// on n'a jamais donne de valeur a target_node->above_median
			// ==453265==  Address 0xc is not stack'd, malloc'd or (recently) free'd
			// printf("  target_node->above_median: %d\n", toPrint->target_node->above_median);
			// toPrint = toPrint->next;
		// }

		// pas gere si a->target_node == NULL

		if ((*a)->target_node)
		{
			if ((*a)->target_node->value > mediane)
				(*a)->push_cost += (*a)->target_node->index;
			else
				(*a)->push_cost += len_b - ((*a)->target_node->index);
		}
		printf("push_cost 1: %d\n", (*a)->push_cost);
		(*a) = (*a)->next;
	}
}

void	set_cheapest(t_list *stack)
{
	long		cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		printf("push_cost: %d\n", stack->push_cost);
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
	ft_index(a);
	ft_index(b);
	set_target_a(a, b);
	cost_for_a(&a, b);
	set_cheapest(a);
}