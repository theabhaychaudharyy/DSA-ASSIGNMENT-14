#include <iostream>
#include <vector>

using namespace std;

int num_unique_bsts(int n) {
    if (n <= 1)
        return 1;

    vector<int> catalan(n + 1, 0);
    catalan[0] = 1;
    catalan[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main() {
    int n = 3;
    int result = num_unique_bsts(n);
    cout << "Number of structurally unique BSTs with " << n << " nodes: " << result << endl;
    return 0;
}
