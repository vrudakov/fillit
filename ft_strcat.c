/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:59:02 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/11/24 18:09:37 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int destsize;

	i = 0;
	destsize = 0;
	while (s1[destsize])
		destsize++;
	while (s2[i])
	{
		s1[destsize] = s2[i];
		destsize++;
		i++;
	}
	s1[destsize] = '\0';
	return (s1);
}
