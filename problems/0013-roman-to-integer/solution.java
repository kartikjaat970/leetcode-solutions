public class Solution {
    public int romanToInt(String s) {
        int total = 0;
        int n = s.length();
        int prevVal = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int currentVal = 0;
            switch (s.charAt(i)) {
                case 'I': currentVal = 1; break;
                case 'V': currentVal = 5; break;
                case 'X': currentVal = 10; break;
                case 'L': currentVal = 50; break;
                case 'C': currentVal = 100; break;
                case 'D': currentVal = 500; break;
                case 'M': currentVal = 1000; break;
            }
            
            if (currentVal < prevVal) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
            prevVal = currentVal;
        }
        
        return total;
    }
}
