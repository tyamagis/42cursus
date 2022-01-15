/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_bitCalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:58:03 by tyamagis          #+#    #+#             */
/*   Updated: 2021/02/13 18:33:20 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void){
	/*
	**
	**
	*/
	int i = 0;
	int bit[32];
	
	/*
	** int 4 Byte = 32bit.
	** set 0x0000 0000.
	*/
	while (i <= 32)
		bit[i++] = 0;

	/*
	** test 1 -----------------------
	** simple shift to Right '>>'
	*/
	i = 255;
	while (i > 0){
		printf("%d, ", i);
		i >>= 1;
	}
	printf("\n\n");
	/*
	** OUTPUT >> "255, 127, 63, 31, 15, 7, 3, 1, %"
	*/

	/*
	** test 2 -------------------------
	** simple shift to Left '<<'
	*/
	i++;
	while (i <= 256){
		printf("%d, ", i);
		i <<= 1;
	}
	printf("\n\n");
	/*
	** OUTPUT >> "1, 2, 4, 8, 16, 32, 64, 128, 256, %"
	*/

	/*
	** test 3 ----------------------------
	** OR operation '|'
	*/
	i = -3;
	while (i++ <= 3){
		printf("%d, i | 255 = %d\n", i, i | 255);
	}
	printf("\n\n");
	i = 252;
	while (i++ <= 260){
		printf("%d, i | 255 = %d\n", i, i | 255);
	}
	return (0);
}
