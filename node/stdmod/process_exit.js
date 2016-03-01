
process.kill(process.pid);

process.once('beforeExit', () => {
	console.log("before exit");});

process.on('exit', (code)=>console.log('Program exit code : ', code));


process.exit(1);
