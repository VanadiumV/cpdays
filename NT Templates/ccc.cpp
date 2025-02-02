#include <iostream>
#include <unordered_set>
using namespace std;

// // Function to count unique subsequences for a given string
// int countUniqueSubsequences(string s) {
//     const int MOD = 1e9 + 7;
//     int n = s.size();
//     int dp[n + 1];
//     dp[0] = 1;

//     unordered_map<char, int> lastOccurrence;

//     for (int i = 1; i <= n; i++) {
//         dp[i] = (2 * dp[i - 1]) % MOD;

//         if (lastOccurrence.find(s[i - 1]) != lastOccurrence.end()) {
//             dp[i] = (dp[i] - dp[lastOccurrence[s[i - 1]] - 1] + MOD) % MOD;
//         }

//         lastOccurrence[s[i - 1]] = i;
//     }

//     return dp[n];
// }

// int main() {
//     int T;
//     cin >> T;

//     for (int t = 0; t < T; t++) {
//         string s;
//         cin >> s;

//         int result = countUniqueSubsequences(s);
//         cout << result << endl;
//     }

//     return 0;
// }


long long countUniqueSubsequences(string s) {
    const int MOD = 1e9 + 7;
    int n = s.length();
    unordered_set<string> uniqueSubsequences;

    for (int i = 0; i < n; i++) {
        string subsequence = "";
        for (int j = i; j < n; j++) {
            subsequence += s[j];
            uniqueSubsequences.insert(subsequence);
        }
    }

    return uniqueSubsequences.size() % MOD;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        long long result = countUniqueSubsequences(s);
        cout << result << endl;
    }

    return 0;
}

