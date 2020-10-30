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


vi kmp(string txt){
    vi k(txt.size()+7, 0);
	int i = 0, j = -1;
	k[0] = -1;
	while(i < txt.size()){
		while(j >= 0 && txt[i] != txt[j]) j = k[j];
		i++; j++;
		k[i] = j;
	}
    return k;
}

void solvetask() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    int ans = 0;
    while(m--) {
        string x;
        cin >> x;
        if(x.size() == 1) continue;
        string pref = x + '#' + s;
        reverse(x.begin(), x.end());
        reverse(s.begin(), s.end());
        string suf = x + '#' + s;
        reverse(x.begin(), x.end());
        reverse(s.begin(), s.end());

        vi kp = kmp(pref);
        vi ks = kmp(suf);
        for(int i = 2+x.size()+1; i < 2+x.size()+s.size(); i++)
            ks[i] = max(ks[i], ks[i-1]);
        int melhor = kp[2+x.size()];
        for(int i = 2+x.size(); i < 2+x.size()+s.size(); i++) {
            melhor = max(melhor, kp[i]);
            if(melhor + ks[2*x.size()+s.size()-i+2] >= x.size()) {
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    int t = 1;

    while(t--) solvetask();
}
