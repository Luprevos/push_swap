/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2nd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:31:47 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/13 15:41:38 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void    set_target_b(t_list *a, t_list *b)
{
    t_list  *current_a;
    t_list  *node_target;
    long        best_index;
    
    while(b)
    {
        best_index = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->value > b->value && current_a->value < best_index)
            {
                best_index = current_a->value;
                node_target = current_a;
            }
            current_a = current_a->next;
        }
        if (best_index == LONG_MAX)
            b->target_node = get_min(a);
        else
            b->target_node = node_target;
        b = b->next;
    }
}

void    init_nodes_b(t_list *a, t_list *b)
{
    stack_mediane(a);
	stack_mediane(b);
    set_target_b (a, b);
}

