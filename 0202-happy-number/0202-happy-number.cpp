class Solution {
public:
    int getNext(int num){
        int sum = 0;
        while(num){
            sum += (num%10)*(num%10);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while(fast != 1 && slow!= fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return (fast == 1);
    }
};