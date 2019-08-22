/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

int					base64_handler(t_ssl *ssl, t_input **input)
{
	char			*output;

	if (ssl->mode == 0)
		output = (char *)base64_encode_handler(
					(unsigned char *)input[0]->content, input[0]->length);
	else
		output = (char *)base64_decode_handler(
				(unsigned char *)input[0]->content, input[0]->length);
	ft_printf("output_fd = %d\n", input[0]->output_file);
	write(input[0]->output_file, output, ft_strlen(output) -1);
	if (input[0]->output_file == 0)
		ft_printf("\n");
	return (0);
}
