.
int num [N];
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