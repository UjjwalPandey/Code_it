/*Problem:
	https://www.interviewbit.com/courses/programming/topics/strings/problems/int2roman/
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.


Solution:
*/
public class Solution {
	public String intToRoman(int A) {
    	int q_t = A/1000, r_t= A%1000;
        int q_h=r_t/100, r_h= r_t%100;
        int q_te = r_h/10,r_te=r_h%10;
        String str="";
        int count =0;
        switch(q_t){
            case 1: str += "M"; break;
            case 2: str += "MM"; break;
            case 3: str += "MMM"; break;
        }
        switch(q_h){
            case 1  : str += "C"; break;
            case 2  : str += "CC"; break;
            case 3  : str += "CCC"; break;
            case 4  : str += "CD"; break;
            case 5  : str += "D"; break;
            case 6  : str += "DC"; break;
            case 7  : str += "DCC"; break;
            case 8  : str += "DCCC"; break;
            case 9  : str += "CM"; break;
            
        }
        
        switch(q_te){
            case 1  : str += "X"; break;
            case 2  : str += "XX"; break;
            case 3  : str += "XXX"; break;
            case 4  : str += "XL"; break;
            case 5  : str += "L"; break;
            case 6  : str += "LX"; break;
            case 7  : str += "LXX"; break;
            case 8  : str += "LXXX"; break;
            case 9  : str += "XC"; break;
            
        }
        switch(r_te){
            case 1  : str += "I"; break;
            case 2  : str += "II"; break;
            case 3  : str += "III"; break;
            case 4  : str += "IV"; break;
            case 5  : str += "V"; break;
            case 6  : str += "VI"; break;
            case 7  : str += "VII"; break;
            case 8  : str += "VIII"; break;
            case 9  : str += "IX"; break;
            
        }
        return str;
        
	}
}
