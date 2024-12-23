import sys

sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')

for _ in range(int(input())):
    start = input()
    target = input()

    def visualise(l,label):
        temp = 0
        s = []
        sums = []
        for c in l:
            if c=='R':
                s.append('1')
                temp+=1
            elif c =='L':
                s.append('-1')
                temp-=1
            else:
                s.append('0')
            sums.append(str(temp))
        
        print(label+":")
        print(' '.join(list(l)))
        print(' '.join(s))
        print(' '.join(sums))
        
    def canChange(start: str, target: str) -> bool:
        visualise(start,"start")
        visualise(target,"target")
        print()
        return False
    
    canChange(start,target)

    # n = len(start)
    #     blanks = 0
    #     i = j = 0
    #     while i < n and j < n:
    #         if start[i] == '_':
    #             blanks += 1
    #         if target[j] == '_':
    #             if blanks > 0:
    #                 blanks -= 1
    #                 j += 1
    #         if target[j] == start[i]:
                
    #         i += 1

    # def getval(c):
    #         if c == 'L':
    #             return -1
    #         if c == 'R':
    #             return 1
    #         return 0

    #     startsum = 0
    #     targetsum = 0
    #     s = []
    #     t = []
    #     for i in range(n):
    #         startsum += getval(start[i])
    #         targetsum += getval(target[i])
    #         s.append(startsum)
    #         t.append(targetsum)
    #     print(s)
    #     print(t)
        
    #     return False
            