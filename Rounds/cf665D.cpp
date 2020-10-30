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

ll n;
int m;
ll p[60010];
vi adj[100010];
ll subt[100010];
vll freq;

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

void clear() {
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        subt[i] = 0;
    }
    freq.clear();
}

void dfs(int u, int p) {
    subt[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        freq.PB(subt[v] * (n - subt[v]));
        subt[u] += subt[v];
    }
}

void solvetask() {
    clear();
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 1);
    sort(freq.rbegin(), freq.rend());
    cin >> m;
    for(int i = 0; i < m; i++) cin >> p[i];
    sort(p, p + m);
    while(m > n-1) {
        p[m-2] = mul(p[m-2], p[m-1]);
        m--;
    }
    reverse(p, p + m);
    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(i >= m) {
            ans = add(ans, freq[i]);
        }else {
            ans = add(ans, mul(freq[i], p[i]));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;
    cin >> t;

    while(t--) solvetask();
}
