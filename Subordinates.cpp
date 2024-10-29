#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

string doOperation(int times, string &s)
{
    string curr;
    curr.push_back(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
 
        while (curr.size() && curr.back() > s[i] && times)
        {
            times--;
            curr.pop_back();
        }
        curr.push_back(s[i]);
    }
 
    while (times)
    {
        times--;
        curr.pop_back();
    }
    return curr;
}
 
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int pos;
    cin >> pos;
    int curr = n;
    int times = 0;
    while (true)
    {
        if (curr >= pos)
        {
            break;
        }
        times++;
        pos -= curr;
        curr--;
    }
    s = doOperation(times, s);
    cout << s[pos - 1];
    // cout << times << endl;
}
 

int32_t
main()
{
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    /* stuff you should look for
     * int overflow, array bounds
     * special cases (n==1?)
     * do smth instead of nothing and stay organized
     * WRITE STUFF DOWN
     * DON'T GET STUCK ON ONE APPROACH
     * IF STUCK ON A QUESTION, MOVE TO THE NEXT ONE
     */
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}


