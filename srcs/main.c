/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:50:19 by rde-mour          #+#    #+#             */
/*   Updated: 2023/10/04 16:47:08 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		ft_display_file(char *str);

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_display_file(argv[1]));
	}
	if (argc < 2)
		ft_putstr("File name missing.");
	if (argc > 2)
		ft_putstr("Too many arguments.");
	return (1);
}
