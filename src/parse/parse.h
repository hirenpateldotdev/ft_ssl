/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../../inc/ft_ssl.h"

int			parse_input_file(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_output_file(char **arg, int i, t_ssl *ssl, t_input **input);
int			parse_stdin(t_ssl *ssl, t_input **input);
int			parse_string_flag(char **arg, int i, t_ssl *ssl, t_input **input);
int			read_pass(char **pass);

#endif
