#include <bits/stdc++.h>
using namespace std;
bool coins(int amt,int sum,vector<int> v,int i,vector<int> &cur,vector<vector<int> > &res)
{   if(i>=v.size())
    return false;
	if(sum+v[i]>amt)
	return false;
	cur.push_back(v[i]);
	sum+=v[i];
	if(sum==amt)
	{
		res.push_back(cur);
		return true; 
	}
	else
	{
		
	if(coins(amt,sum,v,i,cur,res))
		cur.pop_back();
	if(coins(amt,sum,v,i+1,cur,res))
		cur.pop_back();
	}
	cur.pop_back();
		return false;
	
}
bool solve(int amt,vector<int> v,vector<vector<int> > &res)
{
	vector<int> cur;
	coins(amt,0,v,0,cur,res);
	if(res.size()==0)
	return false;
	else
	return true;
}
int main() {
   string s="";
   getline(cin,s);
   int i=0;
   vector<int> v;
   bool firstTime=true;
   int no=0;
   int amt=0;
   while(s[i]!='\0')
   {
   	if(s[i]!=',')
   	{no=no*10+s[i]-'0';
   	}
   	else
   	{
   		if(firstTime)
   		{amt=no;
   		firstTime=false;
   		no=0;}
   		else
   		{v.push_back(no);
   		no=0;}
   	    
   	
   }
   i++;
   }
   v.push_back(no);
   vector<vector<int> > res;
   
   if(!solve(amt,v,res))
   cout<<"Nil";
   else
   {
   	for(int i=0;i<res.size();i++)
   	{
   		for(int j=0;j<res[i].size();j++)
   		cout<<res[i][j]<<",";
   		cout<<"\n";
   	}
   }
	return 0;
}
