# Longest Substring Without Repeating Characters

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **LeetCode #** | 3 |
| **Độ khó** | 🟡 Medium |
| **Chủ đề** | String, Sliding Window |
| **Link** | [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |

## 📝 Đề bài

Given a string `s`, find the length of the longest substring without repeating characters.

### Ví dụ
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

## 💡 Ý tưởng giải thuật

### Sliding Window Optimized - O(n) ✅
Sử dụng kỹ thuật **Cửa sổ trượt (Sliding Window)** kết hợp với mảng đánh dấu vị trí ký tự.
-   Sử dụng vector `charIndex` kích thước 128 (ASCII) để lưu vị trí xuất hiện gần nhất của từng ký tự.
-   Duyệt `right` từ đầu đến cuối chuỗi:
    -   Nếu ký tự `s[right]` đã xuất hiện trước đó (trong vùng cửa sổ hiện tại `[left, right]`), cập nhật `left` để "nhảy" qua vị trí trùng lặp: `left = charIndex[s[right]] + 1`.
    -   Cập nhật vị trí mới nhất của `s[right]`.
    -   Tính độ dài cửa sổ hiện tại `right - left + 1` và cập nhật kết quả tối đa.

## 📊 Độ phức tạp

| Phương pháp | Thời gian | Không gian |
|-------------|-----------|------------|
| Sliding Window | O(n) | O(min(m, n)) hoặc O(128) |

## 🚀 Chạy thử

```bash
g++ main.cpp -o main && ./main
```

**Output:**
```
Input: abcabcbb
Longest substring without repeating characters: 3
```
