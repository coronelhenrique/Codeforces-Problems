#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'
 
vector<int> prefix_function(const string & s){
    int n = s.size();
    vector<int> p(n);
    for (int i=1; i<n; i++){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
 
const int N = 8001, inf = 1e8;
 
// dp[i][j] = resposta
int n;
string s;
vector<vector<int>> dp, aux;
 
int digits(int x){
    if (x < 10) return 1;
    if (x < 100) return 2;
    if (x < 1000) return 3;
    return 4;
}
 
int solve(int j, int sz){
    if (dp[j][sz] != -1) return dp[j][sz];
    if (j == n){
        if (sz > 1) return dp[j][sz] = inf;
        return dp[j][sz] = 0;
    }
    int i = j - sz + 1;
    return dp[j][sz] = min(solve(j+1, sz+1), solve(j+1, 1) + digits((j - i + 1) / aux[i][j]) + aux[i][j]);
}
 
void solvetask(){
    cin >> s;
    n = s.size();
    dp  = vector<vector<int>>(n+1, vector<int>(n+2, -1));
    aux = vector<vector<int>>(n, vector<int>(n));
    for (int i=0; i<n; i++){
        vector<int> p = prefix_function(s.substr(i, n - i));
        for (int j=0; j<p.size(); j++){
            if ((j+1) % (j + 1 - p[j]) == 0){
                aux[i][i + j] = j + 1 - p[j];
            } else{
                aux[i][i + j] = j + 1;
            }
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