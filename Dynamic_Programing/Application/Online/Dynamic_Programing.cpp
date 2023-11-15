#include<bits/stdc++.h>

using namespace std;

struct job{
    int s;
    int f;
    int v;
};

bool comp(job &a, job &b){
    if(a.f == b.f)
        return a.s < b.s;
    return a.f < b.f;
}

int MaxValue(job a[], int n, int t, int **&dp){
    if(dp[n][t] == -1){
        if(a[n-1].f > t)
            dp[n][t] = MaxValue(a, n-1, t, dp);
        else{
            int x = a[n-1].v + MaxValue(a, n-1, a[n-1].s, dp);
            int y = MaxValue(a, n-1, t, dp);
            dp[n][t] = max(x, y);
        }
    }
    return dp[n][t];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    job a[n];
    int mx_f = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i].s >> a[i].f >> a[i].v;
        if(a[i].f > mx_f) mx_f = a[i].f;
    }
    sort(a, a+n, comp);
    int** dp = new int*[n+1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[mx_f+1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= mx_f; i++)
        dp[0][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= mx_f; j++)
            dp[i][j] = -1;

    int mx_value = MaxValue(a, n, mx_f, dp);
    cout << mx_value << endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= mx_f; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}