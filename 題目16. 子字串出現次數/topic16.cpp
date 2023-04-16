#include <iostream>
#include <string>
using namespace std;

int countSubstring(string& sub, string& str, int pos);
// 傳入兩個字串和一個起始位置，回傳子字串 sub 在主字串 str 中的出現次數

int main() {
    string sub, str;

    // 輸入子字串和主字串
    cin >> sub >> str;

    // 計算子字串出現次數
    int count = countSubstring(sub, str, 0);

    // 輸出結果
    cout << count << endl;

    return 0;
}

int countSubstring(string& sub, string& str, int pos) {
    int count = 0; // 計數器，統計子字串出現次數

    // 從起始位置開始尋找子字串
    pos = str.find(sub, pos);

    // 若找到子字串
    while (pos != string::npos) {
        // 計數器加 1
        count++;

        // 繼續尋找下一個子字串
        pos = str.find(sub, pos + 1);
    }

    return count;
}