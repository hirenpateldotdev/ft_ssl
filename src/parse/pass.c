/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int					read_pass(char **pass)
{
	char			*pass1;
	char			*pass2;

	ft_printf("Enter your password:");
	ft_read_fd(0, &pass1);
	ft_printf("\nVerifying - Enter your password:");
	ft_read_fd(0, &pass2);
	ft_printf("\n");
	if (ft_strcmp(pass1, pass2) != 0)
	{
		ft_printf("\nVerifying failure");
		free(pass1);
		free(pass2);
		return (-1);
	}
	*pass = ft_strdup(pass1);
	free(pass1);
	free(pass2);
	ft_printf("%s is the password\n", *pass);
	return (1);
}

int					read_vector(char **v)
{
	char			*v1;
	char			*v2;

	ft_printf("Enter your initial vector:");
	ft_read_fd(0, &v1);
	ft_printf("\nVerifying - Enter your initial vector:");
	ft_read_fd(0, &v2);
	ft_printf("\n");
	if (ft_strcmp(v1, v2) != 0)
	{
		ft_printf("\nVerifying failure");
		free(v1);
		free(v2);
		return (-1);
	}
	*v = ft_strdup(v1);
	free(v1);
	free(v2);
	ft_printf("%s is the initial vector\n", *v);
	return (1);
}

int					read_key(char **k)
{
	char			*k1;
	char			*k2;

	ft_printf("Enter your key:");
	ft_read_fd(0, &k1);
	ft_printf("\nVerifying - Enter your key:");
	ft_read_fd(0, &k2);
	ft_printf("\n");
	if (ft_strcmp(k1, k2) != 0)
	{
		ft_printf("\nVerifying failure");
		free(k1);
		free(k2);
		return (-1);
	}
	*k = ft_strdup(k1);
	free(k1);
	free(k2);
	ft_printf("%s is the key\n", *k);
	return (1);
}
