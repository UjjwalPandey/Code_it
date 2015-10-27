/*
Problem:
	https://www.interviewbit.com/courses/programming/topics/stacks-and-queues/problems/nearest/?ref=dash-reco
	
	Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

	More formally,

	G[i] for an element A[i] = an element A[j] such that 
		j is maximum possible AND 
		j < i AND
		A[j] < A[i]
	Elements for which no smaller element exist, consider next smaller element as -1.


Solution:
		Approach One: Time Complexity O(n square). A Brute force method
*/
    
       
 public class Solution {
    public ArrayList<Integer> prevSmaller(ArrayList<Integer> arr) {      
       
        
        int i,j, flag, n;
        int size = arr.size();
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for(i=0; i<size; i++){
            j=i-1;
            n = arr.get(i);
            flag =0;
            while(j != -1){
                if(arr.get(j)< n){
                    flag = 1; 
                    break;
                }
                j--;
            }
            if(flag == 1){
                temp.add(arr.get(j));
            }else{
                temp.add(-1);
            }
        }
        return temp;
    }
}

/*

	Approach Two:
		Using Stack, and mainating numbers in the stack such that number greater than the upcoming number is popped out.
		Time Complexity: O(n)

*/
public class Solution {
    public ArrayList<Integer> prevSmaller(ArrayList<Integer> arr) {
        Stack<Integer> stack = new Stack<Integer>();
        int i,n,min;
        int size = arr.size();
        ArrayList<Integer> temp = new ArrayList<Integer>();
        if(arr.isEmpty()){
            return temp;
        }
       
        for(i=0; i<size; i++){
            n = arr.get(i);
            
            while(!stack.empty() && stack.peek() >= n){
                  stack.pop();
            }
            
            if(stack.empty()){
                stack.push(n);
                temp.add(-1);
            }else{
                temp.add(stack.peek());
                stack.push(n);
            }
        }
        return temp;
    }
}