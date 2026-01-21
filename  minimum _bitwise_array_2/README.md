# Minimum Bitwise Array II

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **LeetCode #** | 3315 |
| **Độ khó** | 🟡 Medium |
| **Chủ đề** | Bit Manipulation |
| **Link** | [LeetCode](https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/) |

## 📝 Đề bài

You are given an array `nums` consisting of `n` prime numbers.

You need to construct an array `ans` of length `n`, such that for each index `i`, `ans[i] OR (ans[i] + 1) == nums[i]`.

Return the resulting array. If no valid `ans[i]` exists, set `ans[i] = -1`.

### Ví dụ
```
Input: nums = [2, 3, 5, 7]
Output: [-1, 1, 4, 3]
Giải thích:
- 2: Không có ans[i] thỏa mãn → -1
- 3: 1 OR 2 = 3 ✓
- 5: 4 OR 5 = 5 ✓
- 7: 3 OR 4 = 7 ✓
```

## 💡 Ý tưởng giải thuật

### Kỹ thuật: Lowbit (x & -x)

Biểu thức `x & (-x)` trả về **bit 1 thấp nhất (Lowest Set Bit)** của số `x`.

### Phân tích
- Nếu `nums[i] = 2`: Không có lời giải → trả về `-1`
- Nếu `nums[i] = 3`: Trả về `1` (vì 1 OR 2 = 3)
- Với các số khác:
  ```cpp
  int x = nums[i] + 1;
  int power_of_2 = x & (-x);        // Tìm bit 1 thấp nhất
  result[i] = nums[i] - (power_of_2 >> 1);
  ```

### Ví dụ chi tiết với nums[i] = 7
```
x = 7 + 1 = 8 (binary: 1000)
x & (-x) = 8 (chính nó, vì là lũy thừa của 2)
power_of_2 >> 1 = 4
result = 7 - 4 = 3

Kiểm tra: 3 OR 4 = 011 OR 100 = 111 = 7 ✓
```

## 📊 Độ phức tạp

| Độ phức tạp | Giá trị |
|-------------|---------|
| **Thời gian** | O(n) |
| **Không gian** | O(n) |

## 🚀 Chạy thử

```bash
g++ main.cpp -o main && ./main
```

**Output:**
```
Result: -1 1 4 3
```

## 📚 Bài học rút ra

- **Lowbit trick** (`x & -x`): Kỹ thuật quan trọng trong Bit Manipulation
- Hiểu về **Two's Complement** (bù 2) giúp nắm vững cách hoạt động của số âm trong máy tính
- Phân tích pattern của `x OR (x+1)` để tìm ra công thức ngược
