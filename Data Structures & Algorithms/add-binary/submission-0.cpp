class Solution {
    int toInt(char c){
        return c - '0';
    }
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
            return addBinary(b, a);


        int carry = 0;
        for(int i = a.length()-1, j = b.length()-1; i>= 0; i--, j--){
            int sum = toInt(a[i]) + (j >= 0? toInt(b[j]): 0) + carry;
            a[i] = '0' +(sum % 2);
            carry = (sum >= 2);
        }

        if(carry)
            return "1" + a;
        return a;
    }
};