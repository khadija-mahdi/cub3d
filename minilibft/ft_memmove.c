/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:52:59 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/09 17:26:18 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest > src)
	{
		while (len)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
