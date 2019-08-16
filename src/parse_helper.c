/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
int			parse_command(char *arg, t_ssl *ssl, t_input **input);
int			parse_mod_flag(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_file(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_string_flag(char **arg, int i, t_ssl *ssl, t_input **input);

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

int			check_if_no_input(t_ssl *ssl, t_input **input)
{
	if (ssl->current_input == 0 && has_error(ssl) != 1)
	{
		parse_file((char*[1]){"-p"}, 0, ssl, input);
		parse_mod_flag((char*[1]){"-q"}, 0, ssl, input);
	}
	return (0);
}

int			go_through_arg(t_ssl *ssl, t_input **input,
							int arg_len, char **arg)
{
	int i;

	i = 0;
	while (++i < arg_len)
		if (i == 1)
			parse_command(arg[i], ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 's' && !arg[i][2])
			i += parse_string_flag(arg, i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] != 'p')
			parse_mod_flag(arg, i, ssl, input);
		else
			parse_file(arg, i, ssl, input);
	return (0);
}