//Last Solved on: 27 Nov, 2026, Friday
//Last Solved in: 45 minutes

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (!s.count(endWord)) return 0;
        unordered_set<string> visited;
        int changes = 1;
    
        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string word = q.front();
                q.pop();
                if(endWord == word) return changes;

                for(int i=0; i<word.length(); i++){
                    string arr = word;
                    
                    for(char k='a'; k<= 'z'; k++){
                        arr[i] = k;

                        if(s.count(arr) && !visited.count(arr)){    
                            q.push(arr);
                            visited.insert(arr);
                        }
                    }
                }
            }
            changes++;
        }
        return 0;
    }
};

//Pattern: BFS
//Add the word in queue
//From that word, add in the queue all the words you can create (after changing only one letter), that are in wordList.
//Increase the count to 1
//As soon as endWord is encountered, return the count