#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int smallestInt(int a, int b){
    if (a<b){
        return a;
    } else {
        return b;
    }
}

int* arrayMerge(int length,int* array){
    if (length==1){
        cout << "returning single value array of " << *(array) << endl;
        return array;
    }
    for (int z=0;z<length;z++){
        cout << "value " << z << " = " << *(array + z) << endl;
    }
    cout << "length = " << length << endl;
    int* array1 = new int[length/2];
    for (int b=0;b<length/2;b++){
        cout << "adding " << *(array + b) << " to array1" << endl;
        *(array1 + b) = *(array + b);
    }
    if ((length)>2){
        array1 = arrayMerge(length/2,array1);
    } else {
        cout << "array1 = " << *(array1) << endl;
    }
    int* array2 = new int[length/2];
    int count = 0;
    for (int c=length/2;c<length;c++){
        cout << "adding " << *(array + c) << " to array2 at spot" << count << endl;
        *(array2 + count) = *(array + c);
        count++;
    }
    if ((length)>2){
        array2 = arrayMerge(length/2,array2);
    } else {
        cout << "array2 = " << *(array2) << endl;
    }
    int* sortedArray = new int[length];
    for (int d=0; d<length;d++){
        //cout << "*array1 = " << *(array1) << " array2 = " << *(array2) << endl;
        *(sortedArray + d) = smallestInt(*(array1),*(array2));
        cout << "Sorted value: " << *(sortedArray + d) << endl;
        int count = 0;
        if (*(sortedArray +d)== *(array1)){
            while (*(array1)>= *(array1 + count)){
                count++;
                if (count==length){
                    cout << "counter error" <<endl;
                    break;
                }
            }
                *(array1) = *(array1 + count);
        } else if (*(sortedArray + d)== *(array2)){
            while (*(array2)>= *(array2 +count)){
                count++;
                if (count==length){
                    cout << "counter error" <<endl;
                    break;
                }
            }
                *(array2) = *(array2 +count);
        }
    }
    return sortedArray;
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
            array = arrayMerge(lineStart,array);
            ofstream insertFile;
            insertFile.open("merge.txt");
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