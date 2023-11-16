#include <fstream>

// #include"LL_Stack.h"
// #include "LL_Queue.h"
#include "Arr_Stack.h"
#include"Arr_Queue.h"

using namespace std;

int main(){
    int Q_initialSize, Q_maxSize, S_initialSize, S_maxSize, n, f, p, currentPosition, returnedValue;

    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("task1input.txt");
    outputFile.open("task1output.txt");

    inputFile >> Q_initialSize >> Q_maxSize;
    int Q_dataList[Q_initialSize];
    for (int i = 0; i < Q_initialSize; i++){
        inputFile >> Q_dataList[i];
    }

    inputFile >> S_initialSize >> S_maxSize;
    int S_dataList[S_initialSize];
    for (int i = 0; i < S_initialSize; i++){
        inputFile >> S_dataList[i];
    }

    // Queue <int> Q_list(Q_initialSize, Q_dataList);
    // Stack <int> S_list(S_initialSize, S_dataList);

    Queue <int> Q_list(Q_maxSize, Q_initialSize, Q_dataList);
    Stack <int> S_list(S_maxSize, Q_initialSize, S_dataList);

    Q_list.print(outputFile);
    S_list.print(outputFile);

    inputFile >> n;

    while (n--){
        inputFile >> f >> p;
        switch (f){
        case 1:
            Q_list.clear();
            Q_list.print(outputFile);
            outputFile << -1 << endl;
            break;
        case 2:
            Q_list.enqueue(p);
            Q_list.print(outputFile);
            outputFile << -1 << endl;
            break;
        case 3:
            returnedValue = Q_list.dequeue();
            Q_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 4:
            returnedValue = Q_list.length();
            Q_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 5:
            returnedValue = Q_list.frontValue();
            Q_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 6:
            returnedValue = Q_list.rearValue();
            Q_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 7:
            returnedValue = Q_list.leaveQueue();
            Q_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 8:
            S_list.clear();
            S_list.print(outputFile);
            outputFile << -1 << endl;
            break;
        case 9:
            S_list.push(p);
            S_list.print(outputFile);
            outputFile << -1 << endl;
            break;
        case 10:
            returnedValue = S_list.pop();
            S_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 11:
            returnedValue = S_list.length();
            S_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 12:
            returnedValue = S_list.topValue();
            S_list.print(outputFile);
            outputFile << returnedValue << endl;
            break;
        case 13:
            Q_list.reverseQueue();
            Q_list.print(outputFile);
            outputFile << -1 << endl;
            break;
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}