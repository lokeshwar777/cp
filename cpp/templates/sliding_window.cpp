#define ll long long
#define cost(x) ((vec[x].size()>2)?vec[x][2]:1)

ll slide(vector<vector<int>>& vec, int k){ // non-overlapping intervals
    sort(vec.begin(),vec.end());
    ll curr=0,ans=0,n=vec.size(),partial;
    for(int i=0,j=0;i<n;++i){
        int l=vec[i][0],r=vec[i][1],windowLen=l+k-1;partial=0;
        while(j<n&&vec[j][1]<=windowLen)curr+=1LL*cost(j)*(vec[j][1]-vec[j++][0]+1);
        if(j<n)partial=1LL*max(0,windowLen-vec[j][0]+1)*cost(j);
        ans=max(ans,curr+partial);
        // cout<<i<<" "<<j<<" "<<curr<<" "<<partial<<" "<<ans<<endl;
        curr-=1LL*(r-l+1)*cost(i);
    }
    return ans;
}

ll reverseSlide(vector<vector<int>>& vec, int k){ // non-overlapping intervals
    sort(vec.begin(),vec.end());
    ll curr=0,ans=0,n=vec.size(),partial;
    for(int i=n-1,j=n-1;i>=0;--i){
        int l=vec[i][0],r=vec[i][1],windowLen=r-k+1;partial=0;
        while(j>=0&&windowLen<=vec[j][0])curr+=1LL*cost(j)*(vec[j][1]-vec[j--][0]+1);
        if(j>=0)partial=1LL*max(0,vec[j][1]-windowLen+1)*cost(j);
        ans=max(ans,curr+partial);
        // // cout<<i<<" "<<j<<" "<<curr<<" "<<partial<<" "<<ans<<endl;
        curr-=1LL*(r-l+1)*cost(i);
    }
    return ans;
}

int flipConsecutive(vector<int>& nums){
    int n=nums.size(),minops=0;
    for(int i=0,curr=0;i<n;++i){
        if(curr^nums[i])continue;
        minops++;
        curr^=1;
    }
    return minops;
}

// returns minops if possible else -1 using partial sum
int flipKConsecutive(vector<int>& nums,int k){
    int n=nums.size();
    vector<int>pre(n+k+1,0);
    int minops=0;
    for(int i=0,curr=0;i<n;++i,curr^=pre[i]){
        if(curr^nums[i])continue;
        if(i>n-k)return -1;
        minops++;
        pre[i+1]^=1;
        pre[i+k]^=1;
    }
    return minops;
}