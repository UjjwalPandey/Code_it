/*
Problem:
	https://www.interviewbit.com/courses/programming/topics/stacks-and-queues/problems/evalexp/?ref=dash-reco
	
	Evaluate the value of an arithmetic expression in Reverse Polish Notation.

	Valid operators are +, -, *, /. Each operand may be an integer or another expression.

	Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
	Solution:
 */
 
 public class Solution {
    public int eval(int a, int b, String s){
        int res=0;
        switch(s){
            case "+": res = a+b;
                break;
            case "-": res = a-b;
                break;
            case "*": res = a*b;
                break;
            case "/": res = a/b;
                break;
        }
        return res;
    }
	public int evalRPN(ArrayList<String> a) {
	    Stack<Integer> s = new Stack<Integer>();
	    int size = a.size(), i, n1,n2, k;
	    for(i=0; i<size; i++){
	        String t = a.get(i);
	        try{
	            k = Integer.parseInt(t);
	            s.push(k);
	        }catch(NumberFormatException e){
	            n2 = s.pop();
	            n1 = s.pop();
	            s.push(eval(n1,n2,t));
	        }
	    }
	    return s.pop();
	}
	
}

  