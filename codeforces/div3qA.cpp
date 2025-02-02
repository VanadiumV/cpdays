#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            m[x]++;
        }
        auto it= m.begin();
        int last=it->first;
        int ans= it->second;
        it++;
        for(;it!=m.end(); it++) {
            it(it->first !=(last+1)){
                ans+=it->second;
            }else{
                ans +=max(0,it->second - lastCount);
            }
            last = it->first;
            lastCount = it->second;
        }
        //1.5hrs then easily expert 100solved prtoblems 
        cout<<ans<<"\n";
    }
    return 0;
}