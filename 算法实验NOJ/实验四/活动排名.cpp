#include<iostream>
using namespace std;
 
int main(){
   int i, j, tmp, num = 0;
   int n;
   int start[1001], end[1001];
 
   cin >> n;
   for(i = 0; i < n; i++){
       cin >> start[i] >> end[i];
   }
 
   for(i = 0; i < n-1; i++){
	   for(j = i; j < n; j++){
		   if(end[i] > end[j]){
		       tmp = end[i];
			   end[i] = end[j];
			   end[j] = tmp;
			   tmp = start[i];
			   start[i] = start[j];
			   start[j] = tmp;
		   }
	   }
   }
 
   i = 0;
   while(i < n){
        for(j = i+1; j < n && start[j] < end[i]; j++);
		num++;
		i = j;
   }
 
   cout << num << endl;
   return 0;
}
