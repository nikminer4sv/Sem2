#include <iostream>
#include <functional>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS;

using namespace std;

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

void PrintCard(const Card& card) {

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

class Deck {
private:
    function<void(const Card&)> fPrint = nullptr;
    vector<Card> cards;

public:

private:
    void IndexValidation(const size_t& index) const {
        if (index >= cards.size())
            throw invalid_argument("Invalid index");
    }
    bool CardComporator(const Card& card1, const Card& card2) const {
        return card1.type == card2.type && card1.suit == card2.suit;
    }

public:
    Deck() = default;

    Deck(const vector<Card>& cards) {
        this->cards = cards;
    }

    Deck(const Deck& deck) {
        this->cards = deck.cards;
    }

    void Configure(function<void(const Card&)> func) { fPrint = func; }

    void Print(const size_t& index) const {

        IndexValidation(index);

        auto it = cards.begin();
        advance(it, index);
        Print(*it);

    }

    void Print(const Card& card) const { 

        if (fPrint == nullptr)
            throw runtime_error("NO PRINT FUNCTION");

        fPrint(card); 
    }

    void Add(const Card& card) {

        for (size_t i = 0; i < cards.size(); i++) 
            if (CardComporator(card, cards[i]))
                throw runtime_error("Again this fcking card!");

        cards.push_back(card);
    }

    void Remove(const size_t& index) {

        IndexValidation(index);

        auto it = cards.begin();
        advance(it, index);
        cards.erase(it);

    }

    Card Get(size_t index) const {

        IndexValidation(index);

        auto it = cards.begin();
        advance(it, index);
        
        return *it;

    }

    bool Contain(const Card& card) const {

        for (size_t i = 0; i < cards.size(); i++)
            if (CardComporator(card, cards[i]))
                return true;

        return false;

    }
    
    void Join(const Deck& deck) {
        for (size_t i = 0; i < deck.GetSize(); i++) {
            bool flag = true;
            for (size_t j = 0; j < this->GetSize(); j++) {
                if (CardComporator(cards[j], deck.Get(i))) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                this->Add(deck.Get(i));
        }
    }

    void Difference(const Deck& deck) {
        for (size_t i = 0; i < deck.GetSize(); i++) 
            for (size_t j = 0; j < this->GetSize(); j++) 
                if (CardComporator(deck.Get(i), this->cards[j])) 
                    this->Remove(j);
    }

    void Crossing(const Deck& deck) {

        for (size_t i = 0; i < this->GetSize(); i++) {
            bool flag = true;
            for (size_t j = 0; j < deck.GetSize(); j++) {
                if (CardComporator(this->cards[i], deck.Get(j))) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                this->Remove(i);
        }
    }

    size_t GetSize() const { return cards.size(); }

};

int main() {

    Card card1(CardType::N1, CardSuit::Clubs);
    Card card2(CardType::N2, CardSuit::Clubs);
    Card card3(CardType::N3, CardSuit::Clubs);
    Card card4(CardType::N4, CardSuit::Clubs);
    Card card5(CardType::N5, CardSuit::Clubs);

    Deck deck;
    deck.Add(card1);
    deck.Add(card2);
    deck.Add(card3);
    deck.Configure(PrintCard);

    Deck deck2;
    deck2.Add(card1);
    deck2.Add(card2);

    deck.Crossing(deck2);

    for (size_t i = 0; i < deck.GetSize(); i++)
        deck.Print(i);

}

/*

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


}*/