Ncr mod p^x
fac[n] * inv(fac[r]) * inv(fac[n - r])
now you can get inv x if and only if gcd(x , mod) = 1
now if (p > max(r , n - r)) you can get inv because p doesnot appear in fac[r] or fac[n - r].
else now you canot get the inv so assume that g[x] = x! / p^c[x]
c[x] -> is the maximum power to p in x!
g[x] -> is the x! without any p .
gcd(g[x] , p) always equal 1 .
nCr = !n / (!r * !(n - r)) --- !n = g[n] * p^c[n] , !r = g[r] * p^c[r] , !(n-r) = g[(n-r)] * p^c[(n-r)]
nCr = g[n] * p^c[n] / (g[r] * p^c[r] * g[(n-r)] * p^c[(n-r)]) .
nCr = (g[n] / g[r] * g[n - r]) * p ^(c[n] - c[r] - c[n - r]) . {
    let z = (c[n] - c[r] - c[n - r])
}if (z >= x) the NcR = 0 ,because p^z % p^x = 0
else now you can get inv to g[r] & g[n - r] because gcd(g[i],p) = 1 .
        // code
const int N = 1e6;
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

int p , x , mod , res , g[N + 1] , c[N + 1] ,inverse[N + 1];
ll add(ll x, ll a) {return ((a % mod) + (x % mod)) % mod;}
ll mul(ll a , ll b){ return ((a%mod) * (b % mod))%mod; }
ll sub(ll a , ll b){ return ((a%mod) - (b%mod) + mod) % mod; }
ll inv(ll a){return fast_pow_mod(a,res - 1,mod);}
void func(){
    g[0] = 1;
    for (int i = 1; i <= N ; ++i) {
        int num = i , cnt = 0;
        while (num % p == 0) cnt ++ , num /= p;
        c[i] = c[i - 1] + cnt;
        g[i] = mul(g[i - 1] , num);
    }
    inverse[0] = 1;
    for (int i = 1; i <= N ; ++i) {
        inverse[i] = inv(g[i]);
    }
}
int NcR(int n , int r){
    int z = c[n] - c[r] - c[n -r];
    if(z >= x)return 0;
    else return mul(fast_pow_mod(p , z , mod) , mul(g[n] , mul(inverse[r] , inverse[n - r])));

}
int phi(int n) {// O(sqrt n)
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void init(){
    cin >> p >> x;
    mod = pow(p , x);
    res = phi(mod);
    func();
}
