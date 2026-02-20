let arr=['2','web',true,0];
for(let j in arr){
console.log(arr[j]);}
console.log("原数组的长度为："+arr.length);

arr.push('sb');
for(let j in arr){
console.log(arr[j]);}
console.log("push后数组的长度为："+arr.length);//末尾添加

arr.pop();
for(let j in arr){
    console.log(arr[j]);
}
console.log("pop后数组的长度为："+arr.length);//末尾删除
