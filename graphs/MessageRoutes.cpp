#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int numOfCompters;
    cin>>numOfCompters;
    int numOfConnections;
    cin>>numOfConnections;
    vector<vector<int> > auxList(numOfCompters+1);
    for(int i = 0;i<numOfConnections;i++){
        int comp1;
        cin>>comp1;
        int comp2;
        cin>>comp2;
        auxList[comp1].push_back(comp2);
        auxList[comp2].push_back(comp1);
    }
    vector<int> computedArray(numOfCompters+1, -1);
    queue<int> q;
    q.push(1);
    int count = 0;
    while(!q.empty()){
        int len = q.size();
        for(int i = 0;i<len;i++){
            int top = q.front();
            q.pop();
            for(auto it: auxList[top]){
                if(computedArray[it]==-1){
                    computedArray[it]=top;
                    if(it==numOfCompters){
                        vector<int> revArr;
                        int index = it;
                        while(index!=1){
                            revArr.push_back(index);
                            index = computedArray[index];
                        }

                        revArr.push_back(1);
                        int len = revArr.size();
                        cout<<len<<endl;
                        reverse(revArr.begin(),revArr.end());
                        for(auto it: revArr ){
                            cout<<it<<" ";
                        }
                        return 0;
                    }
                    else{
                        q.push(it);
                    }
                }

            }
            count++;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
