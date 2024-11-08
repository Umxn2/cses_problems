#include <iostream>

#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 0;
    set<int> us;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        if(us.find(temp)==us.end()){
            us.insert(temp);
            count++;
        }
    }
    cout<<count;
    return 0;
}
