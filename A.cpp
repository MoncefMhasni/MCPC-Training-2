#include<bits/stdc++.h>
int round(int d,int D){
    int k = d/D;
    if(k*D<d)k++;
    return k*D;
}
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int H,M,D,h,m;
        scanf("%d:%d %d %d:%d",&H,&M,&D,&h,&m);
        if(h<H)h+=24;
        int d = h*60+m-H*60-M;
        d = round(d,D);
        M+=d%60;
        d/=60;
        H=(H+d+M/60)%24;
        printf("%02d:%02d\n",H,M%60);
    }
}
