"""
1          0
2        1   2
3      3   4   5
4    6  7   8   9
5  10 11  12  13  14


n = int(input())
triangle = []

for i in range(n):
    triangle.append(list(map(int,input().split())))

sum = 0

while(True):
    sum = sum + triangle[0]
    for i in range(n):

        if triangle[i+1] > triangle[i+2]:
            sum = sum + triangle[i+1]

        else:
            sum = sum + triangle[i+2]


"""

n = int(input())
triangle = []

for i in range(n):
    triangle.append(list(map(int,input().split())))

## 행
for i in range(1,n):
    ## 열
    for j in range(0,i+1):
        ## 첫번째 열
        if j == 0 :
            triangle[i][0] += triangle[i-1][0]
        ## 마지막 열
        elif j == i :
            triangle[i][j] += triangle[i-1][j-1]
        ## 밑에 두가지 중에서 큰 경우를 더하기
        else:
            triangle += max(triangle[i-1][j-1],triangle[i-1][j])

print(max(triangle[n-1]))  #최댓값 출력