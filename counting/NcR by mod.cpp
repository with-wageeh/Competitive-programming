int factorial[N + 1] , inverse[N + 1];
void func(){
    factorial[0] = 1;
    inverse[0] = 1;
    for (int i = 1; i <= N ; ++i) {
        factorial[i] = mul(factorial[i - 1] , i);
        inverse[i] = inv(factorial[i]);
    }
}
int NcR(int n , int r){
    return mul(factorial[n] , mul(inverse[r] , inverse[n - r]));
}