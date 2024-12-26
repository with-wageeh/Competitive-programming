int n ;
cin >> n;
int a[n];
loop(i,n) cin >> a[i];
vector<int>mxlen(n + 2 , 2e9),par(n+2,-1),best(n + 2 , -1);
mxlen[0] = -2e9;
int ans = 1;
for (int i = 0; i < n; ++i) {
auto it = std::lower_bound(mxlen.begin(), mxlen.end(),a[i]) - mxlen.begin();
// cout << i << " " << a[i] << " " << it << endl;
mxlen[it] = a[i];
best[it] = i;
par[i] = best[it - 1];
cout << i + 1 << " " << a[i] << " "
<< it << " " << par[i] +1 << endl;
ans = max(ans , (int)it);
}
cout << ans << endl;
// construct
cout << "LIS = ";
set<int>s;
int x = best[ans];
while (par[x] != -1){
s.insert(a[x]);
x = par[x];
}
s.insert(a[x]);
for(auto &it : s) cout << it << " ";