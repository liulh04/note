#include<iostream>
#include<algorithm>
using namespace std;
 
int main(){
	int n;
	int arr1[300],arr2[300];
	int l[300][300];
	while(cin >> n && n){
		for(int i = 0; i < n; i++){
		    cin >> arr1[i];
		}
		for(int i = 0; i < n; i++){
			cin >> arr2[i];
		}
		sort(arr1, arr1+n, greater<int>());
		sort(arr2, arr2+n, greater<int>());
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
			    l[i][j] = 0;
			}
		}
 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i; j++){
				if(arr1[j-1] > arr2[i-1]){
				    l[j][i] = l[j-1][i-1] + 1;
				}
				else if(arr1[j-1] == arr2[i-1]){
				    l[j][i] = max(l[j-1][i-1], l[j-1][i] - 1);
				}
				else{
				    l[j][i] = l[j-1][i] - 1;
				}
			}
		}
		cout << l[n][n] << endl;
	}
}
