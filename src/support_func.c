/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int			has_error(t_ssl *ssl)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		if (ssl->error[i] == 1)
        {
            ssl->valid = 0;
            return (1);
        }
	}
    ssl->valid = 1;
	return (0);
}