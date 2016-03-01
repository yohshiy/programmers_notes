
process.on('SIGINT', () => {
	console.log('Got SIGINT signal.');
	//process.exit(1);
});

setTimeout(() => {
  console.log('Exiting.');
  process.exit(0);
}, 5000);

process.kill(process.pid, 'SIGINT');
