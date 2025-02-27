def get_prev_greater_ele(nums):
    n=len(nums)
    prev_greater_ele=[0]*n
    stack=[]
    for i in range(n):
        num=nums[i]
        while stack and stack[-1]<=num:stack.pop() # use < or <= or > or >= based on problem
        if stack:prev_greater_ele[i]=stack[-1]
        stack.append(num)
    # print(prev_greater_ele, "prev_greater_ele")
    return prev_greater_ele
    # pge=get_prev_greater_ele(nums) # call this in solve

def get_next_greater_ele(nums):
    n=len(nums)
    next_greater_ele=[0]*n
    stack=[]
    for i in reversed(range(n)):
        num=nums[i]
        while stack and stack[-1]<num:stack.pop()  # use < or <= or > or >= based on problem
        if stack:next_greater_ele[i]=stack[-1]
        stack.append(num)
    # print(next_greater_ele, "next_greater_ele")
    return next_greater_ele
    # nge=get_next_greater_ele(nums) # call this in solve

def get_prev_max_ele(nums):
    n=len(nums)
    prev_max_ele=[0]*n
    prev_max=0
    for i in range(n):
        num=nums[i]
        prev_max_ele[i]=prev_max
        prev_max=max(prev_max,num)
    # print(prev_max_ele, "prev_max_ele")
    return prev_max_ele
    # nge=get_prev_max_ele(nums) # call this in solve

def get_next_max_ele(nums):
    n=len(nums)
    next_max_ele=[0]*n
    next_max=0
    for i in reversed(range(n)):
        num=nums[i]
        next_max_ele[i]=next_max
        next_max=max(next_max,num)
    # print(next_max_ele, "next_max_ele")
    return next_max_ele
    # nge=get_prev_max_ele(nums) # call this in solve
        
def solve(nums):
    print(nums)


def getLongestIncreasing(self,arr):
    n=len(arr)
    temp=[1]*n
    for i in range(1,n):
        if arr[i-1]<arr[i]:temp[i]=temp[i-1]+1
    return max(temp)