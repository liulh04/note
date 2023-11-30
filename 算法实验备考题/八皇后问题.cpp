/*
����
���8�ʺ��������н����

����
û�����롣

���
ÿ�������һ����No n������ʽ��n��ʾ������ǵڼ������������8�У�ÿ��8���ַ�����A����ʾ�ʺ󣬡�.����ʾ�ո񡣲�ͬ�Ľ���У��������һ���ʺ�λ�ÿ�ǰ�Ľ����
��һ���ʺ�λ����ͬ��������ڶ����ʺ�λ�ÿ�ǰ�Ľ�����������ơ�

��������
 ����������

�������
�����ǰ���У�
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

��ʾ
�����������ȷ��������ǰ���С�
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



