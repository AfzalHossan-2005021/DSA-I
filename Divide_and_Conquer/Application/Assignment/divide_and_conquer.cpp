#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int> >

// void print_vi(const vi &v, int s, int e){
//     for(int i = s; i <= e; i++)
//         cout << v[i] << " ";
//     cout << endl;
// }

void print_vpii(const vpii &v){
    cout << v.size() << endl;
    cout << "The inverted pairs are ";
    for(int i = 0; i < v.size(); i++){
        cout << "(" << v[i].first << "," << v[i].second << ")";
        if(i < v.size()-1)
            cout <<", ";
    }
    cout << endl;
}

void count_and_sort(vi &v, int s1, int e1, int s2, int e2, vpii &vp){
    vi a, b;
    for(int i = s1; i <= e1; i++)
        a.push_back(v[i]);
    for(int i = s2; i <= e2; i++)
        b.push_back(v[i]);
    // cout << "a: ";
    // print_vi(a, 0, a.size()-1);
    // cout << "b: ";
    // print_vi(b, 0, b.size()-1);
    int i = 0, j = 0;
    for(int k = s1; k <= e2; k++){
        if(i < a.size() && j < b.size()){
            if(a[i] > b[j]){
                for(int l = i; l < a.size(); l++)
                    vp.push_back({a[l], b[j]});
                v[k] = b[j++];
            }
            else
                v[k] = a[i++];
        }
        else if(i < a.size())
            v[k] = a[i++];
        else if(j < b.size())
            v[k] = b[j++];
    }
    // cout << "Marged: ";
    // print_vi(v, s1, e2);
    // cout << "Pairs: ";
    // print_vpii(vp);
}

void get_inverted_pairs(vi &v, int s, int e, vpii &vp){
    if(s == e)
        return;
    int mid = (s + e) / 2;
    get_inverted_pairs(v, s, mid, vp);
    get_inverted_pairs(v, mid+1, e, vp);
    count_and_sort(v, s, mid, mid+1, e, vp);
}

vpii get_inverted_pairs(vi stock_prices){
    vpii inverted_pairs;
    get_inverted_pairs(stock_prices, 0, stock_prices.size()-1, inverted_pairs);
    return inverted_pairs;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vi stock_prices(n);
    for(int i = 0; i < n; i++)
        cin >> stock_prices[i];
    vpii a = get_inverted_pairs(stock_prices);
    print_vpii(a);
    // print_vi(stock_prices, 0, n-1);
    return 0;
}