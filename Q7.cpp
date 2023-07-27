#include <iostream>
#include <vector>

const int MOD = 1000000007;

int numWays(std::vector<int>& nums, int left, int right) {
    if (left >= right)
        return 1;

    int root = nums[left];
    int mid = left + 1;

    while (mid <= right && nums[mid] < root)
        mid++;

    int leftCount = numWays(nums, left + 1, mid - 1);
    int rightCount = numWays(nums, mid, right);

    // Calculate the number of ways to choose left and right subtrees.
    long long ways = 1;
    for (int i = 1; i <= right - left; i++)
        ways = (ways * i) % MOD;

    long long inverse = 1;
    for (int i = 1; i <= mid - left - 1; i++)
        inverse = (inverse * i) % MOD;

    inverse = pow(inverse, MOD - 2, MOD); // Calculate modular inverse.

    ways = (ways * inverse) % MOD;

    return (leftCount * rightCount % MOD) * ways % MOD;
}

int numWays(std::vector<int>& nums) {
    return numWays(nums, 0, nums.size() - 1);
}

int main() {
    // Example usage:
    std::vector<int> nums = {2, 1, 3};

    int result = numWays(nums);
    std::cout << "Output: " << result << std::endl; // Output: 1

    return 0;
}
