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

#include "../../inc/ft_ssl.h"

int			parse_input_file(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_output_file(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_stdin(t_ssl *ssl, t_input **input);

int			parse_key(char **arg, int i, t_ssl *ssl, t_input **input)
{
	if (!arg[i])
	{
		SET_INVALID_STRING;
		return (0);
	}
	ssl->key = 1;
	INPUT->key = ft_strdup(arg[i]);
	ft_printf("key : %s \n",INPUT->key);
	return (1);
}

int			parse_salt(char **arg, int i, t_ssl *ssl, t_input **input)
{
	if (!arg[i])
	{
		SET_INVALID_STRING;
		return (0);
	}
	ssl->salt = 1;
	INPUT->salt = ft_strdup(arg[i]);
	ft_printf("salt : %s \n",INPUT->salt);
	return (1);
}

int			parse_pass(char **arg, int i, t_ssl *ssl, t_input **input)
{
	if (!arg[i])
	{
		SET_INVALID_STRING;
		return (0);
	}
	ssl->pass = 1;
	INPUT->pass = ft_strdup(arg[i]);
	ft_printf("pass : %s \n",INPUT->pass);
	return (1);
}

int			parse_vector(char **arg, int i, t_ssl *ssl, t_input **input)
{
	if (!arg[i])
	{
		SET_INVALID_STRING;
		return (0);
	}
	ssl->vector = 1;
	INPUT->vector = ft_strdup(arg[i]);
	ft_printf("vector : %s \n",INPUT->vector);
	return (1);
}

int					parse_encryption(t_ssl *ssl, t_input **input,
					int arg_len, char **arg)
{
	int i;

	i = 1;
	ssl->output_file = 1;
	while (++i < arg_len)
		if (arg[i][0] == '-' && arg[i][1] == 'd' && !arg[i][2])
			ssl->mode = 1;
		else if (!ft_strncmp(arg[i], "-nosalt", 7))
			ssl->nosalt = 1;
		else if (arg[i][0] == '-' && arg[i][1] == 'i' && !arg[i][2])
			parse_input_file(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'o' && !arg[i][2])
			parse_output_file(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'k' && !arg[i][2])
			parse_key(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'p' && !arg[i][2])
			parse_pass(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 's' && !arg[i][2])
			parse_salt(arg, ++i, ssl, input);
		else if (arg[i][0] == '-' && arg[i][1] == 'v' && !arg[i][2])
			parse_vector(arg, ++i, ssl, input);
		else if (!(arg[i][0] == '-' && arg[i][1] == 'e' && !arg[i][2]))
		{
			SET_INVALID_FLAG;
			invalid_flag(ssl->command_str, arg[i][1]);
		}
	if (ssl->current_input == 0 && has_error(ssl) != 1)
		parse_stdin(ssl, input);
	// ft_printf("parse over s : %s\n",INPUT->salt);
	// ft_printf("\n\n__________\ninput : |%s|\n\noutput : |%d|\n",input[0]->content,input[0]->output_file);
	return ((has_error(ssl) == 1 ? -1 : 1 ));
}








