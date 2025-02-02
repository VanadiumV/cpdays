#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
# define  endl \n;
int main()
{
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(NULL);cout.tie(NULL);
    int n,t,k;
    cin>>n>>t>>k;
    int l=1,r=n;
    
    while(l<r)
    {
        m=(l+r)/2;
        cout<<"? 1 "<<m<<"\n";
        cout.flush();
        int x;
        cin>>x;
        x=m-x;
        if(x<k) l=m+1;
        
        else r=m;
        }
    cout<<"! "<<l<<"\n";
cout.flush();


    return 0;
}
