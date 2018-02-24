#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
const int MAX  =10001;
using namespace std;
struct unionfind {
int p[MAX], r[MAX],sz; // r contains the population
unionfind() { for(int i=0;i<MAX;i++) p[i] = i, r[i] = 1; }
int find( int x ) { if( p[x] == x ) return x; else return p[x] = find( p[x] ); }
void Union(int x, int y) {
int px = find( x ), py = find( y );
if( px == py ) return; //already joined
sz--;
if( r[ px ] < r[ py ] ) p[px] = py, r[py] += r[px];
else p[ py ] = px, r[px] += r[py];
}
};
int main(){
    ios::sync_with_stdio(false);
    unionfind u;
    int N,M;cin>>N>>M;
    vector<pii> adj;
    unordered_map<int,unordered_map<int,int>> m;
    while(M--){
        int x,y;cin>>x>>y;
        x--;y--;
        adj.pb(mp(x,y));
        m[x][y] = m[y][x] = 1;
    }
    int Q;cin>>Q;
    stack<pair<int,int>> s;
    stack<int>ans;
    while(Q--){
        int x,y;cin>>x>>y;
        x--;y--;
        s.push(mp(x,y));
        m[x][y] = m[y][x] = 0;
    }
    u.sz = N;
    for(auto e:adj)if(m[e.f][e.s])u.Union(e.f,e.s);
    while(!s.empty()){
        auto e  = s.top();s.pop();
        ans.push(u.sz);
        u.Union(e.f,e.s);
    }
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}