#include <iostream>
#include "Common/nikminer4sv.h"
#include <string>

using namespace std;
using namespace nikminer4sv;

enum CardSuit {
    Diamonds,
    Hearts,
    Spades,
    Clubs
};

enum CardType {
    N1,
    N2,
    N3,
    N4,
    N5,
    N6,
    N7,
    N8,
    N9,
    N10,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card {
    CardType type;
    CardSuit suit;

    Card() {}

    Card(CardType type, CardSuit suit) : type(type), suit(suit) {}
};

class Deck {
private:
    List<Card> list;

public:
    Deck() {}

    void Append(const Card& card) {
        list.Append(card);
    }

    void Remove(const size_t& index) {
        list.Remove(index);
    }

    void PrintCard(const size_t& index) const {
        PrintCard(list[index]);
    }

    void PrintCard(const Card& card) const {

        string type;
        if (card.type < 10)
            type = to_string(card.type + 1);
        else {

            switch (card.type) {
                
                case 10: {
                    type = "jack";
                    break;
                }
                case 11: {
                    type = "queen";
                    break;
                }
                case 12: {
                    type = "king";
                    break;
                }
                case 13: {
                    type = "ace";
                    break;
                }

            }

        }

        string suit;
        switch (card.suit) {

            case 0: {
                suit = "diamonds";
                break;
            }
            case 1: {
                suit = "hearts";
                break;
            }
            case 2: {
                suit = "spades";
                break;
            }
            case 3: {
                suit = "clubs";
                break;
            }

        }

        cout << "Card type: " << type << endl
             << "Card suit: " << suit << endl;

    }

    size_t GetSize() const {
        return list.GetSize();
    }

    Card operator[](size_t index) const {

        if(index < 0 || index > this->GetSize() - 1)
            throw std::invalid_argument("index is out of bounds");

        return list[index];

    }

    Deck Join(const Deck& deck) {

        Deck newDeck;

        for (size_t i = 0; i < this->GetSize(); i++) 
            newDeck.Append(list[i]);

        for (size_t i = 0; i < deck.GetSize(); i++) {

            bool flag = false;

            for (size_t j = 0; j < newDeck.GetSize(); j++) {

                if (deck[i].type == newDeck[j].type && deck[i].suit == newDeck[j].suit) {
                    flag = true;
                    break;
                }

            }

            if (!flag) {
                newDeck.Append(deck[i]);
            }

        }

        return newDeck;

    }

    Deck& operator = (const Deck& deck){
        
        for (size_t i = 0; i < deck.GetSize(); i++)
            this->Append(deck[i]);

        return *this;
    }

};

int main() {

    Card card1(CardType::JACK, CardSuit::Diamonds);
    Card card2(CardType::ACE, CardSuit::Spades);
    Deck deck1;
    Deck deck2;

    deck1.Append(card1);
    deck1.Append(card1);
    deck2.Append(card2);
    
    Deck deck;

    deck = deck1.Join(deck2);
    cout << deck.GetSize();


}