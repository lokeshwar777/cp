#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int r, int c) {
    // if(i+j>=4 && i>=j-4)return '*';
    if(i%5==j%8 || i%5+j%8==8)cout<<char(j+'a');
    else cout<<'.';
}

int main() {
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            func(i,j,r,c);
        }
        cout<<endl;
    }

    return 0;
}