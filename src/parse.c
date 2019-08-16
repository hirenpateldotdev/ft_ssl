/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int			parse_command(char *arg, t_ssl *ssl, t_input **input)
{
	(void)input;
	ssl->command_str = arg;
	ssl->command = ft_arrchr((char**)g_command, g_valid_commands, arg);
	if (ssl->command == -1)
	{
		invalid_command(ssl->command_str);
		SET_INVALID_COMMAND;
	}
	return (0);
}

int			parse_string_flag(char **arg, int i, t_ssl *ssl, t_input **input)
{
	if (!arg[i + 1])
	{
		SET_INVALID_STRING;
		invalid_string(ssl->command_str);
		return (0);
	}
	INPUT->type = STRING;
	INPUT->descriptor = ft_strdup(arg[i + 1]);
	INPUT->content = ft_strdup(arg[i + 1]);
	INPUT->length = ft_strlen(arg[i + 1]);
	I_INPUT++;
	return (1);
}

int			parse_mod_flag(char **arg, int i, t_ssl *ssl, t_input **input)
{
	char	f;

	(void)input;
	f = arg[i][1];
	if (arg[i][2] || !(f == 'q' || f == 'r'))
	{
		SET_INVALID_FLAG;
		invalid_flag(ssl->command_str, f);
		return (0);
	}
	if (f == 'q')
		ssl->q = 1;
	else if (f == 'r')
		ssl->r = 1;
	return (0);
}

int			parse_file(char **arg, int i, t_ssl *ssl, t_input **input)
{
	int		fd;

	fd = open(arg[i], 'r');
	if (arg[i][0] == '-' && arg[i][1] == 'p' && !arg[i][2])
		fd = 0;
	if (fd == -1)
	{
		SET_INVALID_FLAG;
		invalid_file(arg[i], ssl->command_str);
		close(fd);
		return (0);
	}
	INPUT->length = ft_read_fd(fd, &INPUT->content);
	INPUT->type = FILE;
	INPUT->descriptor = ft_strdup(arg[i]);
	if (fd == 0 && (arg[i][0] == '-' && arg[i][1] == 'p' && !arg[i][2]))
	{
		INPUT->type = STDIN;
		INPUT->descriptor = ft_strdup(INPUT->content);
	}
	close(fd);
	I_INPUT++;
	return (0);
}

int			parse_arguments(t_ssl *ssl, t_input **input,
							int arg_len, char **arg)
{
	int		i;

	if (arg_len < 2)
		usage(SET_NO_ARG);
	else
		go_through_arg(ssl, input, arg_len, arg);
	check_if_no_input(ssl, input);
	i = -1;
	while (++i < 5)
		if (ssl->error[i] == 1)
			return (ssl->valid = 0);
	return (ssl->valid = 1);
}