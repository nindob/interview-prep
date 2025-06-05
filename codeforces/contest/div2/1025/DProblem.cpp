#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
const int64_t NEG_INF = -1; 

vector<vector<int>> adj;
vector<int> dist1, parity;

void bfs(int n) {
    dist1.assign(n+1, -1);
    parity.assign(n+1, -1);
    queue<int> q;
    dist1[1] = 0;
    parity[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist1[v] == -1) {
                dist1[v] = dist1[u] + 1;
                parity[v] = dist1[v] & 1;
                q.push(v);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> A(l);
        for (int i = 0; i < l; i++) {
            cin >> A[i];
        }

        adj.assign(n+1, {});
        for (int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(n);

        bool is_bip = true;
        for (int u = 1; u <= n && is_bip; u++) {
            for (int v : adj[u]) {
                if (parity[v] == parity[u]) {
                    is_bip = false;
                    break;
                }
            }
        }

        int64_t M[2] = { NEG_INF, NEG_INF };
        if (l > 0) {
            for (int k : A) {
                int64_t old0 = M[0], old1 = M[1];
                if ((k & 1) == 0) {
                    M[0] = max<int64_t>(M[0], k);
                    if (old0 >= 0) M[0] = max<int64_t>(M[0], old0 + k);
                    if (old1 >= 0) M[1] = max<int64_t>(M[1], old1 + k);
                } else {
                    M[1] = max<int64_t>(M[1], k);
                    if (old0 >= 0) M[1] = max<int64_t>(M[1], old0 + k);
                    if (old1 >= 0) M[0] = max<int64_t>(M[0], old1 + k);
                }
            }
        }

        string ans;
        ans.reserve(n);
        for (int i = 1; i <= n; i++) {
            bool ok = false;
            if (i == 1 && dist1[i] == 0) {
                ok = true;
            } else if (l > 0 && dist1[i] >= 0) {
                int d = dist1[i];
                if (is_bip) {
                    if (M[d & 1] >= d) ok = true;
                } else {
                    int64_t Smax = max(M[0], M[1]);
                    if (Smax >= d) ok = true;
                }
            }
            ans.push_back(ok ? '1' : '0');
        }

        cout << ans << "\n";
    }
    return 0;
}