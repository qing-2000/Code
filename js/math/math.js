let num=-999; 
console.log(Math.abs(num));            //math内置库

console.log("最大值："+Math.max(1,2,3));          
console.log("最小值："+Math.min(99,0,3));  

console.log(Math.floor(3.2));           //向下取整
console.log(Math.ceil(-1.1));          //向上取整    

console.log(Math.random());            //随机数[0,1)
function func1(min,max){               //任意范围随机数,塞入Math.floor()中可实现随机整数
    return Math.random()*(max-min)+min;
}
document.writeln(func1(10,20));

