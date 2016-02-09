
var srcary = "3,x,2,9,a,6".split(",");

var prod = 1;
for (cnt in srcary) {
	if (!isNaN(srcary[cnt])) {
		var num = parseInt(srcary[cnt], 10);
		if (num <= 5) {
			prod *= num;
		}
	}
}

console.log(prod);				// 6
