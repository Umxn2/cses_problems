#include <iostream>
#include <vector>
using namespace std;
bool checkIfPossible(int k, vector<int> & nums){
    int partitions = 0;
    int curr = k;
    for(auto it: nums){
        if(curr>it){
            curr-=it;
            continue;
        }
        else{
            partitions++;
            curr=k;
            curr-=it;
        }
    }
}
int main(){




}
