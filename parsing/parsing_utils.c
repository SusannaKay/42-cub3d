/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:32 by skayed            #+#    #+#             */
/*   Updated: 2025/09/30 16:05:52 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *clean_line(char *line)
{
	char *cleaned;
	
	while (*line)
	cleaned = ft_strtrim(line, "\n");
	return (cleaned);
}
