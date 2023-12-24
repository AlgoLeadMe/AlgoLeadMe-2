import sys
input = sys.stdin.readline

def ok(x,y,op):
    if(op == '<'):
        if(x > y):
            return False
    if(op == '>'):
        if(x < y):
            return False
    return True

def go(index, num):
    if (index == k+1):
        ans.append(num)
        return
    
    for i in range(10):
        if (check[i]):
            continue
        if (index == 0 or ok(num[index-1], str(i), sign[index-1])):
            check[i] = True
            go(index+1, num+str(i))
            check[i] = False


k = int(input())
sign = list(input().split())

check = [False for _ in range(10)]
num = ''
ans = []

go(0, num)

print(max(ans))
print(min(ans))