answer shop(int x,int n,int* w,int* p,int* i){
    int y = 0;
    int* inv = new int[n];
    for (int a=0;a<n;a++){
        inv[a] = 0;
    }
    if (x==0){
        return 0;
    }
    for (int b=0;b<n;b++){
        if (w[b]<x && inv[b]==0){
            answer one = shop(x-w[b],n,w,p,i);
            if (y>=one.maxPrice + p[b]){

            } else if (y<one.maxPrice + p[b]){
                
            }
        }
    }
}