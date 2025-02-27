import sys

sys.stdin = open('input.txt','r')
sys.stdout = open('output.txt','w+')

seen=set()
def generate_exact_swaps(l,swaps_left):
    if swaps_left==0:
        seen.add(''.join(l))
        return
    n=len(l) 
    for i in range(n):
        for j in range(i+1,n):
            l[i],l[j]=l[j],l[i]
            generate_exact_swaps(l,swaps_left-1)
            l[i],l[j]=l[j],l[i]

# preventing redundant swaps
'''
def generate_atmost_swaps(l,swaps_left,start_index=0):
    if swaps_left<0:return
    seen.add(''.join(l))
    n=len(l)
    for i in range(start_index,n):
        for j in range(i+1,n):
            if l[i]==l[j]:continue
            l[i],l[j]=l[j],l[i]
            generate_atmost_swaps(l,swaps_left-1,i+1)
            l[i],l[j]=l[j],l[i]
'''

def generate_atmost_swaps(l,swaps_left):
    if swaps_left<0:return
    seen.add(''.join(l))
    n=len(l)
    for i in range(n):
        for j in range(i+1,n):
            l[i],l[j]=l[j],l[i]
            generate_atmost_swaps(l,swaps_left-1)
            l[i],l[j]=l[j],l[i]

s=input()
swaps=int(input())
# recursive-only suitable for n<10
# generate_exact_swaps(list(s),swaps)
generate_atmost_swaps(list(s),swaps)
for x in seen:print(x)
