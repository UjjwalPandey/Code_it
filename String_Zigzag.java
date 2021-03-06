Problem:
	https://www.interviewbit.com/courses/programming/topics/strings/problems/zigzag/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

Solution:
*/
	public class Solution {
	public String convert(String a, int b) {
	    int level = 0;
	    int len = a.length();
	    if(len==1 || b==1){
	        return a;
	    }
	    String str = "";
	    int first_jump = 2*(b-1),i,flag,jump;
	    while(level<b){
	        flag = 0;
	        jump = 2*level;
	        for(i=level;i<len;){
	            str+= Character.toString(a.charAt(i));
	            if(level == 0 || level==(b-1)){
	                i += first_jump;
	                continue;
	            }
	            if(flag==0){
	                i+= (first_jump-jump);
	                flag=1;
	            }else if(flag==1){
	                i += jump;
	                flag =0;
	            }
	        }
	        level++;
	    }
	    return str;
	}
}
