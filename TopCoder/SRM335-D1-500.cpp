#include <iostream>
#include<iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;
//   <<>>

/**
* For each cell, find all the cells such that you can go from the first one to this one in a minute or less using DFS.
* Now you have an undirected unweighted(all weights are 1) graph of 50*50 nodes.
* Use BFS to find the shortest distance between start and end.
*/

ll dx[4]={0,1,0,-1} , dy[4]={1,0,-1,0};
ll g[51][51][51][51];
ll vis[51][51];
ll n,m;
ll ci,cj;

bool good(ll x,ll y){
    if(x<=0 || y<=0) return 0;
    if(x>n || y>m) return 0;
    return 1;
}

ld f(char ch){
    ld x=ch-'0';
    return 1/x;
}

void dfs(vector<string>&mm,ll i,ll j,ll pi,ll pj,ld cost){
    if(cost > (ld)1) return;
    if(ci!=i || cj!=j) g[ci][cj][i][j]=1;

    FOR(a,0,3)
        if((i+dx[a]!=pi || j+dy[a]!=pj) && good(i+dx[a],j+dy[a]))
            dfs(mm,i+dx[a],j+dy[a],i,j,cost+f(mm[i+dx[a]-1][j+dy[a]-1]));
}

class ExpensiveTravel{
    public: int minTime(vector <string> mm, int startRow, int startCol, int endRow, int endCol){
        n=mm.size() , m=mm[0].size();
        ll sx=startRow , sy=startCol;
        ll tx=endRow , ty=endCol;

        FOR(i,1,n) FOR(j,1,m) ci=i , cj=j , dfs(mm,i,j,i,j,f(mm[i-1][j-1]));

        queue<pair<ll,pair<ll,ll> > >q;
        q.push(mp(0,mp(sx,sy)));
        vis[sx][sy]=1;
        while(!q.empty()){
            ll ux=q.front().second.first , uy=q.front().second.second , d=q.front().first;
            q.pop();

            if(ux==tx && uy==ty) return d;

            FOR(vx,1,n) FOR(vy,1,m) if(!vis[vx][vy] && g[ux][uy][vx][vy]){
                vis[vx][vy] = 1;
                q.push(mp(d+1,mp(vx,vy)));
            }
        }

        return -1;
    };
};
