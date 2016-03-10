'use strict';

function usage()
{
	console.log('process_signal_kill.js PID [SIGCODE]');
}

// プロセス ID
var pid = process.argv[2];
if (!pid || parseInt(pid) == 0) {
	usage();
	progress.exit(1);
}
pid = parseInt(pid);

// シグナルコード
var sig = process.argv[3];
// 未指定の場合は SIGTERM を送信
if (!sig) {
	sig = 'SIGTERM';
}

console.log("Send : \"%s\"", sig);

// シグナル送信
process.kill(pid, sig);

