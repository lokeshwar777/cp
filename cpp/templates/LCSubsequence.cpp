#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n1, n2;
string a, b, lcs;
vector<vector<int>> dp;

int topDown(int i,int j) {
    if (i == n1 || j == n2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (a[i] == b[j]) ? (1 + topDown(i + 1, j + 1)) : max(topDown(i + 1, j), topDown(i, j + 1));
}

void printLCS(int i, int j) {
    if (i == n1 || j == n2) return;
    if (topDown(i, j) == topDown(i + 1, j)) {
        printLCS(i + 1, j);
    } else if (topDown(i, j) == topDown(i, j + 1)) {
        printLCS(i, j + 1);
    } else {
        lcs += a[i];
        printLCS(i + 1, j + 1);
    }
}

void solve() {
    cin >> a >> b;
    n1 = a.size(); n2 = b.size();
    dp.resize(n1, vector<int>(n2, -1));
    topDown(0, 0);
    printLCS(0, 0);
    cout << lcs;
}


signed main() {
    FAST_IO
    solve();
    return 0;
}
