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
# define LEFTROTATE(X,	N) ((X << N) | (X >> (32 - N)))
# define RIGHTROTATE(X,	N) ((X >> N) | (X << (32 - N)))
# define B6 64
# define B8 256
# define B28 268435456
# define B32 4294967296

uint64_t		permutate_choice_1(uint64_t in);
uint64_t		permutate_choice_2(uint64_t in);
uint64_t		permutate_choice_3(uint64_t in);
uint64_t		permutate_choice_4(uint64_t in_1,\
											uint64_t in_2);
uint64_t		permutate_choice_5(uint64_t in, int option);
char			*des(uint8_t **blocks_arr, int arr_len);
char			*des_hash(uint8_t *hash);
void			check_hex(t_ssl *ssl, char *s);
void			set_subkeys(t_ssl *ssl);
void			check_hex(t_ssl *ssl, char *s);
char			*get_input(char *prompt);
void			decryption_depadding(uint64_t *block_s, int *len);
void			des_processes(t_ssl *ssl, t_input **input,\
							uint64_t block_s);

#endif
