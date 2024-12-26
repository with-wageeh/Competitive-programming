// nCr = (n - 1)Cr + (n - 1)C(r - 1)
// nCr = n! / (r! * (n - r))!
// nCr = nC(n - r)
// nCr = ((double) n / k ) * (n - 1)C(r - 1)
//0Cr + 1Cr + 2Cr + 3Cr + ..... + nCr = (n + 1)C(r + 1)
//nC0 + nC1 + nC2 + nC3 + ..... + nCn = 2^n
//1 * nC1 + 2 * nC2 +3 * nC3 + ..... +n * nCn = n2^(n - 1)
//(nC0)^2 + (nC1)^2 + (nC2)^2 + (nC3)^2 + ..... + (nCn)^2 = 2nCn
//nC0 +(n - 1)C1 + (n - 2)C2 + (n-3)C3 + ..... + 0Cn = fibonacci[n + 1]
// sum from i to k (McR)(Nc(K-R)) = M + N c k
***********************************************************************
You are given two numbers n & k. Find the largest power of k (x) such that n! is divisible by (k ^ x).
the answer = (n / k) + (n / k^1) + (n / k^2) + ........ + (n / k^i) + ....
//the solution if k is prime
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k; // = (n / k) + (n / k^1) + (n / k^2) + ........ + (n / k^i) + ....
        res += n;
    }
    return res;
}
// if the k = a^x * b^y * c^z
// for each prime {a , b , c} calculate the values a[i] by the above code and the answer will be min for each i
// a[i] / power of prime i {x , y , z}
int factorial_power(int n,int k) {
    int res = inf;
    for (int j = 2; j * j <= k; j++) {
        if (k % j == 0) {
            res = min(res, fast_pow(n, j));
        }
        while(k % j == 0){
            k /= j;
        }
    }
    if(k != 1)res = min(res , fast_pow(n , k));
    return res;
}
// https://cp-algorithms.com/algebra/factorial-divisors.html
*****************************
int nCr(int n, int r) {
    double res = 1;
    for (int i = 1; i <= r; ++i)
        res = res * (n - r + i) / i;
    return (int)(res + 0.01);
}
inclusuion & exclusion
|A1 u A2 u A3| = |A1| + |A2| + |A3| - |A1 n A2| - |A1 n A3| - |A2 n A3| + |A1 n A2 n A3|.
        calculate how number of permination of size n so no (p_i = i)
ll func(int n){
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += pow(-1,i) * factorial[n] / factorial[i + 1];
    }
    return factorial[n] - res;
}
https://cp-algorithms.com/combinatorics/inclusion-exclusion.html
    *********************************************************
    stars and bars
The number of ways to put n identical objects into k labeled boxes is (n + k - 1)Cn || (n + k - 1)C(k - 1).
//Number of non-negative integer sums¶
x1 + x2 + x3 + xk = n -> xi >= 0
        answer will be (n + k - 1)Cn
// Number of lower-bound integer sums¶
but if xi >= ai so you must return it to original formula
        (x1` + a1) + (x2` + a2) + (x3` + a3) + (xk` + ak) = n
          x1` + x2` + x3` + xk` = n - (a1 + a2 + a3 + ak)
//Number of upper-bound integer sums¶
 0 <= xi <= z
 now u must use inclusion and exclusion
{A1 , A2 ,..., Ak} -> Ai = if we put xi  > z
        if k = 6
 so the problem will be -> all possible without restricted xi <= z so the answer (n + k - 1)C(k - 1)
 now using inclusion exclusion calculate |A1 u A2 u A3 u ... u A6| but take care you stop when i * z > n









