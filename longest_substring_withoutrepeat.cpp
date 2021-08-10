#include <string.h>
int lengthOfLongestSubstring(char * s){
    int substring_start=0, max=0;
    short arr[128];


    for(int i=0; i<128; i++){
        arr[i] = -1;
    }

    for(int i=0; i<strlen(s); i++){
        if(s[i]=='\0'){
            break;
        }
        if(arr[s[i]] >= substring_start){        //character is in the substring
            substring_start = arr[s[i]]+1;        //move substring ahead for one position
            arr[s[i]] = i;
        }
        else{                       //character is not in the substring
            arr[s[i]] = i;
            if(i - substring_start +1 > max){
                max = i-substring_start+1;
            }
        }
    }
    return max;
}