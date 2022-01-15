// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   sum_args.js                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/24 07:29:59 by tyamagis          #+#    #+#             //
//   Updated: 2020/12/29 16:03:25 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

var i = 2;
var sum = 0;

if (process.argv.length == 2){
	console.log(" ! -- Error -- ! ");
	console.log("no input. Retry >>");
} else {
	while (i < process.argv.length){
		sum += +(process.argv[i]);
		i++;
	}
	if (!sum){
		console.log(" ! -- Error -- ! ");
		console.log("Your input includes non-NUMERIC character.");
		console.log("Result may be 'NaN'. Retry >>");
	}
	console.log(sum);
}
