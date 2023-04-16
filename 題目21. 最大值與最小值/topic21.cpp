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