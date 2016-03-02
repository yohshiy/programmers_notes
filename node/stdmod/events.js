"use strict";

//// 基本
////////////////////////////////////////////////////////////////

const EventEmitter = require('events');

// 継承して emitter を作成
class MyEmitter extends EventEmitter {};
var myEmitter = new MyEmitter();

// listener の登録
function barListener()
{
  console.log('a foo event occurred!');  
}
myEmitter.on('fooEvent', barListener);

// イベントの発行
myEmitter.emit('fooEvent');
// barListener の実行 => a foo event occurred!



//// 引数渡し
////////////////////////////////////////////////////////////////
console.log();

var myEmitter = new MyEmitter();

myEmitter.on('fooEvent', function(a, b) {
    console.log('fooEvent', a, b);
});
myEmitter.emit('fooEvent', 'bar', 'baz');
// fooEvent bar baz


//// this
////////////////////////////////////////////////////////////////
console.log();

var myEmitter = new MyEmitter();

myEmitter.on('fooEvent', function() {
    console.log('fooEvent this =', this);
});
myEmitter.emit('fooEvent');
// fooEvent this= MyEmitter {
//   domain: null,
//   _events: { fooEvent: [Function] },
//   _eventsCount: 1,
//   _maxListeners: undefined }


////////////////

var myEmitter = new MyEmitter();

myEmitter.on('fooEvent', () => {
    console.log('fooEvent this = ', this);
});

console.log('this = ', this);   // this = {}
myEmitter.emit('fooEvent');	// fooEvent this = {}


//// エラーイベント
////////////////////////////////////////////////////////////////
console.log();

// var myEmitter = new MyEmitter();
// myEmitter.emit('error', new Error('whoops!'));
// // events.js:141
// //       throw er; // Unhandled 'error' event
// //       ^
// // Error: whoops!
// //     at Object.<anonymous> (d:\h...

var myEmitter = new MyEmitter();
myEmitter.on('error', (err) => {
    console.log('myEmitter error happned. ', err);
});
myEmitter.emit('error', new Error('whoops!'));
// myEmitter error happned.  [Error: whoops!]


//// async
////////////////////////////////////////////////////////////////
console.log();

var myEmitter = new MyEmitter();

myEmitter.on('fooEvent', () => console.log('1'));
myEmitter.on('fooEvent', () => console.log('2'));
myEmitter.on('fooEvent', () => console.log('3'));

myEmitter.emit('fooEvent');
// 1
// 2
// 3

////
console.log();

var myEmitter = new MyEmitter();

myEmitter.on('fooEvent', () => console.log('1'));
myEmitter.on('fooEvent', () => {
    setImmediate(() => console.log('2 (async)'));
});
myEmitter.on('fooEvent', () => console.log('3'));

myEmitter.emit('fooEvent');
// 1
// 3
// 2 (async)



