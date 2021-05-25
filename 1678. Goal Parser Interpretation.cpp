class Solution {
public:
    string interpret(string command) {
        string answer;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                answer += 'G';
            } else {
                if (command[i] == '(') {
                    if (command[i+1] == ')') {
                        answer += 'o';
                        ++i;
                    } else {
                        answer += "al";
                        i += 3;
                    }
                }
            }
        }
        return answer;
    }
};
