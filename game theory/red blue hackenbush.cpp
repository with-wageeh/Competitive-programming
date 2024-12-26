#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define wageh ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0)
#define loop(i, n) for (int i=0;i<int(n);i++)
#define rep(k, n) for (int k=1 ;k<= long long (n);k++)
#define ll long long
#define all(x) x.begin(),x.end()
#define vec  vector<ll>
#define stt stack<ll>
#define dqq deque<ll>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vecp  vector<pair<ll,ll>>
#define memo(v, d) memset(v, d , sizeof(v))
int fx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int fy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const double PI = 3.14159265359;
const int N = 5e5;
ll fast_pow_mod(ll base , ll power,ll mod ) {
    ll res=1;
    while (power>0){
        if (power&1)res=((res%mod)*(base%mod))%mod;
        base*=base;
        base%=mod;
        power/=2;
    }
    return res;
}
const int mod = 1e9 + 7;
ll add(ll x, ll a) {return ((a % mod) + (x % mod)) % mod;}
ll mul(ll a , ll b){ return ((a%mod) * (b % mod))%mod; }
ll sub(ll a , ll b){ return ((a%mod) - (b%mod) + mod) % mod; }
ll inv(ll a){return fast_pow_mod(a,mod - 1 - 1,mod);}
struct surreal {
    int val, w; // val=integer part
    map<int, int>frac; // fraction part
    void clear() {
        frac.clear();
        val = w = 0;
    }
    surreal() {
        clear();
    }
    void add(int x) {
        frac[x]++;
        auto it = frac.find(x);
        while (it != frac.end() && it->second != 1) {
            if (it->second > 1) {
                frac[it->first + 1] += it->second >> 1;
                it->second &= 1;
            }
            auto it1 = it;
            ++it;
            if (!it1->second) frac.erase(it1);
        }
    }
    // n=n/(1<<x)
    void divide(int x) {
        for (int i = 0; i < x; ++i) {
            if (!val) break;
            if (val & 1) add(i - w);
            val >>= 1;
        }
        w -= x;
    }
    inline void operator +=(surreal x) {
        val += x.val;
        for (auto it2 = x.frac.begin(); it2 != x.frac.end(); ++it2)
            if (it2->second) add(it2->first + x.w - w);
        while (!frac.empty() && frac.rbegin()->first + w >= 0) {
            if (frac.rbegin()->second) val += 1 << (frac.rbegin()->first + w);
            frac.erase(--frac.end());
        }
    }
    void solve0() {
        int p = max(1, 1 - val);
        if (frac.empty() && p + val == 1) ++p;
        val += p;
        divide(p - 1);
    }
    void solve1() {
        int p = max(1, 1 + val);
        if (val - p == -1) ++p;
        val -= p;
        divide(p - 1);
    }
} a[N];

int id[N], vis[N];
vector<pair<int, int> >g[N];
void dfs(int u) {
    vis[u] = 1;
    for (auto x : g[u]) {
        int v = x.first, c = x.second;
        if (vis[v]) continue;
        dfs(v);
        if (c == 0) a[id[v]].solve0();
        else a[id[v]].solve1();
        if (a[id[v]].frac.size() > a[id[u]].frac.size()) swap(id[v], id[u]);
        a[id[u]] += a[id[v]];
        a[id[v]].clear();
    }
}
int main() {
    wageh;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) id[i] = i, g[i].clear(), vis[i] = 0, a[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].emplace_back(v, c);
            g[v].emplace_back(u, c);
        }
        dfs(1);
        if (a[id[1]].val > 0) cout << "first_player";
        else cout << "second_player";


    }
}