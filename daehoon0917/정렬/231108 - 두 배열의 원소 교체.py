'맞음'

"""
이 내용은 쉬운편
"""

N, K = map(int,input().split())

array1 = list(map(int,input().split()))

array2 = list(map(int,input().split()))

array1 = sorted(array1,reverse=False)
array2 = sorted(array2,reverse=True)

for k in range(K):
    array1[k], array2[k] = array2[k], array1[k]

result = 0

for l in range(N):
    result += array1[l]

print(result)