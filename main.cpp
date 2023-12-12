#include <iostream>
#include <vector>

using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}


int backpack(int backpack_capacity, vector<int>& items_weights, vector<int>& items_value, int n) {

    vector<vector<int>> temp_table(n + 1, vector<int>(backpack_capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= backpack_capacity; w++) {
            if (items_weights[i - 1] <= w) {
                temp_table[i][w] = max(items_value[i - 1] + temp_table[i - 1][w - items_weights[i - 1]], temp_table[i - 1][w]);
            } else {
                temp_table[i][w] = temp_table[i - 1][w];
            }
        }
    }

    return temp_table[n][backpack_capacity];
}

int main() {
    system("chcp 65001");
    int backpack_capacity = 30;
    vector<int> items_weights = {10, 20, 30};
    vector<int> items_items_value = {60, 100, 120};
    int n = items_weights.size();

    cout << backpack(backpack_capacity, items_weights, items_items_value, n) << endl;

    return 0;
}
