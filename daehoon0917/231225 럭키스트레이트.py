N = list(map(int, input()))
A = 0
B = 0
length = len(N)//2

for i in range(0,length):
    A += N[i]
for i in range(length, len(N)):
    B += N[i]

if A == B:
    print("LUCKY")
else:
    print("READY")