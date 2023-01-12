https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47792e

#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), vis(n + 1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<int> szs(n + 1);
    vector<int> b;
    int mx = 0;
    for(int i=1;i<=n;++i) {
        if(!vis[i]) {
            int cnt = 0;
            int cur = i;
            while(!vis[cur]) {
                ++cnt;
                vis[cur] = 1;
                cur = a[cur];
            }
            szs[cnt] += 1;
            amax(mx, cnt);
        }
    }
    // debug(szs);
    vector<int> dp(n + 1, 1e8);
    dp[0] = 0;

    vector<int> tmp(n + 1, 1e9);

    for(int i=1;i<=n;++i) {
        if(szs[i] == 0) {
            continue;
        }
        for(int j=0;j<i;++j) {
            deque<int> dq;
            for(int k=0;;++k) {
                if(j + k * i > n) {
                    break;
                }
                debug(i,j,j+k*i);
                while(!dq.empty() and dp[j + k * i] - k < dp[j + i * dq.back()] - dq.back()) {
                    dq.pop_back();
                }
                dq.push_back(k);
                while(!dq.empty() and dq.front() < k - szs[i]) {
                    dq.pop_front();
                }
                // assert(!dq.empty());
                // debug(dq.front());
                // debug(dq);
                tmp[j + k * i] = dp[j + i * dq.front()] - dq.front() + k;
            }
        }
        for(int j=0;j<i;++j) {
            for(int k=0;;++k) {
                if(j + k * i > n) {
                    break;
                }
                dp[j + k * i] = tmp[j + k * i];
            }
        }
        // debug(i,dp);
    }

    auto dp2 = dp;
    for(int i=n-1;i>=0;--i) {
        dp2[i] = min(dp2[i], dp2[i + 1]);
    }
    // debug(dp);

    for(int i=1;i<=n;++i) {
        if(szs[i]) {
            cout << "0 ";
        }
        else {
            cout << min(dp[i] - 1, dp2[i]) << " ";
        }
    }
    cout << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    for(int i=1;i<=TESTS;++i) {
        cout << "Case #" << i << ": ";
        _runtimeTerror_();
    }
    return 0;
}