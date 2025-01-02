import sys
from itertools import combinations
import math
from functools import reduce

sys.stdin = open("input.txt",'r')
sys.stdout = open("output.txt",'w')

def inclusion_exclusion(l,limit):
    n=len(l)
    indices=list(range(n))
    mycount = 0
    for k in range(1,n+1):
        combs = tuple(combinations(indices,k))
        for comb in combs:
            lcm_ele = reduce(math.lcm,[l[ind] for ind in comb])
            curr_count = limit//lcm_ele
            if k&1: # k is odd -> add them
                mycount += curr_count
            else: # k is even -> subtract
                mycount -= curr_count
    print(f"My count :",mycount)

    # sets = [set(range(x,limit+1,x)) for x in l]
    # union = set.union(*sets)
    # print(f"(Expected)Union count :",len(union))
    # print("Union set is:",union)

l=list(map(int,input().split()))
limit=int(input())
inclusion_exclusion(l,limit)

''' 
# without set and using lcm
def inclusion_exclusion(l,limit):
    n=len(l)
    # a list of no. of multiples of each element upto limit
    counts = [limit//x for x in l] 
    indices=list(range(n))
    mycount = 0
    for k in range(1,n+1):
        combs = tuple(combinations(indices,k))
        for comb in combs:
            lcm_ele = reduce(math.lcm,[l[ind] for ind in comb])
            curr_count = limit//lcm_ele
            if k&1: # k is odd -> add them
                mycount += curr_count
            else: # k is even -> subtract
                mycount -= curr_count
    # union = set.union(*sets)
    # print(f"(Expected)Union count :",len(union))
    print(f"My count :",mycount)

l=list(map(int,input().split()))
limit=int(input())
inclusion_exclusion(l,limit)
'''

''' 
# combination over indices
def inclusion_exclusion(l,limit):
    n=len(l)
    # sets is a list of all the set of multiples of each element in l
    sets = [set(range(x,limit+1,x)) for x in l]
    indices=list(range(n))
    mycount = 0
    for k in range(1,n+1):
        combs = tuple(combinations(indices,k))
        for comb in combs:
            comb_sets = tuple(sets[i] for i in comb)
            intersection = set.intersection(*comb_sets)
            # print(intersection)
            if k&1: # k is odd -> add them
                mycount += len(intersection)
            else: # k is even -> subtract
                mycount -= len(intersection)
    union = set.union(*sets)
    print(f"(Expected)Union count :",len(union))
    print(f"My count :",mycount)

l=list(map(int,input().split()))
limit=int(input())
inclusion_exclusion(l,limit)
'''

'''
# combination over sets
def inclusion_exclusion(l,limit):
    # sets is a list of all the set of multiples of each element in l
    sets = [set(range(x,limit+1,x)) for x in l]
    mycount = 0
    for k in range(1,len(l)+1):
        combs = tuple(combinations(sets,k))
        for comb in combs:
            intersection = set.intersection(*comb)
            # print(intersection)
            if k&1: # k is odd -> add them
                mycount += len(intersection)
            else: # k is even -> subtract
                mycount -= len(intersection)
    union = set.union(*sets)
    print(f"(Expected)Union count :",len(union))
    # print("Union set is:",union)
    print(f"My count :",mycount)

l=list(map(int,input().split()))
limit=int(input())
inclusion_exclusion(l,limit)
'''