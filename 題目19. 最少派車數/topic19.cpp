#include <iostream>
using namespace std;

int main(){
	int n, s, d, max_cars = 0;
    int time[25] = {0}; // 用陣列記錄每個時間點所需的車輛數量，初始化為0
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s >> d;
        for (int j = s; j < d; j++){
            time[j]++; // 該時間點所需車輛數量加1
        }
    }
    for (int k = 0; k < 25; k++){
        if (time[k] > max_cars)
            max_cars = time[k]; // 找出最大需要車輛數量
    }
    cout << max_cars << endl; // 輸出最大需要車輛數量
    return 0;
}