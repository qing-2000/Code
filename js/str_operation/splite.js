let str="Hello World !";
let result="Hello| World | !".split("|");//按|切割字符串，用数组包起来
console.log(str);
console.log(result);
console.log(str.split(""));//传空，切割每个字符
console.log(str.split("",5));//返回5个