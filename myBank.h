#ifndef MYBANK_H
    #define MYBANK_H
    void init();
    void open(double amount);
    void balance(int account_number);
    void deposit(int account_number);
    void withdraw(int account_number);
    void closeAccount(int account_number);
    void insert_rate(int rate);
    void print();
    void closeAllAccount();
#endif