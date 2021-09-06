class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        map<char, int> hashTable;
        map<char, int>::iterator it;
        hashTable[keysPressed[0]] = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            int timeDiff = releaseTimes[i] - releaseTimes[i-1];
            it = hashTable.find(keysPressed[i]);
            if (it == hashTable.end()) { // Not found in the hashTable. add it to the table
                hashTable[keysPressed[i]] = timeDiff;
            } else if (it->second < timeDiff) { // Found in hashTable, and new time diff is larger
                hashTable[keysPressed[i]] = timeDiff;
            }
        }
        char answer{'a'};
        int counter{INT_MIN};
        for (auto keyPair: hashTable) {
            if (keyPair.second > counter || keyPair.second == counter && keyPair.first > answer) {
                answer = keyPair.first;
                counter = keyPair.second;
            }
        }
        return answer;
    }
};
