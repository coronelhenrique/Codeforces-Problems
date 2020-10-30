#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
 
struct node{
    node * l = nullptr, * r = nullptr;
    int sum = 0;
    node(int val) : sum(val) {};
    node(node * l, node * r) : l(l), r(r), sum(0){
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
 
node * build(int l, int r, int val){
    if (l == r) return new node(val);
    int m = (l + r) >> 1;
    return new node(build(l, m, val), build(m + 1, r, val));
}
 
node * update(node * no, int l, int r, int pos, int val){
    if (l == r) return new node(val);
    int m = (l + r) >> 1;
    if (pos <= m) return new node(update(no->l, l, m, pos, val), no->r);
    return new node(no->l, update(no->r, m + 1, r, pos, val));
}
 
node * cpy(node * a, node * b, int l, int r, int lq, int rq){
    if (l > rq || r < lq) return a;
    if (lq <= l && r <= rq) return b;
    int m = (l + r) >> 1;
    return new node(cpy(a->l, b->l, l, m, lq, rq), cpy(a->r, b->r, m + 1, r, lq, rq));
}
 
const int mxQ = 1e5 + 1;
node * v[mxQ], * rv[mxQ];
 
void solvetask(){
    int n, m, q; cin >> n >> m >> q;
    int mx = n * m;
    v[0] = build(1, mx, 0), rv[0] = build(1, mx, 1);
    
    int cur_v = 0;
    while (q--){
        int tp; cin >> tp;
        cur_v++;
        if (tp == 1){
            int i, j; cin >> i >> j;
            v[cur_v] = update(v[cur_v - 1], 1, mx, (i - 1) * m + j, 1);
            rv[cur_v] = update(rv[cur_v - 1], 1, mx, (i - 1) * m + j, 0);
        } else if (tp == 2){
            int i, j; cin >> i >> j;
            v[cur_v] = update(v[cur_v - 1], 1, mx, (i - 1) * m + j, 0);
            rv[cur_v] = update(rv[cur_v - 1], 1, mx, (i - 1) * m + j, 1);
        } else if (tp == 3){
            int i; cin >> i;
            v[cur_v] = cpy(v[cur_v - 1], rv[cur_v - 1], 1, mx, (i - 1) * m + 1, i * m);
            rv[cur_v] = cpy(rv[cur_v - 1], v[cur_v - 1], 1, mx, (i - 1) * m + 1, i * m);
        } else{
            int k; cin >> k;
            v[cur_v] = v[k];
            rv[cur_v] = rv[k];
        }
        cout << v[cur_v]->sum << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solvetask();
}