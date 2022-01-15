// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   http-json-api-server.js                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/01/13 09:26:57 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/19 13:21:22 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

if (process.argv.length !== 3 || +(process.argv[2]) == NaN){
	console.log("Err:\nport number needed.\nRETRY >>");
	return ;
}
try {
	let server = require('http').createServer((rq, rs) => {
		let url = new URL(rq.url, "http://test.com");
		let iso = url.searchParams.get("iso");
		let time = new Date(iso);
		if (rq.url.startsWith("/api/parsetime")){
			rs.writeHead(200, { 'content-Type': 'application/json'});
			rs.end(JSON.stringify({
				"hour": time.getHours(),
				"minute": time.getMinutes(),
				"second": time.getSeconds()
			}));
		} else if (rq.url.startsWith("/api/unixtime")){
			rs.writeHead(200, { 'content-Type': 'application/json'});
			rs.end(JSON.stringify({ "unixtime": time.getTime()}));
		} else {
			rs.writeHead(404);
			rs.end();
		}
	});
	server.listen(+(process.argv[2]));
} catch (e) {
	console.log(e.message + "\nRETRY >>");
}

