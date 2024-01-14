#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hasLowercase(char password[100]){
    int i;
    for(i=0;i<=strlen(password)-1;i++){
        if(islower(password[i])){
            return 1;
        }
    }
    return 0;
    
}
int hasUppercase(char password[100]){
    int i;
    for(i=0;i<=strlen(password)-1;i++){
        if(isupper(password[i])){
            return 1;
        }
    }
    return 0;
}
int hasDigit(char password[100]){
    int i;
    for(i=0;i<=strlen(password)-1;i++){
        if(isdigit(password[i])){
            return 1;
        }
    }
    return 0;
}
int hasSpecialChar(char password[100]){
    int i;
    for(i=0;i<=strlen(password)-1;i++){
        if (!isalnum(password[i])) {
            return 1;
        }
        
    }
    return 0;
}

int evaluateStrength(char password[100]){
    int score = 0;
    int lower = hasLowercase(password);
    int upper = hasUppercase(password);
    int digit = hasDigit(password);
    int special = hasSpecialChar(password);
    if(strlen(password)>=12){
        score = score +1;
    }
    score = score+ lower+upper+digit+special;
    return score;
}



int main() {
    int x =0;
    
    
    printf("Password Resilience Analyzer\n");
    while(x!=3){
        printf("Type 1 to test a new passsword\nType 2 to view strength of the last tested password\nType 3 to exit\nEnter your choice:");
    
        scanf("%d",&x);
        char password[100];
        if(x==1){
            
            printf("Enter a password:\n");
            scanf("%s",password);
            while(strlen(password)<8){
                printf("Error, password should be at least 8 characters, re-enter password:\n");
                scanf("%s",password);
            }
            int score = evaluateStrength(password);
            if (score>=0&&score<=2){
                printf("Weak password\n");
                
            }
            else if(score>=3&&score<=4){
                printf("Moderate password\n");
            }
            else if(score==5){
                printf("Strong password\n");
            }
            
        }
        else if(x==2){
            int score = evaluateStrength(password);
            if (score>=0&&score<=2){
                printf("Weak password\n");
                
            }
            else if(score>=3&&score<=4){
                printf("Moderate password\n");
            }
            else if(score==5){
                printf("Strong password\n");
            }
        }
        else if (x==3) {
            printf("Exiting...");
            return 0;
    }}

    return 0;
}

