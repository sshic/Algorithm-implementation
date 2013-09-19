class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        
        dict.erase(start);
        queue<pair<string, int> > q;
        q.push(pair<string, int>(start, 1));
        
        while (!q.empty()) {
            pair<string, int> cur = q.front();
            if (cur.first == end)
                return cur.second;
            q.pop();
            for (int n=0; n<(cur.first).size(); n++) {
                string word = cur.first;
                int stop = word[n] - 'a';
                for (int i=(stop+1)%26; i!=stop; i=(i+1)%26) {
                    word[n] = 'a' + i;
                    if (dict.find(word) != dict.end()) {
                        q.push(pair<string, int>(word, cur.second+1));
                        dict.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};