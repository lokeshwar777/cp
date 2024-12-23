# import sys

# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')

from collections import Counter 

for _ in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split()]

    s = Counter()
    a = b = 1
    for x in l:
        if (n-2)%x ==0  and (n-2)//x in s:
            a, b = x, (n-2)//x
            break
        s[x] += 1

    print(a, b)
    