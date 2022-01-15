// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   time-server.js                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/01/13 05:37:08 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/13 09:14:39 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

var add_zero = function(num){
	num += "";
	if (num.length === 1){
		num = "0" + num;
	}
	return num;
};

if (process.argv.length !== 3 || +(process.argv[2]) == NaN){
	console.log("Err:\nport number needed.\n RETRY >>");
}
try {
	let server = require('net').createServer((c) => {
		c.on('data', () => {
			let date = new Date();
			let y = date.getFullYear();
			let m = add_zero(date.getMonth() + 1);
			let d = add_zero(date.getDate());
			let h = add_zero(date.getHours());
			let min = add_zero(date.getMinutes());
			c.end(`${y}-${m}-${d} ${h}:${min}\n`);
		});
	}).listen(+(process.argv[2]));
} catch (e){
	console.log(e.message + "\nRETRY >>");
}
