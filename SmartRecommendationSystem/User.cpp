#include "User.h"
#include <iostream>

#pragma region Getters/Setters
string User::getName()
{
	return name;
}

string User::getEmail()
{
	return email;
}

string User::getPassword()
{
	return password;
}

string User::getUserRole() const
{
	return userRole;
}

void User::setName(string newName)
{
	name = newName;
}

void User::setEmail(string newEmail)
{
	email = newEmail;
}

void User::setPassword(string newPassword)
{
	password = newPassword;
}

void User::setUserRole(const string newRole)
{
	userRole = newRole;
}
#pragma endregion

string User::login()
{
	return string();
}

void User::logout()
{
	// logout
	setName("");
	setEmail("");
	setPassword("");
	setUserRole("");
	cout << endl << "Logout Successfull!" << endl << endl;
}


