# 題目19. 最少派車數

```c++
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
```

用 pair<int, int> 來存儲每一筆訂單的出發時間和返回時間，然後將所有訂單按照出發時間從小到大排序。再用變量 count 記錄需要調度的遊覽車輛數量，以及變量 endTime 記錄當前使用的遊覽車的返回時間。初始情況下，將 count 設為 1，並且將 endTime 設為第一筆訂單的返回時間。接下來，遍歷所有訂單，對於每一筆訂單，如果其出發時間晚於等於 endTime，就可以使用當前的遊覽車來執行該訂單，因此需要將 count 增加 1，並且將 endTime 設為該訂單的返回時間。最後，輸出 count 即可。
