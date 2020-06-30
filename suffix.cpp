#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define ll long long
#define pii pair<int,int>


int main() {
	string s;
	cin>>s;
	s+="$";   //added $ it will not affect suffix array as ascii value of $ is less.First value of suffix array is index of empty string n+1
	
	int n=s.size();
	
	vector<pair<char,int>> v(n);
	for(int i=0;i<n;i++)
	    v[i]={s[i],i};
	    
	sort(v.begin(),v.end());
	
	vector<int>p(n),c(n);
	
	for(int i=0;i<n;i++)
	    p[i]=v[i].second;   //stores index of starting character for unit length strings in sorted order (k=0)
	  
	c[p[0]]=0;      //equivalence class for first is 0
	for(int i=1;i<n;i++)
	{
	    if(v[i].first==v[i-1].first)
	        c[p[i]]=c[p[i-1]];
	    else
	        c[p[i]]=c[p[i-1]]+1;  //equivalence class if two strings are same they correspond to same class else value will be greater
	}
	
	int k=0;
	while((1<<k)<n)    //  for k=0 unit length then k=1  (length=2) then (length=4) and so on 
	{
	    vector<pair<pii,int>> v(n);
	    for(int i=0;i<n;i++)
	        v[i]={{c[i],c[(i+(1<<k))%n]},i};   // for length 2^k+1 we split into two halves each of length 2^k
	        
	   sort(v.begin(),v.end());   // sorting on the basis of equivalence class 
 	   for(int i=0;i<n;i++)
	    p[i]=v[i].second;   //generating suffix array p 
	  
    	c[p[0]]=0;
    	for(int i=1;i<n;i++)
    	{
    	    if(v[i].first==v[i-1].first)
    	        c[p[i]]=c[p[i-1]];
    	    else
    	        c[p[i]]=c[p[i-1]]+1;
    	}
    	k++;
	}
	
	//after log2(n) iterations at most all equivalence classes will be distinct then we get suffix array
	for(int i=0;i<n;i++)
	    cout<<p[i]<<"\t"<<s.substr(p[i],n-p[i])<<"\n";  
	    
	 return 0;
	
}