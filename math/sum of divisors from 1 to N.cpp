ll fast_pow_mod(ll base , ll power, ll mod ) {
    ll res=1;
    while (power>0){
        if (power&1)res=((res%mod)*(base%mod))%mod;
        base*=base;
        base%=mod;
        power/=2;
    }
    return res;
}
const int mod = 1e9+7;
int add(ll x, ll a) {return ((a % mod) + (x % mod)) % mod;}
ll mul(ll a , ll b){ return ((a%mod) * (b % mod))%mod; }
int sub(ll a , ll b){ return ((a%mod) - (b%mod) + mod) % mod; }
ll inv(ll x){return fast_pow_mod(x,mod-2,mod);}
int y = inv(2);
int sum(int st , int end){
    return sub( mul(end , end + 1) * y ,  mul(st , st + 1) * y );
}
int main() {
        ll n ;
        cin >> n ;
        ll x = 1;
        int ans = 0;
        while (x <= n){
            ll g = n / x;
            ll l = x , r = n , end = x;
            while (l <= r){
                ll mid = (l + r) / 2;
                if(n / mid == g) l = mid + 1, end = mid;
                else r = mid - 1;
            }
            ans = add(mul(sum((x - 1) % mod , end % mod) ,  g) , ans);
            x = end + 1;
        }
        cout << ans ;
    }
}
