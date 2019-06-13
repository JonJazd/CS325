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

struct vert{
    string name;
    int goodguy;
};

int makeOpposite(vert w1, vert w2){
    if (w1.goodguy==w2.goodguy){
        return -1;
    }
    cout << w1.name << " is opposite of " << w2.name << endl;
    if (w1.goodguy==1){
        return 0;
    } else {
       return 1;
    }
}

int makeSame (vert w1, vert w2){
    cout << w1.name << " is the same as " << w2.name << endl;
    return w1.goodguy;
}

int minOf1 (int a, int b){
    if (a<b){
        return a;
    }
    return b;
}

int delve (vert* w, string* r1, string* r2, int n, int r,int a,int check){
    if (check==n){
        return n;
    }
    int check1 = check +1;
    for (int b=0;b<r;b++){
        if (w[a].name==r1[b]){
            for (int c=0;c<n;c++){
                if (c!=a){
                    if (r2[b]==w[c].name){
                        if(w[c].goodguy==w[a].goodguy && w[a].goodguy!=2){
                            cout << w[c].name << " and " << w[a].name << " cannot be rivals" << endl;
                            return -1;
                        } else if (w[c].goodguy!=2 && w[c].goodguy!=w[a].goodguy){
                            int goodGuyCheck = makeOpposite(w[c],w[a]);
                            if (goodGuyCheck!=-1){
                                w[a].goodguy = goodGuyCheck;
                            }
                        } else if (w[c].goodguy==2){
                            check1 = delve(w,r1,r2,n,r,c,check1);
                        }
                    }
                }
            }
        } else if (w[a].name==r2[b]){
            for (int c=0;c<n;c++){
                if (c!=a){
                    if (r1[b]==w[c].name){
                        if(w[c].goodguy==w[a].goodguy && w[a].goodguy!=2){
                            cout << w[c].name << " and " << w[a].name << " cannot be rivals" << endl;
                            return -1;
                        } else if (w[c].goodguy!=2 && w[c].goodguy!=w[a].goodguy){
                            int goodGuyCheck = makeOpposite(w[c],w[a]);
                            if (goodGuyCheck!=-1){
                                w[a].goodguy = goodGuyCheck;
                            }
                        } else if (w[c].goodguy==2){
                            check1 = delve(w,r1,r2,n,r,c,check1);
                        }
                    }
                }
            }
        }
    }
    return check1;
}

bool makeRivals(vert* w, string* r1, string* r2, int n, int r){
    int check = 0;
    for (int c=0;c<n;c++){
        if (w[c].goodguy==2){
            check = delve(w,r1,r2,n,r,c,0);
        }
        if (check==n){
            cout << "check = n" << endl;
            w[c].goodguy=1;
        } else if (check==-1){
            return false;
        }   
    }
    return true;
}

int main(){
    string fileName;
    cout << "Please enter the file name." << endl;
    cin >> fileName;
    ifstream file;
    file.open(fileName);
    int n;
    int r;
    file >> n;
    vert* wrestlers = new vert[n];
    for (int a=0;a<n;a++){
        file >> wrestlers[a].name;
        if (a==0){
            wrestlers[a].goodguy = 1;
        } else {
            wrestlers[a].goodguy = 2;
        }
    }
    file >> r;
    string* rivalries1 = new string[r];
    string* rivalries2 = new string[r];
    for (int b=0;b<r;b++){
        file >> rivalries1[b];
        file >> rivalries2[b];
    }
    file.close();
    bool possible = makeRivals(wrestlers,rivalries1,rivalries2,n,r);
    if (possible){
        cout << "Yes" << endl;
        cout << "Babyfaces:";
        for (int h=0;h<n;h++){
            if (wrestlers[h].goodguy==1){
                cout << " " << wrestlers[h].name;
            }
        }
        cout << endl;
        cout << "Heels:";
        for (int i=0;i<n;i++){
            if (wrestlers[i].goodguy==0){
                cout << " " << wrestlers[i].name;
            }
        }
        cout << endl;
    } else {
        cout << "No" << endl;

        
        cout << "Babyfaces:";
        for (int h=0;h<n;h++){
            if (wrestlers[h].goodguy==1){
                cout << " " << wrestlers[h].name;
            }
        }
        cout << endl;
        cout << "Heels:";
        for (int i=0;i<n;i++){
            if (wrestlers[i].goodguy==0){
                cout << " " << wrestlers[i].name;
            }
        }
        cout << endl;
    }
    return 0;
}