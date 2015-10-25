#include <stdio.h>
#include<string.h>
int isPalindrome(char* A) {
    int len = strlen(A);
    //printf("%d",len);
    char* t = (char*)malloc(sizeof(char)*len);
    char* rev = (char*)malloc(sizeof(char)*len);
    memset(t,'\0',sizeof(t));
    memset(rev,'\0',sizeof(rev));
    int i,count=0;
   i=0;
  
    for(i=0; A[i] != '\0'; i++){
        
            if(isalpha(A[i])){
                t[count++] = tolower(A[i]);
            }else if(isdigit(A[i])){
                t[count++] = A[i];
            }
        
    }
    
    i = 0;
    int l = count-1;
 
   while (i <= l) {
      rev[i] = t[l-i];
      i++;
      
   }
    //printf("\n%s\n%s\n",t,rev);
    i = 0;
    
   while(i<=l){
       if(t[i]!=rev[i]){
           return 0;
       }
       i++;
   }
   return 1;
    
}
int main(void) {
	char str[] = "dyryd";
	if(isPalindrome(str)){
		printf("Palindrome");
	}else{
		printf("Not a Palindrome");
	}
	return 0;
}
