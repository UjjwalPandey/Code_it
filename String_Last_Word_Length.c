/**Problem:
	https://www.interviewbit.com/courses/programming/topics/strings/problems/lengthlast/
	
	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
	If the last word does not exist, return 0.
	Note: A word is defined as a character sequence consists of non-space characters only.

Solution:

 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int lengthOfLastWord(const char* A) {
    int i,count=0,flag=0;
    for(i=0;A[i]!='\0';i++){
        if(A[i]==' '){
            flag=1;
            continue;
        }
        if(flag==1){
            count=0;
            flag=0;
        }
        count++;
    }
    return count;
}
