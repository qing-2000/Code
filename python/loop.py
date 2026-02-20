#闰年
from calendar import isleap
for i in range(100,1000):
    a,b,c = map(int,str(i))
    if(int(a**3+b**3+c**3) == i):
        print(i)
print(isleap(2026))

#随机整数列表
import random
alit=list()
for i in range(50):
    alit.append(random.randint(1,100))
print(alit)
for i in alit[:]:
    if i%2 != 0:
        alit.remove(i)
print(alit)

#100以内奇数和
a=1
sum=0
while a<100:
    sum+=a
    a+=2
print(sum)
ans=0
for i in range(1,100):
    if i%2 != 0:
        ans+=i
print(ans)