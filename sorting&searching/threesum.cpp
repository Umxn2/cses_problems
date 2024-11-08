#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    int len;
    cin>>len;
    int target;
    cin>>target;
    vector<int> nums (len);
    unordered_map<int, int> um;
    for(int i = 0;i<len;i++){
        cin>>nums[i];
    }


    return 0;
}
