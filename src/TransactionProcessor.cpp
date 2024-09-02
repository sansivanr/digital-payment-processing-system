#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

enum class TransactionStatus {
    SUCCESS,
    FAILURE
};

struct Transaction {
    string transactionId;
    string paymentMethod;
    double amount;
    TransactionStatus status;
    time_t timestamp;
};

map<string, Transaction> transactionDB;

string generateTransactionId() {
    static int id = 1000;
    return "TX" + to_string(id++);
}

Transaction processTransaction(string paymentMethod, double amount) {
    Transaction txn;
    txn.transactionId = generateTransactionId();
    txn.paymentMethod = paymentMethod;
    txn.amount = amount;
    txn.status = (amount > 0) ? TransactionStatus::SUCCESS : TransactionStatus::FAILURE;
    txn.timestamp = time(0);

    transactionDB[txn.transactionId] = txn;

    return txn;
}

void printTransaction(const Transaction& txn) {
    cout << "Transaction ID: " << txn.transactionId << endl;
    cout << "Payment Method: " << txn.paymentMethod << endl;
    cout << "Amount: $" << fixed << setprecision(2) << txn.amount << endl;
    cout << "Status: " << (txn.status == TransactionStatus::SUCCESS ? "Success" : "Failure") << endl;
    cout << "Timestamp: " << ctime(&txn.timestamp);
}

