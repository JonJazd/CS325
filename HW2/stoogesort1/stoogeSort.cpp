#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


void stoogeSort(int start,int end,int* array){
    cout << "start = " << start << endl;
    cout << "end = " << end << endl;
    if (array[start]>array[end]){
        cout << "swap " << array[start] << " & " << array[end] << endl;
        int swap = array[start];
        array[start] = array[end];
        array[end] = swap;
    }
    if ((end-start+1)>2){
        int top = ceil(((end-start+1)/3));
        cout << "top = " << top << endl;
        stoogeSort(start,end-top,array);
        stoogeSort(start+top,end,array);
        stoogeSort(start,end-top,array);
    }
    else {
        return;
    }
}

void mergeSort(){
    string fileName = "data.txt";
    ifstream file;
    int lineStart;
    int value;
    file.open(fileName);
    if (file){
        cout << "File opened" << endl;
        if (file >> lineStart){
            cout << "linestart" << lineStart <<endl;
            int* array = new int[lineStart];
            for (int a =0; a<lineStart; a++){
                
                if (file >> value){
                    
                    *(array+a) = value;
                   
                    cout << value << endl;
                } else {
                    cout << "There was an error getting value." << endl;
                    return;
                }
            }
            file.close();
            stoogeSort(0,lineStart-1,array);
            ofstream insertFile;
            insertFile.open("stooge.out");
            for (int f=0;f<lineStart;f++){
                insertFile << array[f] << " ";
            }
            insertFile << endl;
            insertFile.close();
            delete[]array;
        } else {
            cout << "There was an error getting lineStart." << endl;
            return;
        }
        
    } else {
        cout << "No file." << endl;
        return;
    }
    
}
int main(){
    mergeSort();
}