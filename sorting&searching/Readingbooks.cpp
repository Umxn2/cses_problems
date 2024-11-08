#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int num;
    cin>>num;
    vector<int> books(num);
    long long sum =0;
    for(int i = 0;i<num;i++){
        cin>>books[i];
        sum+=books[i];
    }
    sort(books.begin(), books.end());
    int l = 0;
    int r = num-1;
    long long prefixsum = 0;
    long long endsum = 0;
    long long timewaited = 0;
    while(l!=r && l<num && r>=0){
        if(prefixsum+books[l]>=endsum+books[r]){
            endsum+=books[r];
            r--;
        }
        prefixsum+=books[l];
        l++;
    }
    if(l==r){
        if(l==0 || l == num-1){
        if(prefixsum>endsum){
            timewaited = endsum+books[l]-prefixsum;
                    }
        else{
            timewaited = prefixsum+books[l]-endsum;
        }
        }
    }
    cout<<sum+timewaited;
    return 0;

}
