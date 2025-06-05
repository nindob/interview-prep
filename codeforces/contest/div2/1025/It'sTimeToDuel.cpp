#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int vars = n - 1;              
        int N = 2 * vars;              
        vector<vector<int>> g(N), gr(N);
        auto add_imp = [&](int u, int v){
            g[u].push_back(v);
            gr[v].push_back(u);
        };
        auto var_id = [&](int idx, bool val){
            int i = idx - 1;
            return 2*i + (val ? 1 : 0);
        };
        auto add_unit = [&](int idx, bool val){
            int u = var_id(idx, !val);
            int v = var_id(idx, val);
            add_imp(u, v);
        };
        auto add_or = [&](int idx1, bool val1, int idx2, bool val2){
            int l1 = var_id(idx1, val1);
            int nl1 = var_id(idx1, !val1);
            int l2 = var_id(idx2, val2);
            int nl2 = var_id(idx2, !val2);
            add_imp(nl1, l2);
            add_imp(nl2, l1);
        };

        if (a[1] == 0) add_unit(1, false);
        if (a[n] == 0) add_unit(n-1, true);
        for (int i = 2; i <= n-1; i++){
            if (a[i] == 0) {
                add_unit(i-1, true);
                add_unit(i, false);
            }
        }

        if (a[1] == 1) add_unit(1, true);
        if (a[n] == 1) add_unit(n-1, false);
        for (int i = 2; i <= n-1; i++){
            if (a[i] == 1) {
                add_or(i, true, i-1, false);
            }
        }

        vector<bool> used(N,false);
        vector<int> order, comp(N,-1);

        function<void(int)> dfs1 = [&](int u){
            used[u] = true;
            for (int v: g[u]) if (!used[v]) dfs1(v);
            order.push_back(u);
        };
        for (int i = 0; i < N; i++){
            if (!used[i]) dfs1(i);
        }
        function<void(int,int)> dfs2 = [&](int u,int c){
            comp[u] = c;
            for (int v: gr[u]) if (comp[v] < 0) dfs2(v, c);
        };
        int cid = 0;
        for (int i = N-1; i >= 0; i--){
            int u = order[i];
            if (comp[u] < 0) dfs2(u, cid++);
        }

        bool ok = true;
        for (int i = 1; i <= vars; i++){
            int f = var_id(i, false), t = var_id(i, true);
            if (comp[f] == comp[t]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "NO\n" : "YES\n");  
    }
    return 0;
}
