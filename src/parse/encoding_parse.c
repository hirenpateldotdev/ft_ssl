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
	INPUT->type = FILE;
	INPUT->descriptor = ft_strdup(arg[i]);
	if (fd == 0)
	{
		INPUT->type = STDIN;
		INPUT->descriptor = ft_strdup(INPUT->content);
	}
	close(fd);
	I_INPUT++;
	return (0);
}

int			parse_output_file(char **arg, int i, t_ssl *ssl)
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
	ssl->output_file = fd;
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


int					parse_encoding(t_ssl *ssl, t_input **input,
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
			parse_output_file(arg, ++i, ssl);
		else if (!(arg[i][0] == '-' && arg[i][1] == 'e' && !arg[i][2]))
		{
			SET_INVALID_FLAG;
			invalid_flag(ssl->command_str, arg[i][1]);
		}
	if (ssl->current_input == 0 && has_error(ssl) != 1)
		parse_stdin(ssl, input);
	//ft_printf("\n\n__________\ninput : |%s|\n\noutput : |%d|\n",input[0]->content,ssl->output_file);
	return ((has_error(ssl) == 1 ? -1 : 1 ));
}