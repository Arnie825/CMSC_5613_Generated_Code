#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Event{
public:
	string name;

	Event(string name);
};

class User {
public:
    int user_id;
	string userPerference;
    string email;
    string password;
    string mood;

    // Constructor
    User(int id, string email, string password);

    // Methods
    bool login(string email, string password);
    void updateUserPreferences(string userPerference);
    list<Event> getRecommendations();
    void setMood(string mood);
    list<Event> searchEvents(string query);
    void applyFilter(list<string> filters);
};

#endif