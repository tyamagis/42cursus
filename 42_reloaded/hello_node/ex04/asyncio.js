// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   asyncio.js                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/27 15:14:16 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/01 23:14:07 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

if (process.argv[2] == undefined){
	console.log("No Args, RETRY >>");
	return ;
}
require("fs").readFile(process.argv[2], (err, data) => {
	if (err)
		console.log(err.name, err.message);
	else
		console.log(data.toString().split("\n").length - 1);
});
