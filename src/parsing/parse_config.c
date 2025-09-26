/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:06 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/26 14:39:01 by rmhazres         ###   ########.fr       */
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

void	*extract_config(t_config *config, char *line)
{
	char **result;
	
	result = ft_split(line, ' ');
	if(!result)
		return(NULL);
	if (ft_strncmp(result[0] ,"NO",ft_strlen(result[0])) == 0)
	{
		//config->identifiers[config->dubplicate] = result[0];
		config->no_tex = result[1];
	}
	else if (ft_strncmp(result[0] ,"SO",ft_strlen(result[0])) == 0)
	{
	//	config->identifiers[config->dubplicate] = result[0];
		config->so_tex = result[1];
	}
	else if (ft_strncmp(result[0] ,"WE",ft_strlen(result[0])) == 0)
	{
	//	config->identifiers[config->dubplicate] = result[0];
		config->we_tex = result[1];
	}
	else if (ft_strncmp(result[0] ,"EA",ft_strlen(result[0])) == 0)
	{
	//	result[0] = config->identifiers[config->dubplicate];
		config->ea_tex = result[1];
	}
	else if (ft_strncmp(result[0] ,"F",ft_strlen(result[0])) == 0)
	{
	//	config->identifiers[config->dubplicate] = result[0] ;
	//	result[1] = config->floor.;
	}
	else if (ft_strncmp(result[0] ,"C",ft_strlen(result[0])) == 0)
	{
	//	config->identifiers[config->dubplicate] = result[0];
	//	result[1] = config->ceiling;
	}
	else
		return NULL;
	config->dubplicate++;
	return NULL;
}
int	parse_config(t_config *config)
{
	int	i;
	int config_len;
	i = 0;

	config_len = 6;
	config->dubplicate = 0;
	while(i < config_len)
	{
		if(ft_isspace(config->setting[i]) == SUCCESS)
		{
			i++;
			config_len++;
		}
		else
		{
			extract_config(config,config->setting[i]);
			i++;
		}
	}
	ft_printf("%s\n",config->ea_tex);
	return (0);
}
