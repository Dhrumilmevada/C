#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char str[30];
    int frq[10] = {0};
    int i,n=0;
    
    scanf("%[^\n]",str);
    
    for(i=0; i<(int)strlen(str); i++)
    {
        printf("\n\n%d ... %d",(int)strlen(str),i);
        if(isdigit(str[i])){
            n = (int) (str[i]- '0');
            //sscanf(&str[i], "%d" , n);
            //printf("\n%d",n);
            frq[n]+=1;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",frq[i]);
    }
    return 0;
}










//8g614eggv7n388564l82nl6f35826hrzd533380b7870n4954497308f03wsx6zyr45025845zz55x7576631425l311cj4n9u29f4xje02l35t31m6me078bx421c24cocx83e438g88d069cc39bn6292033q055kk81m4f82798h7pt031mv530g4v7519h6g78z34p228f9z6067emv47e83uj805q805d572k18h077q6zzo22f35k22631l5j6n8fz0u583xkuu392613478x8823119241o6802910551sm8w9or6v78443c8wt63i3ft21d548p79h14i26k65qhbs79h65su27l1waz62m7l155bib1a2w401b8j7s2i719i68tr60492f685g7lx96i077775kq9436s6s6h81f827624583m894314vjvd41385ww0639e6xs8wzn6362a0029233j99097be0124408o90c861281jgu3168765af270z47e208bclp3845799e4p2710i231h

