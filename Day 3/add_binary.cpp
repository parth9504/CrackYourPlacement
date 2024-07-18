class Solution {
public:
    string addBinary(string a, string b) {
        // make both the string of equal length..
        if (a.length() < b.length()) {
            int diff = b.length() - a.length();
            for (int i = 0; i < diff; i++) {
                a = "0" + a;
            }
        } else if (b.length() < a.length()) {
            int diff = a.length() - b.length();
            for (int i = 0; i < diff; i++) {
                b = "0" + b;
            }
        }

        int i,carry=0;
        string res;
        for (i = a.length() - 1; i >= 0; i--) {

            // if both are 0's
            if (a[i] == '0' && b[i] == '0') {
                // check if carry is 0
                if (carry == 0) {
                    res = "0" +res;
                } else {
                    res = "1" +res;
                    carry = 0; // set carry to 0 now
                }
            }

            // if both of them 1's
            else if (a[i] == '1' && b[i] == '1') {
                // check for carry
                if (carry == 0) {
                    res = "0"+res;
                    carry = 1; // set carry to 1
                } else {
                    res = "1"+res;
                    carry = 1;
                }
            }

            // if either of them is 1
            else if (a[i] == '1' || b[i] == '1') {
                // check for carry
                if (carry == 0) {
                    res = "1"+res;
                } else {
                    res = "0"+res;
                    carry = 1;
                }
            }
        }
        //if carry is still 1..
        if(carry==1){
            res="1"+res;}
        return res;
    }
};
