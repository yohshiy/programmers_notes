'use strict';

// プロセス ID の表示
console.log('Process ID = ', process.pid);

// 終了する際に終了ステータスを表示
process.on('exit',  (code) => console.log('Exit. code = ', code));

// 5 分待って終了
setTimeout(console.log, 5*60*1000, 'Time out');

