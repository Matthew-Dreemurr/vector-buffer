/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:15:46 by mahadad           #+#    #+#             */
/*   Updated: 2021/12/01 16:28:47 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	t_vector	test;
	char 		buff[256];

	buff[0] = '\0';
	if (!vect_init(&test))
	{
		printf("Fail init!\n");
		return (0);
	}
	while (test.buff)
	{
		printf(
			"test.len  = [%lu]\n"
			"test.max  = [%lu]\n"
			"test.buff = [%p]\n",
			test.len,
			test.max,
			(test.buff)
			);
		scanf("%s", buff);
		if (!strcmp(buff, "!q"))
			break ;
		else
			vect_cat(&test, buff);
	}
	free(test.buff);
	return (0);
}