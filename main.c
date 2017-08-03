/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:51:30 by vrudakov          #+#    #+#             */
/*   Updated: 2017/01/06 21:29:52 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		coord(void)
{
	g_coord[0] = "1";
	g_coord[1] = "00102030";
	g_coord[2] = "00010203";
	g_coord[3] = "00010212";
	g_coord[4] = "00102001";
	g_coord[5] = "00101112";
	g_coord[6] = "20011121";
	g_coord[7] = "02101112";
	g_coord[8] = "00102021";
	g_coord[9] = "00100102";
	g_coord[10] = "00011121";
	g_coord[11] = "00011011";
	g_coord[12] = "10011121";
	g_coord[13] = "00011102";
	g_coord[14] = "00102011";
	g_coord[15] = "10011112";
	g_coord[16] = "00101121";
	g_coord[17] = "10011102";
	g_coord[18] = "10200111";
	g_coord[19] = "00011112";
}

static void	errorusage(char **argv)
{
	int i;

	i = -1;
	write(1, "usage: ", 7);
	while (argv[0][++i])
		write(1, &argv[0][i], 1);
	write(1, " sourcefile", 11);
}

int			read_file(char *buffer, int argc, char **argv)
{
	int		fd;
	int		i;
	char	buff;

	i = -1;
	if (argc != 2)
	{
		errorusage(argv);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (write(1, "error\n", 6) && 0);
	while (read(fd, &buff, 1) != 0 && buff != '\0')
		buffer[++i] = buff;
	buffer[i + 1] = '\0';
	if (close(fd) == -1)
		return (write(1, "error\n", 6) && 0);
	sqr_valid(buffer);
	if (val_nl(buffer) || ft_val_str(buffer) || connection(tetri_arr(buffer)) ||
			i > 546)
	{
		write(1, "error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	char	buffer[BUFF_SIZE];
	int		*input;

	if (read_file(buffer, argc, argv) == 0)
		exit(EXIT_FAILURE);
	input = input_tets(buffer);
	slower(input);
	return (0);
}
