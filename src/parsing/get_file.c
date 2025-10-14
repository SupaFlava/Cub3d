/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:34:35 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/01 11:14:58 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*join_str(char *map_str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(map_str, buffer);
	free(map_str);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*read_map_file(int fd)
{
	char	buffer[BUFF + 1];
	char	*map_str;
	ssize_t	bytes_read;

	map_str = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!map_str)
			map_str = ft_strdup(buffer);
		else
			map_str = join_str(map_str, buffer);
		if (!map_str)
			return (perror("Error\n"), close(fd), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
	if (bytes_read < 0)
		return (perror("Error\n"), NULL);
	return (map_str);
}

int	get_file(char *path, t_config *config)
{
	int		fd;
	char	*map_str;
	char	**map;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		return(FAILURE);
	}
	map_str = read_map_file(fd);
	if (!map_str)
		return (FAILURE);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		return (ft_printf("Error\n"), FAILURE);
	config->setting = map;
	return (SUCCESS);
}

