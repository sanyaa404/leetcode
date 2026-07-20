class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string comp = "";
        for(int i=0; i<n;){
            char ch = word[i];
            int cnt = 0;
            while(cnt < 9 && word[i] == ch){
                i++; cnt++;
                if(i >= n) break;
            }
            comp += to_string(cnt) + ch;
        }
        return comp;
    }
};