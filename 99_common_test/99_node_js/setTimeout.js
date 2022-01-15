// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   setTimeout.js                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/01/01 23:41:27 by tyamagis          #+#    #+#             //
//   Updated: 2021/01/06 20:24:51 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// test for setTimeout() func

console.log('start');
(async () => { await 0; console.log('async')})();
function promiseFunc(){
	return new Promise((resolve) => resolve())
}
// setTimeout(() => console.log('setTo'), 0);
Promise.resolve().then(() => console.log('rslv'));
promiseFunc().then(() => console.log('prms'));
console.log('end');
