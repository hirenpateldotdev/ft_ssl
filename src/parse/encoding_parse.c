/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_ssl.h"

int			has_error(t_ssl *ssl)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		if (ssl->error[i] == 1)
			return (1);
	}
	return (0);
}

int			parse_string_flag(char **arg, int i, t_ssl *ssl, t_input **input)
{

	return (1);
}

int			parse_mod_flag(char **arg, int i, t_ssl *ssl, t_input **input)
{

	return (0);
}

int			parse_file(char **arg, int i, t_ssl *ssl, t_input **input)
{

	return (0);
}

int					parse_encoding(t_ssl *ssl, t_input **input,
					int arg_len, char **arg)
{

    return (0);
}