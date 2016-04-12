'use strict';

var path = require('path');

console.log(process.cwd());

//// ファイルパス解析
////////////////////////////////////////////////////////////////

var pathstr = '/foo/bar/baz/asdf/quux.html';
console.log(path.dirname(pathstr));    // /foo/bar/baz/asdf
console.log(path.extname(pathstr));	   // .html
console.log(path.basename(pathstr));   // quux.html
console.log(path.basename(pathstr, path.extname(pathstr)));    // quux

console.log(path.parse(pathstr));
// { root: '/',
//   dir: '/foo/bar/baz/asdf',
//   base: 'quux.html',
//   ext: '.html',
//   name: 'quux' }
console.log(path.parse('c:\\foo\\bar\\baz\\asdf\\quux.html'));
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

console.log(path.relative('/data/orandea/test/aaa', '/data/orandea/impl/bbb')); // ../../impl/bbb
console.log(path.resolve('../foo.txt')); // /home/user/foo.txt

console.log(path.isAbsolute('/foo/bar')); // true
console.log(path.isAbsolute('../bar'));   // false
console.log(path.isAbsolute('c:\\Program Files')); // true


//// ファイルパス操作
////////////////////////////////////////////////////////////////

console.log(path.join('/foo/bar/baz/asdf/', 'quux.html')); // /foo/bar/baz/asdf/quux.html
console.log(path.join('/foo/bar/baz/asdf',  'quux.html')); // /foo/bar/baz/asdf/quux.html
console.log(path.join('/foo', 'bar', 'baz/asdf', 'quux', '..')); // /foo/bar/baz/asdf/quux.html

console.log(path.normalize('./foo/bar/baz/../quz/.')); // foo/bar/quz
console.log(path.resolve('./foo/bar/baz/../quz/.'));   // /home/user/programmers_notes/foo/bar/quz



//// Windows, POSIX(Unix)
////////////////////////////////////////////////////////////////

console.log('/foo/bar/baz'.split(path.sep)); // [ '', 'foo', 'bar', 'baz' ]

console.log(process.env.PATH);	// C:\Windows\system32;C:\Windows; ...
console.log(process.env.PATH.split(path.delimiter));
// [ 'C:\\Windows\\system32',
//   'C:\\Windows',
//     :


console.log(path.posix.sep); // /
console.log(path.win32.sep); // \
console.log(path.posix.join('/foo/bar/baz/asdf/', 'quux.html')); // /foo/bar/baz/asdf/quux.html
console.log(path.win32.join('/foo/bar/baz/asdf/', 'quux.html')); // \foo\bar\baz\asdf\quux.html
