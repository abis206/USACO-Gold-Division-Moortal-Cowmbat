#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define S second
#define F first
#define MEM(i, j) memset(i, j, sizeof(i))
using namespace std;
const int MAXN = 100005;
typedef long long ll;
int n, m, k;
string s;
int dp[100005][27];
int a[27][27];
int pre[100005][27];
int seg[100005][27];
int segment(int l, int r, int c){
    int ret = 0;
    for(int i=0;i<m;i++){
        int num = pre[r][i];
        if(l != 0)
            num -= pre[l-1][i];
//        if(l == 0 && r == 1 && c == 0){
//            cout<<num<<endl;
//        }
        ret += a[i][c] * num;
    }
    return ret;
}
int DP(int x, int c){
    if(x == n){
        return 0;
    }
    int &ret = dp[x][c];
    if(ret != -1)
        return ret;
    int cur = s[x] - 'a';
    ret = DP(x+1, c) + a[cur][c];
    if((x+k) <= n){
        for(int i=0;i<m;i++){
            ret = min(ret, DP(x+k, i) + seg[x][i]);
//            if(x == 2 && c == 1){
//                cout<<"SSSS "<<DP(x+k, i)<<" "<<seg[x][i]<<" "<<i<<endl;
//            }
        }
    }
    return ret;
}
int main(){
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    MEM(dp, -1);
    cin>>n>>m>>k>>s;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int z=0;z<m;z++){
            for(int j=0;j<m;j++){
                a[z][j] = min(a[z][j], a[z][i] + a[i][j]);
            }
        }
    }
//    cout<<"----------------\n";
//    for(int i=0;i<m;i++){
//        for(int j=0;j<m;j++){
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    pre[0][s[0]-'a'] = 1;
    for(int i=1;i<n;i++){
        pre[i][s[i]-'a'] = 1;
        for(int j=0;j<m;j++){
            pre[i][j] += pre[i-1][j];
        }
    }
//    cout<<"---------------\n";
    for(int i=0;i<=n-k;i++){
        for(int j=0;j<m;j++){
            seg[i][j] = segment(i, i+k-1, j);
//            cout<<seg[i][j]<<" ";
        }
//        cout<<endl;
    }
    int ans = 1e9;
    for(int i=0;i<m;i++){
//        cout<<seg[0][i]<<" "<<DP(k, i)<<endl;
        ans = min(ans, DP(k, i) + seg[0][i]);
    }
    cout<<ans;
    return 0;
}

