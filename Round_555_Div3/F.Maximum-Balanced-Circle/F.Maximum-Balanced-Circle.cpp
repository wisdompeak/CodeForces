int main() {
    int n;
    vector<int>nums;
    
    cin>>n;    
    nums.resize(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    sort(nums.begin(),nums.end());
    
    // n = 7;
    // nums = {4, 3, 5, 1, 2, 2, 1};
    
    map<int,int>Map;
    for (auto x:nums)
        Map[x]++;
    
    vector<pair<int,int>>pairs;
    for (auto a:Map)
        pairs.push_back(a);
    
    int start = 0;
    int maxLen = 0;
    int duration;
    for (int i=0; i<pairs.size(); )
    {
        int curLen = pairs[i].second;
        int j = i+1;
        int flag = 0;
        
        while (j<pairs.size() && pairs[j].first==pairs[j-1].first+1 && pairs[j].second>1)
        {
            curLen += pairs[j].second;
            j++;
        }        
        
        if (j<pairs.size() && pairs[j].first==pairs[j-1].first+1 && pairs[j].second==1)
        {
            curLen += 1;
            j++;
            flag = 1;
        }
        
        if (curLen>maxLen)
        {
            maxLen = curLen;
            start = i;
            duration = j-i;
        }
        
        if (flag==0)
            i = j;  
        else
            i = j-1;
    }        
    
    vector<int>a;
    vector<int>b;
    for (int i=start; i<start+duration; i++)
    {                
        a.push_back(pairs[i].first);
        for (int k=0; k<pairs[i].second-1; k++)
            b.push_back(pairs[i].first);        
    }
    
    reverse(b.begin(),b.end());
    cout<<maxLen<<endl;
    for (auto x:a)
        cout<<x<<" ";
    for (auto x:b)
        cout<<x<<" ";
}
