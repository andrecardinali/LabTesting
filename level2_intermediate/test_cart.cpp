#include <gtest/gtest.h>
#include "shopping_cart.h"

// ESEMPIO PROFESSORE:
TEST(ShoppingCartTest, StartsEmptyAndAddsSuccessfully) {
    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotalCents(), 0);
    
    cart.AddItem("Mela", 150); // 1.50 euro
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 150);
}

// TODO STUDENTE 1: Aggiungi tre prodotti diversi al carrello.
// Usa EXPECT_EQ per verificare il conteggio totale e il prezzo totale.
// Usa messaggi personalizzati << se l'asserzione fallisce.
TEST(ShoppingCartTest, CalculatesTotalForMultipleItems) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Pane", 200); // 2.00 euro
    cart.AddItem("Latte", 120); // 1.20 euro
    cart.AddItem("Uova", 300); // 3.00 euro
    EXPECT_EQ(cart.GetItemCount(), 3) << "Il conteggio degli articoli dovrebbe essere 3 dopo aver aggiunto 3 prodotti.";
    EXPECT_EQ(cart.GetTotalCents(), 620) << "Il totale in centesimi dovrebbe essere 620 dopo aver aggiunto Pane, Latte e Uova.";
}

// TODO STUDENTE 2: Testa l'estrazione di un prodotto esistente.
// Ricorda di controllare che il puntatore restituito da ExtractItem NON sia nullptr 
// usando ASSERT_NE prima di verificarne il nome e il prezzo.
// Dopo averlo estratto, verifica che il totale e il conteggio del carrello siano diminuiti.
// Ricordati di fare delete del puntatore estratto!
TEST(ShoppingCartTest, ExtractsExistingItemCorrectly) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Formaggio", 250); // 2.50 euro
    Item* extracted = cart.ExtractItem("Formaggio");
    ASSERT_NE(extracted, nullptr) << "ExtractItem dovrebbe restituire un puntatore non nullo per un prodotto esistente.";
    EXPECT_EQ(extracted->name, "Formaggio") << "Il nome dell'articolo estratto dovrebbe essere 'Formaggio'.";
    EXPECT_EQ(extracted->price_cents, 250) << "Il prezzo in centesimi dell'articolo estratto dovrebbe essere 250.";
    delete extracted;
}

// TODO STUDENTE 3: Testa l'estrazione di un prodotto NON esistente.
// Verifica che ExtractItem restituisca nullptr.
TEST(ShoppingCartTest, ExtractNonExistingItemReturnsNull) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Yogurt", 100); // 1.00 euro
    Item* extracted = cart.ExtractItem("Gelato");
    EXPECT_EQ(extracted, nullptr) << "ExtractItem dovrebbe restituire nullptr per un prodotto non esistente.";
}