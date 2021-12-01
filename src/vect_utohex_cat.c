/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utohex_cat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:48:00 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/26 23:54:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static char	utohex(int index, int upper)
{
	char	*dico;

	if (upper)
		dico = "0123456789ABCDEF";
	else
		dico = "0123456789abcdef";
	return (dico[index]);
}

/**
 * index   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
 *        [-][9][2][2][3][3][7][2][0][3][6][8][5][4][7][7][5][8][0][8]
 * @brief Convert Uinteger to string of char. (use malloc())
 * 
 * @param n The integer to convert.
 * @return int `0` if error else `!0`.
 */
char	*vect_utohex_cat(unsigned int n, t_vector *vec, int upper)
{
	char	buff[20];
	char	*ptr;

	ptr = buff;
	if (n == 0)
		*ptr++ = '0';
	while (n > 0)
	{
		*ptr++ = (char)(utohex((n % 16), upper));
		n /= 16;
	}
	*ptr = '\0';
	n = strlen_protect(buff);
	rev_char_arr(buff, n);
	if (!vect_cat(vec, buff))
		return (VEC_EXIT_FAILURE);
	return (vec->buff);
}
