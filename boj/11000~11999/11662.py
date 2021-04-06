#first와 last의 거리가 오차범위 안에 들어올 때까지 이분탐색으로 근사값을 구해 나갑니다.
def dist(a, b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5

def midspot(a, b):
    return ((a[0]+b[0])/2, (a[1]+b[1])/2)

inp = input().split()
first1, last1, first2, last2 = [(int(inp[i*2]), int(inp[i*2+1])) for i in range(len(inp)//2)]
result = 99999

while dist(first1, last1)>0.000001:
    mid1 = midspot(first1, last1)
    mid2 = midspot(first2, last2)
    result = min(result, dist(mid1, mid2))

    if dist(midspot(first1, mid1), midspot(first2, mid2))<dist(midspot(mid1, last1), midspot(mid2, last2)):
        last1 = mid1
        last2 = mid2
    else:
        first1 = mid1
        first2 = mid2

print(result)
