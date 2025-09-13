
class Solution {
    public boolean doesAliceWin(String s) {

    Set<Character> Vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
    boolean noVowels = false;
    int counter = 0;

    for(int i = 0; i < s.length(); i++){
    
    if(Vowels.contains(s.charAt(i))){
        counter++;
    }
    
    
    if(!Vowels.contains(s.charAt(i))){
        noVowels = true;
    }
    }

    if(noVowels == true && counter == 0){
        return false;
    }

    return true; 

    }
}
