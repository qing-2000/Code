//createElement()创建内容
let text=document.createElement('p');
console.log(text);  

//createTextNode()写入文本
let text_content=document.createTextNode("document.createTextNode创建的文本。");
console.log(text_content);

//createAttribute()为标签增加属性,如id
let id=document.createAttribute("id");
id.value="root";

//appendChild（）将内容塞入父容器
text.appendChild(text_content);

//setAttributeNode()将id加入标签中
text.setAttributeNode(id);

console.log(text);
console.log(id);

let temp=document.getElementById("3");
temp.appendChild(text);
//document.getElementById("3").innerHTML=text; 错误：html直接解释DOM对象不能得到预期
//document.getElementById("3").innerHTML = text.outerHTML; 正确可以替代appendChild();