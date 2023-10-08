/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:01:31 by rde-mour          #+#    #+#             */
/*   Updated: 2023/10/04 16:58:06 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c);

int	ft_open(char *filename, int *filepos)
{
	if (open(filename, O_RDONLY) < 0)
		return (1);
	else
		*filepos = open(filename, O_RDONLY);
	return (0);
}

void	ft_read(int filepos)
{
	char	c;

	c = '0';
	while ((read(filepos, &c, sizeof(char)) == 1))
		ft_putchar(c);
}

void	ft_close(int filepos)
{
	close(filepos);
}

int	ft_display_file(char *str)
{
	int	filepos;
	int	status;

	filepos = 0;
	status = ft_open(str, &filepos);
	if (filepos > 0)
	{
		ft_read(filepos);
		ft_close(filepos);
	}
	return (status);
}
