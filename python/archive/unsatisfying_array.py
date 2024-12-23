import sys

sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')

for _ in range(int(input())):
    n,k = map(int, input().split())
    l = []
    prefix = [n]*(n+1)
    possible = True
    for _ in range(k):
        left,right,m = map(int, input().split())

        if prefix[left-1] == n:
            prefix[left-1] = m+1
        else:
            prefix[left-1] = max(prefix[left-1], m+1)
        if prefix[right] == n:
            prefix[right] = m+1
        else:
            prefix[right] = max(prefix[right], m+1)

        l.append((left-1,right-1,m))
        if m == n:
            possible = False
    
    if not possible:
        print(-1)
        continue

    print(l)

    # res = [n]*n
    # # print(res)

    # not_found = True


    # if not_found:
    #     print("-1")