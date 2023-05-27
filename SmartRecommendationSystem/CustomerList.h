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
        void deleteCustomer(Customer customer);
        Customer* findCustomerById(string userID);
        CustomerNode* getHead();
        bool loginCustomer(string name, string password);
        ~CustomerList();

    private:
        CustomerNode* head;
};

