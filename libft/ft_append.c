/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:35:49 by vmiachko          #+#    #+#             */
/*   Updated: 2019/06/01 18:40:19 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_append(char *curr_str, char *to_append)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	i = ft_strlen(curr_str);
	k = ft_strlen(to_append);
	j = 0;
	new_str = ft_realloc(curr_str, ft_strlen(curr_str) + ft_strlen(to_append));
	while (j < k)
		new_str[i++] = to_append[j++];
	return (new_str);
}
