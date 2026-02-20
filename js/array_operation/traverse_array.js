let arry=['sb','wp','dsa'];
let i=0;
for(let j=0;j<arry.length;j++){
    console.log(arry[j]);
}

while(i<arry.length){
    console.log(arry[i]);
    i++;
}

for(let k in arry){
    console.log(arry[k]);//若是直接填k输出arry的索引
}