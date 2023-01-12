// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47e79

#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int n = 1e5 + 10;
    const int inf = 1e9;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        int c = 4;
        for (int j = i + i; j < n; j += i) {
            c += 2;
            dp[j] = min(dp[j], dp[i] + c);
        }
    }
    int tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        int l;
        cin >> l;
        cout << dp[l] << '\n';
    }
    return 0;
}