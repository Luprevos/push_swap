/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:36 by luprevos          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:01 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void is_above_mediane(char **stack)
{

    int mediane;
    int len;

    if (*stack)
    {
        len = stack_len(*stack);
        if (len % 2 == 0)
        {
            len / 2;
            stack[len]
        }        
    }
}