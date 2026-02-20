a=True
b=False
print(type(a))
print(type(b))

#所有非零的数字和非空的字符串、列表、元组等数据类型都被视为 True，只有 0、空字符串、空列表、空元组等被视为 False。
print(bool([]))
print(bool([2,3,4]))
print(bool(""))