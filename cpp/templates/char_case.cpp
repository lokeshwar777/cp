#include "bits/stdc++.h"
using namespace std;

/**
1. lowercase - uppercase = 32 = ' '
2. lcase&'_'=ucase
3. ucase|' '=lcase
*/

string bin(int n){
    string s="";
    for(int i=0;i<10;++i){
        s.push_back(((n>>i)&1)?'1':'0'); 
    }
    // while(n>0){s.push_back(n&1);n>>=1;} // wrong
    reverse(s.begin(),s.end());
    return s;
}

int decimal(string b){
    int i=0,dec=0;
    while(!b.empty()){
        dec+=(b.back()-'0')<<i;i++;
        b.pop_back();
    }
    return dec;
}

bool islower(char c){
    return c&32;
}

bool isupper(char c){
    return !(c&32);
}

// string bin(int n) {
//     bitset<sizeof(int) * 8> b(n);  // Create a bitset of the appropriate size (e.g., 32 bits)
//     return b.to_string();  // Convert it to a string
// }

int main(){
    for(int i=0;i<5;++i)cout<<char('a'+i)<<" "<<bin('a'+i)<<" "<<int('a'+i)<<" "<<isupper('a'+i)<<endl;
        cout<<endl;
    for(int i=0;i<5;++i)cout<<char('A'+i)<<" "<<bin('A'+i)<<" "<<int('A'+i)<<endl;
        cout<<endl;
    cout<<(char)decimal("1011111")<<endl;
    cout<<"$$"<<(char)decimal("0100000")<<"$$"; // space

}