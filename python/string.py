#从左往右，从0开始（0，1，2，3，4，5，6，7，8）；
#从前面截取（ ：2345 ：）
#从右往左，从-1开始（-1，-2，-3，-4，-5，-6，-7，-8，-9）
#从后面截取（ ：-5，-4，-3，-2，-1，：）
str="123456789"

#打印整个字符串
print(str)

#打印第一个到倒数第二个
print(str[0:-1])

#打印第3个到第5个
print(str[2:5])

#开始位置1，终止位置5，步长2
print(str[1:5:2])

#第二个到最后一个
print(str[1:])

#打印2遍
print(str *2)

#\+n换行
print("123\n456")

#加上r取消转义
print(r"123\n456")

# ”+“ 拼接两个字符串
print(str+"test")

#字符串去重
s="This is is the desk"
tmp=list(s.split(" "))
result=[]
for i in tmp[:]:
    if i not in result:
        result.append(i)
out=" ".join(result)
print(out)
print(result)
#输出指定长度单词（3）
words=[]
for i in result[:]:
    if len(i) == 3 :
        words.append(i)
output=" ".join(words)
print(output)