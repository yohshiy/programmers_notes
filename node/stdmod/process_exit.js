

//// exit イベント
////////////////////////////////////////////////////////////////

process.on('exit',  (code)=> {
	console.log('Program exit. code = ', code);
});

process.on('exit',  (code)=> {
	// 非同期は実行されない
	setImmediate(console.log, 'This will not run');
});



//// beforeExit イベント
////////////////////////////////////////////////////////////////

process.once('beforeExit', () => {
	console.log("before exit");
});


//// プログラムの終了
////////////////////////////////////////////////////////////////

process.exit(1);

