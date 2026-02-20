let arry1=[1,2,3];
let arry2=[1,"sbwjx",3];
let arry3=[1,2,["js",'b']];//多维数组

console.log(arry1);
console.log(arry2);
console.log(arry3);
console.log(arry3[2]);
console.log(arry3.length);
console.log(Array.isArray(arry1));//补足typeof不能判断数组,返回true和false

arry1.push(4);                 //push数组末尾添加
console.log(arry1);
arry1.pop();                  //pop删除数组末尾，并返回被删除的元素
console.log(arry1);



arry1.shift();                  //shift删除第一个元素,并返回被删除的数据
console.log(arry1);
arry1.unshift(900);              //unshift插入到头位置
console.log(arry1);



console.log(arry1.join(''));         //join把数组的内容转为字符串
console.log(arry1.join());            //默认 ，


console.log(arry1.concat(arry2,arry3));//数组.concat(数组1，数组2....),合并数组（类型系统会合并为一维数组）,反会一个新的数组



console.log(arry1.reverse());      //会改变原数组



console.log(arry1.indexOf(30));         //查询数组中是否有30
console.log(arry1.indexOf(900,1));     //从索引1开始查询数组中有没有900