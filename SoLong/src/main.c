/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:41:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:06:06 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "validators.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	check_arguments(argc, argv);
	initialize_game(argv[1]);
	return (0);
}
