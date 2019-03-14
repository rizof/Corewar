/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:36 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 07:12:41 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	int	fd;
	char	*line;
	int	test;

	if (ac  <= 1)
		return (0);
	while (*(++av))
	{
		fd = open(*av, O_RDONLY);
		test = lseek(fd, 0, SEEK_END);
		printf("fd:%d\nlseek:%d\n", fd, test);
		while (get_next_line(fd, &line) > 0)
			printf("%s\n", line);
	}
	return (1);
}
