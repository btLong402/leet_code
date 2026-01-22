#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  bool checkIsNonDecreasing(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        return false;
      }
    }
    return true;
  }

  int minimumPairRemoval(vector<int> &nums) {
    int time = 0;

    while (!checkIsNonDecreasing(nums)) {
      int numsSize = nums.size();
      int minVal = INT_MAX;
      int minIndex = -1;
      
      for (int i = 0; i < numsSize - 1; i++) {
        int sum = nums[i] + nums[i + 1];
        if (sum < minVal) {
          minVal = sum;
          minIndex = i;
        }
      }

      nums[minIndex] = minVal;
      nums.erase(nums.begin() + minIndex + 1);
      time++;
    }

    return time;
  }
};

int main() {
  Solution sol;

  // Test cases
  vector<vector<int>> test_cases = {{1, 2, 3, 4, 5},
                                    {5, 4, 3, 2, 1},
                                    {1, 3, 2, 4, 5},
                                    {1, 2, 1, 3, 1, 4, 1, 5},
                                    {3, 1, 4, 1, 5, 9, 2, 6}};

  for (auto &nums : test_cases) {
    int result = sol.minimumPairRemoval(nums);
    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i) {
      cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    cout << "Minimum pairs to remove: " << result << endl;
    cout << "------------------------\n";
  }

  return 0;
}