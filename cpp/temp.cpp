// #include<stdio.h>
// int main(){
//     int n;scanf("%d",&n);
//     printf("%d",n);
//     return 0;
// }

// #include<iostream>
// int main(){
//     int n;std::cin>>n;
//     std::cout<<n;
// }

// read the input numbers when you do not know the number of numbers in a single line
// #include <iostream>
// #include <vector>
// #include <sstream>
// int main(){
//     std::string s;
//     std::getline(std::cin,s);
//     std::istringstream stream(s);
//     std::vector<int> v;
//     int num;while(stream>>num)v.push_back(num);
//     for(auto &x:v)std::cout<<x<<std::endl;
// }

// for mulitple lines
// #include <iostream>
// #include <vector>
// #include <sstream>
// int main(){
//     std::vector<int> v;
//     std::string s;
//     while(std::getline(std::cin,s)){
//         std::istringstream stream(s);
//         int num;while(stream>>num)v.push_back(num);
//     }
//     for(auto &x:v)std::cout<<x<<std::endl;
// }


#include "bits/stdc++.h"
using namespace std;
int n,t;
int main(){
    cin>>n;cout<<n;
}