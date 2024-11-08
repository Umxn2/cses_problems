#include <fstream>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int cites;
    cin>>cites;
    int flights;
    cin>>flights;
    vector<vector<pair<int,long long> > > auxList(cites+1);
    vector<long long> distanceArr (cites+1, -1);
    for(int i = 0;i<flights;i++){
        int firstCity;
        cin>>firstCity;
        int secondCity;
        cin>>secondCity;
        long long weight;
        cin>>weight;
        auxList[firstCity].push_back({secondCity, weight});
    }
    priority_queue<pair<long long, int> , vector<pair<long long,int > >, greater<pair<long long, int> > > q;
    q.push({0, 1});
    vector<bool> done (cites+1, false);
    distanceArr[1]=0;
    while(!q.empty()){
        pair<long long, int> top = q.top();
        q.pop();
        if(done[top.second]){
            continue;
        }
        done[top.second]=true;
        for(auto &it: auxList[top.second]){
            if((top.first+it.second<distanceArr[it.first] ||distanceArr[it.first] ==-1) ){
                distanceArr[it.first] =top.first+it.second;
                q.push({top.first+it.second,it.first});
            }
        }
    }
    for(int i =1;i<=cites;i++){
        cout<<distanceArr[i]<<" ";
    }
    return 0;
}
