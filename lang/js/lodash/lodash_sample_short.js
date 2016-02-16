
var _ = require('lodash');

// 逐次処理
_.forEach([3,2,9,6],
	  function(elem) { console.log(elem);});

_([3,2,9,6]).forEach(function(elem) { console.log(elem);});


// 変換
_.map([3,2,9,6],
      function(elem) {return elem*2;});
// [ 6, 4, 18, 12 ]

_.map([3,2,9,6],
      elem => elem*2 );



// フィルター
_.filter([3,2,9,6], elem => (elem % 2) == 1);



// フィルター 非関数版
var objs = [{'name': 'Tanaka', 'age': 35, 'enrolled': true},
	    {'name': 'Yamada', 'age': 30, 'enrolled': false},
	    {'name': 'Satou',  'age': 41, 'enrolled': true}];

// matches 呼び出し
_.filter(objs, {'age': 35, 'enrolled': true});
// [ { name: 'Tanaka', age: 35, enrolled: true } ]

// matchesProperty 呼び出し
_.filter(objs, ['age', 35]);
// [ { name: 'Tanaka', age: 35, enrolled: true } ]

_.filter(objs, 'enrolled');
// [ { name: 'Tanaka', age: 35, enrolled: true },
//   { name: 'Satou', age: 41, enrolled: true } ]


// 畳み込み
var src = [3,2,9,6];
_.reduce(src, (sum, elem) => sum + elem);		 // 20
_.reduce(src, (max, elem) => (max < elem) ? elem : max); // 9
_.reduce([3,2,9,6], (count, elem) => count+1, 0);	 // 4



// ソート 

var objs = [{'name': 'Tanaka', 'age': 35},
	    {'name': 'Yamada', 'age': 30},
	    {'name': 'Satou',  'age': 41}];

// age の値でソート
_.sortBy(objs, 'age');
//   { name: 'Yamada', age: 30 },
//   { name: 'Tanaka', age: 35 },
//   { name: 'Satou', age: 41 } ]

// age で逆順ソート
_.sortBy(objs, elem => elem.age * -1);
// [ { name: 'Satou', age: 41 },
//   { name: 'Tanaka', age: 35 },
//   { name: 'Yamada', age: 30 } ]


// 関数で指定
var strs = ["foo", "bar", "BAZ", "qux"];
_.sortBy(strs);	                           // [ 'BAZ', 'bar', 'foo', 'qux' ]
_.sortBy(strs, elem => _.toLower(elem) );  // [ 'bar', 'BAZ', 'foo', 'qux' ]
// _.sortBy(strs, _.toLower); でも可

var points = [{'x': 2, 'y': 8},
	      {'x': 5, 'y': 1},
	      {'x': 2, 'y': 4}];

// x でソートし、x が同じなら y でソート
_.sortBy(points, ['x', 'y']);
// [ { x: 2, y: 4 }, { x: 2, y: 8 }, { x: 5, y: 1 } ]




// その他のメソッド

result = _.size([3,2,9,6]);	// 4

_.find([3,2,9,6], elem => (elem % 2) == 1);     // 3
_.findLast([3,2,9,6], elem => (elem % 2) == 1); // 9

_.includes([3,2,9,6], 2);	// true

_.some([3,2,9,6], elem => (elem % 2) == 1);  // true
_.every([3,2,9,6], elem => (elem % 2) == 1); // false


// メソッド連結と遅延評価

_.chain([3,2,9,6])		// _([3,2,9,6]) と同じ
    .filter(elem => (elem % 2) == 1)
    .map(elem => elem * 2)
    .value();
// [ 6, 18 ]
