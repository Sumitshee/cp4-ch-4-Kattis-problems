
/*/ Author: Sumit8707 /*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define endl "\n"
#define ff first
#define ss second
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define sz(x) ((int)(x).size())
#define pb push_back
#define all(v) (v).begin(),(v).end()
 
 
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using moset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
void kick_start(int t) {cout << "Case #" << t << ": ";}

int dfs(vector<vector<int>>&matrix, vector<vector<bool>>&visited, int i, int j, int height, int n, int m){
   
   // dfs korar somoy jodi kono adjacent cell er height current height er theke besi hoi then flag = false; means can't grow rice there  so return 0; 
   bool flag = true;
   visited[i][j]=true; // mark the current cell as visited
   // cout<<matrix[i][j]<<" "<<i<<' '<<j<<endl;
   int currSize = 1;

   int dy[] = {0, 0, 1, -1};
   int dx[] = {1, -1, 0, 0};
    
   for(int k = 0; k< 4; k++){
       int nbrx = i + dx[k];
       int nbry = j + dy[k];
       if(nbrx>=0 and nbrx<n and nbry>=0 and nbry<m and matrix[nbrx][nbry] < height){
        flag = false;
       }
       else if(nbrx>=0 and nbrx<n and nbry>=0 and nbry<m and matrix[nbrx][nbry]==height and visited[nbrx][nbry]==false){
         int subComponentSize = dfs(matrix,visited,nbrx,nbry,height,n,m);
         if(subComponentSize==0){
            currSize=0;
            flag = false;
        }
         else
         currSize += subComponentSize;
       }
   }
   // if(!flag)cout<<0<<endl;
   // else
   // cout<<currSize<<endl;

   if(!flag)return 0;
   return currSize;

}
/*------------------------------------------------------------------------------------------------------------*/
void wrong_submission(){
    int n,m; cin>>m>>n;
    vector<vector<int>>matrix(n,vector<int>(m,0));//initially matrix ta ke 0 diye fill kore rakhlam
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(!visited[i][j]){
                int cell = matrix[i][j]; //storing the height of the land jar opor dfs korbo
                ans += dfs(matrix,visited,i,j,cell,n,m);
            }
        }
    }
    cout<<ans<<endl;

}
/*------------------------------------------------------------------------------------------------------------*/ 
int32_t main() {
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   // #endif

   auto start = std::chrono::high_resolution_clock::now();
 
     int t=1;
     // cin>> t;
      for(int i = 1; i <= t; i++){
           // kick_start(i);
           wrong_submission();
      }


   auto stop = std::chrono::high_resolution_clock::now(); 
   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

   // #ifndef ONLINE_JUDGE
   // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;    
   // #endif
   return 0;
}
