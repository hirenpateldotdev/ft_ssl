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

int					find_chr(char c)
{
	size_t			i;

	i = 0;
	while (i < 64)
	{
		if (g_b[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void				loop(unsigned char *s, unsigned char *n, int x, int i)
{
	unsigned int	tmp;

	tmp = 0;
	tmp = (s[i] << 2);
	tmp <<= 6;
	tmp += (s[i + 1] << 2);
	tmp <<= 6;
	tmp += (s[i + 2] << 2);
	tmp <<= 6;
	tmp += (s[i + 3] << 2);
	tmp <<= 6;
	n[x] = (tmp >> 24) & 255;
	n[x + 1] = (tmp >> 16) & 255;
	n[x + 2] = (tmp >> 8) & 255;
}

unsigned char		*base64_decode(int len, int i, int x, unsigned char *s)
{
	unsigned char	*n;
	static int		neg;

	n = ft_memalloc(((len / 4) * 3) + 8);
	while ((int)++i < len)
		s[i] = find_chr(s[i]);
	i = 0;
	while ((int)i < len)
	{
		loop(s, n, x, i);
		if (i + 4 >= len && !n[x + 1] && !n[x + 2])
			neg = 2;
		else if (i + 4 >= len && !n[x + 2])
			neg = 1;
		i += 4;
		x += 3;
	}
	return (n);
}

unsigned char		*base64_decode_handler(unsigned char *s, int len)
{
	unsigned char	*n;
	int				i;
	int				x;

	i = -1;
	x = -1;
	while (++i < len)
	{
		while (++x < 64)
			if (g_b[x] == s[i])
				s[i] = x;
		if (i > len)
			s[i] = 0;
	}
	n = base64_decode(len, 0, 0, s);
	return (n);
}
