// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c4766e

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
    int tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        long long l, n;
        cin >> l >> n;
        long long ans = 0;
        long long now = 0;
        char last = 'A';
        for (int i = 0; i < n; i++) {
            long long d;
            char c;
            cin >> d >> c;
            if (now == 0) {
                last = c;
            }
            if (c == 'C') {
                now += d;
                if (now >= l) {
                    if (last != c) {
                        last = c;
                        ans--;
                    }
                    ans += now / l;
                    now %= l;
                }
            } else {
                now = (l - now) % l;
                now += d;
                if (now >= l) {
                    if (last != c) {
                        last = c;
                        ans--;
                    }
                    ans += now / l;
                    now %= l;
                }
                now = (l - now) % l;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}