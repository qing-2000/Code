console.log(document);
console.log("此处正常输出。");

var T = document.getElementsByTagName("div")[1]; // 获取第二个div元素

var C = document.getElementsByClassName("1"); // 获取类名为"1"的元素集合
if (C.length > 0) {
    C[0].innerHTML = "E"; // 修改第一个匹配元素的innerHTML
}

var N = document.getElementsByName("2"); // 获取name属性为"2"的元素集合
if (N.length > 0) {
    N[0].innerHTML = "L"; // 修改第一个匹配元素的innerHTML
}

var I = document.getElementById("3"); // 获取id为"3"的元素
console.log(I);

//id前面加#，class前面加.
var nav=document.querySelector(".nav");//返回第一个div内容
console.log("querySelector():");
console.log(nav);

var navs=document.querySelectorAll(".nav");//返回所有div
console.log("querySelectorAll():");
console.log(navs);
