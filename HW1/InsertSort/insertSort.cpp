#include <iostream>
#include <string>
#include <fstream>

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
            for (int e = 1; e < length; e++)
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
    string fileName = "data.txt";
    ifstream file;
    int lineStart;
    int value;
    file.open(fileName);
    if (file)
    {
        if (file >> lineStart)
        {
            int *array = new int[lineStart];
            for (int a = 0; a < lineStart; a++)
            {
                if (file >> value)
                {
                    array[a] = value;
                }
                else
                {
                    cout << "There was an error getting value." << endl;
                    return;
                }
            }
            for (int b = 1; b < lineStart; b++)
            {
                if (array[b] >= array[b - 1])
                {
                }
                else
                {
                    for (int c = 0; c < b; c++)
                    {
                        if (array[b] < array[c])
                        {
                            array = arraySwap(b, c, lineStart, array);
                        }
                    }
                }
            }
            ofstream insertFile;
            insertFile.open("insert.txt");
            for (int f = 0; f < lineStart; f++)
            {
                insertFile << array[f] << " ";
            }
            delete[] array;
            insertFile << endl;
            insertFile.close();
        }
        else
        {
            cout << "There was an error getting lineStart." << endl;
            return;
        }
        file.close();
    }
    else
    {
        cout << "No file." << endl;
        return;
    }
}
int main()
{
    insertSort();
}