import sys

sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')


def solve(n,l,s):
    dp = {}
    def helper(word, mask):
        if (word,mask) in dp:
            return dp[(word,mask)]
        
        maxi = 0
        for j in range(n):
            if (mask & (1<<j)) == 0:
                f_ind = word.find(l[j])
                if f_ind != -1:
                    new_mask = mask | (1<<j)
                    new_word = word[:f_ind]+word[f_ind+len(l[j]):]
                    # print(l[j],f_ind, word, new_word )
                    maxi = max(maxi, 1+helper(new_word,new_mask))
        
        dp[(word,mask)] = maxi
        return maxi
    
    res = helper(s,0)
    print(res)

n = int(input())
l = input().split()
s = input()
solve(n,l,s)