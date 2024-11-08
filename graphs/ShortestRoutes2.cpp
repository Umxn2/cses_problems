#include <iostream>
#include <random>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int cities;
    cin>>cities;
    int roades;
    cin>>roades;
    int queries;
    cin>>queries;
    vector< vector<long long > > costMatrix(cities+1, vector<long long > (cities+1));
    for(int i = 0;i<=cities;i++){
        for(int j =0;j<=cities;j++){
            if(i==j){
                costMatrix[i][j]=0;
            }
            else{
                costMatrix[i][j]=1e16;
            }
        }
    }
    for(int i = 0;i<roades;i++){
        int firstCity;
        cin>>firstCity;
        int secondCity;
        cin>>secondCity;
        long long weight;
        cin>>weight;
        costMatrix[firstCity][firstCity]=0;
        costMatrix[secondCity][secondCity]=0;
        costMatrix[firstCity][secondCity]=min(weight, costMatrix[firstCity][secondCity]);
        costMatrix[secondCity][firstCity]=min(weight, costMatrix[secondCity][firstCity]);
    }
    cout<<endl;
    for(int via = 1;via<=cities;via++){
        for(int i = 1;i<=cities;i++){
            for(int j = 1;j<=cities;j++){
                costMatrix[i][j]= min(costMatrix[i][j], costMatrix[i][via]+costMatrix[via][j]);
            }
        }
    }
    for(int i = 0;i<queries;i++){
        int firstCityQ;
        cin>>firstCityQ;
        int secondCityQ;
        cin>>secondCityQ;
        long long ans = costMatrix[firstCityQ][secondCityQ];
        ans==1e16?cout<<"-1"<<endl:cout<<ans<<endl;
       // cout<<cout<<costMatrix[firstCityQ][secondCityQ]<<endl;
    }
    return 0;
}
