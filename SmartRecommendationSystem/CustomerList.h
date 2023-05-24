#pragma once
#include "Customer.h"

class CustomerList {

public:
    struct CustomerNode {
        Customer customer;
        CustomerNode* next;
        CustomerNode(Customer customer)
            : customer(customer), next(nullptr) {};
    };
    CustomerList();

    void addCustomer(Customer customer);

    void displayCustomers();

    void deleteCustomer(Customer customer);

    Customer* findCustomerById(string userID);

    bool loginCustomer(string name, string password);

    ~CustomerList();

    CustomerNode* head;
};

