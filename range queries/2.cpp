#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    bool flag=true;
	     for(int i=0;i<n;i++){
	         if(a[i]<=4)flag=false;
	}
	if(flag==true)cout<<"YES"<<endl;
	else cout<< "NO"<<endl;
	return 0;

}