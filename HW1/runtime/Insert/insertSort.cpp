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

int *arraySwap(int a, int b, int length, int *array)
{
    //a is always greater than b
    int *newArray = new int[length];
    for (int d = 0; d < length; d++)
    {
        if (b == d)
        {
            newArray[d] = array[a];
            for (int e = 1; e < length-d; e++)
            {
                if ((d+e-1)>=a){
                    newArray[d + e] = array[d + e];
                } else {
                    newArray[d + e] = array[d + (e - 1)];
                }
            }
            break;
        }
        else
        {
            newArray[d] = array[d];
        }
    }
    return newArray;
}

void insertSort()
{
   int n = 5000;
   int* array = new int[n];
   for (int a = 0;a<n;a++){
       array[a] = rand() % 10001;
   }
   clock_t t;
   t= clock();
    for (int b = 1; b < n; b++){
        if (array[b] >= array[b - 1])
            {
            }
            else
            {
                for (int c = 0; c < b; c++)
                {
                    if (array[b] < array[c])
                    {
                        array = arraySwap(b, c, n, array);
                    }
                }
            }
        }
        delete[]array;
    t = clock() - t;
    cout << "sorted " << n << " numbers in " << (float)t/CLOCKS_PER_SEC << " seconds." << endl;
}
int main()
{
    insertSort();
}