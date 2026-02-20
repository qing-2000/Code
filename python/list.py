#listName=['a',   'b',   'c',   'd']
##########（0）-->（1）-->（2）-->（3）##                     从左往右
##########(-4)<--(-3)<--(-2)<--——(-1)##                     从右往左

#list反转字符串（顺序）实例
#输入abd c为两个字符串，反转结果为c adb

def reverseString(input):
    temp=input.split(" ")
    temp=temp[-1::-1]
    out=" ".join(temp)
    return out
if __name__ == "__main__":
    ans=reverseString(input("输入要反转的字符串"))
    print(ans)
