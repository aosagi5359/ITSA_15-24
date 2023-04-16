# 題目24. 計算複利

```c++
#include<iostream>
using namespace std;

int main(){
    long double r, sum;  // 宣告變數 r 和 sum ，使用 long double 型別，保證浮點數的精度
    long int n, p;  // 宣告變數 n 和 p ，使用 long int 型別，保證整數的精度

    cin >> r;  // 讀入每期利率 r
    cin >> n;  // 讀入期數 n
    cin >> p;  // 讀入每期投入金額 p

    sum = p;  // 設定初始本利和為每期投入金額 p
    while (n > 1)  // 計算 n-1 次本利和
    {
        sum *= (1.0 + r);  // 計算每期本利和
        sum += p;  // 加上每期投入金額
        n--;  // 更新期數
    }
    sum *= (1.0 + r);  // 計算第 n 期本利和，但不需加上每期投入金額

    cout << (long long)sum << endl;  // 輸出整數的本利和，並強制轉換為 long long 型別
    return 0;  // 結束程式
}
```

計算複利的公式為：s = p * (1 + r)^n，因此需要使用pow()函數來計算次方。

使用pow()函數計算本利和s，最後使用cout輸出並使用setprecision()函數設定精度為0位。
