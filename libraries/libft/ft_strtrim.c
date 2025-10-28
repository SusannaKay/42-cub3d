/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:28:16 by skayed            #+#    #+#             */
/*   Updated: 2025/10/28 15:07:02 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*out;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	end = len;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	out = (char *)malloc((end - start + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s1 + start, end - start);
	out[end - start] = '\0';
	return (out);
}
