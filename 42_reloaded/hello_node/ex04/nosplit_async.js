// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   asyncio.js                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/27 15:14:16 by tyamagis          #+#    #+#             //
//   Updated: 2020/12/27 17:44:56 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

var line = 0;

require("fs").readFile(process.argv[2], (err, data) => {
	if (err){
		console.log("Something went wrong, retry >>");
	} else {
		for (var i = 0; i < data.length; i++){
			if (data[i] === 10){
				line++;
			}
		}
		console.log(line);
	}
});
