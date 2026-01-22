# Minimum Pair Removal to Sort Array

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **Loại bài toán** | Custom / Practice |
| **Độ khó** | 🟡 Medium (Estimated) |
| **Chủ đề** | Array, Greedy, Simulation |
| **Link** | N/A |

## 📝 Đề bài

Given an array of integers `nums`. In one operation, you can:
1.  Choose any two adjacent elements `nums[i]` and `nums[i+1]`.
2.  Replace them with a single element equal to `nums[i] + nums[i+1]`.
    *Exceptions or specific logic might apply based on implementation details (e.g., removing min sum pairs).*
    *(Based on code analysis: Remove pairs based on specific logic until sorted)*

Find the minimum number of operations (or pairs removed/merged) required to make the array sorted in **non-decreasing order**.

### Ví dụ
```
Input: [1, 3, 2, 4, 5]
Output: 1
Explanation: Merge (3, 2) -> 5? Or remove pair? 
(Specifics depend on the exact custom problem definition)
```

## 💡 Ý tưởng giải thuật

### Greedy Simulation - O(n^2) worst case
Bài toán yêu cầu thực hiện các thao tác trên mảng cho đến khi mảng được sắp xếp tăng dần.
-   Kiểm tra mảng đã sắp xếp chưa. Nếu chưa:
    -   Duyệt qua các cặp phần tử liền kề.
    -   Tính tổng hoặc tìm cặp thỏa mãn điều kiện tối ưu (ví dụ: tổng nhỏ nhất).
    -   Thay thế/Xóa cặp phần tử đó và chèn giá trị mới.
    -   Tăng biến đếm thao tác.
-   Lặp lại cho đến khi mảng sắp xếp xong.

## 📊 Độ phức tạp

| Phương pháp | Thời gian | Không gian |
|-------------|-----------|------------|
| Simulation | O(K * N) | O(N) |

*(K là số bước lặp, N là kích thước mảng)*

## 🚀 Chạy thử

```bash
g++ main.cpp -o main && ./main
```
