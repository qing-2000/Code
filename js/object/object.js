//对象类型
var chusheng={
    cs_name:"sb",
    age:13,
    money:50,
    getAdd:function(){
        console.log(this.age+this.money);
    }
}
chusheng.getAdd();//调用对象函数