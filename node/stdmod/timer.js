'use strict';

//// setTimeout
////////////////////////////////////////////////////////////////

setTimeout(() => {
    console.log('Timeout');
}, 5000);

setTimeout((a, b) => {
    console.log('Timeout', a, b); // Timeout foo bar
}, 5000, 'foo', 'bar');


//// setInterval
////////////////////////////////////////////////////////////////

// 止まらない
//
// setInterval(() => {
//     console.log('Interval');
// }, 1000);

var intervalID = setInterval(() => {
    console.log('Interval');
}, 1000);

setTimeout(() => {
    clearInterval(intervalID);
}, 5000);


// ショート版
//
// setTimeout(clearInterval, 5000,
// 	   setInterval(console.log, 1000, 'Interval'));



//// setImmediate
////////////////////////////////////////////////////////////////

setImmediate(()=>console.log('Immediate'));

