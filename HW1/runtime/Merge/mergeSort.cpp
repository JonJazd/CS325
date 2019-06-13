#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int smallestInt(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int* arrayMerge(int length,int* array){
    if (length==1){
       
        return array;
    }
    int* array1 = new int[length/2];
    for (int b=0;b<length/2;b++){
        
        *(array1 + b) = *(array + b);
    }
    if ((length)>2){
        array1 = arrayMerge(length/2,array1);
    } else {
        
    }
    int* array2 = new int[length/2];
    int count = 0;
    for (int c=length/2;c<length;c++){
        
        *(array2 + count) = *(array + c);
        count++;
    }
    if ((length)>2){
        array2 = arrayMerge(length/2,array2);
    } else {
        
    }
    int* sortedArray = new int[length];
    for (int d=0; d<length;d++){
        
        *(sortedArray + d) = smallestInt(*(array1),*(array2));
        
        int count = 0;
        if (*(sortedArray +d)== *(array1)){
            while (*(array1)>= *(array1 + count)){
                count++;
                if (count==length){
                    
                    break;
                }
            }
                *(array1) = *(array1 + count);
        } else if (*(sortedArray + d)== *(array2)){
            while (*(array2)>= *(array2 +count)){
                count++;
                if (count==length){
                    
                    break;
                }
            }
                *(array2) = *(array2 +count);
        }
    }
    return sortedArray;
}

void mergeSort()
{
    int n = 36000*2;
    int *array = new int[n];
    for (int a = 0; a < n; a++)
    {
        array[a] = rand() % 10001;
        
    }
    clock_t t;
    t = clock();
    array = arrayMerge(n, array);
    delete[] array;
    t = clock() - t;
    cout << "sorted " << n << " numbers in " << (float)t/CLOCKS_PER_SEC << " seconds." << endl;
}
int main()
{
    mergeSort();
}