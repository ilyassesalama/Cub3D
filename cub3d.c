/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalama <isalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:19:45 by isalama           #+#    #+#             */
/*   Updated: 2023/10/23 18:28:00 by isalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables_rest(t_config *config)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		config->f[i] = -1;
		config->c[i] = -1;
		i++;
	}
}

void	init_variables(t_config *config)
{
	config->player.up = false;
	config->player.down = false;
	config->player.left = false;
	config->player.right = false;
	config->player.dir_left = false;
	config->player.dir_right = false;
	config->ea_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->no_texture = NULL;
	config->colors = NULL;
	config->map_start = 0;
	config->found_attrs = 0;
	config->player.angle = M_PI_2;
	config->longest_map_line = 0;
	config->map = NULL;
	config->textures = NULL;
	config->map_tmp = NULL;
}

int	main(int argc, char **argv)
{
	t_config	*config;

	if (argc != 2)
		return (printf("Error\nMap path was not specified\n"), 1);
	config = malloc(sizeof(t_config));
	if (!config)
		ft_exit(config, 5);
	init_variables(config);
	init_variables_rest(config);
	init_map_validator(argv[1], config);
	init_window(config);
	clear_resources(config);
}
