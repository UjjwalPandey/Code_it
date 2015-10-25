/**
Solution:

Time Complexity: O(n square)

 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* maxone(int* A, int n1, int B, int *len1) {
    int i,j,k,count=0,temp,start=0,end=0,b;
    for(i=0;i<n1;i++){
        b=0;
        temp=0;
        for(j=i;j<n1;j++){
            if(A[j]==0){
                if(b==B){
                    break;
                }
                if(b<B){
                    b++;
                    
                }
            }
            temp++;
            if(temp>count){
               count = temp;
               start=i;
               end=j;
            }
        }
    }
    *len1 = end-start+1;
    int* res = (int*)malloc(sizeof(int)*( *len1));
    for(i=start; i<=end;i++){
        res[i-start] = i;
    }
    return res;
}
