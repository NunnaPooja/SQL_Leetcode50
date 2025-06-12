class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs
        //add wordList elements into set for an easy search
    /*Search Complexity:
    std::vector:
    If unsorted, linear search O(N)
    If sorted, binary search can be used O(logn)).

    std::set: Search is always logarithmic (O(logn)) because of its tree structure.
    Ease of Use:
    Searching in a vector requires you to manage sorting explicitly if you want efficient search (e.g., std::sort followed by std::binary_search).
    In a set, elements are always sorted, and searching is straightforward using methods like set.find().*/
    unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord) return level;
            // for(auto it:word){
            //    char original=it;
                // for(char c='a';c<='z';c++){
                //     it=c;
                //   if(st.find(word)!=st.end()){
                //     q.push({word,level+1});  
                //   st.erase(word);
                //   }
                // }
                // it=original;
                /*Your implementation has a logical issue: it is a copy of the character in word and not a reference.
                 This means modifying it will not update the original word. To fix this, you need to iterate over word
                  by reference or directly access its characters using an index.*/
                  for(int i=0;i<word.size();i++){
                    char original=word[i];
                    for(char c='a';c<='z';c++){
                        word[i]=c;
                        if(st.find(word)!=st.end()){
                            q.push({word,level+1});
                            st.erase(word);
                        }
                    }
                    word[i]=original;
                  }
        }
        return 0;
    }
};