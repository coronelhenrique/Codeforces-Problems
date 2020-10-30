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

int q, k;
ll dp[1010][1010][2];
vector<pair<string, string>> p;
int n;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b) {
    return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

bool check(string &s) {
    ll last = -INF;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '4' || s[i] == '7') {
            if(i-last <= k) return true;
            else {
                last = i;
            }
        }
    }
    return false;
}

ll solve(int i, int last, bool ok) {
    if(i == n) return ok;
    if(dp[i][last][ok] != -1) return dp[i][last][ok];
    ll resp = mul(2, solve(i+1, i, (last != n && i-last <= k) || ok));
    resp = add(resp, mul(8, solve(i+1, last, ok)));
    return dp[i][last][ok] = resp;
}

ll get(string &x) {
    int j = 0;
    while(x[j] == '0') j++;
    ll ans = 0;
    int last = n;
    bool ok = false;
    for(; j < n; j++) {
        for(char c = '0'; c < x[j]; c++) {
            if(c == '4' || c == '7') {
                ans = add(ans, solve(j+1, j, (last != n && j-last <= k) || ok));
            }else {
                ans = add(ans, solve(j+1, last, ok));
            }
        }
        if(x[j] == '4' || x[j] == '7'){
            if(last != n && j-last <= k) ok = true;
            last = j;
        }
    }
    if(check(x)) ans = add(ans, 1);
    return ans;
}

void solvetask() {
    cin >> q >> k;
    n = 1;
    for(int i = 0; i < q; i++) {
        string f, s;
        cin >> f >> s;
        p.PB(MP(f, s));
        n = max(n, (int) p[i].S.size());
    }

    for(int i = 0; i < q; i++) {
        int falta1 = n - p[i].F.size();
        int falta2 = n - p[i].S.size();
        string st1 = "";
        string st2 = "";
        for(int j = 0; j < falta1; j++) st1 += '0';
        st1 += p[i].F;
        for(int j = 0; j < falta2; j++) st2 += '0';
        st2 += p[i].S;

        p[i].F = st1;
        p[i].S = st2;
    }
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < q; i++) {
        ll qtd2 = get(p[i].S);
        ll qtd1 = get(p[i].F);
        ll ans = add(sub(qtd2, qtd1), check(p[i].F));
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;

    while(t--) solvetask();
}
