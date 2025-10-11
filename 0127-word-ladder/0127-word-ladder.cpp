class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>set1(wordList.begin(),wordList.end());
        if(set1.count(endWord)<=0) return 0;
        q.push({beginWord,1});
        unordered_set<string>vis;
        vis.insert(beginWord);
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(set1.count(word)>0 && vis.count(word)<=0){
                        q.push({word,steps+1});
                        vis.insert(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0; //return -1 if no such sequence found
    }
};