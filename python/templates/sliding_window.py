# for non-overlapping intervals
def slide(lst,k):
        lst.sort()
        n=len(lst)
        curr=ans=j=0
        def cost(x):return lst[x][2] if len(lst[x])>2 else 1
        for i in range(n):
            l,r=lst[i][0],lst[i][1]
            windowLen=l+k-1
            while j<n and lst[j][1]<=windowLen:
                curr+=cost(j)*(lst[j][1]-lst[j][0]+1)
                j+=1
            partial=max(0,windowLen-lst[j][0]+1)*cost(j) if j<n else 0
            ans=max(ans,curr+partial)
            curr-=(r-l+1)*cost(i)
        return ans
# slide(arr,k)
            
def reverseSlide(lst,k):
        lst.sort()
        n=len(lst)
        j=n-1
        curr=ans=0
        def cost(x):return lst[x][2] if len(lst[x])>2 else 1
        for i in reversed(range(n)):
            l,r=lst[i][0],lst[i][1]
            windowLen=r-k+1
            while j>=0 and windowLen<=lst[j][0]:
                curr+=cost(j)*(lst[j][1]-lst[j][0]+1)
                j-=1
            partial=max(0,lst[j][1]-windowLen+1)*cost(j) if j>=0 else 0
            ans=max(ans,curr+partial)
            curr-=(r-l+1)*cost(i)
        return ans
# reverseSlide(arr,k)

from typing import Counter
def sliding_window(l,k): # check at start
    n=len(l)
    if k==0:return
    k-=1 # as k-1 are already in the window
    freq=Counter(l[:k])
    for i in range(n-k):
        if i>0:
            freq[l[i-1]]-=1
            if freq[l[i-1]]==0:del freq[l[i-1]]
        freq[l[i+k]]+=1
        print(freq)
# sliding_window(arr,k)

# TODO : 
# def sliding_window(n,l,k): # window at end


'''
- Getting number of subarrays with atmost k distinct elements
1. We are going to add the subarrays with at most k distinct elements in th window ending at right
2. a single pass from left to right would suffice with left initialised with 0
3. move the left pointer whenever the distinct elements exceed k until we find a valid window

- Getting number of subarrays with exactly k distinct elements
1. f(k)-f(k-1) = (0->k) - (0->k-1)
'''
from collections import defaultdict
def subarraysWithAtmostK(arr,k):
    freq=defaultdict(int)
    cnt=left=0
    for right,num in enumerate(arr):
        freq[num]+=1
        while len(freq)>k:
            curr=arr[left]
            if freq[curr]==1:del freq[curr]
            else:freq[curr]-=1
            left+=1
        cnt+=right-left+1
        # print(left,right,freq)
    return cnt

def subarraysWithKDistinct(arr,k):
    n=len(arr)
    atmost_k=subarraysWithAtmostK(arr,k)
    # atmost_k_minus_one=subarraysWithAtmostK(arr,k-1) if k>1 else 0 # good practice
    atmost_k_minus_one=subarraysWithAtmostK(arr,k-1)
    return atmost_k-atmost_k_minus_one