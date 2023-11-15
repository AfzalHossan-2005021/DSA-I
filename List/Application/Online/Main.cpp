#include <fstream>
#include "LL_List.h"
// #include "Arr_List.h"

using namespace std;

void writeFile(MyList<int> list, ofstream &outputFile){
    int currentPosition = list.currPos();
    list.setToBegin();

    outputFile << "<";
    for (int i = 0; i < list.size(); i++){
        if (currentPosition == i){
            outputFile << "| ";
        }
        outputFile << list.getValue();
        if (i < list.size() - 1){
            outputFile << " ";
        }
        list.next();
    }
    outputFile << ">" << endl;

    list.setToPos(currentPosition);
}

int main(){
    int initalSize, maxSize, n, f, p, currentPosition, returnedValue;

    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("list_input.txt");
    outputFile.open("list_output.txt");

    inputFile >> initalSize >> maxSize;
    int dataList[initalSize];
    for (int i = 0; i < initalSize; i++){
        inputFile >> dataList[i];
    }

    MyList <int> list(initalSize, dataList);
    // MyList <int> list(initalSize, maxSize, dataList);

    writeFile(list, outputFile);

    inputFile >> n;

    while (n--){
        inputFile >> f >> p;
        switch (f){
        case 1:
            returnedValue = list.size();
            writeFile(list, outputFile);
            outputFile << returnedValue << endl;
            break;
        case 2:
            list.push(p);
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 3:
            list.pushBack(p);
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 4:
            returnedValue = list.erase();
            writeFile(list, outputFile);
            outputFile << returnedValue << endl;
            break;
        case 5:
            list.setToBegin();
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 6:
            list.setToEnd();
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 7:
            list.prev();
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 8:
            list.next();
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 9:
            returnedValue = list.currPos();
            writeFile(list, outputFile);
            outputFile << returnedValue << endl;
            break;
        case 10:
            list.setToPos(p);
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        case 11:
            returnedValue = list.getValue();
            writeFile(list, outputFile);
            outputFile << returnedValue << endl;
            break;
        case 12:
            returnedValue = list.find(p);
            writeFile(list, outputFile);
            outputFile << returnedValue << endl;
            break;
        case 13:
            list.clear();
            writeFile(list, outputFile);
            outputFile << -1 << endl;
            break;
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}