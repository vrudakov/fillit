/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 08:28:15 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/11/25 15:09:47 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	int		j;

	j = 1;
	while (s1[j])
		j++;
	i = 0;
	str = malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
