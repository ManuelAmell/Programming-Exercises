#include <iostream>
#include <vector>
using namespace std; 
int sumarr(const vector<int>& arr,int n){
	if (n==0){
		return 0;
	}
	return arr[n-1] + sumarr(arr, n-1);
}

int main(){
	vector<int> arr;
   	 	arr.push_back(1);
    	arr.push_back(2);
    	arr.push_back(3);
    	arr.push_back(4);
    	arr.push_back(5);

    int n = arr.size();
	cout << "Suma de elementos de la lista [1,2,3,4,5] = "<<sumarr(arr,n);
	return 0;
}
