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

void				check_hex(t_ssl *ssl, char *s)
{
	int					i;
	unsigned long long	tmp;

	i = 0;
	while (s[i] != '\0' && i < 16)
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			tmp = tmp * 16 + (10 + s[i] - 'a');
		else if (s[i] >= 'A' && s[i] <= 'F')
			tmp = tmp * 16 + (10 + s[i] - 'A');
		else if (s[i] >= '0' && s[i] <= '9')
			tmp = tmp * 16 + (s[i] - '0');
		else
		{
			ft_printf("Error, enter hex digit");
			exit(1);
		}
		i++;
	}
	while (i++ < 16)
		tmp *= 16;
	if (!ssl->key && (ssl->key = 1))
		ssl->des_key = tmp;
	else if (ssl->des_cbc && !ssl->vector && (ssl->vector = 1))
		ssl->des_iv = tmp;
}

char				*get_input(char *prompt)
{
	char			*pass1;
	char			*pass2;

	ft_printf("%s",prompt);
	ft_read_fd(0, &pass1);
	ft_printf("\nVerifying - %s",prompt);
	ft_read_fd(0, &pass2);
	ft_printf("\n");
	if (ft_strcmp(pass1, pass2) != 0)
	{
		ft_printf("\nVerifying failure");
		free(pass1);
		free(pass2);
		exit(1);
	}
	free(pass1);
	return(pass2);
}

int					des_handler(t_ssl *ssl, t_input **input)
{
	char			*output;

	if (!ssl->key)
		check_hex(ssl, get_input("Enter your key: "));
	if (ssl->des_cbc && !ssl->vector)
		check_hex(ssl, get_input("Enter your initial vector: "));






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
