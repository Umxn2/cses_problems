#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main(){
    int cities;
    cin>>cities;
    int routes;
    cin>>routes;
    vector< vector<pair<int,int> > > auxList (cities+1);
    for(int i = 0;i<routes;i++){
        int firstCity;
        cin>>firstCity;
        int secondCity;
        cin>>secondCity;
        int weight;
        cin>>weight;
        auxList[firstCity].push_back({secondCity, weight});
    }
    long long shorty =  LLONG_MAX;
    //node, sum, longest

    priority_queue <
    pair<int, pair<long long, int> >,
    vector<pair<int, pair<long long, int > > >,
    greater< pair<int, pair<long long, int> > >
    >
  // queue< pair<int, pair< long long, int > > >
    q;
    vector<int> distance_arr(cities+1,INT_MAX);
    q.push({1,{0,0}});
    while(!q.empty()){
        pair<int, pair<long long, int> > top = q.top();
        q.pop();
        for(auto it: auxList[top.first]){
            int newNode = it.first;
            int weight = it.second;
            int prevSum = top.second.first;
            int prevMax = top.second.second;
            int maxi = max(weight, prevMax);
            long long Newsum = top.second.first+ weight;
            distance_arr[newNode]=Newsum;
            q.push({newNode,{Newsum, maxi}});
            if(newNode==cities){
                // cout<<Newsum<<endl;
                // cout<<maxi<<endl;
                shorty = min(shorty,Newsum-maxi+maxi/2);
            }
        }
    }
    cout<<shorty;
    return 0;
}
