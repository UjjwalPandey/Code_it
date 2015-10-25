/*Problem:
https://www.interviewbit.com/courses/programming/topics/arrays/problems/largestnum/

Given a list of non negative integers, arrange them such that they form the largest number.
For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Solution:
*/
public class Solution {
	// DO NOT MODIFY THE LIST
	public String largestNumber(final List<Integer> a) {
	    //Convert Integer to String array.
		String[] str = new String[a.size()];
	    for(int i=0; i< a.size(); i++){
	        str [i] = String.valueOf(a.get(i));
	    }
		//Use a Comparator function to Sory as per the value of concatenation of strings.
	    Arrays.sort(str,new Comparator<String>(){
    	        public int compare(String s1, String s2){
                String leftRight = s1+s2;
                String rightLeft = s2+s1;
                return -leftRight.compareTo(rightLeft);
     
            }
	    });
	    StringBuilder sb = new StringBuilder();
    for(String s: str){
        sb.append(s);
    }
 
    while(sb.charAt(0)=='0' && sb.length()>1){
        sb.deleteCharAt(0);
    }
 
    return sb.toString();
	}
}
