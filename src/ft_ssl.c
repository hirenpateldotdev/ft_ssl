/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int				dispatch(t_ssl *ssl, t_input **input)
{
	int			ret;
	int			(*handle[6])(t_ssl *, t_input **);

	handle[0] = md5_handler;
	handle[1] = sha256_handler;
	handle[2] = base64_handler;
	// handle[3] = des_handler;
	// handle[4] = des_ecb_handler;
	// handle[5] = des_cbc_handler;
	ret = handle[ssl->command](ssl, input);
	return (ret);
}

int			parse_command(char *arg, t_ssl *ssl, t_input **input)
{
	(void)input;
	ssl->command_str = arg;
	ssl->command = ft_arrchr((char**)g_command, g_valid_commands, arg);
	if (ssl->command == -1)
		return (-1);
	return (0);
}

int			parse_arguments(t_ssl *ssl, t_input **input,
							int arg_len, char **arg)
{
	if (arg_len < 2)
		return (usage(SET_NO_ARG));
	else if (parse_command(arg[1], ssl, input) == -1)
		return (invalid_command(ssl->command_str));
	if (ssl->command >= 0 && ssl->command <= 1)
		return (parse_message_digest(ssl, input, arg_len, arg));
	else if (ssl->command == 2)
		return (parse_encoding(ssl, input, arg_len, arg));
	// else if (ssl->command >= 3 && ssl->command <= 5)
	// 	return (parse_encryption(ssl, input, arg_len, arg));
	return (1);
}

int				main(int ac, char **av)
{
	t_ssl		*ssl;
	t_input		**input;
	int			i;

	i = -1;
	ssl = malloc(sizeof(t_ssl));
	ft_bzero(ssl, sizeof(t_ssl));
	input = malloc(sizeof(t_input *) * INPUT_MAX);
	while (++i < INPUT_MAX)
	{
		input[i] = malloc(sizeof(t_input));
		ft_bzero(input[i], sizeof(t_input));
	}
	ssl->ac = ac;
	init_structs(ssl, input);
	if (parse_arguments(ssl, input, ac, av) == 1)
		dispatch(ssl, input);
	free_structs(ssl, input);
	return (1);
}
