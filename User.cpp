#include "User.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

Event::Event(string name){
	this->name = name;
}

//Some constructor
User::User(int user_id, string email, string password){
	this->user_id = user_id;
	this->email = email;
	this->password = password;
}

//Pretend to login
bool User::login(string email, string password) {
	return true;
}

//Update some user perference variable
void User::updateUserPreferences(string userPerference) {
	this->userPerference = userPerference;
}

//return base recommendations
list<Event> User::getRecommendations() {
	list<Event> events;
	events.push_back(Event("Rock"));
	events.push_back(Event("Tame Impala"));
	return events;
}

//Set some mood
void User::setMood(string mood) {
	this->mood = mood;
}

//Search for some event
list<Event> User::searchEvents(string event) {
	list<Event> events;
	if (event == "concert") {
		events.push_back(Event("Rock"));
	} else {
		events.push_back(Event("Tame Impala"));
	}
	return events;
}

//apply some filter
void User::applyFilter(list<string> filters) {
	for (auto& filter : filters) {
		cout << "Applying filter: " << filter << endl;
	}
}
