// t-tree, tl-tree left, tr-tree right, tm-tree mid, v-node, x-new value, p-position
// queries [l,r]
int const MAXN=1e5;
int n,t[4*MAXN];// but requires only 2n-1 space

void build(vector<int>& a,int v,int tl,int tr){
    if(tl==tr)t[v]=a[tl];
    else{
        int tm=tl+(tr-tl)/2;
        build(a,2*v,tl,tm);build(a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}

int sum(int v,int tl,int tr,int l,int r){
    if(l>r)return 0;
    if(tl==l&&tr==r)return t[v];
    int tm=tl+(tr-tl)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v,int tl,int tr,int p,int x){
    if(tl==tr)t[v]=x;
    else{
        int tm=tl+(tr-tl)/2;
        if(tm<=pos)update(v*2,tl,tm,p,x);
        else update(v*2+1,tm+1,tr,p,x);
        t[v]=t[2*v]+t[2*v+1];
    }
}

int main(){
    n=a.size();
    build(a,1,0,n-1);
    return 0;
}