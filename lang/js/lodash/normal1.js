// 元の配列
var srcary = "3,x,2,9,a,6".split(",");
// [ '3', 'x', '2', '9', 'a', '6' ]


// 数値にならない要素を取り除く
var filary = [];
for (cnt in srcary) {
	if (!isNaN(srcary[cnt])) {
		filary.push(srcary[cnt]);
	}
}
// [ '3', '2', '9', '6' ]


// 数値に変換
var mary = [];
for (cnt in filary) {
	if (!isNaN(filary[cnt])) {
		mary.push(parseInt(filary[cnt], 10));
	}
}
// [ 3, 2, 9, 6 ]


// 5 以下の数値を取得
var fil2ary = [];
for (cnt in mary) {
	if (mary[cnt] <= 5) {
		fil2ary.push(mary[cnt]);
	}
}
// [ 3, 2 ]


// 要素の積算
var prod = 1;
for (cnt in fil2ary) {
	prod *= fil2ary[cnt];
}

console.log(prod);				// 6
