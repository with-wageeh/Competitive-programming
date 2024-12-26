#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define wageh ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0)
#define loop(i, n) for (int i=0;i<int(n);i++)
#define rep(k, n) for (int k=1 ;k<= long long (n);k++)
#define ll long long
#define all(x) x.begin(),x.end()
void comp(vector<int>&v , int n , int a[] , map<int,int>&pos){
    sort(all(v));
    v.erase(unique(all(v)) , v.end());
    for (int i = 0; i < v.size(); ++i) {
        pos[v[i]] = i + 1;
    }
}
struct segtree{
    int n ;
    vec tree;
    segtree(int x){
        n = 1;
        while (n <= x) n *= 2;
        tree.resize(n * 2 + 5);
    }
    ll merge (ll l , ll r ){
        return max(l,r);
    }
    void update(int ind , ll val){
        update(1 , 0 , n - 1  , ind , val);
    }
    void update(int node ,int l ,int r , int ind , ll val){
        if(ind > r || ind < l) return;
        if(ind == l && l == r) {
            tree[node] = val;
            return;
        }
        int mid = ( l + r) / 2;
        update(node * 2 , l , mid , ind , val);
        update(node * 2  + 1, mid + 1 , r , ind , val);
        tree[node]  = merge(tree[node * 2] , tree[node * 2 + 1]);
    }
    ll get (int l , int r){
        return get(1 , 0 , n - 1 , l , r);
    }
    ll get(int node , int cur_l , int cur_r , int l , int r){
        if(cur_r < l ||  cur_l > r)return -2e9;
        if(cur_r <= r && cur_l >= l)return tree[node];
        int mid = (cur_l + cur_r) / 2;
        return merge(get(node * 2 , cur_l , mid , l , r ) , get (node * 2 + 1 , mid + 1 , cur_r , l , r));
    }
};
signed main() {
    wageh;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        int a[n];
        map<int,int>pos;
        loop(i, n) cin >> a[i] , v[i] = a[i];
        comp(v,n,a,pos);
        int sz = v.size();
        segtree seg(sz);
        for (int i = 0; i < n ; ++i) {
            int mx = seg.get(0 , pos[a[i]] - 1);
            seg.update(pos[a[i]] , mx + 1);
        }
        cout << seg.get(0 , v.size());

    }
}