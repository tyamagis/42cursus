// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   async-http-collect.js                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/01/01 21:22:27 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/13 09:19:55 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

let i = 2;

function put_html(url){
	try {
		var html = "";
		var req = require("http").get(url, (res) => {
			res.on("data", (chunk) => {
				html += chunk.toString();
			});
			res.on("end", () => {
				console.log(html);
				if (++i < 5){
					put_html(process.argv[i]);
				}
			});
		});
		req.on("error", (e) => {
			console.log(e.message + "\nRETRY >>");
		});
	} catch (e){
		console.log(e.message + "\nRETRY >>");
	}
}

if (process.argv.length !== 5){
	console.log("ARGS Err:\n3 [http url] needed.\nRETRY >>");
	return ;
}
put_html(process.argv[i]);
