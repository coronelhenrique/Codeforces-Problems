#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'
 
const int N = 5001, inf = 1e9;
vector<vector<int>> dp, aux; // aux[i][j] = menor posicao que a string s[i...j] aparece em s
string s;
int n, a, b;
 
vector<int> z_function(const string & t) {
    int n_ = t.length();
    vector<int> z(n_);
    for (int i = 1, l = 0, r = 0; i < n_; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n_ && t[z[i]] == t[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
 
int solve(int i, int sz){
    if (dp[i][sz] != -1) return dp[i][sz];
    if (i == n){
        if (sz == 1){
            return dp[i][sz] = 0;
            cout << i << endl;
        }
        return dp[i][sz] = inf;
    }
    dp[i][sz] = inf;
    if (aux[i - sz + 1][i] + sz - 1 <  i - sz + 1){
        dp[i][sz] = solve(i+1, 1) + b;
    }
    if (sz == 1){
        dp[i][sz] = min(dp[i][sz], solve(i+1, 1) + a);
    }
    dp[i][sz] = min(dp[i][sz], solve(i+1, sz+1));
    return dp[i][sz];
}
 
void solvetask(){
    cin >> n >> a >> b >> s;
    dp = vector<vector<int>>(n+1, vector<int>(n+2, -1));
    aux = vector<vector<int>>(n+1, vector<int>(n+1, n*n));
    for (int i=1; i<n; i++){
        vector<int> z = z_function(s.substr(i, n - i) + "#" + s.substr(0, i));
        vector<int> cur(n+2, n);
        for (int j=0; j < i; j++){
            cur[z[j + n - i + 1]] = min(cur[z[j + n - i + 1]], j);
        }
        for (int j=n - i; j>=0; j--) cur[j] = min(cur[j], cur[j+1]);
        for (int j=1; j <= n - i; j++){
            aux[i][i + j - 1] = min(aux[i][i + j - 1], cur[j]);
        }
    }
    cout << solve(0, 1) << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solvetask();
}