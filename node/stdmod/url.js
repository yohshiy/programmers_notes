'use strict';

var url = require('url');


//// URL 解析
////////////////////////////////////////////////////////////////

var urlStr = 'http://user:pass@host.com:8080/p/a/t/h?q=string#elemid';
console.log(url.parse(url.parse(urlStr)));
// Url {
//   protocol: 'http:',
//   slashes: true,
//   auth: 'user:pass',
//   host: 'host.com:8080',
//   port: '8080',
//   hostname: 'host.com',
//   hash: '#elemid',
//   search: '?q=string',
//   query: 'q=string',
//   pathname: '/p/a/t/h',
//   path: '/p/a/t/h?q=string',
//   href: 'http://user:pass@host.com:8080/p/a/t/h?q=string#elemid' }


//// query の解析
////////////////////////////////////////////////////////////////
console.log();

console.log(url.parse(urlStr, true));
// Url {
//     : 
//   query: { q: 'string' },
//     :



//// URL(ネットワークコンピューター名) の解析
////////////////////////////////////////////////////////////////
console.log();


var smbStr = '//pcname/share/foo';
console.log(url.parse(smbStr));
// Url {
//    :
//   slashes: null,
//    :
//   host: null,
//    :
//   hostname: null,
//    :
//   pathname: '//pcname/share/foo',
//   path: '//pcname/share/foo',
//   href: '//pcname/share/foo' }

console.log(url.parse(smbStr, false, true));
// Url {
//    :
//   slashes: true,
//    :
//   host: 'pcname',
//    :
//   hostname: 'pcname',
//    :
//   pathname: '/share/foo',
//   path: '/share/foo',
//   href: '//pcname/share/foo' }



//// URL(エスケープ文字列付き) の解析
////////////////////////////////////////////////////////////////
console.log();


var escStr = 'file:///C:/Program Files/nodejs/index.html';
console.log(url.parse(url.parse(escStr)));
// Url {
//   protocol: 'file:',
//   slashes: true,
//       : 
//   pathname: '/C:/Program%20Files/nodejs/index.html',
//   path: '/C:/Program%20Files/nodejs/index.html',
//   href: 'file:///C:/Program%20Files/nodejs/index.html' }





var urlObj = {
	protocol: 'http',
	auth: 'user:pass',
	port: '8080',
	hostname: 'host.com',
	hash: 'elemid',
	search: 'q=string',
	pathname: 'p/a/t/h' };
console.log(url.format(urlObj));
// http://user:pass@host.com:8080/p/a/t/h?q=string#elemid


urlObj = {
	protocol: 'foo',
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
console.log(url.format(urlObj));
// foo:host.com/p/a/t/h

urlObj = {
	protocol: 'foo',
	slashes: true,
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
console.log(url.format(urlObj));
// foo://host.com/p/a/t/h


urlObj = {
	protocol: 'http',
	slashes: false,
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
console.log(url.format(urlObj));
// http://host.com/p/a/t/h


