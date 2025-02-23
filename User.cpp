#include "User.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Event {
	public:
		string name;

		Event(string name){
			this->name = name;
		}
	};
	
class User {
public:
	int user_id;
	string userPerference;
	string email;
	string password;
	string mood;

	//Some constructor
	User(int user_id, string email, string password){
		this->user_id = user_id;
		this->email = email;
		this->password = password;
	}

	//Pretend to login
	bool login(string email, string password) {
		return true;
	}

	//Update some user perference variable
	void updateUserPreferences(string userPerference) {
		this->userPerference = userPerference;
	}

	//return base recommendations
	list<Event> getRecommendations() {
		list<Event> events;
		events.push_back(Event("Rock"));
		events.push_back(Event("Tame Impala"));
		return events;
	}

	//Set some mood
	void setMood(string mood) {
		this->mood = mood;
	}

	//Search for some event
	list<Event> searchEvents(string event) {
		list<Event> events;
		if (event == "concert") {
			events.push_back(Event("Rock"));
		} else {
			events.push_back(Event("Tame Impala"));
		}
		return events;
	}

	//apply some filter
	void applyFilter(list<string> filters) {
		for (auto& filter : filters) {
			cout << "Applying filter: " << filter << endl;
		}
	}
};
