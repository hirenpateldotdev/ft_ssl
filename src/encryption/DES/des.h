/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../../inc/struct.h"
# include "../../../libft/inc/ft_printf.h"
# define DIGEST_LENGTH 16
# define PADDED_LENGTH 9
# define BLOCK_LENGTH 64
# define S_B input->b_p
# define S_I input
# define LEFTROTATE(X, N) ((X << N) | (X >> (32 - N)))
# define RIGHTROTATE(X, N) ((X >> N) | (X << (32 - N)))

unsigned char			*des_decrypt_handler(unsigned char *s, int len);
unsigned char			*des_encrypt_handler(unsigned char *s, int len);
char					*des(uint8_t **blocks_arr, int arr_len);
char					*des_hash(uint8_t *hash);

#endif
