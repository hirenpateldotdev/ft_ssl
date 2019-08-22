/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

void			byte_pad(unsigned char **str, int len)
{
	*str = (unsigned char*)ft_memcat((void*)*str, 0, len, 0);
	*str = (unsigned char*)ft_memcat((void*)*str, 0, ++len, 0);
}

int				get_bit_len(int len)
{
	int	bit_len;

	bit_len = len;
	while (bit_len % 3 != 0)
		bit_len++;
	return ((bit_len / 3) * 4);
}

unsigned char	*base64_encode(int bit_len, int pad, size_t i, unsigned char *s)
{
	unsigned char	*n;
	int				m;

	m = 0;
	n = ft_memalloc(bit_len + 8);
	while ((int)i < bit_len)
	{
		n[i] = g_b[(s[m] & 252) >> 2];
		n[i + 1] = g_b[(((s[m] & 3) << 4) | ((s[m + 1] & 240) >> 4))];
		n[i + 2] = g_b[(((s[m + 1] & 15) << 2) | (((s[m + 2] & 192) >> 6)))];
		n[i + 3] = g_b[(s[m + 2] & 63)];
		m += 3;
		i += 4;
	}
	i -= pad;
	while (pad--)
		n[i++] = '=';
	return (n);
}

unsigned char	*base64_encode_handler(unsigned char *content, int content_len)
{
	unsigned char	*n;

	byte_pad(&content, content_len);
	n = base64_encode(get_bit_len(content_len), ((content_len * 8) % 3), 0, content);
	return (n);
}