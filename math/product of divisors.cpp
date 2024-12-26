// assume that product of divisors of (x) = delta[x]
// delta[x] = x ^ (number of divisors x) / 2
int num[N + 1]; // number of divisors
void number_of_divisors(){
    num[1]=1;
    for (int i = 2; i*i <=N ; ++i) {
        if(num[i]==0){
            for (int j = i; j <=N ; j+=i) {
                int power=0;
                int temp=j;
                while(temp%i==0){

                    power++;
                    temp/=i;
                }
                if (num[j])num[j]*=(power+1);
                else num[j]=(power+1);
            }
        }
    }
}
int delta[N] ; // product of divisors
void product_of_divisors(){
    for (int i = 0; i < N; ++i) {
        delta[i] = pow(i , num[i] / 2);
        if(num[i] & 1) delta[i] = sqrt(i);
    }
}
// another way
// product[i] = (product[i - 1] ^ (x[i] + 1)) * (prime[i] ^ (x[i] * x[i] + 1) / 2) ^ num[i - 1];
// product[i] -> the product of divisors until prime_i
// x[i] -> the power of prime[i]
// num[i] -> the number of divisors until prime_i
int product[N] , prime[N] , x[N] , num[N];
void calc(int n ){
    product[0] = num[0] = 1;
    for (int i = 1; i <= n ; ++i) {
        num[i] = ((num[i - 1] % (mod - 1)) * ((x[i] + 1) % (mod - 1))) % (mod - 1);
        product[i] = mul(fast_pow_mod(product[i - 1] , add(x[i] , 1) ,mod) ,
        fast_pow_mod(fast_pow_mod(prime[i], 1LL * x[i] * (x[i] + 1) / 2, mod ),num[i - 1],mod));
}
    cout <<product[n] << endl;
}

