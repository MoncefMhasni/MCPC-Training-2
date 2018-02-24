#include <bits/stdc++.h>
#define MAX 100001
#define pb push_back
using namespace std;
struct unionfind {
int p[MAX], r[MAX]; // r contains the population
unionfind() { for(int i=0;i<MAX;i++) p[i] = i, r[i] = 1; }
int find( int x ) { if( p[x] == x ) return x; else return p[x] = find( p[x] ); }
void Union(int x, int y) {
int px = find( x ), py = find( y );
if( px == py ) return; //already joined
if( r[ px ] < r[ py ] ) p[px] = py, r[py] += r[px];
else p[ py ] = px, r[px] += r[py];
}
};
int main(){
    ios::sync_with_stdio(false);
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        unionfind x;int cc=1;
        unordered_map<string,int> d;
        while(n--){
            string a,b;cin>>a>>b;
            if(d[a]==0)d[a]=cc++;
            if(d[b]==0)d[b]=cc++;
            x.Union(d[a],d[b]);
            cout<<x.r[x.find(d[a])]<<endl;

        }
    }

}
