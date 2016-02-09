var _ = require('lodash');

var srcary = "3,x,2,9,a,6".split(",");

var prod = _(srcary)
		.filter(str => !isNaN(str))
		.map(str => parseInt(str,10))
		.filter(n => n <= 5)
		.reduce((t,n) => t * n);

console.log(prod);				// 6


