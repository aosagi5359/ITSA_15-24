# 題目22. 圈圈叉叉

```c++
#include <iostream>
using namespace std;

int main(){
    int board[3][3]; 
    bool win = false; // 建立一個布林變數，初始為 false

    // 讀入 3x3 的二維陣列
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    // 檢查所有的橫排和直排是否都是 0 或都是 1
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            win = true; // 設定 win 為 true，表示勝利
        }
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            win = true; // 設定 win 為 true，表示勝利
        }
    }

    // 檢查兩條對角線是否都是 0 或都是 1
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        win = true; // 設定 win 為 true，表示勝利
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        win = true; // 設定 win 為 true，表示勝利
    }

    // 根據 win 的值輸出結果
    if (win) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
```
