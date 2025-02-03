/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2nd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:33:37 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/03 18:18:49 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void    move_a_to_b(t_list **a, t_list **b)
{
    t_list *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
        rev_rotate_both(a, b, cheapest_node);
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a); 
}

void move_b_to_a(t_list **a, t_list **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b);
}

void    sort_stacks(t_list **a, t_list **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a-- > 3 && !stack_already_sorted(*a))
        pb (b, a);
    if (len_a-- > 3 && !stack_already_sorted(*a))
        pb (b, a);
    while(len_a-- > 3 && !stack_already_sorted(*a))
    {
        init_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_stack_3E(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    ft_index(*a);
    min_go_top(a);
}