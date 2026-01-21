#include <iostream>
#include <vector>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums) {
  vector<int> result(nums.size(), -1);

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 2)
      continue;
    else if (nums[i] == 3)
      result[i] = 1;
    else if (nums[i] == 1)
      result[i] = 0;
    else {
      int x = nums[i] + 1;
      int power_of_2 = x & (-x);
      result[i] = nums[i] - (power_of_2 >> 1);
    }
  }

  return result;
}

int main() {
  vector<int> nums = {2, 3, 5, 7};
  vector<int> result = minBitwiseArray(nums);
  cout << "Result: ";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}