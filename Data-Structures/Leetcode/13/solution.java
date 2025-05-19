import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        
        HashMap<Character, Integer> RomantoInt = new HashMap<Character, Integer>();

        RomantoInt.put('I', 1);
        RomantoInt.put('V', 5);
        RomantoInt.put('X', 10);
        RomantoInt.put('L', 50);
        RomantoInt.put('C', 100);
        RomantoInt.put('D', 500);
        RomantoInt.put('M', 1000);

        int result = 0;

        for(int i = 0; i < s.length(); i++){
            if( i + 1 < s.length() && RomantoInt.get(s.charAt(i)) < RomantoInt.get(s.charAt(i + 1))){
                result += RomantoInt.get(s.charAt(i+1)) - RomantoInt.get(s.charAt(i));

                i++;
            }
            else {
                result += RomantoInt.get(s.charAt(i));
            }

        }
            return result;

    }
}