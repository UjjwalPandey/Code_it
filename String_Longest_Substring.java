/*Problem:
	https://www.interviewbit.com/courses/programming/topics/strings/problems/longestpalin/

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"


---------------------------------------------------------
Solution:	Using DYNAMIC PROGRAMMING
---------------------------------------------------------
*/
	public class Solution {
   
	public String longestPalindrome(String str) {
	    int n =  str.length(); // get length of input string
 
    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    boolean[][] table = new boolean[n][n];
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            table[i][j] = false;
        }
    }
 
    // All substrings of length 1 are palindromes
    int maxLength = 1,i;
    for( i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for(i = 0; i < n-1; ++i)
    {
        if (str.charAt(i) == str.charAt(i+1))
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2. k is length
    // of substring
    int k;
    for(k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for ( i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str.charAt(i) == str.charAt(j))
            {
                table[i][j] = true;
 
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
       return str.substring(start, start+maxLength);
	}
}


	
