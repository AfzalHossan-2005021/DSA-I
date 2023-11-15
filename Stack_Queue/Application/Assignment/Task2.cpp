#include<fstream>
#include<iostream>

// #include"LL_Stack.h"
// #include "LL_Queue.h"
#include "Arr_Stack.h"
#include"Arr_Queue.h"

using namespace std;

class customer{
public:
    int no;
    int arrival;
    int rented;
    int departure;
    customer(int c_no = -1, int a_time = -1, int r_time = -1){
        no = c_no;
        arrival = a_time;
        rented = r_time;
    }
};

void check_time_limit(int &console_time, int time_limit, customer &cstmr){
    if(console_time < cstmr.arrival)
        console_time = cstmr.arrival;
    console_time += cstmr.rented;
    if(console_time > time_limit)
        cstmr.departure = time_limit;
    else
        cstmr.departure = console_time;
}

int main(){
    freopen("task2input.txt", "r", stdin);
    freopen("task2output.txt", "w", stdout);

    int customer_count, time_limit, customer_no, arrival_time, rented_time, console1_time=0, console2_time =0;

    cin >> customer_count >> time_limit;

    Queue <customer> line1;
    Stack <customer> line2;

    int customer_list[customer_count + 1];

    for(int i = 1; i <= customer_count; i++){
        cin >> arrival_time >> rented_time;
        customer new_cstmr(i, arrival_time, rented_time);
        if(line1.length() < 3 || (line1.length() == 3 && console1_time <= new_cstmr.arrival)){
            while(line1.length() > 0 && console1_time < new_cstmr.arrival){
                customer old_cstmr = line1.dequeue();
                check_time_limit(console1_time, time_limit, old_cstmr);
                customer_list[old_cstmr.no] = old_cstmr.departure;
            }
            line1.enqueue(new_cstmr);
        }
        else{
            while(line2.length() > 0 && console2_time < new_cstmr.arrival){
                customer old_cstmr = line2.pop();
                check_time_limit(console2_time, time_limit, old_cstmr);
                customer_list[old_cstmr.no] = old_cstmr.departure;
            }
            line2.push(new_cstmr);
        }
    }
    while (line1.length() > 0){
        customer old_cstmr = line1.dequeue();
        check_time_limit(console1_time, time_limit, old_cstmr);
        customer_list[old_cstmr.no] = old_cstmr.departure;
    }
    while (line2.length() > 0){
        customer old_cstmr = line2.pop();
        check_time_limit(console2_time, time_limit, old_cstmr);
        customer_list[old_cstmr.no] = old_cstmr.departure;
    }

    for(int i = 1; i<= customer_count; i++){
        cout << i << " > " << customer_list[i] << endl;
    }

    return 0;
}