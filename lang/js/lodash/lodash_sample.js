// イントロダクション

var _ = require('lodash');

var src = "3,2,9,6".split(",");

var prod = _(src)
    .map(str => parseInt(str,10)) // 数値に変換
    .filter(n => n % 2 == 1)      // 奇数を取得
    .reduce((t,n) => t * n);      // 要素の積算

console.log(prod);		  // 27




var result;

// 逐次処理
console.log("\n==== forEach ====");
_.forEach([3,2,9,6],
	  function(elem) { console.log(elem);});

_([3,2,9,6]).forEach(function(elem) { console.log(elem);});



// 変換
console.log("\n==== map ====");
result = _.map([3,2,9,6],
	       function(elem) {return elem*2;});
console.log(result);

result = _.map([3,2,9,6],
	       elem => elem*2 );
console.log(result);



// フィルター
console.log("\n==== filter ====");
result = _.filter([3,2,9,6],
		  elem => (elem % 2) == 1);
console.log(result);



// フィルター 非関数版
var objs = [{'name': 'Tanaka', 'age': 35, 'enrolled': true},
	    {'name': 'Yamada', 'age': 30, 'enrolled': false},
	    {'name': 'Satou',  'age': 41, 'enrolled': true}];

// matches 呼び出し
result = _.filter(objs, {'age': 35, 'enrolled': true});
console.log(result);			// [ { name: 'Tanaka', age: 35, enrolled: true } ]

// matchesProperty 呼び出し
result = _.filter(objs, ['age', 35]);
console.log(result);            // [ { name: 'Tanaka', age: 35, enrolled: true } ]

result = _.filter(objs, 'enrolled');
console.log(result);            // [ { name: 'Tanaka', age: 35, enrolled: true },
//  { name: 'Satou', age: 41, enrolled: true } ]


// 畳み込み
console.log("\n==== reduce ====");
var src = [3,2,9,6]
result = _.reduce(src, (sum, elem) => sum + elem);
console.log(result);			// 20
result = _.reduce(src, (max, elem) => (max < elem) ? elem : max);
console.log(result);			// 9
result = _.reduce(src, (count, elem) => count+1, 0);
console.log(result);			// 4


// ソート 
console.log("\n==== sortBy ====");
var objs = [{'name': 'Tanaka', 'age': 35},
	    {'name': 'Yamada', 'age': 30},
	    {'name': 'Satou',  'age': 41}];

// age の値でソート
result = _.sortBy(objs, 'age');
console.log(result);
//   { name: 'Yamada', age: 30 },
//   { name: 'Tanaka', age: 35 },
//   { name: 'Satou', age: 41 } ]

// age で逆順ソート
result = _.sortBy(objs, elem => elem.age * -1);
console.log(result);
// [ { name: 'Satou', age: 41 },
//   { name: 'Tanaka', age: 35 },
//   { name: 'Yamada', age: 30 } ]


// 関数で指定
var strs = ["foo", "bar", "BAZ", "qux"]
result = _.sortBy(strs);
console.log(result);			// [ 'BAZ', 'bar', 'foo', 'qux' ]

result = _.sortBy(strs,
		  elem => _.toLower(elem) );
console.log(result);			// [ 'bar', 'BAZ', 'foo', 'qux' ]


var points = [{'x': 2, 'y': 8},
	      {'x': 5, 'y': 1},
	      {'x': 2, 'y': 4}];

// x でソートし、x が同じなら y でソート
result = _.sortBy(points, ['x', 'y']);
console.log(result);
// [ { x: 2, y: 4 }, { x: 2, y: 8 }, { x: 5, y: 1 } ]


// その他のメソッド
console.log("\n==== Others ====");


result = _.size([3,2,9,6]);
console.log(result);		// 4


result = _.find([3,2,9,6], elem => (elem % 2) == 1);
console.log(result);		// 3

result = _.findLast([3,2,9,6], elem => (elem % 2) == 1);
console.log(result);		// 9

result = _.includes([3,2,9,6], 2);
console.log(result);		// true

result = _.some([3,2,9,6], elem => (elem % 2) == 1);
console.log(result);		// true
result = _.every([3,2,9,6], elem => (elem % 2) == 1);
console.log(result);		// false



// メソッド連結と遅延評価

console.log("\n==== Lazy ====");

result = 
    _.chain([3,2,9,6])		// _([3,2,9,6]) と同じ
    .filter(elem => (elem % 2) == 1)
    .map(elem => elem * 2)
    .value();
console.log(result);		// [ 6, 18 ]
