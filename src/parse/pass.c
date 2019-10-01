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

#include "../../inc/ft_ssl.h"

int					get_pass(char **pass)
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
		return(-1);
	}
	*pass = ft_strdup(pass1);
	free(pass1);
	free(pass2);
	ft_printf("%s is the password\n",pass);
	retrun(1);
}
