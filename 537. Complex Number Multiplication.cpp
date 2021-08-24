class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> c1 = splitComplexNumber(num1);
        vector<int> c2 = splitComplexNumber(num2);
        int r1 = c1.at(0);
        int i1 = c1.at(1);
        int r2 = c2.at(0);
        int i2 = c2.at(1);
        
        int r = r1*r2 - i1*i2;
        int i = r1*i2 + r2*i1;
        return to_string(r)+"+"+to_string(i)+"i";
    }
    
    vector<int> splitComplexNumber(string num) {
        // Find the position of + to split the real and imaginary part
        std::size_t found = num.find('+');
        int real = stoi(num.substr(0,found));
        int img = stoi(num.substr(found+1, num.size()-found-1));
        return {real, img};
    }
};
