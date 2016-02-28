'use strict'

for (let cnt in process.argv) {
    console.log('%d : %s', cnt, process.argv[cnt]);
}

console.log();
console.log('process.execArgv = ', process.execArgv);
console.log('process.execPath = ', process.execPath);
console.log('__dirname        = ', __dirname);
console.log('__filename       = ', __filename);
