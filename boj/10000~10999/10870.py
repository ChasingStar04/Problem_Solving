#앞 두 수를 더하는 기초적인 DP입니다.
n = int(input())
list1 = [0, 1]
for i in range(n-1):
    list1.append(list1[-1]+list1[-2])
print(list1[n])
