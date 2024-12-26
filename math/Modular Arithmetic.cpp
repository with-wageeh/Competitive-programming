// rules of divisibility

//(Divisibility Rule for Powers of Two)
//any integer is divisible by 2^n
//if and only if the integer formed by its last n digits is also divisible by 2^n
//For example, 124564
//is divisible by 4 because 64 is divisible by 4.)

//(Divisibility Rule for Nine)
//d1 + d2 + d3 + ..... dn (digits) is also divisible by 9


//Binary exponentiation
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
// OPERATIONS

ll add(ll x, ll a) {return ((a % mod) + (x % mod)) % mod;}
ll mul(ll a , ll b){ return ((a%mod) * (b % mod))%mod; }
ll sub(ll a , ll b){ return ((a%mod) - (b%mod) + mod) % mod; }
ll inv(ll x){return fast_pow_mod(x,mod-2,mod);}
// inv(x) % mod -> should x & mod be co primes
// inv(x) = x ^(phi(mod) - 1)
// if u take mod to the power you shouldn't take mod to this power it is not true
// (a ^ b) % mod != (a ^ (b % mod)) -> (2^4) % 3 != (2 ^ (4 % 3))
// but this is true (a ^ b) % mod = (a ^ (b % phi(mod)) % mod // if mod prime so phi = mod - 1
// a === b mod x -> (a - b) = (q * x)
// a === b mod x -> a^c === b^c mod x
// a === b -> (a ^ z) % x = (b ^ z) % x




