vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        
        for(auto c:strs){
            string temp=c;
            vector<int>freq(26,0);
            for(int i=0;i<temp.length();i++){
                freq[temp[i]-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=freq[i];
            }
            mp[key].push_back(c);
        }
        for(auto i:mp){
            res.push_back(i.second);
        }   
        return res;
    }