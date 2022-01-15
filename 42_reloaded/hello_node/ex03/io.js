// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   io.js                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/24 09:26:36 by tyamagis          #+#    #+#             //
//   Updated: 2020/12/29 16:35:29 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

try {
	var file_contents = require("fs").readFileSync(process.argv[2]);
	var line = 0;

	for (var i = 0; i < file_contents.length; i++){
		if (file_contents[i] === 10){
			line++;
		}
	}
	console.log(line);
} catch (e) {
	console.log(e.name, e.message, "\nRETRY >>");
}
