let str1="Hello World!"
document.writeln(str1.substr(0,5));//第一个参数为开始位置，第二个为长度
document.writeln(str1.substr(3,-5));//第二个参数<0 , 视为0
document.writeln(str1.substr(-6));//从最后一个开始（-1）到指定位置