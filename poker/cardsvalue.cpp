﻿/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "cardsvalue.h"

//using namespace std;

CardsValue::CardsValue()
{
}


CardsValue::~CardsValue()
{
}

int CardsValue::holeCardsClass(int one, int two) {

  if((one-1)%13<(two-1)%13) {
    int temp = one;
    one = two;
    two = temp;
  }


  if((one-1)%13 == (two-1)%13) {
    if((one-1)%13+2 > 10) return 10;
    else {
      switch((one-1)%13+2) {
        case 10: return 9;
        case 9: return 8;
        case 8: return 7;
        case 7: return 6;
        default: return 5;
      }
    }
  }
  switch((one-1)%13+2) {
  //Ass
    case 14: { 
      if((one-1)/13 == (two-1)/13) {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 10;
	  case 2: return 9;
	  case 3: return 9;
	  case 4: return 8;
	  default: return 7;
        }
      }
      else {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 9;
	  case 2: return 8;
	  case 3: return 7;
	  case 4: return 7;
	  default: return 4;
        }
      }
    } break;
    //K�ig
    case 13: { 
      if((one-1)/13 == (two-1)/13) {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 9;
	  case 2: return 8;
	  case 3: return 8;
	  case 4: return 6;
	  default: return 5;
        }
      }
      else {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 7;
	  case 2: return 6;
	  case 3: return 6;
	  default: return 4;
        }
      }
    } break;
    //Dame
    case 12: { 
      if((one-1)/13 == (two-1)/13) {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 8;
	  case 2: return 7;
	  case 3: return 6;
	  case 4: return 5;
	  default: return 4;
        }
      }
      else {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 6;
	  case 2: return 6;
	  case 3: return 4;
	  default: return 3;
        }
      }
    } break;
    //Bube
    case 11: { 
      if((one-1)/13 == (two-1)/13) {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 7;
	  case 2: return 6;
	  case 3: return 5;
	  case 4: return 4;
	  default: return 3;
        }
      }
      else {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 6;
	  case 2: return 5;
	  case 3: return 4;
	  default: return 2;
        }
      }
    } break;
    //10
    case 10: { 
      if((one-1)/13 == (two-1)/13) {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 6;
	  case 2: return 5;
	  default: return 2;
        }
      }
      else {
        switch((one-1)%13-(two-1)%13) {
          case 1: return 5;
	  case 2: return 4;
	  default: return 1;
        }
      }
    } break;
    //Rest
    default: {
      if((one-1)%13 - (two-1)%13 <= 2) {
        if((one-1)/13 == (two-1)/13) return 5;
        else return 3;
      }
      else {
        if((one-1)%13 - (two-1)%13 == 3) return 2;
        else return 1;
      }
    }
 }


}

int CardsValue::holeCardsToIntCode(int* cards) {

	// Code der HoleCards ermitteln
	if(cards[0]%13 == cards[1]%13) {
		return ((cards[0]%13)*1000 + (cards[0]%13)*10);
	} else {
		if(cards[0]%13 < cards[1]%13) {
			if(cards[0]/13 == cards[1]/13) {
				return ((cards[0]%13)*1000 + (cards[1]%13)*10 + 1);
			} else {
				return ((cards[0]%13)*1000 + (cards[1]%13)*10);
			}
		} else {
			if(cards[0]/13 == cards[1]/13) {
				return ((cards[1]%13)*1000 + (cards[0]%13)*10 + 1);
			} else {
				return ((cards[1]%13)*1000 + (cards[0]%13)*10);
			}
		}
	}

}

int* intCodeToHoleCards(int code) {

	// one possibility !!!

	int* cards = new int[2];

	cards[0] = code/1000;
	cards[1] = (code-cards[0]*1000)/10;

	if(cards[0]==cards[1]) { cards[1] +=13; }
	else {
		if(code%10 == 0) cards[1] +=13;
	}

	return cards;

}

int CardsValue::cardsValue(int* cards, int* position) {

int array[7][3];
	int j1, j2, j3, j4, j5, k1, k2, ktemp[3];

	// Kartenwerte umwandeln (z.B. [ 11 (Karo K�ig) -> 0 11 ] oder [ 31 (Pik 7) -> 2 5 ] )
	for(j1=0; j1<7; j1++) {
		array[j1][0] = cards[j1]/13;
		array[j1][1] = cards[j1]%13;
		array[j1][2] = j1;
	}

	// Karten nach Farben sortieren: Kreuz - Pik - Herz - Karo
	for(k1=0; k1<7; k1++) {
		for(k2=k1+1; k2<7; k2++) {
			if(array[k1][0]<array[k2][0]) {
				ktemp[0] = array[k1][0];
				ktemp[1] = array[k1][1];
				ktemp[2] = array[k1][2];
				array[k1][0] = array[k2][0];
				array[k1][1] = array[k2][1];
				array[k1][2] = array[k2][2];
				array[k2][0] = ktemp[0];
				array[k2][1] = ktemp[1];
				array[k2][2] = ktemp[2];
			}
		}
	}

	// Karten innerhalb der Farben nach der Gr�e sortieren: Ass - K�ig - Dame - ... - 4 - 3 - 2
	for(k1=0; k1<7; k1++) {
		for(k2=k1+1; k2<7; k2++) {
			if(array[k1][0]==array[k2][0] && array[k1][1]<array[k2][1]) {
				ktemp[0] = array[k1][0];
				ktemp[1] = array[k1][1];
				ktemp[2] = array[k1][2];
				array[k1][0] = array[k2][0];
				array[k1][1] = array[k2][1];
				array[k1][2] = array[k2][2];
				array[k2][0] = ktemp[0];
				array[k2][1] = ktemp[1];
				array[k2][2] = ktemp[2];
			}
		}
	}

	// Karten auf Bl�ter testen. Klasseneinteilung absteigend: 9 - Royal Flush, 8 - Straight Flush, ... 2 - Zwei Paare, 1 - Ein Paar, 0 - Nischt

	// auf Royal Flush (Klasse 9) und Straight Flush (Klasse 8) testen
	for(j1=0; j1<3; j1++) {
		// 5 Karten gleiche Farbe ?
		if(array[j1][0] == array[j1+1][0] && array[j1][0] == array[j1+2][0] && array[j1][0] == array[j1+3][0] && array[j1][0] == array[j1+4][0]) {
			// zus�zlich in Stra�nform ?
			if(array[j1][1]-1 == array[j1+1][1] && array[j1+1][1]-1 == array[j1+2][1] && array[j1+2][1]-1 == array[j1+3][1] && array[j1+3][1]-1 == array[j1+4][1]) {
				// mit Ass an der Spitze ?
				if(array[j1][1] == 12) {
					// Royal Flush (9*100000000)
					if(position) {
						// Position-Array fuellen
						for(j2=0; j2<5; j2++) {
							position[j2] = array[j1+j2][2];
						}
					}
					return 900000000;
				}
				// sonst nur Straight Flush (8*100000000 + (h�hste Straight-Karte)*1000000)
				else {
					if(position) {
						// Position-Array fuellen
						for(j2=0; j2<5; j2++) {
							position[j2] = array[j1+j2][2];
						}
					}
					return 800000000+array[j1][1]*1000000;
				}
			}
		}
	}

	// Straight Flush Ausnahme: 5-4-3-2-A
	for(j1=0; j1<3; j1++) {
		// 5 Karten gleiche Farbe ?
		if(array[j1][0] == array[j1+1][0] && array[j1][0] == array[j1+2][0] && array[j1][0] == array[j1+3][0] && array[j1][0] == array[j1+4][0]) {
			for(j2=j1+1; j2<4; j2++) {
				if(array[j1][1]-9==array[j2][1] && array[j2][1]-1==array[j2+1][1] && array[j2+1][1]-1==array[j2+2][1] && array[j2+2][1]-1==array[j2+3][1] && array[j1][0]==array[j2+2][0] && array[j1][0]==array[j2+3][0]) {
					// Straight Flush mit 5 als höchste Karte -> 8*100000000+3*1000000
					if(position) {
						// Position-Array fuellen
						position[0] = array[j1][2];
						for(j3=0; j3<4; j3++) {
							position[j3+1] = array[j2+j3][2];
						}
					}
					return 800000000+3*1000000;
				}
			}
		}
	}

	// auf Flush (Klasse 5) testen
	for(j1=0; j1<3; j1++) {
		if(array[j1][0] == array[j1+1][0] && array[j1][0] == array[j1+2][0] && array[j1][0] == array[j1+3][0] && array[j1][0] == array[j1+4][0]) {
			// Flush -> 5*10000000 + h�ste Flush Karten mit absteigender Wertung
			if(position) {
				// Position-Array fuellen
				for(j2=0; j2<5; j2++) {
					position[j2] = array[j1+j2][2];
				}
			}
			return 500000000+array[j1][1]*1000000+array[j1+1][1]*10000+array[j1+2][1]*100+array[j1+3][1]*10+array[j1+4][1];
		}
	}



	// Karten fr den Vierling-, Full-House-, Drilling- und Paartest umsortieren
	for(k1=0; k1<7; k1++) {
		for(k2=k1+1; k2<7; k2++) {
			if(array[k1][1]<array[k2][1]) {
				ktemp[0] = array[k1][0];
				ktemp[1] = array[k1][1];
				ktemp[2] = array[k1][2];
				array[k1][0] = array[k2][0];
				array[k1][1] = array[k2][1];
				array[k1][2] = array[k2][2];
				array[k2][0] = ktemp[0];
				array[k2][1] = ktemp[1];
				array[k2][2] = ktemp[2];
			}
		}
	}

	// nach Position sortieren: erst board, dann hole cards
	for(k1=0; k1<7; k1++) {
		for(k2=k1+1; k2<7; k2++) {
			if(array[k1][1]==array[k2][1] && array[k1][2]<array[k2][2]) {
				ktemp[0] = array[k1][0];
				ktemp[1] = array[k1][1];
				ktemp[2] = array[k1][2];
				array[k1][0] = array[k2][0];
				array[k1][1] = array[k2][1];
				array[k1][2] = array[k2][2];
				array[k2][0] = ktemp[0];
				array[k2][1] = ktemp[1];
				array[k2][2] = ktemp[2];
			}
		}
	}

	// auf Vierling (Klasse 7) testen
	for(j1=0; j1<4; j1++) {
		if(array[j1][1] == array[j1+1][1] && array[j1][1] == array[j1+2][1] && array[j1][1] == array[j1+3][1]) {
			// Position des Kickers ermitteln und der Blattwertung als dritte Gewichtung hinzuaddieren
			if(j1==0) { 
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<5; j2++) {
						position[j2] = array[j2][2];
					}
				}
				return 700000000+array[j1][1]*1000000+array[j1+4][1]*10000;
			}
			else {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<4; j2++) {
						position[j2] = array[j1+j2][2];
					}
					position[4] = array[0][2];
				}
				return 700000000+array[j1][1]*1000000+array[0][1]*10000;
			}
		}
	}

	// Hilfsvariablen fr die Full-House-Paar- und -Drilling-Zuordnung
	int drei, zwei;

	// auf Straight (Klasse 4) und Full House (Klasse 6) testen
	for(j1=0; j1<7; j1++) {
		for(j2=j1+1; j2<7; j2++) {
			for(j3=j2+1; j3<7; j3++) {
				for(j4=j3+1; j4<7; j4++) {
					for(j5=j4+1; j5<7; j5++) {
						// Straight
						if(array[j1][1]-1 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1] && array[j4][1]-1 == array[j5][1]) {
							if(position) {
								// Position-Array fuellen
								position[0] = array[j1][2];
								position[1] = array[j2][2];
								position[2] = array[j3][2];
								position[3] = array[j4][2];
								position[4] = array[j5][2];
							}
							return 400000000+array[j1][1]*1000000;
						}
						// Full House
						if((array[j1][1] == array[j2][1] && array[j1][1] == array[j3][1] && array[j4][1] == array[j5][1]) || (array[j3][1] == array[j4][1] && array[j3][1] == array[j5][1] && array[j1][1] == array[j2][1])) {
							if(position) {
								// Position-Array fuellen
								position[0] = array[j1][2];
								position[1] = array[j2][2];
								position[2] = array[j3][2];
								position[3] = array[j4][2];
								position[4] = array[j5][2];
							}
							// Paar und Drilling des Full House ermitteln ermitteln
							if(array[j3][1]==array[j1][1]) { drei = array[j1][1]; zwei = array[j4][1]; }
							else { drei = array[j4][1]; zwei = array[j1][1]; }
							return 600000000+drei*1000000+zwei*10000;
						}
					}
				}
			}
		}
	}

	// auf Straight-Spezialfall ( 5 4 3 2 A ) testen
	for(j1=0; j1<7; j1++) {
		for(j2=j1+1; j2<7; j2++) {
			for(j3=j2+1; j3<7; j3++) {
				for(j4=j3+1; j4<7; j4++) {
					for(j5=j4+1; j5<7; j5++) {
						if(array[j1][1]-9 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1] && array[j4][1]-1 == array[j5][1]) {
							if(position) {
								// Position-Array fuellen
								position[0] = array[j1][2];
								position[1] = array[j2][2];
								position[2] = array[j3][2];
								position[3] = array[j4][2];
								position[4] = array[j5][2];
							}
							return 400000000+array[j2][1]*1000000;
						}
					}
				}
			}
		}
	}

	// auf Drilling (Klasse 3) testen
	for(j1=0; j1<5; j1++) {
		if(array[j1][1] == array[j1+1][1] && array[j1][1] == array[j1+2][1]) {
			// Kicker ermitteln
			if(j1==0) {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<5;j2++) {
						position[j2] = array[j2][2];
					}
				}
				return 300000000+array[j1][1]*1000000+array[j1+3][1]*10000+array[j1+4][1]*100;
			}
			else {
				if(j1==1) {
					if(position) {
						// Position-Array fuellen
						for(j2=0; j2<5;j2++) {
							position[j2] = array[j2][2];
						}
					}
					return 300000000+array[j1][1]*1000000+array[j1-1][1]*10000+array[j1+3][1]*100;
				}
				else {
					if(position) {
						// Position-Array fuellen
						for(j2=0; j2<3;j2++) {
							position[j2] = array[j1+j2][2];
						}
						position[3] = array[0][2];
						position[4] = array[1][2];
					}
					return 300000000+array[j1][1]*1000000+array[0][1]*10000+array[1][1]*100;
				}
			}
		}
	}

	// auf Zwei Paare (Klasse 2) testen
	for(j1=0; j1<4; j1++) {
		for(j2=j1+2; j2<6; j2++) {
			if(array[j1][1] == array[j1+1][1] && array[j2][1] == array[j2+1][1]) {
				// Kicker ermitteln
				if(j1==0) {
					if(j2==2) {
						if(position) {
							// Position-Array fuellen
							position[0] = array[j1][2];
							position[1] = array[j1+1][2];
							position[2] = array[j2][2];
							position[3] = array[j2+1][2];
							position[4] = array[j2+2][2];	
						}
						return 200000000+array[j1][1]*1000000+array[j2][1]*10000+array[j2+2][1]*100;
					}
					else {
						if(position) {
							// Position-Array fuellen
							position[0] = array[j1][2];
							position[1] = array[j1+1][2];
							position[2] = array[j2][2];
							position[3] = array[j2+1][2];
							position[4] = array[j1+2][2];	
						}
						return 200000000+array[j1][1]*1000000+array[j2][1]*10000+array[j1+2][1]*100;
					}
				}
				else {
					if(position) {
						// Position-Array fuellen
						position[0] = array[j1][2];
						position[1] = array[j1+1][2];
						position[2] = array[j2][2];
						position[3] = array[j2+1][2];
						position[4] = array[0][2];	
					}
					return 200000000+array[j1][1]*1000000+array[j2][1]*10000+array[0][1]*100;
				}
			}
		}
	}

	// auf Paar (Klasse 1) testen
	for(j1=0; j1<6; j1++) {
		if(array[j1][1] == array[j1+1][1]) {
			// Kicker ermitteln
			if(j1==0) {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<5; j2++) {
						position[j2] = array[j2][2];
					}
				}
				return 100000000+array[j1][1]*1000000+array[j1+2][1]*10000+array[j1+3][1]*100+array[j1+4][1];
			}
			if(j1==1) {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<5; j2++) {
						position[j2] = array[j2][2];
					}
				}
				return 100000000+array[j1][1]*1000000+array[j1-1][1]*10000+array[j1+2][1]*100+array[j1+3][1];
			}
			if(j1==2) {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<5; j2++) {
						position[j2] = array[j2][2];
					}
				}
				return 100000000+array[j1][1]*1000000+array[j1-2][1]*10000+array[j1-1][1]*100+array[j1+2][1];
			}
			else {
				if(position) {
					// Position-Array fuellen
					for(j2=0; j2<2; j2++) {
						position[j2] = array[j1+j2][2];
					}
					position[2] = array[0][2];
					position[3] = array[1][2];
					position[4] = array[2][2];
				}
				return 100000000+array[j1][1]*1000000+array[0][1]*10000+array[1][1]*100+array[2][1];
			}
		}
	}

	// Highest Card (Klasse 0) + Kicker
	if(position) {
		// Position-Array fuellen
		for(j2=0; j2<5; j2++) {
			position[j2] = array[j2][2];
		}
	}
	return array[0][1]*1000000+array[1][1]*10000+array[2][1]*100+array[3][1]*10+array[4][1];
}


vector< vector<int> > CardsValue::calcCardsChance(GameState beRoID, int* playerCards, int* boardCards)
{
	int i,j;

	vector< vector<int> > chance(2);

	chance[0].resize(10);
	chance[1].resize(10);

	for(i=0;i<10;i++) {
		chance[0][i] = 0;
		chance[1][i] = 0;
	}

	int cards[7];
	int sum = 0;

	cards[0] = playerCards[0];
	cards[1] = playerCards[1];
	for(i=0;i<5;i++) cards[i+2] = boardCards[i];

	switch(beRoID) {
		case GAME_STATE_PREFLOP: {
			ArrayData* myArrayData = new ArrayData;

			chance = myArrayData->getHandChancePreflop(holeCardsToIntCode(playerCards));

			delete myArrayData;

		} break;
		case GAME_STATE_FLOP: {

			for(i=0;i<51;i++) {
				if(i!=cards[0] && i!=cards[1] && i!=cards[2] && i!=cards[3] && i!=cards[4]) {
				for(j=i+1;j<52;j++) {
					if(j!=cards[0] && j!=cards[1] && j!=cards[2] && j!=cards[3] && j!=cards[4]) {
						cards[5] = i;
						cards[6] = j;
						(chance[0][cardsValue(cards,0)/100000000])++;
						sum++;
					}
				}
				}
			}
			for(i=0;i<10;i++) {
				if(chance[0][i] > 0) chance[1][i] = 1;
				chance[0][i] = (int)(((double)chance[0][i]/(double)sum)*100.0+0.5);
			}

		} break;
		case GAME_STATE_TURN: {

			for(i=0;i<52;i++) {
				if(i!=cards[0] && i!=cards[1] && i!=cards[2] && i!=cards[3] && i!=cards[4] && i!=cards[5]) {
					cards[6] = i;
					(chance[0][cardsValue(cards,0)/100000000])++;
					sum++;
				}
			}
			for(i=0;i<10;i++) {
				if(chance[0][i] > 0) chance[1][i] = 1;
				chance[0][i] = (int)(((double)chance[0][i]/(double)sum)*100.0+0.5);
			}

		} break;
		case GAME_STATE_RIVER: {
			chance[0][cardsValue(cards,0)/100000000] = 100;
			chance[1][cardsValue(cards,0)/100000000] = 1;
		} break;
		default: {
		}
	}

	return chance;
}

//int** CardsValue::showdown(GameState beRoID, int** playerCards, int playerCount) {
//
// 	int i,j;
// 
// 	int** chance = new int*[2];
// 
// 	for(i=0;i<10;i++) {
// 		chance[i] = new int[2];
// 		for(j=0;j<2;j++) {
// 			chance[i][j] = 0;
// 		}
// 	}
// 
// 	int rand[5];
// 
// 	return chance;
//
//}
