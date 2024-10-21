// ĐIỀU KIỆN:

// *ĐỒ THỊ VÔ HƯỚNG:
// - Các đỉnh có bậc khác 0 của đồ thị liên thông với nhau
// - Đồ thị có 0 hoặc 2 đỉnh có số bậc lẻ, khi đó 1 trong hai đỉnh là đỉnh  bắt đầu, đỉnh còn lại là đỉnh kết thúc

// *ĐỒ THỊ CÓ HƯỚNG:
// - Các đỉnh có bậc khác 0 của đồ thị thuộc cùng 1 thành phần liên thông
// - Tồn tại hai đỉnh u, v mà deg+(u) - deg-(u) = 1 và deg-(v) - deg+(u) = 1. Khi đó đỉnh u là đỉnh bắt đầu, v là đỉnh kết thúc

#include <bits/stdc++.h>
using namespace std;

int main(){
    //Dựa vào điều kiện tìm ra điểm bắt đầu và kết thúc của đường đi euler, sau đó dùng thuật toán tương tự chu trình euler:
    //Gọi hàm euler_cycle(điểm bắt đầu)
}