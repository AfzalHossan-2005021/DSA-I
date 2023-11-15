#include<fstream>
#include "LRUCache.h"

using namespace std;

int main(){
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("lru_input.txt");
    outputFile.open("lru_output.txt");
    
    int capacity, n, f, key, value;
    inputFile >> capacity >> n;
    LRUCache<int, int> memory(capacity);
    while(n--){
        inputFile >> f;
        if(f == 1){
            inputFile >> key;
            outputFile << memory.get(key) << endl;
        }
        else if(f == 2){
            inputFile >> key >> value;
            memory.put(key, value);
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}