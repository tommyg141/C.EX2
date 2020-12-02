#include <stdio.h>
#include "myBank.h"
double bank[50][3];

//901-950
void init(){
  int count = 901;
  for(int i=0; i< 50; i++){
    bank[i][0]=count; // number account
    bank[i][1]=0; //close
    bank[i][2]=0; //amount
    count++;
  }
}
void open(double amount){
  for(int i=0; i< 50; i++){
    if(bank[i][1]==0){
      bank[i][1]=1;
      bank[i][2]=amount;
      printf("New account number is: %.0f\n",bank[i][0] );
      break;
    }
    else if(i == 49){
      printf("50 accounts already open\n");
    }
  } 
}
void balance(int account_number){
  for(int i=0; i< 50; i++){
    if(bank[i][0]==account_number){
      if(bank[i][1]==1){
      printf("The balance of account number %d is: %.2f\n",account_number,bank[i][2] );
      break;
    }else{
        printf("This account is closed \n");
          break;
      }
    }
  }
}
void deposit(int account_number){
  double amount;
  printf("Please enter the amount to deposit: ");
  if(scanf(" %lf", &amount) == 0) printf("Failed to read the amount\n");
  else if(amount < 0) printf("Cannot deposit a negative amount\n");
  else{
   for(int i=0; i< 50; i++){
     if(bank[i][0]==account_number){
       if(bank[i][1]==1){
        bank[i][2]+=amount;
        printf("The new balance is: %.2f\n",bank[i][2]);
        break;
      }
      else{
        printf("This account is closed \n");
        break;
      }
    }
    }
}
}
void withdraw(int account_number){
  double amount;
  printf("Please enter the amount to withdraw: ");
  if(scanf(" %lf", &amount) == 0) printf("Failed to read the amount\n");
  else{
    for(int i=0; i< 50; i++){
      if(bank[i][0]==account_number){
        if(bank[i][1]==1){
          if((bank[i][2]-amount)>0){
            bank[i][2]-=amount;
            printf("The new balance is: %.2f\n",bank[i][2]);
            break;
          }
          else{
          printf("Cannot withdraw more than the balance\n" );
          }
        }
        else{
          printf("This account is closed \n");
          break;
        }
      }
    }
  }
}
void closeAccount(int account_number){
  for(int i=0; i< 50; i++){
    if(bank[i][0]==account_number){
      if(bank[i][1]==1){
        bank[i][1]=0;
        bank[i][2]=0;
        printf("closed account number %.0f\n",bank[i][0] );
        break;
      }
      else{
        printf("This account is already closed \n");
        break;
      }
    }
  }
}
void insert_rate(int rate){
  for(int i=0; i< 50; i++){
    if(bank[i][1]==1){
      bank[i][2]*=((double)rate/100.0);
    }
  }
}
void print(){
  for(int i=0; i< 50; i++){
    if(bank[i][1]==1){
      printf("The balance of account number %.0f is: %.2f\n",  bank[i][0],bank[i][2] );
    }
  }
}
void closeAllAccount(){
  for(int i=0; i< 50; i++){
    if(bank[i][1]==1){
      bank[i][1]=0;
      bank[i][2]=0;
    }
  }
}
