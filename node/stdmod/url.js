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


console.log(decodeURIComponent('%E6%97%A5%E6%9C%AC%E8%AA%9E'));
var parsed = url.parse('https://ja.wikipedia.org/wiki/%E3%83%A1%E3%82%A4%E3%83%B3%E3%83%9A%E3%83%BC%E3%82%B8');
console.log(decodeURIComponent(parsed.path));
// /wiki/メインページ

//// URL の生成
////////////////////////////////////////////////////////////////

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


// http, https, ftp, gopher, file 以外の protocol 
urlObj = {
	protocol: 'foo',
	hostname: 'host.com' };
console.log(url.format(urlObj));   // foo:host.com

// foo で slashes を true
urlObj = {
	protocol: 'foo',
	slashes: true,
	hostname: 'host.com' };
console.log(url.format(urlObj));   // foo://host.com

// http で slashes を false
urlObj = {
	protocol: 'http',
	slashes: false,
	hostname: 'host.com' };
console.log(url.format(urlObj));   // http://host.com


//// 相対 URL の生成
////////////////////////////////////////////////////////////////

console.log(url.resolve("http://host.com/foo/index.html", "../bar/baz.html")); // http://host.com/bar/baz.html



//// Query String
////////////////////////////////////////////////////////////////

var querystring = require('querystring');
var qobj = querystring.parse('foo=bar&baz=qux&baz=quux&corge');
console.log(qobj);
// { foo: 'bar', baz: [ 'qux', 'quux' ], corge: '' }

qobj = querystring.parse('sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=%E6%97%A5%E6%9C%AC%E8%AA%9E');
console.log(qobj);

