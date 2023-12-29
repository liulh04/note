#include<iostream>
using namespace std;
 
 
 
int main(){
    int tmp;
	int i, j, r, k, t;
    int n;
    int arr[100];
    int l[100][100] = {0};
	
	cin >> n;
	for(int i = 0; i < n ;i++){
	    cin >> arr[i] >> tmp;
	}
	arr[n] = tmp;
 
	for(r = 1; r < n; r++){
		for(i = 1; i < n; i++){
			j = i+r;
			l[i][j] = l[i+1][j] + arr[i-1]*arr[i]*arr[j];
			for(k = i+1; k < j; k++){
			    t = l[i][k] + l[k+1][j] +arr[i-1]*arr[k]*arr[j];
				if(t < l[i][j]){
				    l[i][j] = t;
				}
			}
		}
	}
	cout << l[1][n] << endl;
}
