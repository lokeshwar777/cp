from math import log2,log10

def countBits(n):return int(log2(n))+1

def countDigits(n):return int(log10(n))+1

 # f(i,x)= 2^i * (x+1)/(2^(i+1)) + max(0,(x+1)%(2^(i+1)) - 2^i)
# f(i,x)= ((2**i)*((x+1)//(2**(i+1)))) + max(0,((x+1)%(2**(i+1)))-2**i)
# consider (0 based), cycle starts at 0, 
# returns no. of set bits i->[0,..),x->[0,...)
def getSetBitsAtPos(self,i,x): return (2**i)*((x+1)//(2**(i+1))) + max(0,(x+1)%(2**(i+1))-(2**i))