#include <stdio.h>
#include <stdbool.h>

//THIS CODE DOESN'T WORK ON ITS OWN, ITS JUST THE LEETCODE ANSWER

//THIS CODE IS NOT OPTIMIZED YET, IT TAKES TIME IN SOME TESTS

bool isPalindrome(int x) {
    int tam = 100;
    char str[tam];
    int start = 0;
    int end;   
    char temp;
    int y = x;

    //converts x to a string

    sprintf(str, "%d", x);

    // loop to switch the strings characters

    end = strlen(str ) - 1;
    while (start < end ){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start ++;
        end --;
    }
    
    //converts the string back to an intenger and tests if its palindrome or not

    sscanf(str, "%d", &x);   
    if( x == y ){
        return true;
    }
    else{
        return false;
    }

}