/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_config_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/13 12:55:05 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/11/13 15:32:13 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_get_line(t_config *config, char **line, int *i)
{
	free(*line);
	*line = getnl_string(config->setting, i);
}

int	get_count(t_config *config, int i)
{
	int	count;

	count = 0;
	while (config->setting[i] && config->setting[i + count])
		count++;
	return (count);
}

int	process_config_lines(t_config *config, bool seen[6], int *i)
{
	char	*line;
	int		count;

	count = 0;
	line = getnl_string(config->setting, i);
	while (line)
	{
		if (*line == '\0' || ft_isspace(line))
		{
			free(line);
			line = getnl_string(config->setting, i);
			continue ;
		}
		if (!extract_config(config, line, seen))
		{
			free(line);
			return (FAILURE);
		}
		free(line);
		count++;
		if (count == 6)
			break ;
		line = getnl_string(config->setting, i);
	}
	return (SUCCESS);
}
