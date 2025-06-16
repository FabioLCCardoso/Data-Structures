public class Solution {
    public String convert(String s, int numRows) {
        //Base cases: 1 row or rows >= strlength
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        //StringBuilder for each row
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }
        //Track current row index
        int currentRow = 0;
        //Direction (1 for up, -1 for down)
        int step = 1;
        
        //Iterate through each character
        for (char c : s.toCharArray()) {
            //append the current character to the strbuilder of the current row
            rows[currentRow].append(c);
            //change direction if we reach top row or bottom row
            if (currentRow == 0) {
                step = 1;
            } else if (currentRow == numRows - 1) {
                step = -1;
            }
            
            currentRow += step;
        }
        //combine all rows into a single strbuilder for the final result
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        
        return result.toString();
    }

