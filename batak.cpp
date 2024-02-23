#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
//Kart takımlarını oluşturma
enum class Suits {
    Diamonds, Hearts, Clubs, Spades
};
//Kart isimlerini oluşturma
enum class CardNames {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

//Oluşturulan enum class tipindeki takımları string’e çevirmek için
string suits_to_string(Suits suit) {
    switch (suit) {
        case Suits::Diamonds: return "Diamonds";
        case Suits::Hearts: return "Hearts";
        case Suits::Clubs: return "Clubs";
        case Suits::Spades: return "Spades";
    }
}

//Oluşturulan enum class tipindeki isimleri string’e çevirmek için
string cardnames_to_string(CardNames card_names) {
    switch (card_names) {
        case CardNames::Ace: return "Ace";
        case CardNames::Two: return "Two";
        case CardNames::Three: return "Three";
        case CardNames::Four: return "Four";
        case CardNames::Five: return "Five";
        case CardNames::Six: return "Six";
        case CardNames::Seven: return "Seven";
        case CardNames::Eight: return "Eight";
        case CardNames::Nine: return "Nine";
        case CardNames::Ten: return "Ten";
        case CardNames::Jack: return "Jack";
        case CardNames::Queen: return "Queen";
        case CardNames::King: return "King";
    }
}

// Bu fonksiyon bir desteyi temsil eden 2D diziyi oluşturur ve bu diziyi "deck" adlı bir 
// parametre olarak alır.
void create_deck(string deck[4][13]) {
    for (int i = 0; i < 4; i++) { // Kartların takımlarını temsil eder. 
        for (int j = 0; j < 13; j++) { // Kart isimlerini temsil eder.

            Suits suit = static_cast<Suits>(i);
            CardNames card_names = static_cast<CardNames>(j);
            // Döngülerin mevcut indislerini, enum türündeki "Suits" ve "CardNames"  
            // türlerine dönüştürür. Bu dönüşümler, her bir kartın takımını ve ismini 
            // belirlemek için kullanılır.

            deck[i][j] = cardnames_to_string(card_names) + " of " + suits_to_string(suit);
            // mevcut kartın ve takımın isimlerini birleştirerek kartın tam adını 
            // oluşturur ve bu adı "deck" dizisinin ilgili elemanına atar. 
        }
    }
}

// Bu fonksiyon, bir önceki kod parçasında oluşturulan 2D dizi olan "deck"i parametre 
// olarak alır ve bu diziyi ekrana yazdırmak için kullanır.
void show_deck(string deck[4][13]){
    // static_cast<int>(Suits::Spades) ifadesi, "Suits" enum türündeki "Spades" değerini 
    // tam sayıya dönüştürür. Aynı şekilde, static_cast<int>(CardNames::King) ifadesi de 
    // "CardNames" enum türündeki "King" değerini tam sayıya dönüştürür. Bu, döngülerin sınırlarını belirler.
    for (int a = 0; a <= static_cast<int>(Suits::Spades); a++) { // Kartların takımlarını temsil eder.
        for (int b = 0; b <= static_cast<int>(CardNames::King); b++) { // Kart isimlerini temsil eder.
            cout << deck[a][b] << " \n"; // Mevcut kartın tam adını ekrana yazdırır.
        }
    cout << endl; // Tüm kartları yazdırdıktan sonra bir boş satır ekler.
    }
}

// Bu kod, bir desteyi temsil eden 2D diziyi karıştırmak için kullanılır.
// Karıştırılmış bir desteyi temsil eden yeni bir 2D dizi oluşturulur.
void shuffle_deck(string deck[4][13], string new_deck[4][13]) {
    // Desteyi, yeni bir desteye kopyalar.
    for (int i = 0; i <= static_cast<int>(Suits::Spades); i++) {
        for (int j = 0; j <= static_cast<int>(CardNames::King); j++) {
            new_deck[i][j] = deck[i][j];
        }
    }

    srand(time(NULL)); //rastgele sayı üretimi için bir başlangıç noktası belirlemek amacıyla zamanı kullanır.

    for (int i = 3; i >= 0; i--) {// Kartların takımlarını temsil eder.
        for (int j = 12; j >= 0; j--) {// Kart isimlerini temsil eder.
            // Rastgele seçilen bir takım (suit) ve bir kart ismi (card name) indeksini hesaplar. 
            int rand_suit = rand() % (i + 1);
            int rand_card_names = rand() % (j + 1);

            // Kartları karıştırmak için, mevcut kart ile rastgele seçilen kartı yer değiştirir.
            string temp = new_deck[i][j];
            new_deck[i][j] = new_deck[rand_suit][rand_card_names];
            new_deck[rand_suit][rand_card_names] = temp;
        }
    }
}

// Karışık bir desteyi (2D dizi olarak temsil edilen) dört oyuncuya dağıtmak için kullanılır.
// Her bir oyuncu, kendi elindeki kartları temsil eden bir diziye atanır.
void deal_deck(string new_deck[4][13],string player1[13],string player2[13],string player3[13],string player4[13]){
    // Dört ayrı döngü kullanılır. Her bir döngü, "new_deck" dizisinden sırayla kartları çeker
    // ve her bir oyuncunun elindeki kartlarını temsil eden diziye atanır.
    for(int i = 0 ; i < 13 ; i++){
        player1[i] = new_deck[0][i];
    }
    for(int i = 0 ; i < 13 ; i++){
        player2[i] = new_deck[1][i];
    }
    for(int i = 0 ; i < 13 ; i++){
        player3[i] = new_deck[2][i];
    }
    for(int i = 0 ; i < 13 ; i++){
        player4[i] = new_deck[3][i];
    }
}

//Bu kod parçası, bir oyuncunun elindeki kartları temsil eden bir diziyi ekrana yazdırmak için kullanılır.
void show_hand(string player[13]){
    for(int i = 0 ; i < 13 ; i++){
        cout << player[i] <<endl;
    }
}

// Bu kod parçası, bir oyuncunun elindeki kartları, kartların değerlerine ve takımlarına göre sıralamak için kullanılır.
// Sıralanmış kartlar, mevcut oyuncunun dizisine geri atanır.
void order_hand(string player[13]) {
    string ordered_hand[13]; // Sıralanmış kartları geçici olarak saklamak için yeni bir dizi oluşturur.
    int ordered_index = 0; // Sıralanmış kartları "ordered_hand" dizisine eklemek için bir indeks oluşturur.

    for (int suit = static_cast<int>(Suits::Diamonds); suit <= static_cast<int>(Suits::Spades); ++suit) {
        for (int value = 0; value < 13; ++value) {
            string card_name = cardnames_to_string(static_cast<CardNames>(value)); // Mevcut kart değerini bir kart ismine dönüştürür.
            string card = card_name + " of " + suits_to_string(static_cast<Suits>(suit)); // Kartın tam adını oluşturur, yani "Kart Değeri of Takım Adı" biçiminde.
            
            // Mevcut kartın oyuncunun elinde olup olmadığını kontrol eder. Eğer kart elde bulunuyorsa, "ordered_hand" dizisine eklenir.
            for (int i = 0; i < 13; ++i) {
                if (player[i].find(card) != string::npos) {
                    ordered_hand[ordered_index++] = player[i];
                    break;
                }
            }
        }
    }
    // Sıralanmış kartlar "ordered_hand" dizisinde bulunur. Bu dizideki kartlar, sırasıyla "player" dizisine geri atanır.
    for (int i = 0; i < 13; ++i) {
        player[i] = ordered_hand[i];
    }
}


int main() {
    string deck[4][13];
    string new_deck[4][13];
    string player1[13];
    string player2[13];
    string player3[13];
    string player4[13];
    cout << "**************CREATE DECK**********************" << endl;
    create_deck(deck);
    show_deck(deck);
    cout << "************************************" << endl;
    cout << "***********SHUFFLE DECK*************************" << endl;
    shuffle_deck(deck,new_deck);
    show_deck(new_deck);
    cout << "************************************" << endl;
    cout << "**************DEAL DECK**********************" << endl;
    deal_deck(new_deck,player1,player2,player3,player4);
    show_hand(player1);
    cout << "************************************" << endl;
    cout << "**************ORDERED DECK**********************" << endl;
    order_hand(player1);
    show_hand(player1);
    return 0;
}
