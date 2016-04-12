'use strict';

var path = require('path');


//// ファイルパス解析
////////////////////////////////////////////////////////////////

var pathstr = '/foo/bar/baz/asdf/quux.html';
path.dirname(pathstr);    // /foo/bar/baz/asdf
path.extname(pathstr);	   // .html
path.basename(pathstr);   // quux.html
path.basename(pathstr, path.extname(pathstr));    // quux

path.parse(pathstr);
// { root: '/',
//   dir: '/foo/bar/baz/asdf',
//   base: 'quux.html',
//   ext: '.html',
//   name: 'quux' }
path.parse('c:\\foo\\bar\\baz\\asdf\\quux.html');
// { root: 'c:\\',
//   dir: 'c:\\foo\\bar\\baz\\asdf',
//   base: 'quux.html',
//   ext: '.html',
//   name: 'quux' }


console.log(path.format({
    dir : "/path/dir",
    base : "file.txt"
}));
// /path/dir/file.txt



//// 相対パス、絶対パス
////////////////////////////////////////////////////////////////

path.relative('/data/orandea/test/aaa', '/data/orandea/impl/bbb'); // ../../impl/bbb
path.resolve('../foo.txt'); // /home/user/foo.txt

path.isAbsolute('/foo/bar'); // true
path.isAbsolute('../bar');   // false
path.isAbsolute('c:\\Program Files'); // true


//// ファイルパス操作
////////////////////////////////////////////////////////////////

path.join('/foo/bar/baz/asdf/', 'quux.html'); // /foo/bar/baz/asdf/quux.html
path.join('/foo/bar/baz/asdf',  'quux.html'); // /foo/bar/baz/asdf/quux.html
path.join('/foo', 'bar', 'baz/asdf', 'quux', '..'); // /foo/bar/baz/asdf/quux.html

path.normalize('./foo/bar/baz/../quz/.'); // foo/bar/quz
path.resolve(  './foo/bar/baz/../quz/.'); // /home/user/programmers_notes/foo/bar/quz



//// Windows, POSIX(Unix)
////////////////////////////////////////////////////////////////

'/foo/bar/baz'.split(path.sep); // [ '', 'foo', 'bar', 'baz' ]

process.env.PATH;	// C:\Windows\system32;C:\Windows; ...
process.env.PATH.split(path.delimiter);
// [ 'C:\\Windows\\system32',
//   'C:\\Windows',
//     :

path.posix.sep; // /
path.win32.sep; // \
path.posix.join('/foo/bar/baz/asdf/', 'quux.html'); // /foo/bar/baz/asdf/quux.html
path.win32.join('/foo/bar/baz/asdf/', 'quux.html'); // \foo\bar\baz\asdf\quux.html
