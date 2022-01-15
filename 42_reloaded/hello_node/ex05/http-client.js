// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   http-client.js                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/27 20:48:07 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/01 23:13:39 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

if (process.argv.length < 3){
	console.log("NO ARG : [http url] needed.\nRETRY >>");
	return ;
}
try {
	var req = require("http").get(process.argv[2], (res) => {
		res.on("data", (chunk) => {
			console.log(chunk.toString());
		});
	});
	req.on("error", (e) => {
		console.log(e.message + "\nRETRY >>");
	});
} catch (e){
	console.log(e.message + "\nRETRY >>");
}
