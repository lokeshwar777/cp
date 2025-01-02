vector<int> getPrefixSum(vector<int>& vec){
    vector<int> presum(n+1,0);
    for(int i=0;i<n;++i) presum[i+1]=presum[i]+vec[i];
    return presum;
}

vector<int> pvec;
void kSum(vector<int>& vec){
    int presum=accumulate(vec.begin(),vec.begin()+k,0);
    pvec.push_back(presum);
    for(int i=k;i<n;++i){
        presum+=vec[i] - vec[i-k];
        pvec.push_back(presum);
    }
}