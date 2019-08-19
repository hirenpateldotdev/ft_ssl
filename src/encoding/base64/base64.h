/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../../inc/struct.h"
# include "../../../libft/inc/ft_printf.h"

int					base64_handler(t_ssl *ssl, t_input **input);

#endif