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
const int mod = 998244353;
ll add(ll x, ll a) {return ((a % mod) + (x % mod)) % mod;}
ll mul(ll a , ll b){ return ((a%mod) * (b % mod))%mod; }
ll sub(ll a , ll b){ return ((a%mod) - (b%mod) + mod) % mod; }
ll inv(ll a){return fast_pow_mod(a,mod - 1 - 1,mod);}
vector<int> g[N];
int n, T, low[N], dis[N];
int dfs (int u, int pre = 0) {
    dis[u] = low[u] = ++T;
    int ans = 0;
    for (auto v : g[u]) {
        if (v == pre) {
            pre += 2 * n;
            continue;
        }
        if (dis[v] == 0) {
            int res = dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dis[u]){
                ans ^= (1 + res) ^ 1; /// bridge
            }

            else
                ans ^= res;           /// non bridge
        } else low[u] = min(low[u], dis[v]);
    }
    if (pre > n) pre -= 2 * n;
    for (auto v : g[u]) if (v != pre && dis[u] <= dis[v]) ans ^= 1;
    return ans;
}
int ground[N];///set 1 for the ground nodes
int main() {
    wageh;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    // cin >> t
    int t = 1;
    //scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) ground[i] = 0;
        int root = 1; ///if there are multiple ground nodes set any ground node as a root
        ground[root] = 1;
        int ans = 0;
        T = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (ground[u]) u = root;
            if (ground[v]) v = root;
            int dummy;
            if (u == v) ans ^= 1;
            else {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        ans ^= dfs(root);
        cout << ans << endl;
        if(ans) puts("Alice");
        else puts("Bob");
        for(int i = 1; i <= n; i++) g[i].clear(), low[i] = dis[i] = 0;
    }
}
