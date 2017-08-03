/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:31:58 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/12/01 13:44:27 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (NULL);
	ss = ft_strnew(len);
	if (!ss)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		ss[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (ss);
}
