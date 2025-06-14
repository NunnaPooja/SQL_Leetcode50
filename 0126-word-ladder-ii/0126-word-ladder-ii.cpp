class Solution {
public:
void f(string &word,vector<string>&v,string startWord, unordered_map<string,int>&mpp,vector<vector<string>>&ans){
    if(word==startWord){
        reverse(v.begin(),v.end());
        ans.push_back(v);
        reverse(v.begin(),v.end());
        return;
    }
    int steps=mpp[word];
    for(int i=0;i<word.size();i++){
        char original=word[i];
        for(char c='a';c<='z';c++){
            word[i]=c;
            if(mpp.find(word)!=mpp.end() && steps-1==mpp[word]){
                 v.push_back(word);
                f(word,v,startWord,mpp,ans);
                v.pop_back(); //remove from vector during callback recursive call
            }
        }
        word[i]=original;
    }
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //rather than storing the whole sequence everytime we can store the min level and store them in map ds and then backtrack
        unordered_set<string>st(wordList.begin(),wordList.end());
        int n=beginWord.size();
        queue<pair<string,int>>q;
        unordered_map<string,int>mpp;
        q.push({beginWord,1});
        mpp[beginWord]=1;
        st.erase(beginWord); //example startword='a' endword='c',wordlist=['a' ,'b' ,'c'] 
        //if u dont remove 'a' initally then while checking for char loop it will again store 'a' in mpp
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) break;//stop further iteration
            // don't unecessarily store other string indices before endword as we need to store min steps
            for(int i=0;i<n;i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                     q.push({word,steps+1}); //u need to find minimum steps for each string
                     mpp[word]=steps+1;
                }
            }
            word[i]=original;
        }
        }
        //u cannot be sure if the map has endWord
        //so u need to check for endWord before starting backtrack
        vector<vector<string>>ans;
        if(mpp.find(endWord)!=mpp.end()){
        vector<string>v={endWord};
          f(endWord,v,beginWord,mpp,ans);
        }
        return ans;
    }
};