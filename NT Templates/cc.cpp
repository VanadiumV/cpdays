#include <iostream>
#include <unordered_set>

using namespace std;

int countUniquelyDecodableSubsequences(string s) {
    const int MOD = 1e9 + 7;
    int n = s.length();
    
    // Initialize arrays to store counts
    int dp[n + 1];
    int last[26];

    // Initialize last occurrence index of each character to -1
    fill(last, last + 26, -1);

    dp[0] = 1;

    // Dynamic Programming to count uniquely decodable subsequences
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;

        // If character has occurred before, subtract count of subsequences ending with its last occurrence
        if (last[s[i - 1] - 'a'] != -1)
            dp[i] = (dp[i] - dp[last[s[i - 1] - 'a'] - 1] + MOD) % MOD;

        // Update the last occurrence index of the character
        last[s[i - 1] - 'a'] = i;
    }

    // Subtract 1 to exclude the empty subsequence
    return (dp[n] - 1 + MOD) % MOD;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        int result = countUniquelyDecodableSubsequences(s);
        cout << result << endl;
    }

    return 0;
}
