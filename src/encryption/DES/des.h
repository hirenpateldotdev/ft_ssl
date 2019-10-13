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

/*https://www.techiedelight.com/des-implementation-c/*/

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

unsigned long long		permutate_choice_1(unsigned long long in);
unsigned long long		permutate_choice_2(unsigned long long in);
unsigned long long		permutate_choice_3(unsigned long long in);
unsigned long long		permutate_choice_4(unsigned long long in_1, unsigned long long in_2);
char					*des(uint8_t **blocks_arr,	int arr_len);
char					*des_hash(uint8_t *hash);
void					check_hex(t_ssl *ssl,	char *s);
void					set_subkeys(t_ssl *ssl);
void					check_hex(t_ssl *ssl,	char *s);
char					*get_input(char *prompt);
unsigned long long		permutate_choice_1(unsigned long long p);
unsigned long long		permutate_choice_2(unsigned long long p);
unsigned long long		permutate_choice_3(unsigned long long p);
unsigned long long		permutate(unsigned long long in, int *permutation,
														int tab_size, int size);
long long				ft_exponent(long long nbr, int power);
void					des_processes(t_ssl *ssl, t_input **input, unsigned long long block_s);

#endif
