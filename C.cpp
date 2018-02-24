#include<bits/stdc++.h>
using namespace std;
int encode(int i){
    int ans = 0;
    for(;i;i/=2)ans = (ans<<1) + i%2;
    return ans;
}
int main(){
    int tc;cin>>tc;
    map<int,int> m;
    for(int i=1;i<1024;i+=2)
        m[encode(i)]=i+1;
    while(tc--){
        int u;cin>>u;
        cout<<m[u]-1<<endl;
    }
}