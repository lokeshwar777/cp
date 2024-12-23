import sys

sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')

for _ in range(int(input())):
    n,m = map(int, input().split())
    s= input()
    t = input()

    def solve(i,j):
        global n,m
        if i == n and j == m:
            return True
        if i == n or j == m:
            return False
        
        res = False
        if s[i] == t[j]:
            res = res or solve(i+1,j+1) # match
        if i != 0 and i <= n-3 and s[i]==s[i+1] and s[i-1]!=s[i+2]:
            res = res or solve(i+2,j) # delete

        return res

    print("YES" if solve(0,0) else "NO")

    '''
        i = j = 0
        while i < n and j < m:
            if s[i]==t[j]:
                i +=1
                j+=1
                continue
            if i == 0 or i > n-3 or s[i]!=s[i+1] or s[i-1]==s[i+2]:
                return False
            i += 2
    '''