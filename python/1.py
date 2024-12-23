import sys
 
sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')
 
'''
1 2
1 1 2 2
4 5 5 1 1 2 2 3
1 8 2 2 1 3 3 9 1 1

'''

from collections import Counter
for _ in range(int(input())):
    n = int(input())
    # n,k = list(map(int,input().split()))
    l = list(map(int,input().split()))
    # print(n)
    # print(n,k)
    s = set(l)
    nn = len(s)
    counter = Counter()
    ans = [l[0]]
    counter[l[0]]+=1
    temp=[1]
    for i in range(1,n):
        num = l[i]
        req = max((i+1)//nn,1)
        temp.append(req)
        # print(num,i+1,req)
        if counter[num]<req:
            ans.append(num)
            counter[num]+=1
            continue        
        inserted = False
        for x in s:
            if counter[x]<counter[num]:
                ans.append(x)
                counter[x]+=1
                inserted=True
                break
        if not inserted:
            ans.append(num)
            counter[num]+=1
    print(l)
    print(temp)
    # print(' '.join([str(x) for x in ans]))

