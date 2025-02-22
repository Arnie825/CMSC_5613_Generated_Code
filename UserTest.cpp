#include "User.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

//Mock class
class MockUser : public User {
    public:
        MockUser(int id, string email, string password)
            : User(id, email, password) {}
    
        MOCK_METHOD(list<Event>, searchEvents, (string query), (override));
    };


//Test to search events
TEST(UserTest, SearchEventsWithMock) {
    User user(1, "something@gmail.com", "333333");
    list<Event> mockEvents;
    mockEvents.push_back(Event("Rock"));
    EXPECT_CALL(mockUser, searchEvents("Somethingt")).WillOnce(testing::Return(mockEvents));
    list<Event> result = mockUser.searchEvents("Somethingt");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result.front().name, "Rock");
}

//We are expecting True always for this example test
TEST(UserTest, LoginWithCorrectCredentials) {
    User user(1, "something@gmail.com", "333333");
    EXPECT_TRUE(user.login("something@gmail.com", "333333"));
}

//Update the userPerference
TEST(UserTest, UpdateUserPreferences) {
    User user(1, "something@gmail.com", "333333");
    user.updateUserPreferences("Perference");
    EXPECT_EQ(user.userPerference, "Perference");
}

//Test search events method
TEST(UserTest, SearchEventsWithValidQuery) {
    User user(1, "something@gmail.com", "333333");
    list<Event> events = user.searchEvents("concert");
    ASSERT_EQ(events.size(), 1);
    EXPECT_EQ(events.front().name, "Rock");
}

//test seach events method, Tame Impala
TEST(UserTest, SearchEventsWithValidQuery2) {
    User user(1, "something@gmail.com", "333333");
    list<Event> events = user.searchEvents("Tame");
    ASSERT_EQ(events.size(), 1);
    EXPECT_EQ(events.front().name, "Tame Impala");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}