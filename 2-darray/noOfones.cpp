#include<iostream>
#include<vector>
using namespace std;

int leftmostonerow(vector<vector<int > > &v){
    int leftmostone = -1;
    int maxonesrow = -1;
    int j=v.size()-1;
    while(j>=0 && v[0][j]==1){
    leftmostone = j;
    maxonesrow = 0;
    j--;

    }
    for(int i=1;i<v.size();i++){
        while(j>=0 && v[0][j]==1){
            leftmostone=j;
            maxonesrow = i;
            j--;
        }
            
        
    }
    return maxonesrow;

}




int maxOnesrow(vector<vector<int> > &v){
    int maxnoOfnes=INT_MIN;
    int maxrowindex = -1;
    int columns = v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<columns;j++){
            if(v[i][j]==1){
                int noOfones=columns - j;
                if(noOfones > maxnoOfnes){
                    maxnoOfnes = noOfones;
                    maxrowindex = i;
                }
                break;
            }
        }
    }
    return maxrowindex;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int res1 = maxOnesrow(v);
    int res2 = leftmostonerow(v);
    cout<<res2<<"\n";
    return 0;
}