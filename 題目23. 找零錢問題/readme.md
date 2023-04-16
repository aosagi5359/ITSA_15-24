# 題目23. 找零錢問題

```c++
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// 字串取代函式，將逗號取代為空格
void replaceD(string &str) {
    for (char &c : str) {
        if (c == ',') c = ' ';
    }
}

int main() {
    // 讀入輸入資料
    string str;
    int N,a1,a2,a3,cost,x,y,z;
    getline(cin, str);

    // 將逗號取代為空格
    replaceD(str);

    // 從字串取出 N、a1、a2、a3
    stringstream ss(str);
    ss >> N >> a1 >> a2 >> a3;

    // 計算水果的價錢總和
    cost = a1 * 15 + a2 * 20 + a3 * 30;

    // 如果錢不夠，輸出 "0"
    if (cost > N) {
        cout << "0" << endl;
    }
    else {
        // 計算找零銅板的數量
        z = (N - cost) / 50;  // 計算 50 元銅板的數量
        y = ((N - cost) % 50) / 5;  // 計算 5 元銅板的數量
        x = ((N - cost) % 50) % 5;  // 計算 1 元銅板的數量

        // 輸出找零銅板的數量
        cout << x << "," << y << "," << z << endl;
    }

    return 0;
}
```

讀取輸入：使用 getline 函數讀取一行字串，接著使用 replaceD 函數將字串中的逗號替換成空格，方便使用 stringstream 將數字讀取出來。

計算總共的成本：使用讀取進來的 a1, a2, a3 分別乘以水果的單價，然後相加得到總共的成本 cost。

計算找回的銅板數量：
首先計算可以找回的 50 元銅板數量 z，可以使用 (N - cost) / 50 計算得到；
接著計算可以找回的 5 元銅板數量 y，可以使用 ((N - cost) % 50) / 5 計算得到；
最後計算可以找回的 1 元銅板數量 x，可以使用 ((N - cost) % 50) % 5 計算得到。

輸出結果：如果總共的成本 cost 大於給的錢 N，代表帶的錢不夠買水果，因此輸出 0；否則，輸出找回的 1 元、5 元、50 元銅板數量。
