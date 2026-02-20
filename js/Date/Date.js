let d=Date.now();//返回当前时间距时间零点（1970.1.1 00：00：00）的毫秒数,及时间戳

let now=new Date(d); //创建Date对象
/*

    Date对象的函数:

    getFullYear() 返回4位数字的年份                               年份

    getMonth() 返回月份（0-11），获取月份时通常需要+1              月份

    getDate() 返回一个月中的某一天（1-31）                        天数

    getDay() 返回一周中的某一天（0-6）                            星期几

    getHours() 返回小时（0-23）

    getMinutes() 返回分钟（0-59）

    getSeconds() 返回秒数（0-59）

    getMilliseconds() 返回毫秒数（0-999）

    getTime() 返回1970年1月1日至今的毫秒数，即时间戳

*/

console.log(now);//获取当前时间
console.log(Date.now());

document.writeln("当前时间："+now.getFullYear()+"-"+(now.getMonth()+1)+"-"+now.getDate()+"，星期："+now.getDay()+"<br>");

function remating_time(){               //计算某年剩余时间
    let startTime=new Date(Date.now());       //计算当前时间戳
    let endTime=new Date('2025-12-31 23:59:59.999');   //截至时间            或者写成let endTime = new Date(2025, 11, 31, 23, 59, 59, 999);
    let ans=(endTime-startTime)/1000/60/60/24;            //将毫秒转为天,可用floor向下取整
    document.writeln("距今年结束还剩："+Math.floor(ans)+"天！");
}
remating_time();