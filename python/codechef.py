import sys

sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')

for _ in range(int(input())):
    n,k = map(int, input().split())
    nums = list(map(int, input().split()))

    def solve(k):
        l = []
        used = [-1]*(n+1)
        for i,num in enumerate(nums):
            # if -k < num < k:
            #     used[i+1]=0
            #     continue
            l.append((num//k ,i+1))
            l.append(((num+k-1)//k,i+1))
        l.sort()
        left = 0
        right = len(l)-1
        temp = 0
        while left<right:
            leftval, leftind = l[left]
            if used[leftind] != -1:
                left+=1
                continue
            rightval, rightind = l[right]
            if used[rightind] != -1:
                right-=1
                continue
            if -leftval == rightval:
                used[leftind]=0
                used[rightind]=0
                left+=1
                right-=1
                continue
            if temp >= 0:
                temp+=leftval
                used[leftind]=0
                left +=1
            else:
                temp+=rightval
                used[rightind]=0
                right-=1
        # print(nums,k,l,temp)

        return temp == 0

    print("YES" if solve(k) else "NO")