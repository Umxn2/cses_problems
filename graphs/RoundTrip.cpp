#include <iostream>
#include <vector>
using namespace std;
bool dfs(int index, int parent, vector<vector<int> > &auxList, vector<int> &visitedArr, vector<int> &visitedPath){
    visitedArr[index]=1;
    for(auto it: auxList[index]){
        if(visitedArr[it]!=-1&&it!=parent){
            visitedPath.push_back(it);
            return true;
        }
        else if(visitedArr[it]==-1){
            visitedPath.push_back(it);
            bool l = dfs(it, index, auxList, visitedArr, visitedPath);
            if(l){
                return true;
            }
            visitedPath.pop_back();
        }
    }
    return false;
}
int main(){
    int cities;
    cin>>cities;
    int roads;
    cin>>roads;
    vector<int> visitedArr(cities+1, -1);
    vector<vector<int> > auxList (cities+1);
    for(int i = 0;i<roads;i++){
        int city1;
        cin>>city1;
        int city2;
        cin>>city2;
        auxList[city2].push_back(city1);
        auxList[city1].push_back(city2);
    }
    vector<int> visitedPath;
    bool hasCycle = false;
    for(int i = 1;i<=cities;i++){
        if(visitedArr[i]==-1){
            visitedPath.push_back(i);
            if(dfs(i,1-1,auxList, visitedArr, visitedPath)){
               hasCycle = true;
               break;
            }
            visitedPath.pop_back();
        }
    }

    if(!hasCycle){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int len = visitedPath.size();
    //cout<<len<<endl;
    int last = visitedPath[len-1];
    bool isFound = false;
    vector<int> temp;
    for(auto it: visitedPath){
        if(it==last){
            isFound=true;
        }
        if(isFound){
            temp.push_back(it);
        }
    }
    len = temp.size();
    cout<<len<<endl;
    for(auto it: temp){
        cout<<it<<" ";
    }
    return 0;
}
