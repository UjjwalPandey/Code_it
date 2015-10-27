/*
Problem: 
	https://www.interviewbit.com/courses/programming/topics/stacks-and-queues/problems/simplifypath/
	
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.




Solution:

First Approach: Correct but inefficeint in terms of time complexity.
*/
public class Solution {
    class MyStack{
            private int maxSize;
            private String[] stackArray;
            private int top=0;
            public MyStack(int s) {
              maxSize = s;
              stackArray = new String[maxSize];
              top = -1;
           }
           public void push(String j) {
              stackArray[++top] = j;
           }
           public String pop() {
              return stackArray[top--];
           }
           public String peek() {
              return stackArray[top];
           }
           public boolean isEmpty() {
              return (top == -1);
           }
           public boolean isFull() {
              return (top == maxSize - 1);
           }
    }
    
	public String simplifyPath(String a) {
	    if(a.equals("/") || a.equals("")){
	        return "/";
	    }
	    String[] arr = a.split("/");
	    int n= arr.length - 1;
	    MyStack theStack = new MyStack(n); 
	    for(int i=1; i<=n;i++){
	            if(arr[i].equals(".") || arr[i].equals("")){
	                continue;
	            }else
	            if(arr[i].equals("..")){
	               if(!theStack.isEmpty()){
	                    theStack.pop();
	                }
	            }else{
	                if(!theStack.isFull()){
	                    theStack.push(arr[i]);
	                }
	            }
	    }
	    if(theStack.isEmpty()){
           return "/";
         }
	    String s = "";
        while(!theStack.isEmpty()){
            s = "/"+theStack.pop()+s;
        }
       
        return s;
	}
}


/*

	Second Approach: Better One with better time complexity.

*/

public class Solution {
    public String simplifyPath(String path) {
    Stack<String> stack = new Stack<String>();
 
    //stack.push(path.substring(0,1));
 
    while(path.length()> 0 && path.charAt(path.length()-1) =='/'){
        path = path.substring(0, path.length()-1);
    }
 
    int start = 0;
    for(int i=1; i<path.length(); i++){
        if(path.charAt(i) == '/'){
            stack.push(path.substring(start, i));
            start = i;
        }else if(i==path.length()-1){
            stack.push(path.substring(start));
        }
    }
 
    LinkedList<String> result = new LinkedList<String>();
    int back = 0;
    while(!stack.isEmpty()){
        String top = stack.pop();
 
        if(top.equals("/.") || top.equals("/")){
            //nothing
        }else if(top.equals("/..")){
            back++;
        }else{
            if(back > 0){
                back--;
            }else{
                result.push(top);
            }
        }
    }
 
    //if empty, return "/"
    if(result.isEmpty()){
        return "/";
    }
 
    StringBuilder sb = new StringBuilder();
    while(!result.isEmpty()){
        String s = result.pop();
        sb.append(s);
    }
 
    return sb.toString();
}
}