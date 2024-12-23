# import sys

# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')

for _ in range(int(input())):
    n, k = map(int, input().split())
    prices = list(map(int, input().split()))
    prices.sort()
    prefix = []
    for x in prices:
        prefix.append(x + (prefix[-1] if prefix else 0))
    result = []
    for i in range(n):
        curr = prefix[i]
        pointer = i-1
        while pointer >=k-1:
            curr -= prices[pointer]
            pointer -= k+1
        result.append(curr)
        
    print(" ".join(map(str, result)))
