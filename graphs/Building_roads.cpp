#include <iostream>
#include <vector>
using namespace std;
void dfs(int currCity,vector<vector<int> > &auxList, vector<int> &visitedcities){
    if(visitedcities[currCity]!=-1){
        return;
    }
    visitedcities[currCity]=1;
    for(auto it: auxList[currCity]){
        dfs(it, auxList, visitedcities);
    }
}
int main(){
    int numOfCities;
    cin>>numOfCities;
    int numOfRoads;
    cin>>numOfRoads;
    vector<vector<int> > auxList (numOfCities+1);
    for(int i = 0;i<numOfRoads;i++){
        int city1;
        cin>>city1;
        int city2;
        cin>> city2;
        auxList[city1].push_back(city2);
        auxList[city2].push_back(city1);
    }
    int count = 0;
    vector<int> visitedArr(numOfCities+1, -1);
    vector<int> notConnected;
    for(int i = 1;i<=numOfCities;i++){
        if(visitedArr[i]==-1){
            dfs(i,auxList, visitedArr);
            count++;
            notConnected.push_back(i);
        }
    }
    int ans = count-1;
    cout<<ans<<endl;
    if(ans==0){
        return 0;
    }
    int len = notConnected.size();
    for(int i =1; i<len;i++){
        cout<<notConnected[0]<<" "<<notConnected[i]<<endl;
    }
    return 0;
}
