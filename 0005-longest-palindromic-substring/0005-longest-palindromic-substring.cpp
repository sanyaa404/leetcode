class Solution {
public:
    string longestPalindrome(string s) {
        string str = "#";
        for(char ch: s){
            str += ch;
            str += '#';
        }
        int n = str.size();

        vector<int> p(n);
        p[0]=0;

        int l=0, r=0; // left and right of longest rightmost palindrome yet
        int centre, maxi=1;

        for(int i=0; i<n; i++){
            int k;
            if(i>r) k=0;
            else{
                int j = l + (r-i);
                if(j-p[j] > l){
                    p[i] = p[j];
                    continue;
                }else{
                    k = r-i;
                }
            }

            while(i-k >=0 && i+k < n && str[i-k] == str[i+k]){
                k++;
            }
            k--;
            p[i] = k;

            if(p[i] > maxi){
                maxi = p[i];
                centre = i/2;
            }

            if(i+k > r){
                l = i-k; 
                r = i+k; //new longest rightmost palindrome
            }
        }

        return s.substr(centre-(maxi/2), maxi);
    }
};