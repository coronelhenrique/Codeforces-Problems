
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007
//#define DEBUG

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine e(seed);
std::mt19937 rng((int) seed);

vi g[100010];
int n;

vector<int> Centroid() {
        vector<int> centroid;
        vector<int> sz(n+1);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (int i = 0; i < g[u].size(); i++)  {
                    auto v = g[u][i];
                    if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                    }
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(1, -1);
        return centroid;
}

vi cent;

int find_leef(int v, int p) {
    if(v == cent[1]) return -1;
    if(g[v].size() == 1) return v;
    for(int u : g[v]) {
        if(u == p) continue;
        int l = find_leef(u, v);
        if(l != -1) return l;
    }
    return -1;
}

void solvetask() {
    cin >> n;
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    cent = Centroid();
    if(cent.size() == 1) {
        cout << g[1][0] << " 1\n";
        cout << g[1][0] << " 1\n";
    }else {
        int x = find_leef(cent[0], cent[0]);
        cout << x << " " << g[x][0] << endl;
        cout << x << " " << cent[1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;
    cin >> t;

    while(t--) solvetask();
}
