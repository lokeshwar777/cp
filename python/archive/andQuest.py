import sys

sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')


from itertools import combinations

def sub(arr):
    return [list(combinations(arr, r)) for r in range(len(arr) + 1)]

for _ in range(int(input())):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))
    
    h1, h2 = l[:n//2], l[n//2:]
    s1, s2 = sub(h1), sub(h2)
    # print(s2)

    m2 = {}
    for ss in s2:
        print(ss)
        v = ss[0] if ss else -1
        print(v)
        for x in ss[1:]:
            v &= x
        if v not in m2:
            m2[v] = []
        m2[v].append(ss)

    f = False
    
    for ss1 in s1:
        v = ss1[0] if ss1 else -1
        for x in ss1[1:]:
            v &= x

        if v == k:
            print("YES")
            print(len(ss1))
            print(" ".join(str(i+1) for i in range(len(ss1))))
            f = True
            break

        c = k & v
        if c in m2:
            for ss2 in m2[c]:
                res = ss1 + ss2
                r = res[0]
                for x in res[1:]:
                    r &= x
                if r == k:
                    print("YES")
                    ans = [i+1 for i in range(len(ss1))] + [i+1 for i in range(len(ss2))]
                    print(len(ans))
                    print(" ".join(map(str, ans)))
                    f = True
                    break
        if f:
            break

    if not f:
        print("NO")
