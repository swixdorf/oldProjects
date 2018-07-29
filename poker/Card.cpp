//---------------------------------------------------------------------------


#pragma hdrstop

#include "Card.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

int Card::KartcevirIndex(int kart, int renk)
		{
			AnsiString Kartip="";
			switch (kart)
			{
				case 10:
					Kartip = "T";
					break;
				case 11:
					Kartip = "J";
					break;
				case 12:
				   Kartip = "Q";
					break;
				case 13:
				  Kartip = "K";
					break;
				case 14:
					Kartip = "A";
					break;
				default:
				   Kartip = IntToStr(kart);;
					break;

			}
			AnsiString RenkTip="";
			switch (renk)
			{
				case 0: RenkTip="d"; break;
				case 1: RenkTip="h"; break;
				case 2: RenkTip="s" ;break;
				case 3: RenkTip="c" ; break;
				default:
					   RenkTip="X";
			}
					 BYTE *rank=Kartip.c_str();
					 BYTE *suit= RenkTip.c_str();
			 return  chars2index(rank[0],suit[0]);


}


Card::Card(){
	gIndex = -1;
};

Card::~Card() {};

Card::Card(int index)
{
	if (index >= 0 && index < NUM_CARDS)
		gIndex = index;
	else
		gIndex = BAD_CARD;
}
Card::Card(int rank, int suit) {
	gIndex =(NUM_RANKS*suit) + rank;
}

	/**
	 * Return the integer index for this card.
	 * @return the card's index value
	 */

int Card::getPokerLibIndex()
{
	if(gIndex<=12)
		return(gIndex+26);
	if(gIndex<=25)
		return(gIndex);
	if(gIndex<=38)
		return(gIndex-26);
	return(gIndex);
}
	/**
 	 * Change the index of the card.
	 * @param index the new index of the card
	 */
void Card::setIndex(int &index) {
	gIndex = index;
}

	/**
	 * convert a rank and a suit to an index
	 * @param rank the rank to convert
	 * @param suit the suit to convert
	 * @return the index calculated from the rank and suit
	 */
int Card::toIndex(int &rank, int &suit) {
	return (NUM_RANKS*suit) + rank;
}

int Card::chars2index(BYTE &rank, BYTE &suit) {
	int r = -1;
	switch (rank) {
		case '2': r = TWO; break;
		case '3': r = THREE; break;
		case '4': r = FOUR; break;
		case '5': r = FIVE; break;
		case '6': r = SIX; break;
		case '7': r = SEVEN; break;
		case '8': r = EIGHT; break;
		case '9': r = NINE; break;
		case 'T': r = TEN; break;
		case 'J': r = JACK; break;
		case 'Q': r = QUEEN; break;
		case 'K': r = KING; break;
		case 'A': r = ACE; break;
		case 't': r = TEN; break;
		case 'j': r = JACK; break;
		case 'q': r = QUEEN; break;
		case 'k': r = KING; break;
		case 'a': r = ACE; break;
	}
	int s = -1;
	switch (suit) {
		case 'h': s = HEARTS; break;
		case 'd': s = DIAMONDS; break;
		case 's': s = SPADES; break;
		case 'c': s = CLUBS; break;
		case 'H': s = HEARTS; break;
		case 'D': s = DIAMONDS; break;
		case 'S': s = SPADES; break;
		case 'C': s = CLUBS; break;
	}
	if (s != -1 && r != -1)
		return toIndex(r,s);
	else return BAD_CARD;
}

	/**
	 * Constructor.
	 * Creates a card from its character based representation.
	 * @param rank the character representing the card's rank
	 * @param rank the character representing the card's suit
	 */
Card::Card(BYTE rank, BYTE suit) {
	gIndex = chars2index(rank,suit);
}



	/**
  	 * Change this card to another. This is more practical 
	 * than creating a new object for optimization reasons.
 	 * @param rank face value of the card
	 * @param suit suit of the card
	 */
void Card::setCard(int rank, int suit) {

gIndex=KartcevirIndex(rank,suit);
  //	gIndex = toIndex(rank, suit);
  }
  
void Card::setCardWin(int byte)
{
	int suit = (byte & 0x0F) - 1;
	int rank = ((byte >>4)  ) - 2;
	this->setCard(rank,suit);
}

	/**
	 * Obtain the rank of this card
	 * @return rank
	 */
int Card::getRank() {
	return (int)(gIndex%NUM_RANKS);
}

	/**
	 * Obtain the suit of this card
	 * @return suit
	 */
int Card::getSuit() {
	return (int)(gIndex/NUM_RANKS);
}

	/**
	 * Obtain a String representation of this Card
	 * @return A string for this card
	 */
String Card::toStringCard() {
	String s;
	//cout<<endl<<(getRank()+2)<<" "<<getSuit();
	switch (getRank()) {

		case ACE:   s+='A'; break;
		case KING:  s+='K'; break;
		case QUEEN: s+='Q'; break;
		case JACK:  s+='J'; break;
		case TEN:   s+='T'; break;
		case NINE:	s+='9'; break;
		case EIGHT:	s+='8'; break;
		case SEVEN:	s+='7'; break;
		case SIX:	s+='6'; break;
		case FIVE:	s+='5'; break;
		case FOUR:	s+='4'; break;
		case THREE:	s+='3'; break;
		case TWO:	s+='2'; break;
	}
	switch (getSuit()) {
		case HEARTS:   s+='h'; break;
		case DIAMONDS: s+='d'; break;
		case CLUBS:    s+='c'; break;
		case SPADES:   s+='s'; break;
	}
	return s;
}

BYTE * Card::toStringC() {
	AnsiString s;
	//cout<<endl<<getRank()<<" "<<getSuit();
	switch (getRank()) {

		case ACE:   s+='A'; break;
		case KING:  s+='K'; break;
		case QUEEN: s+='Q'; break;
		case JACK:  s+='J'; break;
		case TEN:   s+='T'; break;
		case NINE:	s+='9'; break;
		case EIGHT:	s+='8'; break;
		case SEVEN:	s+='7'; break;
		case SIX:	s+='6'; break;
		case FIVE:	s+='5'; break;
		case FOUR:	s+='4'; break;
		case THREE:	s+='3'; break;
		case TWO:	s+='2'; break;
	}
	switch (getSuit()) {
		case HEARTS:   s+='h'; break;
		case DIAMONDS: s+='d'; break;
		case CLUBS:    s+='c'; break;
		case SPADES:   s+='s'; break;
	}
	
	BYTE *c= new BYTE[s.Length()+1];
	strcpy(c, s.c_str());
	return c;

}
