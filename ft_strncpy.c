/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:34:24 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/11/25 18:36:55 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (*src != '\0' && len > 0)
	{
		*ptr++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*ptr++ = '\0';
		len--;
	}
	return (dst);
}
