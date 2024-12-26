.// prime or not

bool prime(int n){
    bool tmam=1;
    if(n==0||n==1)tmam=0;
    else if(n==2||n==3)tmam=1;
    else
    {int f= sqrt(n);
        for (int i = 2; i <=f ; ++i) {
            if (n%i==0)tmam=0;
        }
    }
    return tmam;
}
// sieve
ll fr_prime[N];
void prime_sieve(){fr_prime[1]=1;
    for (ll i = 2; i*i <N ; ++i) {
        if (!fr_prime[i]){
            for (ll j = i*i; j < N ; j+=i) {
                fr_prime[j]=1;
            }
        }
    }
}
