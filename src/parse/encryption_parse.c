/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../encryption/DES/des.h"

int			parse_key(char **arg, int i, t_ssl *ssl)
{
	check_hex(ssl, arg[i]);
	ssl->key = 1;
	return (1);
}

int			parse_vector(char **arg, int i, t_ssl *ssl)
{
	check_hex(ssl, arg[i]);
	ssl->vector = 1;
	return (1);
}

int			parse_encryption(t_ssl *ssl, t_input **input,
			int arg_len, char **arg)
{
	int i;

	i = 1;
	ssl->output_file = 1;
	while (++i < arg_len)
		if (arg[i][0] == '-' && arg[i][1] == 'd' && !arg[i][2])
			ssl->mode = 1;
		else if (arg[i][0] == '-' && arg[i][1] == 'i' && !arg[i][2])
			parse_input_file(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'o' && !arg[i][2])
			parse_output_file(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'k' && !arg[i][2])
			parse_key(arg, ++i, ssl);
		else if (arg[i][0] == '-' && arg[i][1] == 'v' && !arg[i][2])
			parse_vector(arg, ++i, ssl);
		else if (!(arg[i][0] == '-' && arg[i][1] == 'e' && !arg[i][2]))
		{
			SET_INVALID_FLAG;
			invalid_flag(ssl->command_str, arg[i][1]);
		}//ft_printf("((%d && %d|| %d)\n file = %d\n",!ssl->current_input,has_error(ssl) != 1,ssl->in_file == 0,ssl->fd_in);
	if ((!ssl->current_input && has_error(ssl) != 1) || ssl->in_file == 0)
		parse_stdin(ssl, input);
	I_INPUT = 0;
	ssl->encrypt = ssl->mode == 0 ? 1 : 0;
	return ((has_error(ssl) == 1 ? -1 : 1));
}
