#include <bits/stdc++.h>
#include <iostream>

using namespace std;
bool checkIfConnected(int node, vector< vector<long long > > &auxList, vector<int> &visitedArr){
    if(visitedArr[node]!=-1){
        cout<<node;
        return true;
    }
    cout<<node<<" ";
    visitedArr[node]=1;
    for(auto it: auxList[node]){
        if(checkIfConnected(it,  auxList,visitedArr)) return true;
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
    temp.push_back(weight);
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
           // visitedArr[auxList[j][1]]=1;
           cout<<"YES"<<endl;
            checkIfConnected(auxList[j][1], auxList2, visitedArr);
            return 0;
        }
    }

    }
    cout<<"NO";
    return 0;
}
