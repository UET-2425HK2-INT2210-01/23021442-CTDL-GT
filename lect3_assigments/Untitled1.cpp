2^10: Đây là một hằng số, nên độ phức tạp thời gian là O(1).

2^logn: Sử dụng tính chất 2^log𝑛=𝑛, độ phức tạp thời gian là O(n).

3n + 100logn: Thuật ngữ bậc cao nhất chiếm ưu thế, nên độ phức tạp là O(n).

4n: Đây là tuyến tính, nên độ phức tạp là O(n).

nlogn: Đây là logarit tuyến tính, nên độ phức tạp là O(n log n).

4nlogn + 2n: Thuật ngữ chi phối là 4nlogn, nên độ phức tạp là O(n log n).

n^2 + 10n: Thuật ngữ bậc hai chiếm ưu thế, nên độ phức tạp là O(n²).

n^3: Đây là bậc ba, nên độ phức tạp là O(n³).

2^n: Đây là hàm số mũ, nên độ phức tạp là O(2^n).

Thứ tự tăng dần của ký hiệu Big O
O(1) (2^10) < O(n) (2^logn, 3n+100logn, 4n) < O(n log n) (nlogn, 4nlogn + 2n) < O(n^2) (n^2 + 10n) < O(n^3) (n^3) < O(2^n) (2^n).
