/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putvectbuff_ret_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:56:02 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/26 23:54:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

/**
 * @brief    Outputs the `vect->buffer` to `stdout`.
 *
 * @return   Return numbre of char print.
 */
int	putvectbuff_ret_int(t_vector *vect)
{
	if (!vect)
		return (0);
	return (write(STDOUT_FILENO, vect->buff, vect->len));
}
