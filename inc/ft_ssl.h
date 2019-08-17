/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"
# include "../libft/inc/ft_printf.h"
#include "../src/message_digest/message_digest.h"

static const int	g_valid_commands = 6;

static const char	*g_command[6] = {
	"md5", "sha256" ,
	"base64", "des", "des_ecb", "des_cbc"
};

static const int	g_valid_flags = 11;

static const char	*g_flags[11] = {
	"-p", "-q", "-r", "-s",
	"-d", "-e", "-i", "-o",
	"-a", "-k", "-v"
};



void				free_structs(t_ssl *ssl, t_input **input);
void				init_structs(t_ssl *ssl, t_input **input);
int					parse_arguments(t_ssl *ssl, t_input **input, int arg_len,
									char **arg);
int					usage(int x);
int					invalid_flag(char *command, char invalid_flag);
int					invalid_command(char *invalid_command);
int					invalid_string(char *command);
int					invalid_file(char *invalid_file, char *command_val);
int					md5_handler(t_ssl	*ssl, t_input **input);
int					sha256_handler(t_ssl	*ssl, t_input **input);

int					base64_handler(t_ssl	*ssl, t_input **input);


int			check_if_no_input(t_ssl *ssl, t_input **input);
int			go_through_arg(t_ssl *ssl, t_input **input,
							int arg_len, char **arg);

int					parse_message_digest(t_ssl *ssl, t_input **input,
					int arg_len, char **arg);
// int					des_handler(t_ssl	*ssl, t_input **input);
// int					des_ecb_handler(t_ssl	*ssl, t_input **input);
// int					des_cbc_handler(t_ssl	*ssl, t_input **input);
#endif
