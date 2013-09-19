
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        bool isNum[4000000001];
        for(int i=0;i<4000000001;i++){
            isNum[i] = false;
        }
        for(int i=0;i<num.size();i++){
            isNum[num[i]] = true;
        }
        int maxConsecutive = 0;
        int tmp;
        for(int i=0;i<num.size();i++){
            if(isNum[num[i]]==true){
                ++tmp;
                int f = num[i];
                while(isNum[++f]){
                    ++tmp;
                    isNum[f] = false;
                }
                f = num[i];
                while(isNum[--f]){
                    ++tmp;
                    isNum[f] = false;
                }
            }
            if(isNum[i]==false && tmp!=0){
                if(maxConsecutive<tmp)
                    maxConsecutive = tmp;
                tmp = 0;
            }
        }
        return maxConsecutive;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        unordered_map<int, int> hashTable;
        for (int i=0; i<num.size(); i++)
            hashTable[num[i]] = num[i];
        while (!hashTable.empty()) {
            int cur = 0;
            int target = (hashTable.begin())->second;
            cur += consecutiveLength(hashTable, target, -1);
            cur += consecutiveLength(hashTable, target+1, 1);
            if (cur > max)
                max = cur;
        }
        
        return max;
    }
    
private:
    int consecutiveLength(unordered_map<int, int> &hashTable, int target, int step) {
        int count = 0;
        while (hashTable.find(target) != hashTable.end()) {
            count++;
            hashTable.erase(target);
            target += step;
        }
        return count;
    }
};
