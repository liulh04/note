#include<iostream>
//#include<float.h>
#include<stdio.h>
#define DBL_MAX 1.7976931348623158e+308
using namespace std;
/************************/
int n;
double length;
double cap,mile,cost;
double dist[51],prize[51];
/************************/
int addoil[51];
double memo[51];//备忘录
double maxdist; //the max dist after pour in oil
/***********************/
double dp(int i);
double dp(int i)
{
	if(i==n+1)
		return cost;
	else if(memo[i]!=DBL_MAX)
		return memo[i];
	else
	{
		double fuel_j; //fuel from i to j
		double fuel_rest; //the rest fuel after from i to j
		double cost_j; //from i to j and add oil in j
		double cost_j_n; //total cost from i to j to end
		int addoil_j=-1; //the station need to add oil
		for(int j=i+1;j<=n+1 && (dist[j]-dist[i])<=maxdist;j++)
		{
			fuel_j=(dist[j]-dist[i])/mile;
			fuel_rest=cap-fuel_j;
			if(fuel_rest>cap/2 && fuel_rest*mile>=(dist[j+1]-dist[j]))
				continue;
			if(j==n+1)
				cost_j=0;
			else
			{
				cost_j=2;
				cost_j+=fuel_j*prize[j]; //消耗的油*油价=加满油
			}
 
			cost_j_n=cost_j+dp(j);
 
			if(memo[i]>cost_j_n)
			{
				memo[i]=cost_j_n;
				addoil_j=j;
			}
		}
		if(addoil_j!=-1)
			addoil[addoil_j]=1;
		return memo[i];
	}
}
 
int main()
{
	int count=0;
	cin>>length;//input
	cin>>cap>>mile>>cost>>n;
	int i=1;
	while(i<=n)
	{
		cin>>dist[i]>>prize[i];
		i++;
	}
	for(int i=0;i<=n;i++)
	{
		memo[i]=DBL_MAX;
	}
	dist[0]=0;
	dist[n+1]=length;
	maxdist=cap*mile;//
 
	double mincost=dp(0);
 
	printf("%.2lf ",mincost);//first line
	for(int i=1;i<=n;i++)
	{
		if(addoil[i])
			count++;
	}
	cout<<count<<endl;//second line
	for(int i=1;i<=n;i++)
	{
		if(addoil[i])
			cout<<i<<" ";
	}
	cout<<endl;//
	return 0;
}

