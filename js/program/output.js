'use strick'

document.addEventListener('DOMContentLoaded', () => {
    console.log('DOM fully loaded and parsed');

    //剩余参数语法...来表示剩余的参数。
    function jisuan(...num) {
        let total = 0;
        for (const n of num) {
            total += n;
        }
        return total;
    }

    // 一个按钮触发多个操作
    document.getElementById('jisuan').addEventListener('click', () => {
        console.log("1000000");
        // 调用多个ID的操作
        console.log(jisuan(1, 2, 3));  // 输出 6
        document.getElementById('output').textContent = "计算结果: " + jisuan(1, 2, 3);  // 修改某个元素的内容
        document.getElementById('shuchu').textContent = "新的内容";  // 改变另一个元素的内容
    });
});