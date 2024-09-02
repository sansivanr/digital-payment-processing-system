#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool validateCardNumber(const string& cardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';
        if (alternate) {
            n *= 2;
            if (n > 9) n -= 9;
        }
        sum += n;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

bool validatePaymentMethod(const string& method, const string& details) {
    if (method == "credit_card" || method == "debit_card") {
        return regex_match(details, regex("\\d{16}")) && validateCardNumber(details);
    }
    return false;
}

