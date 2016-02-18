

function plus(a, b)
{
    return a + b;
}


function curried_plus(a)
{
    return function(b) { return plus(a,b); };
}

plus(2,3);          // 5
curried_plus(2)(3); // 5


function partial_plus(b)
{
    return plus(2, b);
}

partial_plus(3);	// 5



var _ = require('lodash');

_.map([3,2,9,6], function(e) { return plus(2, e); });
// [ 5, 4, 11, 8 ]

_.map([3,2,9,6], curried_plus(2));


_.map([3,2,9,6], _.curry(plus)(2));   // [ 5, 4, 11, 8 ]
_.map([3,2,9,6], _.partial(plus, 2)); // [ 5, 4, 11, 8 ]



function plus3(a, b, c)
{
    return a+b+c;
}

var curried_plus3 = _.curry(plus3);
var ary = [3,2,9,6];
_.map(ary, curried_plus3("a")("b"));  // [ 'ab3', 'ab2', 'ab9', 'ab6' ]
_.map(ary, curried_plus3("a", "b"));  // [ 'ab3', 'ab2', 'ab9', 'ab6' ]

_.map(ary, curried_plus3("a")(_, "b"));     // [ 'a3b', 'a2b', 'a9b', 'a6b' ]
_.map(ary, curried_plus3(_, "a")(_, "b"));  // [ '3ab', '2ab', '9ab', '6ab' ]


function plus4(a,b,c,d)
{
    return a+b+c+d;
}
_.curry(plus4)('a')('b')(_, 'c')('d');	 // abdc
_.curry(plus4)('a')(_, 'b')('c')('d');	 // acbd
_.curry(plus4)(_, 'a')('b')('c')('d');	 // bacd


// partial
var partial_plus3 = _.partial(plus3, 'a', 'b');
_.map([3,2,9,6], partial_plus3);    // [ 'ab3', 'ab2', 'ab9', 'ab6' ]

_.map([3,2,9,6], _.partial(plus3, 'a', _, 'b')); // [ 'a3b', 'a2b', 'a9b', 'a6b' ]
_.map([3,2,9,6], _.partial(plus3, _, 'a', 'b')); // [ '3ab', '2ab', '9ab', '6ab' ]


// bind
function Person(name, age)
{
	this.name = name;
	this.age = age;
	this.add_age = function (n) { return this.age + n; };
}
var user = new Person('taro', 30);
_.map([3, 2, 9, 6], _.bind(user.add_age, user)); // [ 33, 32, 39, 36 ]
