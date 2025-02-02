#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxB = 0;
        int currB = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                currB++;
            } else {
                maxB = max(maxB, currB);
                currB = 0;
            }
        }

        maxB = max(maxB, currB);

        cout << maxB << endl;
    }

    return 0;
}