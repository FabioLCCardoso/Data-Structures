#include <stdio.h>
#include <stdbool.h>

//THIS IS THE OPTMIZED CODE, WITHOUT CONVERTING THE NUMBER TO STRINGS.
//FOR SOME REASON IT DOESNT WORK!!! 


bool isPalindrome(int x) {
    // tests if the numbers are negative and multiples of 10, those are not palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int start = x;
    int reverse = 0;
    
    while (x > 0) {
        // y gets the last digit of x
        int y = x % 10;       
        // puts the first digit on the end of reverse
        reverse = reverse * 10 + y;
        //removes the last digit of x  
        x /= 10;                  
    }

    return start == reverse;
}

