# Add Two Numbers

## 📋 Thông tin bài toán

| Thuộc tính | Giá trị |
|------------|---------|
| **LeetCode #** | 2 |
| **Độ khó** | 🟡 Medium |
| **Chủ đề** | Linked List, Math |
| **Link** | [LeetCode](https://leetcode.com/problems/add-two-numbers/) |

## 📝 Đề bài

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

### Ví dụ
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Giải thích: 342 + 465 = 807 (lưu ngược lại thành 7->0->8)
```

## 💡 Ý tưởng giải thuật

### Kỹ thuật: Dummy Head Pattern

1. **Tạo nút giả (Dummy Head)**: Giúp đơn giản hóa việc xây dựng danh sách liên kết mới
2. **Duyệt song song**: Duyệt cả hai danh sách cùng lúc
3. **Xử lý số nhớ (Carry)**: Quan trọng! Phải xử lý cả khi vòng lặp kết thúc
4. **Kiểm tra Null an toàn**: Nếu một danh sách ngắn hơn, coi giá trị là 0

### Code quan trọng
```cpp
// Kiểm tra null an toàn
int x = (l1 != nullptr) ? l1->val : 0;
int y = (l2 != nullptr) ? l2->val : 0;

// Điều kiện vòng lặp bao gồm cả carry
while (l1 != nullptr || l2 != nullptr || carry != 0)
```

## 📊 Độ phức tạp

| Độ phức tạp | Giá trị |
|-------------|---------|
| **Thời gian** | O(max(m, n)) |
| **Không gian** | O(max(m, n)) |

> m, n là độ dài của hai danh sách liên kết

## 🚀 Chạy thử

```bash
g++ main.cpp -o main && ./main
```

**Output:**
```
Result: [7 0 8]
```

## 📚 Bài học rút ra

- **Dummy Head** là pattern cực kỳ hữu ích khi xây dựng linked list mới
- Luôn nhớ xử lý trường hợp **carry cuối cùng** (ví dụ: 99 + 1 = 100)
- Kiểm tra `nullptr` trước khi truy cập `.val` hoặc `.next`
