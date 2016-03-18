'use strict';

var url = require('url');

var urlStr = 'http://user:pass@host.com:8080/p/a/t/h?q=string#elemid';
url.parse(url.parse(urlStr));
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


url.parse(urlStr, true);
// Url {
//     : 
//   query: { q: 'string' },
//     :


var smbStr = '//pcname/share/foo';
url.parse(smbStr));
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

url.parse(smbStr, false, true));
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



var escStr = 'file:///C:/Program Files/nodejs/index.html';
url.parse(url.parse(escStr));
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
url.format(urlObj);
// http://user:pass@host.com:8080/p/a/t/h?q=string#elemid


// http などではない → "//" は付かない
urlObj = {
	protocol: 'foo',
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
url.format(urlObj);
// foo:host.com/p/a/t/h

// http などではないが、 slashes を true → "//" が付く
urlObj = {
	protocol: 'foo',
	slashes: true,
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
url.format(urlObj);
// foo://host.com/p/a/t/h


// http だけど、 slashes を false → "//" は付く
urlObj = {
	protocol: 'http',
	slashes: false,
	hostname: 'host.com',
	pathname: '/p/a/t/h' };
url.format(urlObj);
// http://host.com/p/a/t/h



// file だけどホスト名がない
urlObj = {
	protocol: 'file',
	pathname: '/C:/foo/bar' };
url.format(urlObj);   // file:/C:/foo/bar
	
// file 、ホスト名がなし、 slashes を true
urlObj = {
	protocol: 'file',
	slashes: true,
	pathname: '/C:/foo/bar' };
url.format(urlObj);   // file:///C:/foo/bar


//// 相対 URL の生成
////////////////////////////////////////////////////////////////

url.resolve("http://host.com/foo/index.html", "../bar/baz.html");
// http://host.com/bar/baz.html


//// Query String
////////////////////////////////////////////////////////////////

var querystring = require('querystring');

querystring.parse('foo=bar&baz=qux&baz=quux&corge');
// { foo: 'bar', baz: [ 'qux', 'quux' ], corge: '' }

querystring.stringify({ foo: 'bar', baz: [ 'qux', 'quux' ], corge: '' });
// foo=bar&baz=qux&baz=quux&corge=



//// エスケープ
////////////////////////////////////////////////////////////////

var escQstrObj = {
    protocol: 'http',
    hostname: 'host.com',
    pathname: 'search.html',
    query: {q: '日本語'}
};
url.format(escQstrObj);
// http://host.com/search.html?q=%E6%97%A5%E6%9C%AC%E8%AA%9E

var escQstrStr = 'http://host.com/search.html?q=%E6%97%A5%E6%9C%AC%E8%AA%9E';
url.parse(escQstrStr, true);
// Url {
//     :
//   search: '?q=%E6%97%A5%E6%9C%AC%E8%AA%9E',
//   query: { q: '日本語' },
//   pathname: '/search.html',
//      : 


var escObj = {
    protocol: 'file',
    slashes: true,
    pathname: '/C:/Program%20Files/nodejs/index.html'
};
url.format(escObj);
// file:///C:/Program%20Files/nodejs/index.html


var escUrlObj = {
	protocol: 'https',
	hostname: 'ja.wikipedia.org',
	pathname: '/wiki/' + encodeURIComponent('メインページ')
};
url.format(escUrlObj);
// https://ja.wikipedia.org/wiki/%E3%83%A1%E3%82%A4%E3%83%B3%E3%83%9A%E3%83%BC%E3%82%B8


var escUrlStr = 'https://ja.wikipedia.org/wiki/%E3%83%A1%E3%82%A4%E3%83%B3%E3%83%9A%E3%83%BC%E3%82%B8';
var parsedObj = url.parse(escUrlStr);
decodeURIComponent(parsedObj.pathname);
// '/wiki/ メインページ'

