#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"RUSSIAN");
    int X,Y,i,j;
    printf("Enter Y: ");
    scanf("%d",&Y);
    printf("Enter X: ");
    scanf("%d",&X);
    
    int **mnozhestvo;
    mnozhestvo=calloc(Y, sizeof(int));
    for(i=0;i<X;i++){
        mnozhestvo[i]=calloc(X, sizeof(int));
    }
    
    char c;
    j=0;
    for(i=0;i<Y;i++){
        printf("Eneter in %d string (ENTER for the end): ",i);
        while((c=getchar())!='\n'){
            if(c>='0'||c<='9'){
                mnozhestvo[i][j]=c-48;
                j++;
                if(j>X){
                    j=0;
                    i++;
                }
            }
        }
        
        for (j=0;j<X;j++){
            scanf("%d",&mnozhestvo[i][j]);
        }
    }
    
    int exit=1,Xm,Ym,znach,dop_menu;
    while(exit){
        printf("Menu:\n1: Add\n2: Delete\n3: Show list\n0: Exit\n----------\n");
        int menu;
        scanf("%d",&menu);
        printf("----------\n");
        switch(menu){
            case 1:
                printf("Enter Y coordinate of the set: ");
                scanf("%d",&Ym);
                Ym--;
                printf("Enter X coordinate of the set: ");
                scanf("%d",&Xm);
                Xm--;
                printf("Enter a value for (%d,%d): ",Xm+1,Ym+1);
                scanf("%d",&znach);
                
                if(mnozhestvo[Ym][Xm]!=0){
                    printf("In coordinates (%d,%d) value already exists = %d. Change?\n1 - Yes\n0 - No\n",mnozhestvo[Ym][Xm],Xm+1,Ym+1);
                    scanf("%d",&dop_menu);
                    if(dop_menu==1){
                        mnozhestvo[Ym][Xm] = znach;
                        printf("Successfully! In coordinate (%d,%d) value = %d\n",Xm+1,Ym+1,mnozhestvo[Ym][Xm]);
                    }else{
                        break;
                    }
                }else{
                    mnozhestvo[Ym][Xm]=znach;
                    printf("Successfully! In coordinate (%d,%d) value = %d\n",Xm+1,Ym+1,mnozhestvo[Ym][Xm]);
                }
            break;
            case 2:
                printf("Enter Y coordinate of the set: ");
                scanf("%d",&Ym);
                Ym--;
                printf("Enter X coordinate of the set: ");
                scanf("%d",&Xm);
                Xm--;

                mnozhestvo[Ym][Xm]=0;
                printf("Successfully! In coordinate (%d,%d) value = %d\n",Xm+1,Ym+1,mnozhestvo[Ym][Xm]);
            break;
            case 3:
                for(i=0;i<Y;i++){
                    for (j=0;j<X;j++){
                        printf("%d ",mnozhestvo[i][j]);
                    }
                    printf("\n");
                }
            break;
            case 0:
                exit=0;
            break;
            default:
            printf("%d not found in the list\n",menu);
            break;
        }
    }
    return 0;
}
