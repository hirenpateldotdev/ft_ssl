/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:47:45 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:47:48 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

char	*ft_memcat(void *src, void *dest, size_t src_size, size_t dest_size)
{
	char	*n;

	n = ft_memalloc(src_size + dest_size + 1);
	ft_memcpy(n, src, src_size);
	ft_memcpy(&n[src_size], dest, dest_size);
	return (n);
}