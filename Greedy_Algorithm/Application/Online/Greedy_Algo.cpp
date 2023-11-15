#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, total_time = 0;
    cin >> n;
    vector<pair<int,int> > v(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v[i].first = i;
        v[i].second = temp;
    }
    sort(v.begin(), v.end(), comp);
    vector<int> waiting_time(n, 0);
    for(int i=1; i<n; i++){
        waiting_time[i] = waiting_time[i-1] + v[i-1].second;
    }
    for(int i=0; i<n; i++){
        total_time += waiting_time[i];
        cout << v[i].first + 1 << " ";
    }
    cout << endl;
    float avg_time = float(total_time)/n;
    cout << "Minimum average waiting time: " << avg_time << endl;
    return 0;
}