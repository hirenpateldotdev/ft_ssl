/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_digest.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_DIGEST_H
# define FT_MESSAGE_DIGEST_H
# include "../../inc/struct.h"

int				sha256_handler(t_ssl *ssl, t_input **input);
int				md5_handler(t_ssl *ssl, t_input **input);

#endif