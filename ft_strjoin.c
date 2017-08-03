/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:43:18 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/12/04 21:54:24 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cs;
	size_t	ls1;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ls1 = ft_strlen(s1);
	cs = ft_strnew(ls1 + ft_strlen(s2));
	if (!cs)
		return (NULL);
	ft_strcpy(cs, s1);
	ft_strcpy(cs + ls1, s2);
	return (cs);
}
