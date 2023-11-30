/*
描述
输出8皇后问题所有结果。

输入
没有输入。

输出
每个结果第一行是No n：的形式，n表示输出的是第几个结果；下面8行，每行8个字符，‘A’表示皇后，‘.’表示空格。不同的结果中，先输出第一个皇后位置靠前的结果；
第一个皇后位置相同，先输出第二个皇后位置靠前的结果；依次类推。

输入样例
 无输入样例

输出样例
输出的前几行：
No 1:
A.......
....A...
.......A
.....A..
..A.....
......A.
.A......
...A....
No 2:
A.......
.....A..
.......A
..A.....
......A.
...A....
.A......
....A...

提示
输出样例是正确输出结果的前几行。
*/
#include<stdio.h>
#define n 8
#define N 8
int isSafe(int row,int col, char board[n][n]){
	
	for(int i=0;i<row;i++){
		if(board[i][col]=='A'){
			return 0;
		}
	}
	for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
		if(board[i][j]=='A'){
			return 0;
		}
	}
	for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
		if(board[i][j]=='A'){
			return 0;
		}
	}
	
	return 1;
}
void Printf(char board[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c",board[i][j]);
		}
			printf("\n");
	}

}
void  solveq(char board[n][n],int row,int *solution){
	if(row==n){
		(*solution)++;
		printf("No:%d\n",*solution);
		Printf(board);
		return ;
	}
	
	for(int col=0;col<n;col++){
		if(isSafe(row,col,board)){
			board[row][col]='A';
			solveq(board,row+1,solution);
			board[row][col]='.';
		}
	}
	
}
void fineallsolutions(){
	
	char board[n][n];
	int solution=0;
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]='.';
			
		}
	}
	
	solveq(board,0,&solution);
	
	
}
int main(){
	
	fineallsolutions();
	return 0;
}



