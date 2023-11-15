#include<bits/stdc++.h>

#define vpii vector<pair<int, int> >
#define f first
#define s second

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.s == b.s)
        return a.f < b.f;
    return a.s < b.s;
}

void print_vector(vector<pair<int, int> > &v){
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i].f << " " << v[i].s << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int customer_count;
    cin >> customer_count;

    vpii customer_info(customer_count);

    for(int i = 0; i < customer_count; i++)
        cin >> customer_info[i].f >> customer_info[i].s;

    sort(customer_info.begin(), customer_info.end(), comp);

    vpii served_customer;
    served_customer.push_back(customer_info[0]);

    for(int i = 1; i < customer_count; i++)
        if(customer_info[i].f >= served_customer[served_customer.size()-1].s)
            served_customer.push_back(customer_info[i]);

    print_vector(served_customer);

    return 0;
}