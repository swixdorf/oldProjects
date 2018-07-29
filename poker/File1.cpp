#include "PokerAI.h"
using namespace std;
PokerAI *Poker_AI;
KartDagit()
{
int i, j, k,it;
Poker_AI->setPlayerCount(2);
Poker_AI->getPlayerCount();
	int *cardsArray = new int[2*Poker_AI->getPlayerCount() +5];
	Poker_AI->getRandNumber(0, 51, 2*Poker_AI->getPlayerCount()+5, cardsArray, 1,0,0);
	int tempBoardArray[5];
	int tempPlayerArray[2];
	int tempPlayerAndBoardArray[7];
	int bestHandPos[5];
	int sBluff;
	for(i=0; i<5; i++) {
		tempBoardArray[i] = cardsArray[i];
		tempPlayerAndBoardArray[i+2] = cardsArray[i];
	}

	k = 0;
	//myBoard->setMyCards(tempBoardArray);
	Poker_AI->setBoardCards(tempBoardArray);
	for(it=0; it!=Poker_AI->getPlayerCount(); it++, k++) {



		for(j=0; j<2; j++) {
			tempPlayerArray[j] = cardsArray[2*k+j+5];
			tempPlayerAndBoardArray[j] = cardsArray[2*k+j+5];
		}
		//   Poker_AI->myCardsValue.cardsValue() ;
		Poker_AI->getMyBestHandPosition(bestHandPos);
	Poker_AI->setMyCards(tempPlayerArray);
	Poker_AI->setMyCardsValueInt(Poker_AI->myCardsValue.cardsValue(tempPlayerAndBoardArray, bestHandPos));
		Poker_AI->setMyBestHandPosition(bestHandPos);
		Poker_AI->setMyCash(100000) ;
		Poker_AI->setSmallBlind(1000);
		Poker_AI->setMyRoundStartCash(100000);
		for(j=0; j<5; j++) {


		// set sBluff for all players --> TODO for ai-player in internet

			Poker_AI->getRandNumber(1,100,1,&sBluff,0,0,0);
			Poker_AI->setSBluff(sBluff);
			Poker_AI->setSBluffStatus(0);
		}
	}

delete[]  cardsArray;
}

int main()
{
Poker_AI = new PokerAI();
KartDagit();
int k1[2];
Poker_AI->getMyCards(k1) ;
Card *Card1= new Card();
Card1->setIndex(k1[0]);
string a=Card1->toString();
Card1->setIndex(k1[1]);
a=Card1->toString();


Poker_AI->Analiz();
	switch(Poker_AI->getmyAction())
	{
	case PLAYER_ACTION_NONE:     break;
	case PLAYER_ACTION_FOLD:      break;
	case PLAYER_ACTION_CHECK:     break;
	case PLAYER_ACTION_CALL:      break;
	case PLAYER_ACTION_BET:       break;
	case PLAYER_ACTION_RAISE:     break;
	case PLAYER_ACTION_ALLIN:     break;
	}



// Poker_AI->setPlayerCount(2);

//int cardsArray[9];// = new int[2*2 +5];
//	Poker_AI->getRandNumber(0, 51, 2*2+5, cardsArray, 1,0,0);
//KartDagit();
Poker_AI->setMinimumRaise(250);
free(Poker_AI);//Poker_AI->~PokerAI();
int x=Poker_AI->getMinimumRaise();
srand((unsigned)time(0));
int random_integer;
int lowest=0, highest=51;
int range=(highest-lowest)+1;
for(int index=0; index<20; index++){
random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0));
cout << random_integer << endl;

}

}
