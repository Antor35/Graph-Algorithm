#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

vii g[123456];
int vis[12345];
void dfs(int u){
    vis[u]=1;
    for(int i = 0; i<g[u].size(); i++){
        ii v = g[u][i];
        if(vis[v.first]==0){
            dfs(v.first);
        }
    }
}
void printfln(int n){
    printf("+");
    for(int i = 0; i< 2*n -1; i++)printf("-");
    printf("+\n");
}

int main(){
    int t,n,one;
    cin >> t;
    for(int cas=1; cas<=t; cas++){
        cin >> n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> one;
                if(one==1){
                    g[i].push_back(make_pair(j,0));
                }
            }
        }
        bool ans[1005][1005];
        memset(ans,false,sizeof(ans));
        ans[0][0]=true;
        for(int node=1; node<n; node++){
            ans[0][node]=true;
            memset(vis,0,sizeof(vis));
            vis[node]=1;
            dfs(0);
            for(int i = 0; i<n; i++){
                if(vis[i]==0){
                    ans[node][i]=true;
                }
            }
            ans[node][node]=true;
        }
        memset(vis,0,sizeof(vis));
        dfs(0);
        printf("Case %d:\n",cas);
        printfln(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(ans[i][j] and vis[j]==1){
                    cout << "|Y";
                }else{
                    cout << "|N";
                }
            }
            printf("|\n");
            printfln(n);
        }
    }

return 0;
}
