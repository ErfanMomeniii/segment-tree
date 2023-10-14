#include<bits/stdc++.h>
using namespace std;

const int maxn=4e6+10;

int n;
int a[maxn];
int seg[maxn];

void input();
void build(int root,int l,int r);
void output();
int get(int root,int l,int r,int x,int y);

int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	input();
	build(1,0,n);
	output();
}

void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void build(int root,int l,int r){
	if(r-l==1){
		seg[root]=a[l];
		return;
	}
	
	int mid = l+r;
	mid/=2;
	
	build(2*root,l,mid);
	build(2*root+1,mid,r);
	
	seg[root]=min(seg[root<<1],seg[(root<<1)|1]);
	return;
}

void output(){
	int l;
	int r;
	cin>>l>>r;
	cout<<get(1,0,n,l-1,r)<<endl;
}

int get(int root,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return seg[root];
	}
	
	if(r<=x||y<=l){
		return INT_MAX;
	}
	
	int mid=l+r;
	mid/=2;
	return min(get(root<<1,l,mid,x,y),get((root<<1)|1,mid,r,x,y));
}
