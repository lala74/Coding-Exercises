# Binary Search <!-- omit in toc -->

[Link](https://viblo.asia/p/tim-hieu-thuat-toan-chia-de-tri-va-cac-vi-du-ap-dung-3Q75wkP95Wb)

## Problem
Tìm kiếm nhị phân là một thuật toán dùng để tìm kiếm 1 phần tử trong một danh sách đã được sắp xếp. Thuật toán hoạt động như sau:
1. (Chia): Danh sách ban đầu sẽ được chia thành 2 nửa
2. (Trị): Trong mỗi bước, so sánh phần tử cần tìm với phần tử nằm ở chính giữa danh sách. Nếu hai phần tử bằng nhau thì phép tìm kiếm thành công và thuật toán kết thúc. Nếu chúng không bằng nhau thì tùy vào phần tử nào lớn hơn, thuật toán lặp lại bước so sánh trên với nửa đầu hoặc nửa sau của danh sách. Vì số lượng phần tử trong danh sách cần xem xét giảm đi một nửa sau mỗi bước, nên thời gian thực thi của thuật toán là hàm lôgarit.
3. Bằng việc lặp lại cách giải quyết như bước 2 ta sẽ tìm được kết quả.

**Input**  
- N (số phần tử), K (số cần tìm)
- Mảng
```
9 20
1 3 6 9 11 15 20 35 68

```

**Output**  
Index của số cần tìm

```
6 (index của 20 trong mảng là 6)
```
