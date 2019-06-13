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

struct activity {
    int startTime;
    int endTime;
    int number;
};

int greedy (activity* a,int n,int* ans){
    int currentMax =0;
    int maxChange = 0;
    int count = 0;
    int currentMin = 1000000;
    for (int b=0;b<n;b++){
        if (ans[b]!=404404){
            if (ans[b]>0 && a[ans[b]].startTime<currentMin){
                count = 1;
                currentMin = a[ans[b]].startTime;
            }
        }
    }
    //cout << "Current Min = " << currentMin << endl;
    //cout << "count = " << count << endl;
    for (int c=0;c<n;c++){
        int skip;
        for (int d=0;d<n;d++){
            if (ans[d]-1==c){
                skip = 1;
            }
        }
        if (skip==1){

        } else if (count>0){
            //cout << "Start time: " << a[c].startTime << " vs. Current Max = " << a[currentMax].startTime << endl; 
            if (a[c].startTime>a[currentMax].startTime && a[c].endTime<=currentMin){
                //cout << "New max = " << a[c].endTime << endl;
                currentMax = c;
                maxChange = 1;
            } else if (a[c].endTime<=currentMin && c>0 && maxChange==0){
                currentMax = c;
                maxChange = 1;
            }
        } else {
            if (a[c].startTime>a[currentMax].startTime){
                currentMax = c;
                maxChange = 1;
            }
        }
        skip = 0;
    }
    //cout << "Choosing activity " << a[currentMax].number << endl;
    for (int a1=0;a1<n;a1++){
        //cout << ans[a1] << " ";
    }
    //cout << endl;
    if (maxChange==0){
        return -1;
    }
    return currentMax;
}


int main(){
    string filename="act.txt";
    ifstream file;
    file.open(filename);
    int loop = 1;
    while (loop){
        int actNum = 0;
        if (file >> actNum){
            activity* activities = new activity[actNum];
            int* answer = new int[actNum];
            for (int a=0;a<actNum;a++){
                file >> activities[a].number;
                file >> activities[a].startTime;
                file >> activities[a].endTime;
                //cout << "Activity: " << activities[a].number << " Start: " <<activities[a].startTime << " End: " << activities[a].endTime << endl;
                answer[a] = 0;
            }
            for (int c=0;c<actNum;c++){
                answer[c] = greedy(activities,actNum,answer);
                if (answer[c]==-1){
                    answer[c]= 404404;
                }
            }
            int counter = 0;
            for (int d=0;d<actNum;d++){
                if (answer[d]>0 && answer[d]!=404404){
                    counter++;
                }
            }
            cout << "Set " << loop << endl;
            cout << "Number of activities selected: " << counter << endl;
            cout << "Activities: ";
            for (int e=actNum-1;e>-1;e--){
                if (answer[e]>0 && answer[e]!=404404){
                    cout << activities[answer[e]].number << " ";
                }
            }
            cout << endl;
           
            loop++;
        } else {
            loop = 0;
            file.close();
        }
    }
}