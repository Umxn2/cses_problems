#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int ticketsAvailable;
    cin>>ticketsAvailable;
    int numOfCustomers;
    cin>>numOfCustomers;
    multiset<int> ms;
    ms.insert(-1);
    for(int i = 0;i<ticketsAvailable;i++){
        int temp;
        cin>>temp;
        ms.insert(temp);
    }
    vector<int> customers (numOfCustomers);
    for(int i = 0;i<numOfCustomers;i++){
        cin>>customers[i];
    }
    for(auto it: customers){
        auto a = ms.upper_bound(it);
        a--;
        int wantedElem = *(a);
        if(wantedElem==-1){
            cout<<-1<<endl;
            continue;
        }
        else{
        ms.erase(a);
        }
        cout<<wantedElem<<endl;
    }
    return 0;
}
