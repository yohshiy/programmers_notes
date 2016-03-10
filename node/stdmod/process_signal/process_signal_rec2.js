'use strict';

// プロセス ID の表示
console.log('Process ID = ', process.pid);

// 終了する際に終了ステータスを表示
process.on('exit',  (code) => console.log('Exit. code = ', code));

// 5 分待って終了
setTimeout(console.log, 5*60*1000, 'Time out');


////////////////////////////////////////////////////////////////

// ID が 8888 のプロセスに対して SIGINT を送信
// process.kill(8888, 'SIGINT');


// SIGINT
// - Ctrl+C
// - kill で送信 (Windows 不可)
process.on('SIGINT', () => {
    console.log('Got SIGINT. ');
});


// SIGTERM
// - kill で送信 (Windows 不可)

process.on('SIGTERM', () => {
    console.log('Got SIGTERM. ');
    // 後処理など
    // :
    process.exit(128+15);
});


// SIGBREAK
// - Ctrl+Break (Windows のみ)

process.on('SIGBREAK', () => {
    console.log('Got SIGBREAK. ');
    process.exit(1);
});


// SIGHUP
// - ターミナルを閉じる
// - kill で送信 (Windows 不可)

process.on('SIGHUP', ()=> {
    console.log('Got SIGHUP. ');
    // -d オプションが付いていたら、終了しない
    if (process.argv[2] != '-d') {
	process.exit(128+1);
    }
});

