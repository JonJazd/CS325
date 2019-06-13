#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

/*clock_t t;
t= clock();
//do thing
t = clock() - t;*/

int* insertInto(int* arr,int spot, int value, int n){
    int * newestArr = new int[n];
    newestArr[spot] = value;
    for (int h=0;h<n;h++){
        if (h<spot){
            newestArr[h] = arr[h];
        } else if (h>spot) {
            newestArr[h] = arr[h-1];
        }
    }
    return newestArr;
}

int* sort(int* arr, int n){
    int * newArr = new int[n];
    for (int f=0;f<n;f++){
        newArr[f] = NULL;
    }
    newArr[0] = arr[0];
    for (int g=1;g<n;g++){
        if (arr[g]>=newArr[g-1]){
            newArr[g] = arr[g];
        } else {
            int loops = 0;
            while (loops<n){
                if (arr[g]<newArr[loops]){
                    newArr = insertInto(newArr,loops,arr[g],n);
                    loops=n;
                }
                loops++;
            }
        }
    }
    return newArr;
}

void firstFit(int* arr, int cap, int n){
    clock_t t;
    t= clock();
    int * binArr = new int[n];
    for (int c=0;c<n;c++){
        binArr[c] = 0;
    }
    for (int d=0;d<n;d++){
        int loop = 1;
        int count = 0;
        while (loop==1){
            if (arr[d]+binArr[count]<=cap){
                binArr[count] += arr[d];
                loop++;
            }
            count++;
        }
    }
    t = clock() - t;
    int totBins = 0;
    for (int e=0;e<n;e++){
        if (binArr[e]>0){
        totBins++;
        }
    }
    cout << " First Fit: " << totBins << " time: " << (float)t/CLOCKS_PER_SEC/CLOCKS_PER_SEC << " seconds";
    delete[]binArr;
}

void firstFitDec(int* arr, int cap, int n){
    clock_t t;
    t= clock();
    int * newArr = sort(arr,n);
    int * binArr = new int[n];
    for (int y=0;y<n;y++){
        binArr[y] = 0;
    }
    int binCount = 0;
    for (int i=0;i<n;i++){
        if (newArr[i]+binArr[binCount]<=cap){
            binArr[binCount] += newArr[i];
        } else {
            i--;
            binCount++;
        }
    }
    t = clock() - t;
    binCount++;
    cout << " First Fit Decreasing: " << binCount << " time: " << (float)t/CLOCKS_PER_SEC << " seconds";
    delete[]binArr;
    delete[]newArr;
}

void bestFit(int* arr, int cap, int n){
    clock_t t;
    t= clock();
    int * binArr = new int[n];
    for (int o=0;o<n;o++){
        binArr[o] = 0;
    }
    for (int l=0;l<n;l++){
        int check = cap+1;
        int placeIn = n+1;
        for (int m=0;m<n;m++){
            if (arr[l]+binArr[m]<=cap){
                if (cap-(arr[l]+binArr[m])<check){
                    check = cap-(arr[l]+binArr[m]);
                    placeIn = m;
                }
            }
        }
        binArr[placeIn] += arr[l];
    }
    t = clock() - t;
    int binCount = 0;
    for (int p=0;p<n;p++){
        if (binArr[p]>0){
            binCount++;
        }
    }
    cout << " Best Fit: " << binCount << " time: " << (float)t/CLOCKS_PER_SEC << " seconds" << endl;
    delete[]binArr;
}

int main(){
    for (int a=0;a<5;a++){
    int binCap = (rand() % 2000) + 5;
    int numOfItems = (rand() % 1000) + 4000;
    int* itemArr = new int[numOfItems];
    for (int b=0;b<numOfItems;b++){
        itemArr[b] = (rand() % binCap-1) + 1;
    }
    firstFit(itemArr,binCap,numOfItems);
    firstFitDec(itemArr,binCap,numOfItems);
    bestFit(itemArr,binCap,numOfItems);
    cout << "Number of items/bins = " << numOfItems << " bincapacity = " << binCap << endl << endl;
    }
}