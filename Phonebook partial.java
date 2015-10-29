public class Solution {
        ArrayList<String> arr;
        String[] hashTable = {"0", "1", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
        void  printWordsUtil(String number, int curr_digit, String output, int n){
                // Base case, if current output word is prepared
                int i;
                if (curr_digit == n)
                {
                    arr.add(output);
                    return ;
                }else{
             
                    // Try all 3 possible characters for current digir in number[]
                    // and recur for remaining digits
                    int cur = Integer.parseInt(Character.toString(number.charAt(curr_digit)));
                    for (i=0; i< hashTable[cur].length(); i++)
                    {
                        if (number.charAt(curr_digit) == 0 || number.charAt(curr_digit) == 1){
                            output = Character.toString(number.charAt(curr_digit));
                        }else{
                            output = Character.toString(hashTable[cur].charAt(i));
                        }
                        printWordsUtil(number, curr_digit+1, output, n);
                        /*if (number.charAt(curr_digit) == 0 || number.charAt(curr_digit) == 1)
                            return;*/
                    }
                }
            }
 
        // A wrapper over printWordsUtil().  It creates an output array and
        // calls printWordsUtil()
        void printWords(String number, int n){
            String result="";
            printWordsUtil(number, 0, result, n);
        }
    
    	public ArrayList<String> letterCombinations(String a) {
	        arr = new ArrayList<String>();
	        int n = a.length();
    	    printWords(a, n);
    	    return arr;
	    }
    
    
    
}
