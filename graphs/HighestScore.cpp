#include <iostream>
#include <vector>
using namespace std;
bool checkIfConnected(int node, int end, vector< vector<long long > > &auxList, vector<int> &visitedArr){
    if(visitedArr[node]!=-1){
        return false;
    }
    visitedArr[node]=1;
    if(node == end){
        return true;
    }
    for(auto it: auxList[node]){
        if(checkIfConnected(it,  end, auxList,visitedArr)) return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector< vector<long long> > auxList;
    vector< vector< long long> > auxList2(n+1);
    for(int i = 0;i<q;i++){
        int fir;
        cin>>fir;
        int sec;
        cin>>sec;
        int weight;
        cin>>weight;
        vector<long long> temp;
        temp.push_back(fir);
        temp.push_back(sec);
        temp.push_back(weight*-1);
        auxList.push_back(temp);
        auxList2[fir].push_back(sec);
        }

vector<long long> distanceArr(n+1, 1e15);
distanceArr[1]=0;
for(int i =0;i<n-1;i++){
    for(int j = 0;j<q;j++){
        if(distanceArr[auxList[j][0]]!=1e15){
            if(distanceArr[auxList[j][1]]>(distanceArr[auxList[j][0]]+auxList[j][2])){
                distanceArr[auxList[j][1]]= distanceArr[auxList[j][0]]+auxList[j][2];
            }
        }
    }
}
    for(int j = 0;j<q;j++){
        if(distanceArr[auxList[j][0]]!=1e15){
            if(distanceArr[auxList[j][1]]>(distanceArr[auxList[j][0]]+auxList[j][2])){
                vector<int> visitedArr(n+1, -1);
                if(checkIfConnected(auxList[j][1], n, auxList2, visitedArr)){
                    cout<<"-1";
                    return 0;
                }
            }
        }

        }
cout<<distanceArr[n]*-1;
return 0;
}
