/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			parse_input_file(char **arg, int i, t_ssl *ssl, t_input **input)
{
	int		fd;

	fd = open(arg[i], 'r');
	if (fd == -1)
	{
		SET_INVALID_FLAG;
		invalid_file(arg[i], ssl->command_str);
		close(fd);
		return (0);
	}
	INPUT->length = ft_read_fd(fd, &INPUT->content);
	ssl->len = INPUT->length;
	INPUT->type = FILE;
	INPUT->descriptor = ft_strdup(arg[i]);
	if (fd == 0)
	{
		ssl->input_found = 1;
		INPUT->type = STDIN;
		INPUT->descriptor = ft_strdup(INPUT->content);
	}
	close(fd);
	I_INPUT++;
	return (0);
}

int			parse_output_file(char **arg, int i, t_ssl *ssl, t_input **input)
{
	int		fd;

	fd = open(arg[i], 'r');
	if (fd == -1)
	{
		SET_INVALID_FLAG;
		invalid_file(arg[i], ssl->command_str);
		close(fd);
		return (0);
	}
	input[0]->output_file = fd;
	I_INPUT++;
	return (0);
}

int			parse_stdin(t_ssl *ssl, t_input **input)
{
	int		fd;

	fd = 0;
	INPUT->length = ft_read_fd(fd, &INPUT->content);
	INPUT->type = STDIN;
	INPUT->descriptor = ft_strdup(INPUT->content);
	I_INPUT++;
	return (0);
}
