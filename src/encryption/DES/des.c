/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

int					des_handler(t_ssl *ssl, t_input **input)
{
	char			*output;

	if (ssl->mode == 0)
		output = (char *)des_encrypt_handler(
					(unsigned char *)input[0]->content, input[0]->length);
	else
		output = (char *)des_decrypt_handler(
				(unsigned char *)input[0]->content, input[0]->length);
	//ft_printf("output_fd = %d\n", input[0]->output_file);
	write(input[0]->output_file, output, ft_strlen(output));
	if (input[0]->output_file == 0)
		ft_printf("\n");

	return (1);
}
