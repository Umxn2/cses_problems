#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int applicantNum;
    cin>>applicantNum;
    int apartmentNum;
    cin>>apartmentNum;
    int k;
    cin>>k;
    vector<long long> applicants (applicantNum);
    vector<int> apartments (apartmentNum);
    for(int i = 0;i<applicantNum;i++){
        cin>>applicants[i];
    }
    for(int i = 0;i<apartmentNum;i++){
        cin>>apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int applicantsSatisfied = 0;
    int applicantindex = 0;
    int apartmentindex = 0;
    while(applicantindex<applicantNum && apartmentindex<apartmentNum){
        long long minSize = apartments[apartmentindex]-k;
        long long maxSize = apartments[apartmentindex]+k;
        if(applicants[applicantindex]>=minSize && applicants[applicantindex]<=maxSize){
            applicantsSatisfied++;
            applicantindex++;
            apartmentindex++;
        }
        else if(applicants[applicantindex]<minSize){
            applicantindex++;
        }
        else {
            apartmentindex++;
        }
    }
    cout<<applicantsSatisfied;
    return 0;
}
