// prefix sum - O(n) + O(n)space - suitable for n upto 1e5
int range_prefix(vector<int>& arr,int limit){
    int n=arr.size();
    map<int,int>prefix;
    for(int i=0;i<n/2;++i){
        int mini=min(arr[i],arr[n-i-1]),maxi=max(arr[i],arr[n-i-1]);
        int maxPossibleSum=maxi+limit;// max sum possibl with 1 change
        prefix[2]+=2; // 2 changes
        prefix[mini+1]--; // 1 change
        prefix[maxi+mini]--; // 0 change
        prefix[maxi+mini+1]++; // back to 1 change
        prefix[maxPossibleSum+1]++; // 2 changes
    }
    int ans=n,curr=0;
    for(auto &[k,v]:prefix){
        curr+=v;
        ans=min(curr,ans);
    }
    return ans;
}


// sweepline - O(nlogn) - when constraints are upto 1e9

// k intersections or k events at any time
long long sweepLine(vector<vector<int>>intervals,int k,int start,int end){
    vector<pair<int,int>>events;
    events.push_back({start-1,0});
    events.push_back({end+1,0});
    for(auto &x:intervals){
        events.push_back({x[0],+1});
        events.push_back({x[1],-1});
    }
    sort(events.begin(),events.end());
    // for(auto &[x,ty]:events)cout<<x<<" "<<ty<<endl;
    long long cnt=0,n=events.size(),curr=0;
    // handle inclusivity and exclusivity of intervals based on the problem
    for(int i=0;i<n-1;++i){
        curr+=events[i].second;
        if(curr==k)cnt+=max(0,events[i+1].first-events[i].first-1);
        // cout<<events[i].first<<" "<<events[i].second<<" "<<curr<<" "<<cnt<<endl;
    }
    return cnt;
}
// sweepLine(intervals,k,start,end);


// + or - a number with delta, perform this atmost limit times
long long sweepLine(vector<int>arr,long long delta,long long limit){
        vector<pair<int,int>>events;
        unordered_map<int,int>freq;
        for(auto &x:arr){
            freq[x]++;
            events.push_back({x-delta,-1}); // change
            events.push_back({x,0}); // existing
            events.push_back({x+delta,+1}); // revert
        }
        sort(events.begin(),events.end());
        // for(auto &[x,ty]:events)cout<<x<<" "<<ty<<endl;
        long long ans=0,curr=0,reqOps;
        for(auto &[x,ty]:events){
            curr-=ty;
            reqOps=curr-freq[x];
            ans=max(ans,freq[x]+min(reqOps,limit));
            // cout<<x<<" "<<ty<<" "<<curr<<" "<<ans<<endl;
        }
        return ans;
    }
// sweepLine(nums,k,numOperations);


// merge intervals
vector<vector<int>>res;
long long sweepLine(vector<vector<int>>intervals){ // using map
    map<int,int>events;
    for(auto &x:intervals){
        events[x[0]]++;
        events[x[1]]--;
    }
    // for(auto &[x,ty]:events)cout<<x<<" "<<ty<<endl;
    int start=-1,cnt=0;
    for(auto &[x,ty]:events){
        if(cnt==0)start=x;
        cnt+=ty;
        if(cnt==0)res.push_back({start,x});
    }
    return cnt;
}
long long sweepLine(vector<vector<int>>intervals){ // using vector (classical)
    vector<pair<int,int>>events;
    for(auto &x:intervals){
        events.push_back({x[0],+1});
        events.push_back({x[1],-1});
    }
    sort(events.begin(),events.end(),[&](auto a,auto b){
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
    });
    // for(auto &[x,ty]:events)cout<<x<<" "<<ty<<endl;
    int start=-1,cnt=0;
    for(auto &[x,ty]:events){
        if(cnt==0)start=x;
        cnt+=ty;
        if(cnt==0)res.push_back({start,x});
    }
    return cnt;
}
// sweepLine(intervals);return res;

