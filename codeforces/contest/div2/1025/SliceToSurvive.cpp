#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto ceil_log2 = [&](ll x){
        int L = 0;
        ll p = 1;
        while (p < x){
            p <<= 1;
            ++L;
        }
        return L;
    };

    int T;
    cin >> T;
    while (T--){
        ll n, m, a, b;
        cin >> n >> m >> a >> b;

        int rowCuts = ceil_log2(n);
        int colCuts = ceil_log2(m);

        ll up = min(a, n - a + 1);
        ll left = min(b, m - b + 1);

        int rCuts = ceil_log2(up);
        int cCuts = ceil_log2(left);

        ll ans = 1 + min<ll>( rCuts + colCuts,
                              rowCuts + cCuts );

        cout << ans << "\n";
    }
    return 0;
}
