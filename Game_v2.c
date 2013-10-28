#include <stdio.h>

int vincente(int n)
{
        int i;
          if (n<3) return 1;  
          if (n<6) return 0;
          for(i=0;i<n;i++)
      if (vincente(i)==0 && vincente(n-i)==0)
              return 1;
        return 0;
}

int main(){
    int num;
    
    for(num=0;num<40;num++){
                            if(vincente(num)==1){
                                                 printf("il numero %d è vincente! \n",num);
                                                 }else{
                                                       printf("il numero %d è perdente! \n",num);
                                                       }
                            
                            }
    
    
    getch();
    return 0;   
}

