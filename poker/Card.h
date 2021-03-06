//---------------------------------------------------------------------------

#ifndef CardH
#define CardH
#include <vcl.h>
//---------------------------------------------------------------------------
class Card{
	
private:
	int gIndex; //card index 0-51	

public:

	static const int CLUBS = 0;
	static const int DIAMONDS = 1;
	static const int HEARTS = 2;
	static const int SPADES = 3;

	static const int BAD_CARD = -1;
	static const int TWO = 0;
	static const int THREE = 1;
	static const int FOUR = 2;
	static const int FIVE = 3;
	static const int SIX = 4;
	static const int SEVEN = 5;
	static const int EIGHT = 6;
	static const int NINE = 7;
	static const int TEN = 8;
	static const int JACK = 9;
	static const int QUEEN = 10;
	static const int KING = 11;
	static const int ACE = 12;

	static const int NUM_SUITS = 4;
	static const int NUM_RANKS = 13;
	static const int NUM_CARDS = 52;

 	Card();
	~Card();
	Card(int index);
	Card(BYTE rank, BYTE suit);
	Card(int rank, int suit);
	int inline getIndex()
	{

	return gIndex;

    }
	int getPokerLibIndex();
	void setIndex(int &index);
	int toIndex(int &rank, int &suit);
	int chars2index(BYTE &rank, BYTE &suit);
	void setCard(int rank, int suit);
	void setCardWin(int byte);
	int getRank();
	int getSuit();
	String toStringCard();
	BYTE * toStringC();
	int Card::KartcevirIndex(int kart, int renk);
	int value;int suit;


};


#endif
