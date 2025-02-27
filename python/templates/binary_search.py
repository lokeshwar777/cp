def bs(arr,val):
    low,high=0,len(arr)-1
    while low<=high:
        mid=low+((high-low)>>1)
        if val==arr[mid]:return mid
        if val>arr[mid]:low=mid+1
        else:high=mid-1
    return -1
# res=bs(nums,target)

def bsOnAns(arr,low,high,k,ans):
    def check(val): # minimise sample
        cnt=0
        for x in arr:
            cnt+=(x+val-1)//val
            if cnt>k:return False
        return True

    # def check(val): # maximise sample
    #     rem=k
    #     cnt=0
    #     for x in arr:
    #         temp=min(rem,x)
    #         x-=temp
    #         rem-=temp
    #         cnt+=x==0
    #         if cnt>=val:return True
    #     return False

    while low<=high:
        mid=low+((high-low)>>1)
        if check(mid):
            ans=mid
            high=mid-1 # minimise
            # low=mid+1 # maximise
        else:
            low=mid+1 # minimise
            # high=mid-1 # maximise
    return ans
# bsOnAns(nums,lowerlimit,upperlimit,kvalue,defaultanswer)


# use this for getting value at a specific position in a sorted array
# usecases: kth element,median,mode,multiples,...
def bsOnAns(arr,low,high,k,ans):
        # print(f"low:{low}, high:{high}, pos:{k}")
        def check(val): # minimise sample
            cnt=0
            # print(f":{val},:{cnt}")
            return cnt>=k

        while low<=high:
            mid=low+((high-low)>>1)
            if check(mid): # valid found so update answer
                ans=mid
                high=mid-1 # look for less possible candidate
            else:
                low=mid+1
        return ans