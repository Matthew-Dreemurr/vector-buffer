/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utoa_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:48:00 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/26 23:54:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * index   0  1  2  3  4  5  6  7  8  9  10 11
 *        [8][4][6][3][8][4][7][4][1][2][-][\0]
 * @brief Convert integer to string of char. (use malloc())
 * 
 * @param n The Uinteger to convert.
 * @return int `0` if error else `!0`.
 */
char	*vect_utoa_cat(unsigned int n, t_vector *vec)
{
	char	buff[12];
	char	*ptr;
	size_t	nbr;

	nbr = (size_t []){n, -n}[n < 0];
	ptr = buff;
	if (nbr == 0)
		*ptr++ = '0';
	while (nbr > 0)
	{
		*ptr++ = (char)((nbr % 10) + '0');
		nbr /= 10;
	}
	*ptr++ = (char []){'\0', '-'}[n < 0];
	if (*ptr)
		*ptr = '\0';
	nbr = strlen_protect(buff);
	rev_char_arr(buff, nbr);
	if (!vect_cat(vec, buff))
		return (VEC_EXIT_FAILURE);
	return (vec->buff);
}
