#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int nC2(int n) {
    return (n * (n - 1)) / 2;
}

int nC3(int n) {
    return (n * (n - 1) * (n - 2)) / 6;
}

int nC1(int n) {
    return n;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }

    int ans = 0;

    for (auto x : m) {
        int c = x.second;
        int rem = n - c;
 ans +=nC3(c);
        // Assuming you want to use the computed values
        ans += nC2(c) * nC1(rem);

        // If you have a specific calculation to perform based on c and rem, add it here
        // For example: ans += c * rem;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
