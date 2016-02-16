

function plus(a, b)
{
    return a + b;
}

console.log(plus(2,3));


function curried_plus(a)
{
    return function(b) { return plus(a,b); };
}

console.log(curried_plus(2)(3));


function partial_plus(b)
{
    return plus(2, b);
}

console.log(partial_plus(3));	// 5



var _ = require('lodash');

var result = _.map([3,2,9,6], function(e) { return plus(2, e); });
console.log(result);			// [ 5, 4, 11, 8 ]

var result = _.map([3,2,9,6], curried_plus(2));
console.log(result);

var lodash_curried_plus = _.curry(plus);
var result = _.map([3,2,9,6], lodash_curried_plus(2));

var result = _.map([3,2,9,6], _.curry(plus)(2));
console.log(result);



function plus3(a, b, c)
{
    return a+b+c;
}

curried_plus3 = _.curry(plus3);


var result = _.map([3,2,9,6], curried_plus3("a")("b"));
console.log(result);			// [ 'ab3', 'ab2', 'ab9', 'ab6' ]
var result = _.map([3,2,9,6], curried_plus3("a", "b"));
console.log(result);			// [ 'ab3', 'ab2', 'ab9', 'ab6' ]

var result = _.map([3,2,9,6], curried_plus3("a")(_, "b"));
console.log(result);			// [ 'a3b', 'a2b', 'a9b', 'a6b' ]
var result = _.map([3,2,9,6], curried_plus3(_, "a")(_, "b"));
console.log(result);			// [ '3ab', '2ab', '9ab', '6ab' ]


function plus4(a,b,c,d)
{
    return a+b+c+d;
}
console.log(_.curry(plus4)('a')('b')(_,'c')('d'));	 // abdc
console.log(_.curry(plus4)('a')(_, 'b')('c')('d'));	 // acbd
console.log(_.curry(plus4)(_,'a')('b')('c')('d'));	 // bacd
