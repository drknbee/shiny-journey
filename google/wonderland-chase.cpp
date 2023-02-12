// https://codingcompetitions.withgoogle.com/codejam/round/000000000087762e/0000000000b9c499#analysis

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int dis[2][maxn];
vi eg[maxn];
int q[maxn];
int isleaf[maxn], deg[maxn];
int main()
{
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n, c, a[2];
        cin >> n >> c >> a[0] >> a[1];
        const int inf = 1e9;
        for (int i = 1; i <= n; i++) 
            eg[i].clear(), dis[0][i] = dis[1][i] = inf, isleaf[i] = 0;
        for (int i = 1; i <= c; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            eg[u].pb(v), eg[v].pb(u);
        } 
        for (int i = 0; i < 2; i++) {
            int fr = 0, ed = 0;
            q[ed++] = a[i]; dis[i][a[i]] = 0;
            while (fr < ed) {
                int cur = q[fr++];
                for (auto v : eg[cur]) {
                    if (chkmin(dis[i][v], dis[i][cur] + 1))
                        q[ed++] = v;
                }
            }
        }
        int fr = 0, ed = 0;
        for (int i = 1; i <= n; i++) {
            deg[i] = eg[i].size();
            if (deg[i] <= 1) q[ed++] = i;
        }
        while (fr < ed) {
            int cur = q[fr++];
            isleaf[cur] = 1;
            for (auto v : eg[cur]) {
                deg[v] -= 1;
                if (deg[v] == 1) q[ed++] = v;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (dis[0][i] < dis[1][i]) {
                chkmax(ans, 2 * dis[1][i]);
                if (!isleaf[i]) ans = 2e9;
            }
        printf("Case #%d: ", cs);
        if (ans > 1e9) printf("SAFE\n");
        else printf("%d\n", ans);
    }
    return 0;
}

// using chatgpt, compare time and space complexity of each code // answers