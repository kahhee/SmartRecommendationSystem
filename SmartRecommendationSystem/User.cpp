#include "User.h"

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

string User::registerUserAsCustomer(string name, string email, string password) {
	// string = register status
	// register code ..
	return "Success";
}

string User::login(string email, string password)
{
	return "Success";
}

void User::logout()
{
	// logout
}


