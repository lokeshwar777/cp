import sys

# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')


MOD = 998244353

input = sys.stdin.read().split()
t = int(input[0])
y_values = list(map(int, input[1:]))

results = []
for Y in y_values:
    if Y % 4 != 0:
        results.append(0)
        continue

    memo = {}
    K = 25

    def dfs(k, c_prev, Y_remain):
        if Y_remain < 0:
            return 0
        if Y_remain == 0:
            return 1
        if k > K:
            return 0
        key = (k, c_prev, Y_remain)
        if key in memo:
            return memo[key]
        total = 0
        coin_value = 2 ** (k + 1)
        max_c_k = c_prev // 2
        for c_k in range(max_c_k + 1):
            s_k = c_k * coin_value
            total += dfs(k + 1, c_k, Y_remain - s_k)
            total %= MOD
        memo[key] = total
        return total

    total_ways = 0
    max_c1 = Y // 4
    for c1 in range(0, max_c1 + 1):
        s1 = c1 * 4
        Y_remain = Y - s1
        if Y_remain < 0:
            break
        total_ways += dfs(2, c1, Y_remain)
        total_ways %= MOD
    results.append(total_ways % MOD)

sys.stdout.write("\n".join(map(str, results)) + "\n")
