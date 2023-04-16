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