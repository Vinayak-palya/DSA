#include<iostream>
using namespace std;
void selectionsort(char fruit[][60],int n){
    for(int i = 0;i < n;i++){
        //finding the min element 
        int min_idx = i;
        for(int j = i+1;j < n;j++){
            if(strcmp(fruit[min_idx],fruit[j]) > 0){
                min_idx = j;
            }
        }
        if(i != min_idx){
            swap(fruit[i],fruit[min_idx]);
        }
    }
    return ;
    // time complexity == O(nsquare);
    //space complexities == O(1);
}
int main(){
    char fruit[][60] = {"papaya","lime","watermelon","apple","mango","kiwi"};
    int n = sizeof(fruit)/sizeof(fruit[0]);
    selectionsort(fruit,n);
    for(int i = 0;i < n;i++){
        cout<<fruit[i]<<" ";
    }cout<<endl;
    return 0 ;
}