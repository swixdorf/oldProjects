//---------------------------------------------------------------------------

#ifndef aiinterfaceH
#define aiinterfaceH
//---------------------------------------------------------------------------
#include "cardsvalue.h"
/*
class PokerAIInterface
{
public:
CardsValue myCardsValue;
 int Analiz();
int getmyAction() const { return  myAction; }

	void setMyBestHandPosition(int* theValue)
	{
		for (int i = 0; i < 5; i++)
			myBestHandPosition[i] = theValue[i];
	}
	void getMyBestHandPosition(int* theValue) const
	{
		for (int i = 0; i < 5; i++)
			theValue[i] = myBestHandPosition[i];
	}
void setMyCardsValueInt(int theValue) { myCardsValueInt = theValue;}
	int getMyCardsValueInt() const { return myCardsValueInt; }
void setMinimumRaise ( int theValue ) { minimumRaise = theValue; }
int getMinimumRaise() const { return minimumRaise; }

void setSBluff ( int theValue ) { sBluff = theValue; }
int getSBluff() const { return sBluff; }
void setSBluffStatus ( bool theValue ) { sBluffStatus = theValue; }
bool getSBluffStatus() const { return sBluffStatus; }
void setMySet(int theValue) { myLastRelativeSet = theValue; mySet += theValue; myCash -= theValue;	}
void setMySetAbsolute(int theValue) { mySet = theValue; }
void setMySetNull() { mySet = 0; myLastRelativeSet = 0; }
int getMySet() const { return mySet;}
int getMyLastRelativeSet() const { return myLastRelativeSet; }

void setMyRoundStartCash(int theValue) { myRoundStartCash = theValue;}
int getMyRoundStartCash() const { return myRoundStartCash; }

void setSmallBlind(int theValue) { smallBlind = theValue; }
int getSmallBlind() const { return smallBlind; }
void setMyCash(int theValue) { myCash = theValue; }
int getMyCash() const { return myCash; }
void setHighestSet(int theValue) { highestSet = theValue; }
int getHighestSet()  {
if(highestSet==0)
{
  highestSet= smallBlind;
}
return highestSet;

}
void setCurrentRound(int theValue) { currentRound = theValue; }
int getCurrentRound() const { return currentRound; }
void setPlayerCount(int theValue) { PlayerCount = theValue; }
int getPlayerCount(){return PlayerCount;};
void setBoardCards(int* theValue) { int i; for(i=0; i<5; i++) myBoardCards[i] = theValue[i]; }
void getBoardCards(int* theValue) { int i; for(i=0; i<5; i++) theValue[i] = myBoardCards[i]; }
void setMyCards(int* theValue) { int i; for(i=0; i<2; i++) myCards[i] = theValue[i]; }
void getMyCards(int* theValue) const { int i; for(i=0; i<2; i++) theValue[i] = myCards[i]; }
int flopCardsValue(int* cards);

virtual bool RandomBufer(unsigned char *rndbuf,int size) const =0;
virtual int RandomRange(int min,int max) const =0;
virtual void getRandNumber(int start, int end, int howMany, int* randArray, bool different, int* bad, int countBad) =0;
 PokerAI(){

			   srand((unsigned)time(0));
			   memset(myBoardCards,0,7*4) ;
			   memset(myCards,0,2*4) ;
			   myDude=0;
			   myDude4=0;
		  }
void PokerAIReset()
{

}
~PokerAI()
{
	//memset(myBoardCards,0,7*4) ;
     memset(myCards,0,2*4) ;
}






};     */

#endif
