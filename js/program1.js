
document.getElementById("submit").addEventListener("click", function() {
    console.log("按钮值:", this.value); // 输出: "12"
});


var temp = document.getElementById("submit").value;
console.log("Value:", temp); // 输出: "12"

// 获取文本内容
var text = document.getElementById("submit").textContent;
console.log("Text:", text); // 输出: "点击我"