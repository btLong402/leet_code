# Two Sum

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **LeetCode #** | 1 |
| **Độ khó** | 🟢 Easy |
| **Chủ đề** | Array, Hash Table |
| **Link** | [LeetCode](https://leetcode.com/problems/two-sum/) |

## 📝 Đề bài

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

### Ví dụ
```
Input: nums = [3, 2, 4], target = 6
Output: [1, 2]
Giải thích: nums[1] + nums[2] = 2 + 4 = 6
```

## 💡 Ý tưởng giải thuật

### Cách 1: Brute Force - O(n²)
Duyệt qua tất cả các cặp phần tử và kiểm tra tổng.

### Cách 2: Hash Table - O(n) ✅
Sử dụng `unordered_map` để lưu trữ giá trị và chỉ số đã duyệt qua.
- Với mỗi phần tử `nums[i]`, tính `complement = target - nums[i]`
- Kiểm tra xem `complement` đã tồn tại trong map chưa
- Nếu có → trả về kết quả
- Nếu không → thêm `nums[i]` vào map

## 📊 Độ phức tạp

| Phương pháp | Thời gian | Không gian |
|-------------|-----------|------------|
| Brute Force | O(n²) | O(1) |
| Hash Table | O(n) | O(n) |

## 🚀 Chạy thử

```bash
g++ two_sum.cpp -o main && ./main
```

**Output:**
```
Result: [1, 2]
```
