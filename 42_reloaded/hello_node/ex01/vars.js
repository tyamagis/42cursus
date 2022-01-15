// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   vars.js                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/12/23 19:54:57 by tyamagis          #+#    #+#             //
//   Updated: 2020/12/27 20:50:31 by tyamagis         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

console.log('42 is a string.');
console.log('42 is a number.');
console.log('42 is an object.');
console.log('[object Object] is an object.');
console.log('true is a boolean.');
console.log('undefined is an undefined.');


/* --- using vars ------ */

/*
 *
var ary = [42];
var obj = {};
var udf;

console.log("%s is a " + typeof("") + ".", "42");
console.log("%d is a " + typeof(42) + ".", 42);
console.log(ary + " is a " + typeof(ary) + ".");
console.log(obj + " is an " + typeof(obj) + ".");
console.log((!(0)) + " is a " + typeof(true) + ".");
console.log(typeof(udf) + " is an " + typeof(udf) + ".");

*/

/* --- using ${} template LITERAL--- */

/*
 *
var s = '42';
var n = 42;
var o = {key:42};
var u;

console.log(`${s} is a ${typeof(s)}.
${n} is a ${typeof(n)}.
${o.key} is a ${typeof(o)}.
${o + ""} is an ${typeof(o)}.
${!0} is a ${typeof(!0)}.
${u} is an ${typeof(u)}.`);

*/
