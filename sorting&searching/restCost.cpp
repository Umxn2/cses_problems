#include <cinttypes>
#include <iostream>
#include <ratio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int customers;
    cin>>customers;
    vector<int> arrivalTime(customers);
    vector<int> depatureTime(customers);

    for(int i = 0;i<customers;i++){
        cin>>arrivalTime[i];
        cin>>depatureTime[i];
    }
    sort(arrivalTime.begin(), arrivalTime.end());
    sort(depatureTime.begin(), depatureTime.end());
    int maxCus = 0;
    int arrIndex = 0;
    int departIndex = 0;
    int count = 0;
    while(arrIndex<customers){
       if(arrivalTime[arrIndex]<depatureTime[departIndex]){
           count++;
           arrIndex++;
           maxCus=max(maxCus, count);
       }
       else{
           count--;
           departIndex++;
       }
    }
    cout<<maxCus;
    return 0;
}
