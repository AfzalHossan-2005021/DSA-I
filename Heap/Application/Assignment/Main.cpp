#include<iostream>
#include <sstream>
#include"Arr_MinHeap.h"

using namespace std;

int main(){
    MinHeap<int> min_heap;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(!feof(stdin)){
        string line, function, arg1, arg2;
        getline(cin, line);
        stringstream input_stream(line);
        input_stream >> function;
        if(function.compare("FIN") == 0){
            int min = min_heap.FindMin();
            cout << "FindMin returned " << min << endl;
        }
        else if(function.compare("EXT") == 0){
            int min = min_heap.ExtractMin();
            cout << "ExtractMin returned " << min << endl;
        }
        else if(function.compare("INS") == 0){
            input_stream >> arg1;
            min_heap.Insert(stoi(arg1));
            cout << "INSERTED " << arg1 << endl;
        }
        else if(function.compare("DEC") == 0){
            input_stream >> arg1 >> arg2;
            min_heap.DecreaseKey(stoi(arg1), stoi(arg2));
        }
        else if(function.compare("PRI") == 0){
            min_heap.Print();
        }
        else if(function.compare("SRT") == 0){
            min_heap.Sort();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}