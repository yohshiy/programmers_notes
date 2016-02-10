
var src = "3,2,9,6".split(",");

var prod = 1;
for (cnt in src) {
    var num = parseInt(src[cnt], 10); // 数値に変換
    if (num % 2 == 1) {               // 奇数を取得
	prod *= num;                  // 要素の積算
    }
}

console.log(prod);		      // 27
