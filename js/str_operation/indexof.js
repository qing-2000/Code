let str="Hello World!";
document.writeln(str.indexOf('l'));//匹配指定内容，成功返回索引，没找到返回-1
document.writeln(str.indexOf("llo"));//返回第一个匹配到的索引
document.writeln(str.indexOf('u',2));//表示从多少个（2）开始向后匹配u