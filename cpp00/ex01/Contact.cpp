#include "Contact.hpp"

void Contact::setFirstName(const std::string& first) {
	firstName = first;
}

void Contact::setLastName(const std::string& last) {
	lastName = last;
}

void Contact::setNickName(const std::string& nick) {
	nickName = nick;
}

void Contact::setPhoneNumber(const std::string& phone) {
	phoneNumber = phone;
}

void Contact::setDarkestSecret(const std::string& secret) {
	darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickName() const
{
	return nickName;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
