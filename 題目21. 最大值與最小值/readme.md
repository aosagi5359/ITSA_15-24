# 題目21. 最大值與最小值

```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float arr[10];
    float max = -1e9, min = 1e9; // 初始化最大值和最小值
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    cout << "maximum:" << fixed << setprecision(2) << max << endl; // 小數點後兩位
    cout << "minimum:" << fixed << setprecision(2) << min << endl; // 小數點後兩位
    return 0;
}
```

程式首先宣告一個長度為 10 的浮點數陣列，並初始化最大值和最小值為極小和極大值。

然後使用 for 迴圈讀入 10 個浮點數，同時在迴圈中更新最大值和最小值，如果當前數值大於最大值就更新最大值，如果小於最小值就更新最小值。

最後輸出最大值和最小值，使用 fixed 和 setprecision(2) 來控制小數點的輸出格式，以達到小數點後兩位的要求。
