#include<bits/stdc++.h>

using namespace std;

void print_taken_weight(int **&dp, int weight[], int item_count, int capacity){
    if(item_count > 0){
        if(dp[item_count][capacity] != dp[item_count-1][capacity]){
            print_taken_weight(dp, weight, item_count-1, capacity-weight[item_count]);
            cout << weight[item_count] << " ";
        }
        else
            print_taken_weight(dp, weight, item_count-1, capacity);
    }
    
}

int MaxLoot(int n, int weight[], int value[], int capacity, int **&dp){
    if(dp[n][capacity] == -1){
        if(weight[n] > capacity)
            dp[n][capacity] = MaxLoot(n-1, weight, value, capacity, dp);
        else
            dp[n][capacity] = max(value[n] + MaxLoot(n-1, weight, value, capacity-weight[n], dp), MaxLoot(n-1, weight, value, capacity, dp));
    }
    return dp[n][capacity];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int item_count, capacity;
    vector<int> taken_weight;

    cin >> item_count;
    int weight[item_count+1], value[item_count+1];

    for(int i = 1; i <= item_count; i++)
        cin >> weight[i] >> value[i];
    cin >> capacity;

    int** dp = new int*[item_count+1];
    for (int i = 0; i <= item_count; i++)
        dp[i] = new int[capacity+1];

    for(int i = 0; i <= item_count; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    for(int i = 1; i <= item_count; i++)
        for(int j = 1; j <= capacity; j++)
            dp[i][j] = -1;

    int solution = MaxLoot(item_count, weight, value, capacity, dp);
    cout << solution << endl;

    print_taken_weight(dp, weight, item_count, capacity);
    cout << endl;
    
    return 0;
}