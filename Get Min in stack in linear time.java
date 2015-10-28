/*
Problem:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor
 
 Solution:
 
 */
 
 class Solution {
    Stack<Integer> stack;			//To store the stack.. normally
	Stack<Integer> min;				//storing min till that number
    public Solution(){
        min = new Stack<Integer>();
        stack = new Stack<Integer>();
    }
    public void push(int x) {
        stack.push(x);
        if(min.isEmpty()){
            min.push(x);
        }
		//Here's the logic... if number stored in the min-stack is greater than x, then push x to min stack.
        if(x < min.peek()){
            min.push(x);
        }
    }

    public void pop() {
        if(stack.isEmpty()){
            //do nothing
        }else{
            int n = stack.pop();
            if(!min.isEmpty()){
                if(n==min.peek()){
                    min.pop();
                }
            }
            
        }
    }

    public int top() {
        return (stack.isEmpty())?-1:stack.peek();
    }

    public int getMin() {
        if(min.isEmpty()){
            return -1;
        }
        return min.peek();
    }
}

 