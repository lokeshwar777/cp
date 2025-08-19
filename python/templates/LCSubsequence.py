n1, n2 = [int(x) for x in input().split()]
s1 = input()
s2 = input()

'''
dp = [[-1]*n2 for _ in range(n1)]
def topDown(i1, i2):
    if i1 == n1 or i2 == n2: return 0
    if dp[i1][i2] != -1: return dp[i1][i2]
    dp[i1][i2] = (1 + topDown(i1 + 1, i2 + 1)) if s1[i1] == s2[i2] else max(topDown(i1 + 1, i2), topDown(i1, i2 + 1))
    return ans
lcs_length = topDown(0, 0)
print(lcs_length)
rowhead = list(s2)
dp.insert(0,rowhead)
for x in zip(' ' + s1, dp):print(x)
'''

dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]


def bottomUp():

    for i1 in range(n1 - 1, -1, -1):
        for i2 in range(n2 - 1, -1, -1):
            dp[i1][i2] = (
                1 + dp[i1 + 1][i2 + 1]) if s1[i1] == s2[i2] else max(dp[i1 + 1][i2], dp[i1][i2 + 1])

    # visualise
    '''
    rowhead = list(s2 + ' ')
    dp.insert(0,rowhead)
    for x in zip(' ' + s1 + ' ', dp):print(x)
    '''

    res = []
    i = j = 0
    while i < n1 and j < n2:
        if s1[i] == s2[j]:
            res.append(s1[i])
            i += 1
            j += 1
        elif dp[i + 1][j] > dp[i][j + 1]:
            i += 1
        else:
            j += 1

    lcs = ''.join(res)
    lcs_length = dp[0][0]
    print(f"LCSubsequence is {lcs} and its length is {lcs_length}")


bottomUp()
