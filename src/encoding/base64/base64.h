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

static const char	g_b[64] = \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int					base64_handler(t_ssl *ssl, t_input **input);
unsigned char		*base64_encode_handler(unsigned char *s, int len);
unsigned char		*base64_decode_handler(unsigned char *s, int len);

#endif
