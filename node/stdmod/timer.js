
var iobj = setInterval(() => {
	console.log('setInterval()');
}, 1000);


setTimeout((obj) => {
	console.log('setTimeout()');
	clearInterval(obj);
}, 5000, iobj);


setImmediate(()=>console.log('setImmediate()'));
