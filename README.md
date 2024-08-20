# Digital Payment Processing System

## Description

A C++ application that simulates a digital payment processing system. It includes functionality for processing transactions, validating payment methods, and encrypting sensitive data.

## Features

- **Transaction Processing**: Simulates transaction handling and persistence.
- **Payment Methods**: Validates credit and debit card information.
- **Encryption**: Implements basic AES encryption for secure data handling.
- **Testing**: Includes unit tests for transaction processing and payment validation.

## Setup

1. **Install Dependencies**:
   - Ensure you have `g++`, `openssl` installed via Homebrew.

2. **Build the Project**:
   ```bash
   g++ -o payment_system src/main.cpp src/TransactionProcessor.cpp src/PaymentMethodHandler.cpp src/EncryptionUtil.cpp -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -lssl -lcrypto
