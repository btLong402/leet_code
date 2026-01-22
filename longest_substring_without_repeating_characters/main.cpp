#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLength = 0;
    int left = 0;
    vector<int> charIndex(128, -1);

    for (int right = 0; right < n; right++) {
      if (charIndex[s[right]] >= left) {
        left = charIndex[s[right]] + 1;
      }
      charIndex[s[right]] = right;
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};

int main() {
  Solution sol;

  // Test cases
  vector<string> test_cases = {"abcabcbb", "bbbbb", "pwwkew", "", " "};

  for (auto &s : test_cases) {
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Input: " << s << endl;
    cout << "Longest substring without repeating characters: " << result << endl;
    cout << "------------------------\n";
  }

  return 0;
}