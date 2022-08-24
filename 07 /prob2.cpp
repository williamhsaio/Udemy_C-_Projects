#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    
    if(b == 1){
        cout<<a * a<<endl;
    }
    if(b == -1){
        cout<<2 * a + 1<<endl;
    }
    return 0;
}