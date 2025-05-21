import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
class Solution {
    public List<String> letterCombinations(String digits) {
        //initialize result list 
        List<String> result = new ArrayList<>();

        if (digits.isEmpty()) return result;

        //map each number to its letter combination (Like a phone)
        HashMap<Character, String> letter = new HashMap<>();

        
        letter.put('2', "abc");
        letter.put('3', "def");
        letter.put('4', "ghi");
        letter.put('5', "jkl");
        letter.put('6', "mno");
        letter.put('7', "pqrs");
        letter.put('8', "tuv");
        letter.put('9', "wxyz");

        //recursive backtrack with index 0 and empty combination
        backtrack(result, letter, digits, 0 , new StringBuilder() );
    
    return result;
    }

    //recursive helper function
    private void backtrack(List<String> result, Map<Character, String>letter, String digits, int index, StringBuilder current){

        // if combination's length matches digits length, it adds the combination to the result
         if (index == digits.length()) {
            result.add(current.toString());
            return;
    }

        //get the possible letters for the current digit
            String letters = letter.get(digits.charAt(index));

            //for each letter, add it to the current combination and recurse 
        for (char c : letters.toCharArray()) {
            current.append(c);
            backtrack(result, letter, digits, index + 1, current);
            current.deleteCharAt(current.length() - 1);
        }
    }

}
