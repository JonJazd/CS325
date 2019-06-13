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
    //cout << "start = " << start << endl;
    //cout << "end = " << end << endl;
    if (array[start]>array[end]){
        //cout << "swap " << array[start] << " & " << array[end] << endl;
        int swap = array[start];
        array[start] = array[end];
        array[end] = swap;
    }
    if ((end-start+1)>2){
        int top = ceil(((end-start+1)/3));
        //cout << "top = " << top << endl;
        stoogeSort(start,end-top,array);
        stoogeSort(start+top,end,array);
        stoogeSort(start,end-top,array);
    }
    else {
        return;
    }
}

void mergeSort(){
    int n = 10000;
    int *array = new int[n];
    for (int a = 0; a < n; a++)
    {
        array[a] = rand() % 10001;
        
    }
    clock_t t;
    t = clock();
    stoogeSort(0,n-1,array);
    delete[] array;
    t = clock() - t;
    cout << "sorted " << n << " numbers in " << (float)t/CLOCKS_PER_SEC << " seconds." << endl;
    
}
int main(){
    mergeSort();
}
    
    
    