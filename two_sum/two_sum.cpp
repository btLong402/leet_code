#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> result;
  unordered_map<int, int> map;

  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (map.find(complement) != map.end() && map[complement] != i) {
      result.push_back(i);
      result.push_back(map[complement]);
      break;
    }
    map[nums[i]] = i;
  }

  return result;
}

int main() {

  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> result = twoSum(nums, target);
  cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;

  return 0;
}