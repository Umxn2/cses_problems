#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparator(vector<int> &first, vector<int> &second){
    if(first[1]<second[1]){
        return true;
    }
    return false;
}
int main(){
    int numofmovies;
    cin>>numofmovies;
    vector<vector<int> > timings (numofmovies);
    for(int i = 0;i<numofmovies;i++){
        vector<int> temp (2);
        cin>>temp[0];
        cin>>temp[1];
        timings[i]=temp;
    }
    sort(timings.begin(), timings.end(), comparator);
    int count= 0;
    int startEnding = timings[0][1];
    count++;
    for(auto it: timings){
        if(it[0]>=startEnding){
            count++;
            startEnding = it[1];
        }
    }
    cout<<count;
return 0;
}
