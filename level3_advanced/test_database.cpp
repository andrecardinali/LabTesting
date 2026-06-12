#include <gtest/gtest.h>
#include "mock_database.h"

// TODO STUDENTE 0: Crea la Test Fixture "DatabaseTest".
class DatabaseTest : public testing::Test {
protected:
    MockDatabase db;

    void SetUp() override {
        db.Connect();
        db.InsertUser("admin", 1, "administrator");
        db.InsertUser("guest", 2, "visitor");
    }

    void TearDown() override {
        db.Disconnect();
    }
};


// TODO STUDENTE 1: Usando TEST_F, scrivi un test che verifichi l'utente "admin".
TEST_F(DatabaseTest, RetrievesExistingAdmin) {
    UserRecord* admin = db.GetUser("admin");
    ASSERT_NE(admin, nullptr); // Verifica che admin non sia nullptr
    EXPECT_EQ(admin->id, 1); // Verifica che l'id sia 1
    EXPECT_EQ(admin->role, "administrator"); // Verifica che il ruolo sia "administrator
}

// TODO STUDENTE 2: Usando TEST_F, scrivi un test che verifichi l'utente "guest".
TEST_F(DatabaseTest, RetrievesExistingGuest) {
    UserRecord* guest = db.GetUser("guest");
    ASSERT_NE(guest, nullptr); // Verifica che guest non sia nullptr
    EXPECT_EQ(guest->id, 2); // Verifica che l'id sia 2
    EXPECT_EQ(guest->role, "visitor"); // Verifica che il ruolo sia "visitor
}

// TODO STUDENTE 3: Usando TEST_F, scrivi un test che prova a recuperare un utente 
// non esistente (es. "hacker") e verifica che il risultato sia nullptr.
TEST_F(DatabaseTest, UnknownUserReturnsNull) {
    UserRecord* hacker = db.GetUser("hacker");
    EXPECT_EQ(hacker, nullptr); // Verifica che hacker sia nullptr
}

// TODO STUDENTE 4: Usando TEST_F, disconnetti esplicitamente il DB all'interno 
// del test (chiamando Disconnect()) e verifica che chiamare GetUser("admin") 
// restituisca nullptr (il DB non deve rispondere se non e' connesso).
TEST_F(DatabaseTest, GetUserFailsWhenDisconnected) {
    db.Disconnect();
    UserRecord* admin = db.GetUser("admin");
    EXPECT_EQ(admin, nullptr);
}