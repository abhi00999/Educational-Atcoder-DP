#include <bits/stdc++.h>
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define ARR(i,n) for(ll i=n-1;i>=0;i--)
#define F(i,a,b)  for(ll i=b-1;i>=a;i--)
#define float double
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ceil(a) (ll) ceil(a)
#define floor(a) (ll) floor(a)
#define pow(a,b) (ll) pow(a,b)
#define fixed(x) cout<<fixed<<setprecision(6)<<x;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define integer_to_string to_string 
#define IOS  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;
const ll  mod = 1000000000 + 7;
/*freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);*/
ll a[100001],b[100001],c[100001],t[100001][3];

ll vacation(ll a[],ll b[],ll c[],ll aa,ll bb,ll cc,ll n){
	if(n==1 && aa==1) return max(b[n-1],c[n-1]);
	else if(n==1 && bb==1) return max(a[n-1],c[n-1]);
	else if(n==1 && cc==1) return max(a[n-1],b[n-1]);
	else if(n==1) return max(max(a[n-1],b[n-1]),c[n-1]);



	if(aa==0 && bb==0 && cc==0){
    ll p= a[n-1]+vacation(a,b,c,1,0,0,n-1);
	ll q= b[n-1]+vacation(a,b,c,0,1,0,n-1);
	ll r= c[n-1]+vacation(a,b,c,0,0,1,n-1);
    t[n-1][0]=p;
    t[n-1][1]=q;
    t[n-1][2]=r;
    return max(max(t[n-1][0],t[n-1][1]),t[n-1][2]);
    }
    else if(aa==1 && bb==0 && cc==0){
    	if(t[n-1][0]!=-1) return t[n-1][0];
	ll q= b[n-1]+vacation(a,b,c,0,1,0,n-1);
	ll r= c[n-1]+vacation(a,b,c,0,0,1,n-1);
    t[n-1][0]=max(q,r);
    return t[n-1][0];
    }
    else if(aa==0 && bb==1 && cc==0){
    	if(t[n-1][1]!=-1) return t[n-1][1];
	ll p= a[n-1]+vacation(a,b,c,1,0,0,n-1);
	ll r= c[n-1]+vacation(a,b,c,0,0,1,n-1);
    t[n-1][1]=max(p,r);
    return t[n-1][1];
    }
    else if(aa==0 && bb==0 && cc==1){
    	if(t[n-1][2]!=-1) return t[n-1][2];
	ll p= a[n-1]+vacation(a,b,c,1,0,0,n-1);
	ll q= b[n-1]+vacation(a,b,c,0,1,0,n-1);
	t[n-1][2]=max(p,q);
	return t[n-1][2];
    }
    
	
}

void solve()
{
	ll n;
	cin>>n;
	lp(i,0,n) cin>>a[i]>>b[i]>>c[i];
	memset(t,-1,sizeof(t));
	ll aa=0,bb=0,cc=0;
	cout<< vacation(a,b,c,aa,bb,cc,n);
}
int main()
{
    IOS;
    int t=1;
    //cin>>t;
    while(t--)
      solve();
    return 0;
}