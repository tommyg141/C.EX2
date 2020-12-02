#include <stdio.h>
#include "myBank.h"

int main(){
  init();
  char in;
  do
  {
    printf("\nPlease choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n" );
    if(scanf(" %c", &in) == 0) printf("Invalid transaction type\n");
    else if(in == 'O')
    {
      double amount;
      printf("Please enter amount for deposit: ");
      if(scanf(" %lf", &amount) == 0) printf("Failed to read the amount\n");
      else if(amount < 0){
        printf("Invalid Amount\n");
      }
      else open(amount);
    }
    else if(in == 'B'){
      int num;
      printf("Please enter account number: ");
      if(scanf(" %d", &num) == 0) printf("Failed to read the account number\n");
      else if(num < 901 || num > 950) printf("Invalid account number\n");
      else{
        balance(num);
      }
    }
    else if(in == 'D'){
      int num;
      printf("Please enter account number: ");
      if(scanf(" %d", &num) == 0) printf("Failed to read the account number\n");
      else if(num < 901 || num > 950) printf("Invalid account number\n");
      else{
        deposit(num);
      }
    }
    else if(in == 'W'){
      int num;
      printf("Please enter account number: ");
      if(scanf(" %d", &num) == 0) printf("Failed to read the account number\n");
      else if(num < 901 || num > 950) printf("Invalid account number\n");
      else{
        withdraw(num);
      }
    }
    else if(in == 'C'){
      int num;
      printf("Please enter account number: ");
      if(scanf(" %d", &num) == 0) printf("Failed to read the account number\n");
      else if(num < 901 || num > 950) printf("Invalid account number\n");
      else{
        closeAccount(num);
      }
    }
    else if(in == 'I'){
      printf("Please enter interest rate: ");
      int rate;
      if(scanf(" %d", &rate) == 0) printf("Failed to read the interest rate\n");
      else{
        insert_rate(rate);
      }
    }
    else if(in == 'P'){
      print();
    }
    else if(in == 'E'){
      closeAllAccount();
    }
    else{
      printf("Invalid transaction type\n");
    }
  } while (in != 'E');
  
  return 0;
}
