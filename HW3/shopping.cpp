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

int* maxOf(int* first,int* second,int* p,int n){
    int fPrice=0;
    int sPrice=0;
    for (int a=0;a<n;a++){
        if (first[a]>0){
            fPrice += p[a];
        }
        if (second[a]>0){
            sPrice += p[a];
        }
    }
    if (fPrice>sPrice){
        int* fArray = new int[n];
        for (int co=0;co<n;co++){
            fArray[co] = first[co];
        }
        return fArray;
    } else if (sPrice>fPrice) {
        int* fArray = new int[n];
        for (int con=0;con<n;con++){
            fArray[con] = second[con];
        }
        return fArray;
    } else {
        //cout << "equal" << endl;
        int* fArray = new int[n];
        for (int co=0;co<n;co++){
            fArray[co] = first[co];
        }
        return fArray;
    }
}

//recursive function to return max price and a int array that indicates which items it chose
int* shop(int x,int n,int* w,int* p,int* i,int* prev){
    int* y = new int[n];
    int* max = new int[n];
    for (int b3=0;b3<n;b3++){
        y[b3] = 0;
        max[b3] = 0;
    }
    if (x==0){
        return y;
    }
    else {
        for (int h=0;h<n;h++){
            if (w[h]<=x && prev[h]==0){
                y[h] = h+1;
                //cout << "x = " << x << " and is >= " << w[h] << endl;
                if(w[h]==0){
                    break;
                }
                y = maxOf(y,shop(x-w[h],n,w,p,i,y),p,n);
                max = maxOf(max,y,p,n);
            } else if (prev[h]>0){
                //cout << "previous contains" << endl;
            }
            for(int c2=0;c2<n;c2++){
                if (prev[c2]==0){
                    y[c2] = 0;
                }
            }
        }
        //y= max;
        return max;
    }
}

int main(){
    //initiate file and integers for each test case
    string filename = "shopping.txt";
    ifstream file;
    int testCases;
    int items;
    int family;
    //get all the numbers from the file
    file.open(filename);
    if (file){
        cout << "file opened" << endl;
        if (file >> testCases){
            for (int a=0;a<testCases;a++){
                int* prices;
                int* weights;
                int* canCarry;
                int** familyArray;
                if (file >> items){
                    prices = new int[items];
                    weights = new int[items];
                    for (int b=0;b<items;b++){
                        file >> prices[b];
                        file >> weights[b];
                    }
                    //cout << "done with items" << endl;
                    for (int z=0;z<items;z++){
                        cout << prices[z] << " " << weights[z] << endl;
                    }
                }
                if (file >> family){
                    canCarry = new int[family];
                    familyArray = new int*[family];
                    for (int c=0;c<family;c++){
                        file >> canCarry[c];
                    }
                    //cout << "done with family" << endl;
                }
                //file.close();
                //cout << "file closed" << endl;
                //call recursive function that returns a struct with a 
                //max price and array of items that each family member can carry
                int totalPrice = 0;
                int topWeightCapacity = 0;
                for (int f=0;f<family;f++){
                    if (canCarry[f]>topWeightCapacity){
                        topWeightCapacity = canCarry[f];
                    }
                }
                //cout << "top Weight is : " << topWeightCapacity << endl;
                for (int d=0;d<family;d++){
                    familyArray[d] = new int[items];
                    int* newAr = new int[items];
                    for (int e=0;e<items;e++){
                        familyArray[d][e] = 0;
                        newAr[e] = 0;
                    }
                    familyArray[d] = shop(canCarry[d],items,weights,prices,familyArray[d],newAr);
                }
                for (int c1=0;c1<family;c1++){
                    int memberMaxPrice = 0;
                    for (int c2=0;c2<items;c2++){
                        if (familyArray[c1][c2]>0){
                            memberMaxPrice += prices[c2];
                        }
                    }
                    totalPrice += memberMaxPrice;
                }
                ofstream resultFile;
                resultFile.open("results.txt",std::ios_base::app);
                resultFile << "Test Case: " << a+1 << endl;
                resultFile << "Total Price: " << totalPrice << endl;
                resultFile << "Member items:" << endl;
                for (int i=0;i<family;i++){
                    resultFile << i+1 << ": ";
                    for (int k=0;k<items;k++){
                        if (familyArray[i][k]>0){
                            resultFile << k+1 << " ";
                        }
                    }
                    resultFile << endl;
                }
                resultFile.close();
                /*delete[]prices;
                delete[]weights;
                for (int v=0;v<family;v++){
                    delete[]familyArray[v].inventory
                }
                delete[]familyArray;*/
            }
        }
    }
    return 0;
}