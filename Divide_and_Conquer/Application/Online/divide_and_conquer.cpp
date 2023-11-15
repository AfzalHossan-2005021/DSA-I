#include<bits/stdc++.h>

using namespace std;

int marge(string &str, int s1, int e1, int s2, int e2){
    int count_l = 0, count_r = 0;
    for(int i = e1; i > s1; i--){
        if(str[i-1] - str[i] == 1)
            count_l++;
        else
            break;
    }
    for(int i = s2; i < e2; i++){
        if(str[i] - str[i+1] == 1)
            count_r++;
        else
            break;
    }
    cout << count_l << " " << count_r << endl;
    return count_l * count_r;
}
int divide(string &str, int s, int e){
    if(s == e)
        return 0;
    int m = (s+e)/2;
    int l = divide(str, s, m);
    int r = divide(str, m+1, e);
    int c = marge(str, s, m, m+1, e);
    int total  = l + c + r;
    cout << l << " " << c << " " << r << " " << total << endl;
    return total;
}

int main(){
    string s;
    cin >> s;
    cout << divide(s, 0, s.length()-1) << endl;
    return 0;
}