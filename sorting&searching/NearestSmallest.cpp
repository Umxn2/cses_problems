#include <iostream>
#include <vector>
using namespace std;
int main(){
    int len;
    cin>>len;
    vector<int> nums (len+1);
    nums[0]=0;
    vector<int> ans (len+1, 0);
    for(int i = 1;i<=len;i++){
        cin>>nums[i];
    }
    for(int i = 1;i<=len;i++){
        if(nums[i-1]<nums[i]){
            ans[i]=i-1;
        }
        else{
            int prevIndex = ans[i-1];
            while(nums[prevIndex]>=nums[i]&&prevIndex!=0){
                prevIndex = ans[prevIndex];
            }
            ans[i]=prevIndex;
        }
    }
    for(int i = 1;i<=len;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
