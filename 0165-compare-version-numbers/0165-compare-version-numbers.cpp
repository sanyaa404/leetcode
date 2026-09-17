class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size(), n2 = v2.size();
        int i=0, j=0;

        while(i<n1 || j<n2){
            string t1 = "";
            while(i<n1 && v1[i]!='.'){
                t1+=v1[i];
                i++;
            }
            string t2 = "";
            while(j<n2 && v2[j]!='.'){
                t2+=v2[j];
                j++;
            }
            int num1 = t1.empty() ? 0 : stoi(t1);
            int num2 = t2.empty() ? 0 : stoi(t2);

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            i++;j++;
        }
        
        return 0;
    }
};