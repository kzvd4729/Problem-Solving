/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 15:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/690/problem/B1
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define SZ(a)   ((int)(a).size())
#define pb push_back
 int main(){
    int n;
    cin>>n;
    vector<string> a(n);for(int i=0;i<n;i++)cin>>a[i];
     int x0=-1,y0=0,x1 =- 1, y1 = n - 1;
    vector<vector<bool>> v(n);for(int i=0;i<n;i++)v[i].resize(n,0);
    for(int i=0;i<n and x0 == -1;i++){
        for(int j = 0; j < n  and x0 == -1; j++){
            if(a[i][j] == '4')x0 = i , y0 = j;
        }
    }
    if(x0==-1){
        cout<<"NO\n";
        return 0;
    }
    for(int i=n-1;i>=0 and x1 == -1;i--){
        for(int j = n-1; j >=0   and x1 == -1; j--){
            if(a[i][j] == '4')x1 = i , y1 = j;
        }
    }
      for(int i = x0;i<=x1;i++){
        for(int j=y0;j<=y1;j++){
            if(a[i][j] != '4'){
                cout<<"NO\n";
                return 0;
            }
            v[i][j] = 1;
        }
    }
     if(x0 - 1 >= 0 and y0-1 >=0  and a[x0-1][y0-1] != '1'){
        cout<<"NO\n";
        return 0;
     }else if(x0 - 1 >= 0 and y0-1 >=0 )v[x0-1][y0-1]=1;
    if(x0 - 1 >= 0 and y1+1 <n  and a[x0-1][y1+1] != '1'){
        cout<<"NO\n";
        return 0;
     }else if(x0 - 1 >= 0 and y1+1 <n)v[x0-1][y1+1]=1;
    if(x1 + 1 < n and y0-1 >=0  and a[x1+1][y0-1] != '1'){
        cout<<"NO\n";
        return 0;
     }else if(x1 + 1 < n and y0-1 >=0 )v[x1+1][y0-1] = 1;
    if(x1 + 1 < n and y1+1 < n  and a[x1+1][y1+1] != '1'){
        cout<<"NO\n";
        return 0;
     }else if(x1 + 1 < n and y1+1 < n)v[x1+1][y1+1] = 1;
     for(int i = y0 ; i <= y1 ; i++ ){
         if(x0 - 1>=0){
            if(a[x0-1][i]!='2'){
                cout<<"NO\n";
                return 0;
            }
            v[x0-1][i] = 1;
        }
        if(x1 + 1 < n){
            if(a[x1+1][i]!='2'){
                cout<<"NO\n";
                return 0;
            }
            v[x1+1][i] = 1;
        }
    }
    for(int i = x0 ; i <= x1 ; i++ ){
         if(y0 - 1>=0){
            if(a[i][y0-1]!='2'){
                cout<<"NO\n";
                return 0;
            }
            v[i][y0-1] = 1;
        }
        if(y1 + 1 < n){
            if(a[i][y1+1]!='2'){
                cout<<"NO\n";
                return 0;
            }
            v[i][y1+1] = 1;
        }
    }
     //cerr<<x0<<" "<<x1<<" "<<y0<<" "<<y1<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==0 and a[i][j]!='0'){
                    //cerr<<i<<" "<<j<<endl;
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}