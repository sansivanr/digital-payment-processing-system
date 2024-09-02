#include <iostream>
#include <string>
#include "TransactionProcessor.cpp"
#include "PaymentMethodHandler.cpp"
#include "EncryptionUtil.cpp"

using namespace std;

int main() {
    cout << "Digital Payment Processing System\n";
    string method, details;
    double amount;

    cout << "Enter Payment Method (credit_card/debit_card): ";
    cin >> method;

    cout << "Enter Payment Details (Card Number): ";
    cin >> details;

    if (!validatePaymentMethod(method, details)) {
        cout << "Invalid payment method or details.\n";
        return 1;
    }

    cout << "Enter Amount: ";
    cin >> amount;

    string encryptedDetails = encryptAES(details, "your-encryption-key");

    Transaction txn = processTransaction(method, amount);

    printTransaction(txn);

    return 0;
}

