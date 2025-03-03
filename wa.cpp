#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = n * 3 + 1;
        }
    }
    cout << 1 << "\n";
    return 0;
}