/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:06 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/26 18:20:43 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_isspace(char *string)
{
	int i;
	
	i =0;
	while(string[i])
	{
		if(string[i] == ' ' || string[i] == '\t')
			i++;
		else
			return(FAILURE); 
	}
	return(SUCCESS);
}
int classify_directive(char *dir)
{
    char *identifier[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
    int   i;

    i = 0;
    while(identifier[i])
    {
        if(ft_strncmp(identifier[i], dir, ft_strlen(identifier[i])) == 0)
            return(i);
        i++;
    }
    return (DIR_INV);
}
int	extract_config(t_config *config, char *line , bool *seen)
{
	char **result;
	int   dir;

	result = ft_split(line, ' ');
	if (!result)
		return(FAILURE);
	dir = classify_directive(result[0]);
	if(seen[dir])
		return (FAILURE);
	if (dir == DIR_NO)
		config->no_tex = result[1];
	else if (dir == DIR_SO)
		config->so_tex = result[1];
	else if (dir == DIR_WE)
		config->we_tex = result[1];
    else if (dir == DIR_EA)
		config->ea_tex = result[1];
    else if (dir == DIR_F)
		ft_printf("floor\n");
    else if (dir == DIR_C)
		ft_printf("flooor\n");
	seen[dir] = true;
	return SUCCESS;
}
int	parse_config(t_config *config)
{
	int	i;
	int config_len;
	bool seen[6] = {false, false, false, false, false, false};

	i = 0;
	config_len = 0;
	config->in_config = true;
	while(config->setting[i] && config->in_config)
	{
		if(ft_isspace(config->setting[i]) == SUCCESS)
			i++;
		else
		{
			if (extract_config(config,config->setting[i], seen) == FAILURE)
            {
                ft_printf("Error\n duplicate detected\n");
                    return(FAILURE);    
            }
			config_len++;
			i++;
			if (config_len == 6)
				config->in_config = false;
		}
	}
	extrat_map(config, i);
	return (0);
}
