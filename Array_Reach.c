/*Problem: 
https://www.interviewbit.com/courses/programming/topics/arrays/problems/reach/

You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.


Solution: */
/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
 
 int min(int x, int y) {return (x>=y)?y:x;}
int coverPoints(int* X, int n1, int* Y, int n2) {
	//If number of X-Coordinate is not equal to number of Y Coordinate.
    if(n1 != n2) return 0;
    int i=1, j=1, count=0, mini;
    while(i<n1){
	//Move diagonally until the horizontal/vertical difference turns zero.
        mini = min(abs(X[i]-X[i-1]),abs(Y[i]-Y[i-1]));
    
	// Add the remaining distance.
        if(mini == abs(X[i]-X[i-1])){
            count += abs(Y[i]-Y[i-1]);
        }
        else if(mini == abs(Y[i]-Y[i-1])){
            count += abs(X[i]-X[i-1]);
        }
        i++;
    }
    
    return count;
}
