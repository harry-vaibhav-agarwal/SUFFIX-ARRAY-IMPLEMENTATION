#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define ll long long
#define pii pair<int,int>
int main() {
	string s;
	cin>>s;
	s+="$";
	
	int n=s.size();
	
	vector<pair<char,int>> v(n);
	for(int i=0;i<n;i++)
	    v[i]={s[i],i};
	    
	sort(v.begin(),v.end());
	
	vector<int>p(n),c(n);
	
	for(int i=0;i<n;i++)
	    p[i]=v[i].second;
	  
	c[p[0]]=0;
	for(int i=1;i<n;i++)
	{
	    if(v[i].first==v[i-1].first)
	        c[p[i]]=c[p[i-1]];
	    else
	        c[p[i]]=c[p[i-1]]+1;
	}
	
	int k=0;
	while((1<<k)<n)
	{
	    vector<pair<pii,int>> v(n);
	    for(int i=0;i<n;i++)
	        v[i]={{c[i],c[(i+(1<<k))%n]},i};
	        
	   sort(v.begin(),v.end());
	   for(int i=0;i<n;i++)
	    p[i]=v[i].second;
	  
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
	
	for(int i=0;i<n;i++)
	    cout<<p[i]<<"\t"<<s.substr(p[i],n-p[i])<<"\n";
	    
	 return 0;
	
}