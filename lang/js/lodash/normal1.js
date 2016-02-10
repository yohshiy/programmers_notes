// 元の配列  [ '3', '2', '9', '6' ]
var src = "3,2,9,6".split(",");

// 数値に変換 [ 3, 2, 9, 6 ]
var map_ary = [];
for (cnt in src) {
    map_ary.push(parseInt(src[cnt], 10));
}

// 奇数を取得 [ 3, 9 ]
var filter_ary = [];
for (cnt in map_ary) {
    if (map_ary[cnt] % 2 == 1) {
	filter_ary.push(map_ary[cnt]);
    }
}

// 要素の積算
var prod = 1;
for (cnt in filter_ary) {
    prod *= filter_ary[cnt];
}

console.log(prod);		// 27
