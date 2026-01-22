# Minimum Bitwise Array II

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **LeetCode #** | 3286 |
| **Độ khó** | 🟡 Medium |
| **Chủ đề** | Bit Manipulation, Math |
| **Link** | [LeetCode](https://leetcode.com/problems/minimum-bitwise-array-ii/) |

## 📝 Đề bài

Given an array `nums` of positive integers, return an array `ans` where `ans[i]` is the **minimum** non-negative integer such that `ans[i] | (ans[i] + 1) == nums[i]`. If no such integer exists, set `ans[i]` to `-1`.

### Ví dụ
```
Input: nums = [2, 3, 5, 7]
Output: [-1, 1, 4, 3]
Explanation:
- 2: No solution -> -1
- 3: 1 | 2 = 3 -> 1
- 5: 4 | 5 = 5 -> 4
- 7: 3 | 4 = 7 -> 3
```

## 💡 Ý tưởng giải thuật

### Bitwise Logic - Lowbit Pattern - O(1) per element ✅
Quan sát tính chất `x | (x + 1)`:
-   Phép toán này luôn biến bit 0 tận cùng bên phải đầu tiên (nếu có) thành 1.
-   Điều đó có nghĩa là `nums[i]` buộc phải có dạng các bit `...011...1`.
-   Nói cách khác, `nums[i]` phải có ít nhất một bit 0 sau dãy bit 1 liêp tiếp từ phải qua. (Hoặc đơn giản là, `nums[i]` tạo ra từ phép OR nên các bit của nó phải bao hàm `x` và `x+1`).

**Logic tìm ngược lại:**
-   Nếu `nums[i]` là số chẵn (`nums[i] % 2 == 0`), thì không tồn tại `x` vì `x | (x+1)` luôn luôn lẻ (trừ khi x=-1 không hợp lệ). -> Trả về `-1`. (Trường hợp 2 là ngoại lệ đầu vào? Code của bạn xử lý `nums[i] == 2` là continue/-1).
-   Nếu `nums[i]` lẻ:
    -   Ta cần tìm bit 0 đầu tiên từ phải sang trái của `nums[i]`.
    -   Công thức `x = nums[i] + 1`: Chuyển chuỗi bit 1 tận cùng thành 0 và bit 0 ngay trước đó thành 1.
    -   `lowbit = x & (-x)`: Tìm ra vị trí bit 1 thấp nhất của `x`, tương ứng với vị trí bit 0 ta cần tìm.
    -   Trừ đi một nửa `lowbit` chính là thao tác tắt bit 1 tại vị trí đó đi để tìm `ans` nhỏ nhất.

## 📊 Độ phức tạp

| Phương pháp | Thời gian | Không gian |
|-------------|-----------|------------|
| Bit Manipulation | O(n) | O(n) |

## 🚀 Chạy thử

```bash
g++ main.cpp -o main && ./main
```
