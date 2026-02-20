var x=10;
var y=20;
var z="10";
var u="20";
var p="90";
var resualt = z.concat(y,x);/* 仅字符串可以使用concat,全是字符串等同于+*/
console.log(resualt);
console.log(z+u+p);
console.log(x+y+z);/*数字会优先相加*/
function myF(){
    alert("Hello");
}