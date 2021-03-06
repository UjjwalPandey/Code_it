/*Problem:
https://www.interviewbit.com/courses/programming/topics/strings/problems/version/

Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

Solution:


 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 * 
 * @Output Integer
 */
int compareVersion(char* A, char* B) {
    int a=0,b=0;
	//If A||B is like 001
    while(A[a]=='0'){ a++;}
    while(B[b]=='0'){ b++;}
   
    int i=0;
	//Move till we have same elements
    while(A[i+a]==B[i+b] && (i+a < strlen(A) || i+b <strlen(B))){
        i++;
    }
    if(i==(strlen(A)-a) && i==(strlen(B)-b)){
        return 0;
    }
  
    
    
    //Suppose . is encountered first
    if(A[i+a]=='.' && isdigit(B[i+b])){
        //if(A[i+a-1] == B[i+b-1])
        return -1;
    }
    if(B[i+b]=='.'&& isdigit(A[i+a])){
        return 1;
    }
    if(A[i+a]=='.'&& i+b >=strlen(B)){
        int k;
        for(k=1; A[i+a+k] != '\0';k++){
            if(A[i+a+k]-'0' > 0){
                return 1;
            }
        }
        return 0;
    }
    if(B[i+b]=='.'&& i+a >=strlen(A)){
        int k;
        for(k=1; B[i+b+k] != '\0';k++){
            if(B[i+b+k]-'0' > 0){
                return -1;
            }
        }
        return 0;
    }
    
    if(i+a==strlen(A) && i+b<strlen(B)){
        return -1;
    }
    if(i+a<strlen(A) && i+b==strlen(B)){
        return 1;
    }
	
	//If 2 numbers have different value and have different length
    if(A[i+a] < B[i+b]){
        int m =0, n=0;
        while(A[i+a+m] != '.' && i+a+m < strlen(A)){m++;}
        while(B[i+b+n] != '.' && i+a+n < strlen(B)){n++;}
        if(m>n){
            return 1;
        }
        return -1;
    }
    if(A[i+a] > B[i+b]){
        int m =0, n=0;
        while(A[i+a+m] != '.' && i+a+m < strlen(A)){m++;}
        while(B[i+b+n] != '.' && i+a+n < strlen(B)){n++;}
        if(m>=n){
            return 1;
        }
        return -1;
    }
   
    return 0;
}

	
