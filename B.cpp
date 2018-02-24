#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
vector<int> c;
double calc(double x){
    double ans=c[0];
    for(int i=1;i<c.size();i++)
        ans+=c[i]*pow(x,i);
    return ans;
}
double solve(double a,double b){
    double x= 2*b;
    double mid = (a+b)/2;
    while( fabs(x-mid)>eps || fabs(calc(mid))>eps ){
            x= mid;
            if(calc(x)*calc(a)>=0)
                a=x;
            else b=x;
            mid=(a+b)/2;

    }
    return mid;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int N;cin>>N;
        c.clear();c.resize(N+1);
        for(int i=0;i<=N;i++)cin>>c[i];
        double a,b;cin>>a>>b;
        cout.precision(6);
        cout<<fixed<<solve(a,b)<<endl;
    }
}
