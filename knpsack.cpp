#include<iostream>
using namespace std;
struct obj
{
    double profit; 
    double weight;
    double ratio; 
};

void input(obj arr[],int n){
for(int i=0; i<n ;i++){
    cout<<"\n enter weight";
    cin>>arr[i].weight;
    cout<<"\n enter profit";
    cin>>arr[i].profit;
    arr[i].ratio=(arr[i].profit/arr[i].weight);
    }
}

void sort(obj arr[],int n){
    obj temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].ratio < arr[j+1].ratio){
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
        }
    }
}

void output(obj arr[],int n, int w){
    int rw=w;
    double totalprofit=0;
    sort(arr,n);
    cout<<"weight\tprofit\tratio";
    for(int i=0;i<n;i++){
        cout<<"\n"<<arr[i].weight<<"\t"<<arr[i].profit<<"\t"<<arr[i].ratio;
    }  
    
    for(int i=0;i<n;i++){
        if(rw!=0){
            totalprofit=totalprofit+arr[i].profit;
            rw-=arr[i].weight;
        }
    }
    cout<<"\ntotal profit :"<<totalprofit;
}

int main(){
int n,w;
cout<<"\nEnter number of objects";
cin>>n;
cout<<"\nenter total bag weight";
cin>>w;
obj arr[n];
input(arr,n);
output(arr,n,w);
return 0;
}