﻿//---------------------------------------------------------------------------


#pragma hdrstop

#include "PokerAI.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
bool RandomBufer(unsigned char *rndbuf,int size)
{
	for(int index=0; index<size; index++){

		rndbuf[index]=rand();
	}
	return true;
}
void PokerAI::getRandNumber(int start, int end, int howMany, int* randArray, bool different, int* bad, int countBad) {

	int r = end-start+1;
	unsigned char rand_buf[4];
	unsigned int randNumber;

	int i,j;

	if (!different) {

		for (i=0; i<howMany; i++) {
			   //RAND_bytes
			if(!::RandomBufer(rand_buf, 4))
			{

			}

			randNumber = 0;
			for(j=0; j<4; j++) {
				randNumber += (rand_buf[j] << 8*j);
			}

			if(randNumber < ( (unsigned int) ( ((double)numeric_limits<unsigned int>::max()) / r ) ) * r) {
				randArray[i] = start + (randNumber % r);
			}

		}
	}
	else {

		int *tempArray = new int[end-start+1];
		for (i=0; i<(end-start+1); i++) tempArray[i]=1;

		if(bad) {
			for(i=0;i<countBad;i++) {
				tempArray[bad[i]]=0;
			}
		}

		int counter(0);
		while (counter < howMany) {

			if(!RandomBufer(rand_buf, 4))
			{
			  //	LOG_MSG("RAND_bytes failed!");
			}

			randNumber = 0;
			for(j=0; j<4; j++) {
				randNumber += (rand_buf[j] << 8*j);
			}

			if(randNumber < ( (unsigned int) ( ((double)numeric_limits<unsigned int>::max()) / r ) ) * r) {
				randNumber = randNumber % r;

				if (tempArray[randNumber] == 1) {

					randArray[counter] = start + randNumber;
					tempArray[randNumber] = 0;
					counter++;
				}
			}

		}

		delete[] tempArray;
	}

}

int PokerAI::Analiz(int tur)
{
  if(tur==0)
  {
   switch(getCurrentRound()) {

	case 0:preflopEngine(); break;
	case 1:flopEngine(); break;
	case 2:turnEngine(); break;
	case 3:riverEngine();break;
	}
   }
   else
   {
    switch(getCurrentRound()) {

	case 0:preflopEngine3(); break;
	case 1:flopEngine3(); break;
	case 2:turnEngine3(); break;
	case 3:riverEngine3();break;
	}
   }

}
int PokerAI::flopCardsValue(int* cards) {

    int array[5][3];
    int j1, j2, j3, j4, j5, k1, k2, ktemp[3];
    int temp = 0;
    int temp1 = 0;
    int temp2 = 0;
    int temp2Array[2];
    int tempValue = -1;
    bool breakLoop = 0;

    // Kartenwerte umwandeln (z.B. [ 11 (Karo K�ig) -> 0 11 ] oder [ 31 (Pik 7) -> 2 5 ] )
    for(j1=0; j1<5; j1++) {
        array[j1][0] = cards[j1]/13;
        array[j1][1] = cards[j1]%13;
        array[j1][2] = j1;
    }

    // Karten nach Farben sortieren: Kreuz - Pik - Herz - Karo
    for(k1=0; k1<5; k1++) {
        for(k2=k1+1; k2<5; k2++) {
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
    for(k1=0; k1<5; k1++) {
        for(k2=k1+1; k2<5; k2++) {
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

    // auf Straight Flush und Flush testen
    // 5 Karten gleiche Farbe ?
    if(array[0][0] == array[1][0] && array[0][0] == array[2][0] && array[0][0] == array[3][0] && array[0][0] == array[4][0]) {
        // Straight Flush?
        if(array[0][1]-4 == array[4][1]) {
            //              	cout << "Straight Flush";
            return 80000;
        }
        else {
            // Straight Flush Ausnahme: 5-4-3-2-A
            if(array[0][1]==12 && array[1][1]==3 && array[2][1]==2 && array[3][1]==1 && array[4][1]==0) {
                //                   		cout << "Straight Flush Ass unten";
                return 80000;
            }
            // Flush
            else {
                //                   		cout << "Flush";
                return 80000;
            }
        }
    }

    // auf Straight Flush Draw und Flush Draw testen
    for(j1=0; j1<2 && !breakLoop; j1++) {
        // 4 Karten gleiche Farbe ?
        if(array[j1][0] == array[j1+1][0] && array[j1][0] == array[j1+2][0] && array[j1][0] == array[j1+3][0]) {
            // zusammenhaengender Strassenansatz ?
            if(array[j1][1]-3 == array[j1+3][1]) {
                // Strassenansatz am Rand?
                if(array[j1][1] == 12) {
                    //                        		cout << "zusammenhaengender Straight-Flush-Draw mit Ass high";
                    for(j2=0; j2<4; j2++) {
                        if(array[j1+j2][2] <= 1) temp++;
                    }
                    return (70012 + temp*100);
                }
                // Strassenansatz in der Mitte
                else {
                    //                        		cout << "zusammenhaengender Straight-Flush-Draw in der Mitte";
                    for(j2=0; j2<4; j2++) {
                        if(array[j1+j2][2] <= 1) temp++;
                    }
                    return (70000 + temp*100 + array[j1][1]);
                }
            }
            else {
                // Bauchschuss ?
                if(array[j1][1]-4 == array[j1+3][1]) {
                    //                         		cout << "Straight-Flush-Bauchschuss";
                    for(j2=0; j2<4; j2++) {
                        if(array[j1+j2][2] <= 1) temp++;
                    }
                    return (71000 + temp*100 + array[j1][1]);
                }
                else {
                    // Test auf Straight-Flush-Ausnahme 5-4-3-2-A
                    if(array[j1][1] == 12 && (array[j1+1][1]<=3 || (array[j1+2][1]<=3 && array[j1][0]==array[j1+4][0]))) {
                        //                              		cout << "Straight-Flush-Draw Ass unten";
                        for(j2=0; j2<4; j2++) {
                            if(array[j1+j2][2] <= 1) temp++;
                        }
                        return (71012 + temp*100);
                    }
                    // Flush Draw
                    else {
                        //                              		cout << "Flush Draw";

                        // Anteil ermitteln
                        for(j2=0; j2<4; j2++) {
                            if(array[j1+j2][2] <= 1) {
                                temp2Array[temp] = array[j1+j2][1];
                                temp++;
                            }
                        }

                        // Anteil 2
                        if(temp==2) {
                            for(j2=0; j2<4; j2++) {
                                if(temp2Array[1] > array[j1+j2][1]) temp1++;
                                if(temp2Array[0] > array[j1+j2][1]) temp2++;
                            }
                            return (60000 + temp1*1000 + temp2*100 + array[j1][1]);
                        }
                        // Anteil 1
                        else {

                            // 2.Stelle
                            for(j2=0; j2<4; j2++) {
                                if(j1==0) {
                                    if(array[4][1] < array[j1+j2][1]) temp1++;
                                } else {
                                    if(array[0][1] < array[j1+j2][1]) temp1++;
                                }
                            }
                            if(temp1 >= 2) temp1 = 1;
                            if(temp1 == 4) temp1 = 2;

                            // 3.Stelle
                            for(j2=0; j2<4; j2++) {
                                if(temp2Array[0] < array[j1+j2][1]) temp2++;
                            }
                            tempValue = (50000 + temp1*1000 + temp2*100 + temp2Array[0]);
                            breakLoop = 1;
                        }
                    }
                }
            }
        }
    }

    // Karten fr den Vierling-, Full-House-, Drilling- und Paartest umsortieren
    for(k1=0; k1<5; k1++) {
        for(k2=k1+1; k2<5; k2++) {
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

    // auf Vierling testen
    for(j1=0; j1<2; j1++) {
        if(array[j1][1] == array[j1+1][1] && array[j1][1] == array[j1+2][1] && array[j1][1] == array[j1+3][1]) {
            //			cout << "Vierling ";
            return 80000;
        }
    }


    // auf Straight und Full House testen
    // Straight
    if((array[0][1]-1 == array[1][1] || array[0][1]-9 == array[1][1] ) && array[1][1]-1 == array[2][1] && array[2][1]-1 == array[3][1] && array[3][1]-1 == array[4][1]) {
        //           	cout << "Straight";
        return 80000;
    }
    // Full House
    if((array[0][1] == array[1][1] && array[0][1] == array[2][1] && array[3][1] == array[4][1]) || (array[2][1] == array[3][1] && array[2][1] == array[4][1] && array[0][1] == array[1][1])) {
        //           	cout << "Full House";
        return 80000;
    }


    // auf Straßenansatz testen
    for(j1=0; j1<5 && !breakLoop; j1++) {
        for(j2=j1+1; j2<5 && !breakLoop; j2++) {
            for(j3=j2+1; j3<5 && !breakLoop; j3++) {
                for(j4=j3+1; j4<5 && !breakLoop; j4++) {
                    // zusammenhaengender Strassenansatz ?
                    if((array[j1][1]-1 == array[j2][1] || (array[j1][1]-9 == array[j2][1] && array[j1][1] == 12)) && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1]) {
                        // Strassenansatz am Rand?
                        if(array[j1][1] == 12) {
                            // 							cout << "zusammenhaengender Straight-Draw mit Ass high";

                            // Anteil ermitteln
                            if(array[j1][2] <= 1) {
                                temp2Array[temp] = array[j1][1];
                                temp++;
                            }
                            if(array[j2][2] <= 1) {
                                temp2Array[temp] = array[j2][1];
                                temp++;
                            }
                            if(array[j3][2] <= 1) {
                                temp2Array[temp] = array[j3][1];
                                temp++;
                            }
                            if(array[j4][2] <= 1) {
                                temp2Array[temp] = array[j4][1];
                                temp++;
                            }

                            // Anteil 2
                            if(temp==2) {
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 3) temp1 = 2;

                                tempValue = (40012 + temp1*2000);
                            }
                            // Anteil 1
                            else {

                                // 2.Stelle
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 1) temp1 = 2;

                                tempValue = (40012 + (temp1+1)*1000);
                            }
                            breakLoop = 1;
                        }
                        // Strassenansatz in der Mitte
                        else {
                            //                        				cout << "zusammenhaengender Straight-Draw in der Mitte";

                            // Anteil ermitteln
                            if(array[j1][2] <= 1) {
                                temp2Array[temp] = array[j1][1];
                                temp++;
                            }
                            if(array[j2][2] <= 1) {
                                temp2Array[temp] = array[j2][1];
                                temp++;
                            }
                            if(array[j3][2] <= 1) {
                                temp2Array[temp] = array[j3][1];
                                temp++;
                            }
                            if(array[j4][2] <= 1) {
                                temp2Array[temp] = array[j4][1];
                                temp++;
                            }

                            // Anteil 2
                            if(temp==2) {
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 3) temp1 = 2;

                                tempValue = (40000 + (temp1+2)*2000 + array[j1][1]);
                            }
                            // Anteil 1
                            else {

                                // 2.Stelle
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 1) temp1 = 2;

                                // 3.Stelle
                                for(j5=0; j5<5; j5++) {
                                    if(j5 != j1 && j5 != j2 && j5 != j3 && j5 != j4) {
                                        if(array[j5][1] < array[j4][1]) {
                                            temp2 = 0;
                                        }
                                        else {
                                            temp2 = 1;
                                        }
                                    }
                                }

                                tempValue = (40000 + (temp1+5)*1000 + temp2*100 + array[j1][1]);
                            }
                            breakLoop = 1;
                        }
                    }
                    else {
                        // Bauchschuss ?
                        if((array[j1][1]-2 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1]) || (array[j1][1]-1 == array[j2][1] && array[j2][1]-2 == array[j3][1] && array[j3][1]-1 == array[j4][1]) || (array[j1][1]-1 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-2 == array[j4][1])) {
                            // 							cout << "Straight-Draw Bauchschuss";

                            // Anteil ermitteln
                            if(array[j1][2] <= 1) {
                                temp2Array[temp] = array[j1][1];
                                temp++;
                            }
                            if(array[j2][2] <= 1) {
                                temp2Array[temp] = array[j2][1];
                                temp++;
                            }
                            if(array[j3][2] <= 1) {
                                temp2Array[temp] = array[j3][1];
                                temp++;
                            }
                            if(array[j4][2] <= 1) {
                                temp2Array[temp] = array[j4][1];
                                temp++;
                            }

                            // Anteil 2
                            if(temp==2) {
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 3) temp1 = 2;

                                tempValue = (40000 + temp1*2000 + array[j1][1]);
                            }
                            // Anteil 1
                            else {

                                // 2.Stelle
                                if(temp2Array[0] > array[j1][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j2][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j3][1]) {
                                    temp1++;
                                }
                                if(temp2Array[0] > array[j4][1]) {
                                    temp1++;
                                }

                                if(temp1 >= 1) temp1 = 2;

                                // 3.Stelle
                                for(j5=0; j5<5; j5++) {
                                    if(j5 != j1 && j5 != j2 && j5 != j3 && j5 != j4) {
                                        if(array[j5][1] < array[j4][1]) {
                                            temp2 = 0;
                                        }
                                        else {
                                            temp2 = 1;
                                        }
                                    }
                                }

                                tempValue = (40000 + (temp1+1)*1000 + temp2*100 + array[j1][1]);
                            }
                            breakLoop = 1;
                        }
                        else {
                            // Test auf Straßenansatz-Ausnahme 5-4-3-2-A
                            if(array[j1][1] == 12 && ((array[j1][1]-9 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1]) || (array[j1][1]-9 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-2 == array[j4][1]) || (array[j1][1]-9 == array[j2][1] && array[j2][1]-2 == array[j3][1] && array[j3][1]-1 == array[j4][1]) || (array[j1][1]-10 == array[j2][1] && array[j2][1]-1 == array[j3][1] && array[j3][1]-1 == array[j4][1]))) {
                                //                              				cout << "Straight-Draw Ass unten";

                                // Anteil ermitteln
                                if(array[j1][2] <= 1) {
                                    temp2Array[temp] = array[j1][1];
                                    temp++;
                                }
                                if(array[j2][2] <= 1) {
                                    temp2Array[temp] = array[j2][1];
                                    temp++;
                                }
                                if(array[j3][2] <= 1) {
                                    temp2Array[temp] = array[j3][1];
                                    temp++;
                                }
                                if(array[j4][2] <= 1) {
                                    temp2Array[temp] = array[j4][1];
                                    temp++;
                                }

                                // Anteil 2
                                if(temp==2) {
                                    if(temp2Array[0] > array[j1][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j2][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j3][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j4][1]) {
                                        temp1++;
                                    }

                                    if(temp1 >= 3) temp1 = 2;

                                    tempValue = (40012 + temp1*2000);
                                }
                                // Anteil 1
                                else {

                                    // 2.Stelle
                                    if(temp2Array[0] > array[j1][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j2][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j3][1]) {
                                        temp1++;
                                    }
                                    if(temp2Array[0] > array[j4][1]) {
                                        temp1++;
                                    }

                                    if(temp1 >= 1) temp1 = 2;

                                    tempValue = (40004 + (temp1+1)*1000 + 100);
                                }

                                breakLoop = 1;
                            }
                        }
                    }
                }
            }
        }
    }


    // auf Drilling testen
    for(j1=0; j1<3; j1++) {
        if(array[j1][1] == array[j1+1][1] && array[j1][1] == array[j1+2][1]) {
            //              	cout << "Drilling";
            for(j2=0; j2<3; j2++) {
                if(array[j1+j2][2] <= 1) temp++;
            }
            if(temp >=1) {
                return 80000;
            } else {
                if(j1==0) {
                    return (30000 + array[j1+3][1]);
                } else {
                    return (30100 + array[0][1]);
                }
            }
        }
    }

    // auf Zwei Paare testen
    for(j1=0; j1<2; j1++) {
        for(j2=j1+2; j2<4; j2++) {
            if(array[j1][1] == array[j1+1][1] && array[j2][1] == array[j2+1][1]) {
                //              		cout << "Zwei Paare";
                // Anteil ermitteln
                for(j3=0; j3<2; j3++) {
                    if(array[j1+j3][2] <= 1) {
                        temp2Array[temp] = array[j1+j3][1];
                        temp++;
                    }
                }
                for(j3=0; j3<2; j3++) {
                    if(array[j2+j3][2] <= 1) {
                        temp2Array[temp] = array[j2+j3][1];
                        temp++;
                    }
                }

                // Anteil 2
                if(temp == 2) {
                    if(temp2Array[0] != temp2Array[1]) {
                        return (22200 + temp2Array[0]);
                    }
                    else {
                        if(temp2Array[0] == array[j1][1]) {
                            return (22100 + temp2Array[0]);
                        } else {
                            return (22000 + temp2Array[0]);
                        }
                    }

                }
                // Anteil 1
                else {
                    if(temp2Array[0] == array[j1][1]) {
                        return 21100 + array[j1][1];
                    } else {
                        return 21000 + array[j2][1];
                    }
                }
            }
        }
    }

    temp = 0;
    temp1 = 0;
    temp2 = 0;

    // auf Paar testen
    for(j1=0; j1<4; j1++) {
        if(array[j1][1] == array[j1+1][1]) {
            // 			cout << "Paar";
            // ohne Straight- und Flush-Draw
            if(!breakLoop) {
                // Anteil ermitteln
                for(j2=0; j2<2; j2++) {
                    if(array[j1+j2][2] <= 1) temp++;
                }
                // Anteil 2
                if(temp == 2) {
                    return (12000 + j1*100 + array[j1][1]);
                } else {
                    // Anteil 1
                    if(temp == 1) {
                        for(j2=0; j2<5; j2++) {
                            if(array[j2][2] >= 2 && array[j2][1] > array[j1][1]) temp1++;
                        }
                        return (11000 + temp1*100 + array[j1][1]);
                    }
                    // Anteil 0
                    else {
                        for(j2=0; j2<5; j2++) {
                            if(array[j2][2] <= 1 && array[j2][1] > temp1) temp1 = array[j2][1];
                        }
                        for(j2=0; j2<5; j2++) {
                            if(array[j2][2] >= 2 && array[j2][1] > temp1) temp2++;
                        }
                        if(temp2 == 2) temp2 = 1;
                        if(temp2 == 3) temp2 = 2;
                        return (10000 + temp2*100 + temp1);
                    }
                }
            }
            else {
                // STraight (==4)
                if(((int)(tempValue/10000)) == 4) {
                    return (((int)(tempValue/1000))*1000 + 200+ (tempValue - ((int)(tempValue/100))*100));
                }
                // Flush Anteil 1 (==5)
                else {
                    return (((int)(tempValue/10000))*10000 + 3000 + (tempValue - ((int)(tempValue/1000))*1000));
                }
            }
        }
    }

    // Highest Card (Klasse 0) + Kicker

    // ohne Straight- und Flush-Draw
    if(!breakLoop) {
        // 		cout << "Highest Card";
        // Anteil ermitteln
        for(j1=0; j1<5; j1++) {
            if(array[j1][2] <= 1) {
                temp2Array[temp] = array[j1][1];
                temp++;
            }
        }
        for(j1=0; j1<5; j1++) {
            if(temp2Array[1] > array[j1][1]) temp1++;
            if(temp2Array[0] > array[j1][1]) temp2++;
        }
        return (temp1*1000 + temp2*100 + array[0][1]);

    } else {
        return tempValue;
    }


}



void PokerAI::calcMyOdds()
{
	int handCode;

	switch(getCurrentRound()) {

	case 0: {

			handCode = myCardsValue.holeCardsToIntCode(myCards);

            // übergang solange preflopValue und flopValue noch nicht bereinigt
			int players = getPlayerCount();//currentHand->getActivePlayerList()->size();
			if(players > 5) players = 5;
            // paranoia
            if(players < 2) players = 2;

			for (unsigned val = 0; val < NUM_PREFLOP_VALUES; val++) {
                if(handCode == PreflopValues[val].hand) {
					myOdds = 100.0*PreflopValues[val].data[players - 2];
                    break;
                }
            }
		  //  if (myOdds == -1) LOG_ERROR(__FILE__ << " (" << __LINE__ << "): ERROR myOdds - " << handCode);

        }
        break;
    case 1: {

            int tempArray[5];
            int boardCards[5];

            int i;

            for(i=0; i<2; i++) tempArray[i] = myCards[i];
			getBoardCards(boardCards);
			for(i=0; i<3; i++) tempArray[2+i] = boardCards[i];

            // 		cout << myID << ": ";

			handCode = flopCardsValue(tempArray);

            // 		cout << "\t" << handCode << endl;

            // übergang solange preflopValue und flopValue noch nicht bereinigt
			int players =getPlayerCount(); //currentHand->getActivePlayerList()->size();
            if(players > 5) players = 5;
            // paranoia
            if(players < 2) players = 2;

            if(handCode != 80000) {
                for (unsigned val = 0; val < NUM_FLOP_VALUES; val++) {
                    if(handCode == FlopValues[val].hand) {
                        myOdds = 100.0*FlopValues[val].data[players - 2];
                        break;
                    }
                }
                if(myOdds == -1) {
					 int error=1;
					//ostringstream logger;
				   //	logger << "ERROR myOdds is -1: ";
				  //	for(i=0; i<5; i++) logger << tempArray[i] << " ";
				 //	LOG_ERROR(__FILE__ << " (" << __LINE__ << "): " << logger.str());
					// 					cout << "\t" << handCode << "\t" << myID << endl;
                } else {
                    // 			cout << myHoleCardsValue << endl;
                }
            } else {
                myOdds = 100;
            }

        }
        break;
    case 2: {

            // Prozent ausrechnen

            int i, j, k;
            int tempBoardCardsArray[5];
            int tempMyCardsArray[7];
            int tempOpponentCardsArray[7];
			getBoardCards(tempBoardCardsArray);

            tempMyCardsArray[0] = myCards[0];
            tempMyCardsArray[1] = myCards[1];
            tempMyCardsArray[2] = tempBoardCardsArray[0];
            tempMyCardsArray[3] = tempBoardCardsArray[1];
            tempMyCardsArray[4] = tempBoardCardsArray[2];
            tempMyCardsArray[5] = tempBoardCardsArray[3];

            tempOpponentCardsArray[2] = tempBoardCardsArray[0];
            tempOpponentCardsArray[3] = tempBoardCardsArray[1];
            tempOpponentCardsArray[4] = tempBoardCardsArray[2];
            tempOpponentCardsArray[5] = tempBoardCardsArray[3];

            int tempMyCardsValue;
            int tempOpponentCardsValue;

            int countAll = 0;
            int countMy = 0;

            for(i=0; i<49; i++) {
                if(i != myCards[0] && i != myCards[1] && i != tempBoardCardsArray[0] && i != tempBoardCardsArray[1] && i != tempBoardCardsArray[2]) {
                    for(j=i+1; j<50; j++) {
                        if(j != myCards[0] && j != myCards[1] && j != tempBoardCardsArray[0] && j != tempBoardCardsArray[1] && j != tempBoardCardsArray[2]) {
                            for(k=j+1; k<51; k++) {
                                if(k != myCards[0] && k != myCards[1] && k != tempBoardCardsArray[0] && k != tempBoardCardsArray[1] && k != tempBoardCardsArray[2]) {

                                    countAll++;

                                    tempOpponentCardsArray[0] = i;
                                    tempOpponentCardsArray[1] = j;
                                    tempOpponentCardsArray[6] = k;
                                    tempMyCardsArray[6] = k;
									tempMyCardsValue = myCardsValue.cardsValue(tempMyCardsArray,0);
									tempOpponentCardsValue = myCardsValue.cardsValue(tempOpponentCardsArray,0);

                                    if(tempMyCardsValue>=tempOpponentCardsValue) countMy++;
                                }
                            }
                        }
                    }
                }
            }

            myOdds = 100.0*(countMy*1.0)/(countAll*1.0);

        }
        break;
    case 3: {

            // Prozent ausrechnen

            int i, j;
            int tempBoardCardsArray[5];
            int tempMyCardsArray[7];
			int tempOpponentCardsArray[7];
			getBoardCards(tempBoardCardsArray);

            tempMyCardsArray[0] = myCards[0];
            tempMyCardsArray[1] = myCards[1];
            tempMyCardsArray[2] = tempBoardCardsArray[0];
            tempMyCardsArray[3] = tempBoardCardsArray[1];
            tempMyCardsArray[4] = tempBoardCardsArray[2];
            tempMyCardsArray[5] = tempBoardCardsArray[3];
            tempMyCardsArray[6] = tempBoardCardsArray[4];

            tempOpponentCardsArray[2] = tempBoardCardsArray[0];
            tempOpponentCardsArray[3] = tempBoardCardsArray[1];
            tempOpponentCardsArray[4] = tempBoardCardsArray[2];
            tempOpponentCardsArray[5] = tempBoardCardsArray[3];
            tempOpponentCardsArray[6] = tempBoardCardsArray[4];

            int tempMyCardsValue;
            int tempOpponentCardsValue;

			int countAll = 0;
			int countMy = 0;

            for(i=0; i<49; i++) {
                if(i != myCards[0] && i != myCards[1] && i != tempBoardCardsArray[0] && i != tempBoardCardsArray[1] && i != tempBoardCardsArray[2]) {
                    for(j=i+1; j<50; j++) {
                        if(j != myCards[0] && j != myCards[1] && j != tempBoardCardsArray[0] && j != tempBoardCardsArray[1] && j != tempBoardCardsArray[2]) {

                            countAll++;

                            tempOpponentCardsArray[0] = i;
                            tempOpponentCardsArray[1] = j;
							tempMyCardsValue = myCardsValue.cardsValue(tempMyCardsArray,0);
							tempOpponentCardsValue = myCardsValue.cardsValue(tempOpponentCardsArray,0);

							if(tempMyCardsValue>=tempOpponentCardsValue) countMy++;
                        }
                    }
                }
            }

            myOdds = 100.0*(countMy*1.0)/(countAll*1.0);

        }
        break;
	default: break;//LOG_ERROR(__FILE__ << " (" << __LINE__ << "): ERROR - wrong init of currentRound");


    }





}


void PokerAI::evaluation(int bet, int raise) {


    int highestSet = 0;

	highestSet = getHighestSet();




	switch(getmyAction())
	{
	case PLAYER_ACTION_NONE:    break;
	case PLAYER_ACTION_FOLD:

	if(highestSet<=smallBlind)
	{

	            mySet += smallBlind;
				myCash = myCash-mySet;
				myAction = PLAYER_ACTION_CALL;
				raisetutar= highestSet;
	}
	else
	{
	   myAction = PLAYER_ACTION_FOLD;
	}

	break;

	break;
	case PLAYER_ACTION_CHECK:
	if(highestSet<=smallBlind*2)
	{
	   mySet += highestSet;
				myCash = myCash-mySet;
				myAction = PLAYER_ACTION_CALL;
				raisetutar= highestSet;
	}
	else
	{
	   myAction = PLAYER_ACTION_FOLD;
	}

	break;
	case PLAYER_ACTION_CALL:
			  mySet += highestSet;
				myCash = myCash-mySet;
				myAction = PLAYER_ACTION_CALL;
				raisetutar= highestSet;

	 break;
	case PLAYER_ACTION_BET:
				mySet += bet;
				myCash = myCash-mySet;
				myAction = PLAYER_ACTION_RAISE;
				raisetutar=bet;
	break;
	case PLAYER_ACTION_RAISE:
				 mySet += raise;
				myCash = myCash-mySet;
				myAction = PLAYER_ACTION_RAISE;
				raisetutar= raise;
	break;
	case PLAYER_ACTION_ALLIN:     break;
	}

	return;



    // 	cout << "myAction(evaluation): " << myAction << endl;
	switch(myAction) {
        // none
    case 0: {}
        break;
        // fold
    case 1: {}
        break;
        // check
    case 2: {}
        break;
        // call
    case 3: {
            // 			cout << "evaluation(call) - highestSet = " << highestSet << endl;
            // all in
            if(highestSet >= myCash + mySet) {
                mySet += myCash;
                myCash = 0;
                myAction = 6;
                // 				cout << "evaluation(call) - mySet: " << mySet << endl;
            }
            // sonst
            else {
                myCash = myCash - highestSet + mySet;
                mySet = highestSet;
            }
        }
        break;
        // bet
    case 4: {
            // all in
            if(bet >= myCash) {
				// -> full bet rule
			            /*
                	if(myCash < 2*getSmallBlind()) {
                					currentHand->getCurrentBeRo()->setFullBetRule(true);
                				}
								currentHand->getCurrentBeRo()->setMinimumRaise(myCash);
            */
                mySet = myCash;
                myCash = 0;
                myAction = 6;
                highestSet = mySet;
			}
            // sonst
            else {
			  //  currentHand->getCurrentBeRo()->setMinimumRaise(bet);
                myCash = myCash - bet;
                mySet = bet;
                highestSet = mySet;

            }
            // lastPlayerAction für Karten umblättern reihenfolge setzrn
		  //  currentHand->setLastActionPlayer(myUniqueID);
        }
        break;
        // raise
	case 5: {
		if(highestSet >= myCash + mySet) {
                    mySet += myCash;
					myCash = 0;
                    myAction = 6;
				}
                // sonst
				else {
                    myCash = myCash - highestSet + mySet;
					mySet = highestSet;
					myAction = 3;
				}
                // all in
                if(highestSet + raise >= myCash + mySet) {
					if(highestSet + getMinimumRaise() > myCash + mySet) {
						// perhaps full bet rule
                        if(highestSet >= myCash + mySet) {
                            // only call all-in
                            mySet += myCash;
                            myCash = 0;
                            myAction = 6;
                        } else {
                            // raise, but not enough --> full bet rule
						//	currentHand->getCurrentBeRo()->setFullBetRule(true);
							// lastPlayerAction für Karten umblättern reihenfolge setzrn
						//	currentHand->setLastActionPlayer(myUniqueID);

                            mySet += myCash;
						 //	currentHand->getCurrentBeRo()->setMinimumRaise(mySet-highestSet);
                            myCash = 0;
                            myAction = 6;
                            highestSet = mySet;
						}
					} else {
                        // lastPlayerAction für Karten umblättern reihenfolge setzrn
					 //   currentHand->setLastActionPlayer(myUniqueID);

                        mySet += myCash;
					  //  currentHand->getCurrentBeRo()->setMinimumRaise(mySet-highestSet);
                        myCash = 0;
                        myAction = 6;
                        highestSet = mySet;
                    }
                }
                // sonst
                else {
				   // currentHand->getCurrentBeRo()->setMinimumRaise(raise);
					myCash = myCash + mySet - highestSet - raise;
					mySet = highestSet + raise;
					highestSet = mySet;
					// lastPlayerAction für Karten umblättern reihenfolge setzrn
				  //  currentHand->setLastActionPlayer(myUniqueID);
                }
			//}
        }
		break;
		// all in
	case 6: {}
		break;
    default: {}
	}

	// 	cout << "highestSet(ende evaluation): " << highestSet << endl;

  //  currentHand->getCurrentBeRo()->setHighestSet(highestSet);

//    cout << "lAP: " << currentHand->getLastActionPlayer() << endl;

}

 void PokerAI::preflopEngine() {

    int bet = 0;
    int raise = 0;
    int cBluff;


    // temporär solange preflopValue und flopValue noch nicht bereinigt für sechs und sieben spieler
	int players = getPlayerCount();//currentHand->getActivePlayerList()->size();
	if(players > 5) players = 5;

    // myOdds auslesen
    calcMyOdds();

    // Niveaus setzen + Dude + Anzahl Gegenspieler
    // 1. Fold -- Call
    myNiveau[0] = 43 + myDude4 - 6*(players - 2);
    // 3. Call -- Raise
    myNiveau[2] = 54 + myDude4 - 7*(players - 2);

    // eigenes mögliches highestSet
	int individualHighestSet = getHighestSet();
	if(individualHighestSet > myCash) individualHighestSet = myCash;

    // Verhaeltnis Set / Cash für call
	if(myCash/individualHighestSet >= 25) {
        myNiveau[0] += (25-myCash/individualHighestSet)/10;
    } else {
        myNiveau[0] += (25-myCash/individualHighestSet)/3;
    }

    // Verhaeltnis Set / Cash für raise
    if(myCash/individualHighestSet < 11) {
        myNiveau[2] += (21-myCash/individualHighestSet)/2;
    }

    //	cout << myID << ": " << myHoleCardsValue << " - " << myNiveau[0] << " " << myNiveau[2] << " - " << myCards[0] << " " << myCards[1] << endl;

    // count number of active human players

	myNiveau[0] -= 3;
	myNiveau[2] -= 3;




    // Aggresivität des humanPlayers auslesen -> nur wenn er aktiv ist !
    // 	it_c = currentHand->getActivePlayerIt(0);
    // 	if( it_c != currentHand->getActivePlayerList()->end() ) {
    // 		if( (*it_c)->getMyAction() != PLAYER_ACTION_FOLD ) {
    // 			int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
    // 			myNiveau[0] -= aggValue;
    // 			myNiveau[2] -= aggValue;
    // 		}
    //
    // 	}


    //	cout << "Spieler " << myID << ": Dude " << myDude4 << "\t Wert " <<  myHoleCardsValue << "\t Niveau " << myNiveau[0] << " " << myNiveau[1] << " " << myNiveau[2] << "\t Agg " << aggValue << " " << endl;

    // Check-Bluff generieren
getRandNumber(1,100,1,&cBluff,0,0,0);

    // aktive oder passivie Situation ? -> im preflop nur passiv

    // raise (bei hohem Niveau)
    if(myOdds >= myNiveau[2]) {

        // raise-loop unterbinden -> d.h. entweder call oder bei superblatt all in
		if(getHighestSet() >= 12*getSmallBlind()) {
			// all in
            if(myOdds >= myNiveau[2] + 8) {
                raise = myCash;
                myAction = 5;
            }
            // nur call
            else {
				// all in bei knappem call
				if(getHighestSet() <= (myCash*1)/5) {
                    raise = myCash;
                    myAction = 5;
                } else {
                    myAction = 3;
                }
            }

            // Standard-Raise-Routine
        } else {
            // raise-Betrag ermitteln
			raise = (((int)myOdds-myNiveau[2])/2)*2*getSmallBlind();
            // raise-Betrag zu klein -> mindestens Standard-raise
            // 			if(raise < currentHand->getCurrentBeRo()->getHighestSet()) {
            // 				raise = currentHand->getCurrentBeRo()->getHighestSet();
            // 			}
            // all in bei nur wenigen Chips oder knappem raise
			if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4)/5) {
                raise = myCash;
            }
            myAction = 5;
        }

        // auf cBluff testen --> call (bzw check) statt raise
        if(cBluff > 90) {
            myAction = 3;
            // bigBlind --> check
			if(mySet == getHighestSet()) myAction = 2;
        }
        if(cBluff > 80 && myOdds >= myNiveau[2] + 4) {
            myAction = 3;
            // bigBlind --> check
			if(mySet == getHighestSet()) myAction = 2;
        }
        if(cBluff > 70 && myOdds >= myNiveau[2] + 8) {
            myAction = 3;
			// bigBlind --> check
			if( mySet == getHighestSet()) myAction = 2;
        }
		if(cBluff > 60 && myOdds >= myNiveau[2] + 12) {
            myAction = 3;
            // bigBlind --> check
			if( mySet == getHighestSet()) myAction = 2;
        }

    }
    else {
        // call
		if(myOdds >= myNiveau[0] || (mySet >= getHighestSet()/2 && myOdds >= myNiveau[0]-8)) {
			// bigBlind --> check
			if( mySet == getHighestSet()) myAction = 2;
            else {
                // all in bei knappem call
				if(myCash-getHighestSet() <= (myCash*1)/5) {
                    raise = myCash;
                    myAction = 5;
                }
                else {
                    myAction = 3;
                }
            }
        }
        // fold
        else {
            // bigBlind -> check
			if( mySet == getHighestSet()) myAction = 2;
			else myAction = 1;
        }
    }

    // 	cout << sBluff << endl;

	// auf sBluff testen --> raise statt call oder fold
	if((sBluff < 100/((((int)getPlayerCount()-2)*6)+3) && myOdds < myNiveau[2] && getHighestSet() == 2*getSmallBlind() && sBluffStatus == 0) || sBluffStatus == 1) {

        // 		cout << "sBLUFF!" << endl;
        sBluffStatus = 1;

        // Gegner raisen ebenfalls -> call
		if(getHighestSet() >= 4*getSmallBlind()) {
            // all in bei knappem call
            if(myCash-getHighestSet() <= (myCash*1)/6) {
                raise = myCash;
                myAction = 5;
            }
            else {
                myAction = 3;
                // bigBlind --> check
				if( mySet == getHighestSet()) myAction = 2;
            }
        }
        // Standard-Raise-Routine
        else {
			// raise-Betrag ermitteln
			raise = (sBluff/(8-min(7,(int)(getPlayerCount()))))*getSmallBlind();
			// raise-Betrag zu klein -> mindestens Standard-raise
            // 			if(raise < getHighestSet()) {
            // 				raise = getHighestSet();
            // 			}
            // all in bei nur wenigen Chips oder knappem raise
			if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4)/5) {
                raise = myCash;
            }
            myAction = 5;
        }

        // extrem hoher set der gegner -> bluff beenden
		if((getHighestSet() >= 12*getSmallBlind() && myOdds < myNiveau[0]) || (getHighestSet() >= 20*getSmallBlind() && myOdds < myNiveau[2])) {
            myAction = 1;
        }


    }

    // minimum raise setting and resetting
    //        if(myAction == 5) {
    //
    //                if(raise < currentHand->getCurrentBeRo()->getMinimumRaise()) {
    //                        raise = currentHand->getCurrentBeRo()->getMinimumRaise();
    //                }
    //                currentHand->getCurrentBeRo()->setMinimumRaise(raise);
    //        }
    //

    // 	cout << myID << ": " << myOdds << " - " << myNiveau[0] << " " << myNiveau[2] << " - " << "Bluff: " << sBluffStatus << endl;

	    /*
        if(DEBUG_MODE) {
        		switch(myUniqueID) {
                case 0: {}
        			break;
        		case 1: {
                        // player 1
        
        				switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_CALL;
                                //                                                raise = 20;
        					}
                            break;
        				case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 25;
        					}
        					break;
                        default: {
                            }
        				}
        
        			}
                    break;
        		case 2: {
                        // player 2
        
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_CALL;
        //                                                                        raise = 20000;
                                // 						if(mySet >= 40) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_FOLD;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				default: {
                            }
        				}
        
        			}
                    break;
        		case 3: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_CALL;
        //                                                                        raise = 2000;
                                // 						if(mySet >= 40) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_FOLD;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				default: {
                            }
        				}
                    }
        			break;
                case 4: {
        				switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_CALL;
        //                                                                        raise = 2000;
        						// 						if(mySet > 0) {
                                // 							myAction = PLAYER_ACTION_FOLD;
        						// 						}
                            }
        					break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_FOLD;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
        					break;
                        default: {
        					}
                        }
        			}
                    break;
        		case 5: {
                        // 				if(mySet == 0) {
        				myAction = PLAYER_ACTION_CALL;
        //                raise = 20;
        				// 				}
                    }
        			break;
                case 6: {
        				// 				if(mySet == 160) {
                        myAction = PLAYER_ACTION_CHECK;
        				// 				}
                    }
        			break;
                case 7: {
        				// 				if(mySet == 160) {
                        myAction = PLAYER_ACTION_CALL;
        
                        // 				}
        			}
                    break;
        		case 8: {
                        // 				if(mySet == 160) {
        				myAction = PLAYER_ACTION_CALL;
        
        				// 				}
                    }
        			break;
                case 9: {
        				// 				if(mySet == 160) {
                        myAction = PLAYER_ACTION_CALL;
        
                        // 				}
        			}
                    break;
        		default: {}
                }
        

			}
    */


	evaluation(bet, raise);
}



void PokerAI::flopEngine() {

	int raise = 0;
    int bet = 0;
	// 	int i;
    int cBluff;
	int pBluff;
    int rand;
//    PlayerListConstIterator it_c;

	// übergang solange preflopValue und flopValue noch nicht bereinigt
	int players = getPlayerCount();//currentHand->getActivePlayerList()->size();
	if(players > 5) players = 5;

	calcMyOdds();
	sBluffStatus=0;

	// Niveaus setzen + Dude + Anzahl Gegenspieler
    // 1. Fold -- Call
	myNiveau[0] = 53 + myDude4 - 6*(players - 2);
    // 2. Check -- Bet
    myNiveau[1] = 56 + myDude4 - 6*(players - 2);
    // 3. Call -- Raise
    myNiveau[2] = 69 + myDude4 - 7*(players - 2);

    // eigenes mögliches highestSet
	int individualHighestSet = getHighestSet();//getHighestSet();
	if(individualHighestSet > myCash) individualHighestSet = myCash;

	   /*
	// count number of active human players
	/size_t countHumanPlayers = 0;
    for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
        if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN) {
            countHumanPlayers++;
        }
    }
	if(countHumanPlayers) {
        // local or network game and only one human player is active --> set aggValue
        if(countHumanPlayers == 1) {

            for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
                if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN &&  (*it_c)->getMyAction() != PLAYER_ACTION_FOLD) {
                    int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
                    myNiveau[0] -= aggValue;
                    myNiveau[1] -= aggValue;
					myNiveau[2] -= aggValue;
                }
            }
            // network game
		} else {
			myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
        }
	} */

	 myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
    // Aggresivität des humanPlayers auslesen -> nur wenn er aktiv ist !
    // 	it_c = currentHand->getActivePlayerIt(0);
    // 	if( it_c != currentHand->getActivePlayerList()->end() ) {
    // 		if( (*it_c)->getMyAction() != PLAYER_ACTION_FOLD ) {
    // 			int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
    // 			for(i=0; i<3; i++) {
    // 				myNiveau[i] -= aggValue;
    // 			}
    // 		}
    //
    // 	}


	// Check-Bluff generieren
	getRandNumber(1,100,1,&cBluff,0,0,0);

    // aktiv oder passiv?
	if(getHighestSet() > 0) {

        // Verhaeltnis Set / Cash für call
        if(myCash/individualHighestSet >= 25) {
			myNiveau[0] += (25-myCash/individualHighestSet)/20;
        } else {
            myNiveau[0] += (25-myCash/individualHighestSet)/2;
        }

        // Verhaeltnis Set / Cash für raise
        if(myCash/individualHighestSet < 11) {
            myNiveau[2] += (21-myCash/individualHighestSet)/2;
		}

        // raise (bei hohem Niveau)
        if(myOdds >= myNiveau[2]) {

            // raise-loop unterbinden -> d.h. entweder call oder bei superblatt all in
			if(getHighestSet() >= 12*getSmallBlind()) {
                // all in
                if(myOdds >= myNiveau[2] + 15) {
                    raise = myCash;
					myAction = 5;
                }
                // nur call
				else {
                    // all in bei knappem call
					if(myCash-getHighestSet() <= (myCash*1)/5) {
						raise = myCash;
						myAction = 5;
                    } else {
                        myAction = 3;
                    }
                }

                // Standard-Raise-Routine
            } else {
                // raise-Betrag ermitteln
				raise = (((int)myOdds-myNiveau[2])/5)*2*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
				// 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips oder knappem raise
				if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4.0)/5.0) {
                    raise = myCash;
                }
                myAction = 5;
            }

            // auf cBluff testen --> call statt raise
            if(cBluff > 90) myAction = 3;
            if(cBluff > 80 && myOdds >= myNiveau[2] + 4) myAction = 3;
            if(cBluff > 70 && myOdds >= myNiveau[2] + 8) myAction = 3;
            if(cBluff > 60 && myOdds >= myNiveau[2] + 12) myAction = 3;

        }
        else {
            // call -> über niveau0, schon einiges gesetzt im flop, schon einiges insgesamt gesetzt
			if(myOdds >= myNiveau[0] || (mySet >getHighestSet()/2 && myOdds >= myNiveau[0]-5) || (myRoundStartCash-myCash > individualHighestSet && myNiveau[0]-3)) {
                // all in bei knappem call
				if(getHighestSet() > (myCash*3.0)/4.0) {
                    raise = myCash;
                    myAction = 5;
                }
				else myAction = 3;
            }
            // fold
            else {
				myAction = 1;
            }
        }
    }
    else {
        // bet
        if(myOdds >= myNiveau[1]) {
			bet = (((int)myOdds-myNiveau[1])/8)*2*getSmallBlind();
			// bet zu klein
            if(bet == 0) {
				bet = 2*getSmallBlind();
            }
			// all in bei nur wenigen Chips
			if(myCash/(2*getSmallBlind()) <= 6) {
                bet = myCash;
            }
            // all in bei knappem bet
			if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;

            // auf cBluff testen --> check statt bet
            if(cBluff > 80) myAction = 2;
            if(cBluff > 70 && myOdds >= myNiveau[1] + 4) myAction = 2;
            if(cBluff > 60 && myOdds >= myNiveau[1] + 8) myAction = 2;
            if(cBluff > 50 && myOdds >= myNiveau[1] + 12) myAction = 2;
		}
        // check
        else {
            myAction = 2;
            // Position
		 /*	if(myButton == 1) {
                // Position-Bluff generieren
			   getRandNumber(1,100,1,&pBluff,0,0,0);
                if(pBluff <= 16) {
					bet = (pBluff/4)*2*getSmallBlind();
					// bet zu klein
					if(bet == 0) {
						bet = 2*getSmallBlind();
                    }
                    // all in bei nur wenigen Chips
					if(myCash/(2*getSmallBlind()) <= 6) {
                        bet = myCash;
                    }
                    // all in bei knappem bet
                    if(bet > (myCash*4.0)/5.0) {
                        bet = myCash;
					}
                    myAction = 4;
				}
			} */
        }

    }

	// auf sBluffStatus testen --> raise statt call und bet statt check

    // aktiv oder passiv?
	if(getHighestSet() > 0) {

		if(sBluffStatus && myOdds < myNiveau[2]) {

            // 		cout << "sBLUFF!" << endl;

			// Gegner setzen -> call
			if(getHighestSet() >= 4*getSmallBlind()) {
                myAction = 3;
            }
            // Standard-Raise-Routine
            else {
                // raise-Betrag ermitteln
			  getRandNumber(1,8,1,&rand,0,0,0);
				raise = rand*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
                // 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips oder knappem raise
				if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4)/5) {
					raise = myCash;
                }
                myAction = 5;
			}

			// extrem hoher set der gegner -> bluff beenden
			if(getHighestSet() >= 10*getSmallBlind()) {
                myAction = 1;
            }
        }
    }
    else {
		if(sBluffStatus && myOdds < myNiveau[1]) {

            // 		cout << "sBLUFF!" << endl;

		   getRandNumber(1,8,1,&rand,0,0,0);
			bet = rand*getSmallBlind();
            // bet zu klein
			if(bet < 2*getSmallBlind()) {
				bet = 2*getSmallBlind();
			}
			// all in bei nur wenigen Chips
			if(myCash/(2*getSmallBlind()) <= 6) {
                bet = myCash;
            }
            // all in bei knappem bet
            if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;
        }

    }


	    /*
        if(DEBUG_MODE) {
                switch(myUniqueID) {
                case 0: {
        			} break;
                case 1: {
        
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_CHECK;
                                //                                                bet = 20;
                                //                                                if(getHighestSet() > 0) {
                                //                                                        myAction = PLAYER_ACTION_CALL;
                                //                                                }
        					} break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_BET;
        						// 						raise = 25;
                            } break;
                        default: {
                            }
                        }
        			} break;
                case 2: {
        
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_CHECK;
                                //                                                bet = 20;
        						// 						raise = 20;
                                //                                                if(mySet > 20) {
        						//                                                        myAction = PLAYER_ACTION_CALL;
                                //                                                }
        						// 						if(getHighestSet() > 0) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        default: {
                            }
        				}
        
                    }
                    break;
        		case 3: {
                        switch(currentHand->getMyID()) {
                        case 1: {
                                myAction = PLAYER_ACTION_CHECK;
        						//                                                raise = 400;
                                // 						if(getHighestSet() > 0) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        default: {
                            }
        				}
        
        
                    }
        			break;
                case 4: {
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_CHECK;
                                //                                                raise = 140;
        //                        if(getHighestSet() > 0) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                        }
                            }
                            break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
                            break;
                        default: {
        					}
                        }
        
        
        			}
                    break;
                case 5: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_CHECK;
        //                        bet = 20;
                                // 						if(getHighestSet() > 0) {
        						// 							myAction = PLAYER_ACTION_FOLD;
                                // 						}
                            }
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
                            }
                            break;
        				default: {
                            }
                        }
        
        
                    }
                    break;
                case 6: {
        				switch(currentHand->getMyID()) {
                        case 1: {
                                myAction = PLAYER_ACTION_CHECK;
        //                        raise = 40;
        //                        if(getHighestSet() > 60) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                        }
                            }
        					break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
                            }
        					break;
                        default: {
                            }
                        }
        
        
                    }
                    break;
        		case 7: {
                        myAction = PLAYER_ACTION_CHECK;
                    }
                    break;
        		case 8: {
                        myAction = PLAYER_ACTION_CHECK;
                    }
        			break;
                case 9: {
                        myAction = PLAYER_ACTION_CHECK;
        			}
                    break;
                default: {}
        		}
        

			}
    */

	// minimum raise setting and resetting
	//        if(myAction == 5) {
    //
	//                if(raise < currentHand->getCurrentBeRo()->getMinimumRaise()) {
	//                        raise = currentHand->getCurrentBeRo()->getMinimumRaise();
	//                }
	//                currentHand->getCurrentBeRo()->setMinimumRaise(raise);
	//
	//        }
	//
	//        if(myAction == 4) { currentHand->getCurrentBeRo()->setMinimumRaise(bet); }

	evaluation(bet, raise);




    // 		cout << "Engine 0.4" << endl;
	// 		int tempArray[5];
    // 		int boardCards[5];
    // 		int info[4];
    // 		int cBluff;
    // 		int sBluff;
    // 		int bet = 0;
    // 		int raise = 0;
    //
    // 		int i;
    //
    //
    // 		for(i=0; i<2; i++) tempArray[i] = myCards[i];
    // 		currentBoard->getMyCards(boardCards);
    // 		for(i=0; i<3; i++) tempArray[2+i] = boardCards[i];
    //
    // 		for(i=0; i<4; i++) info[i] = -1;
    //
    // // 		for(i=0; i<5; i++) cout << tempArray[i] << " ";
    // // 		cout << endl;
    //
    // 		cout << myID << ": ";
    //
    // 		flopCardsValue(tempArray);
    //
    // 		// aktive Situation --> check / bet
	// 		if(getHighestSet() == 0) {
    //
    // 			switch(info[0]) {
    // 				case 9: {}
    // 				case 8: {}
    // 				case 7: {}
    // 				case 6: {}
    // 				case 5: {}
    // 				case 4: {
    // 					Tools::getRandNumber(0,100,1,&cBluff,0);
    // 					if(cBluff < 35) {
    // 						myAction = 2;
    // 					}
    // 					else {
    // 						if(myCash/(2*getSmallBlind()) <= 8) {
    // 							myAction = 6;
    // 						} else {
    // 							if(cBluff < 60) {
    // 								bet = (7-myDude4)*2*getSmallBlind();
    // 							} else {
    // 								bet = (((100-cBluff)/20)+2)*getSmallBlind();
    // 							}
    // 							if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 							myAction = 4;
    // 						}
    // 					}
    // 				}
    // 				break;
    // 				case 3: {
    // 					switch(info[3]) {
    // 						case 2: {
    // 							Tools::getRandNumber(0,100,1,&cBluff,0);
    // 							if(cBluff < 35) {
    // 								myAction = 2;
    // 							}
    // 							else {
    // 								if(myCash/(2*getSmallBlind()) <= 8) {
    // 									myAction = 6;
    // 								} else {
    // 									if(cBluff < 60) {
    // 										bet = (5-myDude4)*2*getSmallBlind();
    // 									} else {
    // 										bet = (((100-cBluff)/20)+2)*getSmallBlind();
    // 									}
    // 									if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 									myAction = 4;
    // 								}
    // 							}
    // 						}
    // 						break;
    // 						case 1: {
    // 							Tools::getRandNumber(0,100,1,&cBluff,0);
    // 							if(cBluff < 40) {
    // 								myAction = 2;
    // 							}
    // 							else {
    // 								if(myCash/(2*getSmallBlind()) <= 6) {
    // 									myAction = 6;
    // 								} else {
    // 									if(cBluff < 60) {
    // 										bet = (3-myDude4)*2*getSmallBlind();
    // 									} else {
    // 										bet = (((100-cBluff)/20)+2)*getSmallBlind();
    // 									}
    // 									if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 									myAction = 4;
    // 								}
    // 							}
    // 						}
    // 						break;
    // 						default: {
    // 							Tools::getRandNumber(0,100,1,&sBluff,0);
    // 							if(info[1] >= 10 && sBluff <= 40) {
    // 								bet = (sBluff/10)*2*getSmallBlind();
    // 								if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 								myAction = 4;
    // 							}
    // 							else {
    // 								myAction = 2;
    // 							}
    // 						}
    // 					}
    // 				}
    // 				break;
    // 				case 2: {
    // 					switch(info[3]) {
    // 						case 2: {
    // 							Tools::getRandNumber(0,100,1,&cBluff,0);
    // 							if(cBluff > 80) {
    // 								myAction = 2;
    // 							}
    // 							else {
    // 								if(myCash/(2*getSmallBlind()) <= 6) {
    // 									myAction = 6;
    // 								} else {
    // 									bet = (cBluff/20)*2*getSmallBlind();
    // 									if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 									myAction = 4;
    // 								}
    // 							}
    // 						}
    // 						break;
    // 						default: {
    // 							Tools::getRandNumber(0,100,1,&cBluff,0);
    // 							if(cBluff > 90) {
    // 								myAction = 2;
    // 							}
    // 							else {
    // 								if(myCash/(2*getSmallBlind()) <= 5) {
    // 									myAction = 6;
    // 								} else {
    // 									bet = (cBluff/30)*2*getSmallBlind();
    // 									if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 									myAction = 4;
    // 								}
    // 							}
    // 						}
    // 					}
    // 				}
    // 				break;
    // 				case 1: {
    // 					if(!info[2]) {
    // 					Tools::getRandNumber(0,100,1,&sBluff,0);
    // 					switch(info[3]) {
    // 						case 2: {}
    // 						case 1: {
    // 							if(currentHand->getActivePlayerList().size() == 2) {
    // 								bet = (1-myDude4)*2*getSmallBlind();
    // 								if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 								myAction = 4;
    //
    // 							}
    // 							else {
    // 								switch(info[1]) {
    // 									case 3: {
    // 										if(sBluff <= 10) {
    // 											bet = (sBluff/5 + 2)*getSmallBlind();
    // 											myAction = 4;
    // 										}
    // 										else {
    // 											myAction = 2;
    // 										}
    // 									}
    // 									break;
    // 									case 2: {
    // 										if(sBluff <= 15) {
    // 											bet = (sBluff/5 + 2)*getSmallBlind();
    // 											myAction = 4;
    // 										}
    // 										else {
    // 											myAction = 2;
    // 										}
    // 									}
    // 									break;
    // 									case 1: {
    // 										if(sBluff <= 50) {
    // 											bet = (sBluff/15 + 2)*getSmallBlind();
    // 											myAction = 4;
    // 										}
    // 										else {
    // 											myAction = 2;
    // 										}
    // 									}
    // 									break;
    // 									default: {
    // 										if(myCash/(2*getSmallBlind()) <= 5) {
    // 											myAction = 6;
    // 										} else {
    // 											bet = (sBluff/15)*2*getSmallBlind();
    // 											if(bet < 2*getSmallBlind()) bet = 2*getSmallBlind();
    // 											myAction = 4;
    // 										}
    // 									}
    // 									break;
    // 								}
    // 							}
    // 						}
    // 						break;
    // 						default: {
    // 						}
    // 					}
    // 					}
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // 				}
    // 				break;
    // 				default: {}
    // 			}
    //
    //
    //
    // 		}
    // 		// passive Situation --> fold / call / raise
    // 		else {
    //
    //
    //
    // 		}


}

void PokerAI::turnEngine() {

    // 		int tempArray[6];
    // 		int boardCards[5];
    // 		int i;

    // 		for(i=0; i<2; i++) tempArray[i] = myCards[i];
    // 		currentBoard->getMyCards(boardCards);
    // 		for(i=0; i<4; i++) tempArray[2+i] = boardCards[i];

    // 		for(i=0; i<5; i++) cout << tempArray[i] << " ";
    // 		cout << endl;

    // 		cout << myID << ": ";

    // 		turnCardsValue(tempArray);

    int raise = 0;
    int bet = 0;
    // 	int i;
    int cBluff;
    int pBluff;
    int rand;


    calcMyOdds();

    // Niveaus setzen + Dude + Anzahl Gegenspieler
    // 1. Fold -- Call
    myNiveau[0] = 53 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;
    // 2. Check -- Bet
    myNiveau[1] = 56 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;
    // 3. Call -- Raise
    myNiveau[2] = 69 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;

    // count number of active human players
   /* size_t countHumanPlayers = 0;
    for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
        if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN) {
            countHumanPlayers++;
        }
    }
    if(countHumanPlayers) {
        // local or network game and only one human player is active --> set aggValue
        if(countHumanPlayers == 1) {

            for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
                if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN &&  (*it_c)->getMyAction() != PLAYER_ACTION_FOLD) {
                    int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
                    myNiveau[0] -= aggValue;
                    myNiveau[1] -= aggValue;
                    myNiveau[2] -= aggValue;
                }
            }
            // network game
        } else {
			myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
        }
	} */

     myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
    // Aggresivität des humanPlayers auslesen -> nur wenn er aktiv ist !
    // 	it_c = currentHand->getActivePlayerIt(0);
    // 	if( it_c != currentHand->getActivePlayerList()->end() ) {
    // 		if( (*it_c)->getMyAction() != PLAYER_ACTION_FOLD ) {
    // 			int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
    // 			for(i=0; i<3; i++) {
    // 				myNiveau[i] -= aggValue;
    // 			}
    // 		}
    //
    // 	}



    //	cout << "Spieler " << myID << ": Dude " << myDude4 << "\t Wert " <<  myHoleCardsValue << "\t Niveau " << myNiveau[0] << " " << myNiveau[1] << " " << myNiveau[2] << "\t Agg " << aggValue << " " << endl;


    // eigenes mögliches highestSet
	int individualHighestSet = getHighestSet();
    if(individualHighestSet > myCash) individualHighestSet = myCash;

    // Check-Bluff generieren
   getRandNumber(1,100,1,&cBluff,0,0,0);

    // aktiv oder passiv?
    if(getHighestSet() > 0) {

        //		Verhaeltnis Set / Cash
        if(myCash/individualHighestSet >= 25) {
            myNiveau[0] += (25-myCash/individualHighestSet)/10;
        } else {
            myNiveau[0] += (25-myCash/individualHighestSet)/2;
        }

        // Verhaeltnis Set / Cash für raise
        if(myCash/individualHighestSet < 11) {
            myNiveau[2] += (21-myCash/individualHighestSet)/2;
        }

        // raise (bei hohem Niveau)
        if(myOdds >= myNiveau[2]) {

            // raise-loop unterbinden -> d.h. entweder call oder bei superblatt all in
			if(getHighestSet() >= 12*getSmallBlind()) {
                // all in
                if(myOdds >= myNiveau[2] + 15) {
                    raise = myCash;
                    myAction = 5;
                }
                // nur call
                else {
                    // all in bei knappem call
                    if(myCash-getHighestSet() <= (myCash*1)/5) {
                        raise = myCash;
                        myAction = 5;
                    } else {
                        myAction = 3;
                    }
                }

                // Standard-Raise-Routine
            } else {
                // raise-Betrag ermitteln
                raise = (((int)myOdds-myNiveau[2])/4)*2*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
                // 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips oder knappem raise
                if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4.0)/5.0) {
                    raise = myCash;
                }
                myAction = 5;
            }
            // auf cBluff testen --> call statt raise
            if(cBluff > 90) myAction = 3;
            if(cBluff > 80 && myOdds >= myNiveau[2] + 5) myAction = 3;
            if(cBluff > 70 && myOdds >= myNiveau[2] + 10) myAction = 3;
            if(cBluff > 60 && myOdds >= myNiveau[2] + 15) myAction = 3;
        }
        else {
            // call -> über niveau0, schon einiges gesetzt im flop, schon einiges insgesamt gesetzt
            if(myOdds >= myNiveau[0] || (mySet >= getHighestSet()/2 && myOdds >= myNiveau[0]-5) || (myRoundStartCash-myCash > individualHighestSet && myNiveau[0]-3)) {
                // all in bei knappem call
                if(getHighestSet() > (myCash*3.0)/4.0) {
                    raise = myCash;
                    myAction = 5;
                }
                else myAction = 3;
            }
            // fold
            else {
                myAction = 1;
            }
        }
    }
    // aktiv
    else {
        // bet
        if(myOdds >= myNiveau[1]) {
            bet = (((int)myOdds-myNiveau[1])/6)*2*getSmallBlind();
            if(bet == 0) {
                bet = 2*getSmallBlind();
            }
            // all in bei nur wenigen Chips
            if(myCash/(2*getSmallBlind()) <= 6) {
                bet = myCash;
            }
            // all in bei knappem bet
            if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;

            // auf cBluff testen --> call statt raise
            if(cBluff > 90) myAction = 2;
            if(cBluff > 80 && myOdds >= myNiveau[2] + 5) myAction = 2;
            if(cBluff > 70 && myOdds >= myNiveau[2] + 10) myAction = 2;
            if(cBluff > 60 && myOdds >= myNiveau[2] + 15) myAction = 2;
        }
        // check
        else {
            myAction = 2;
            // Position
		  /*	if(myButton == 1) {
                // Position-Bluff generieren
                Tools::getRandNumber(1,100,1,&pBluff,0);
                if(pBluff <= 16) {
                    bet = (pBluff/4)*2*getSmallBlind();
                    // bet zu klein
                    if(bet == 0) {
                        bet = 2*getSmallBlind();
                    }
                    // all in bei nur wenigen Chips
                    if(myCash/(2*getSmallBlind()) <= 6) {
                        bet = myCash;
                    }
                    // all in bei knappem bet
                    if(bet > (myCash*4.0)/5.0) {
                        bet = myCash;
                    }
                    myAction = 4;
                }
			}  */
        }
    }

    // auf sBluffStatus testen --> raise statt call und bet statt check

    // aktiv oder passiv?
    if(getHighestSet() > 0) {

        if(sBluffStatus && myOdds < myNiveau[2]) {

            // 		cout << "sBLUFF!" << endl;

            // Gegner setzen -> call
            if(getHighestSet() >= 4*getSmallBlind()) {
                myAction = 3;
            }
            // Standard-Raise-Routine
            else {
                // raise-Betrag ermitteln
				getRandNumber(1,8,1,&rand,0,0,0);
                raise = rand*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
                // 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips oder knappem raise
                if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4)/5) {
                    raise = myCash;
                }
                myAction = 5;
            }

            // extrem hoher set der gegner -> bluff beenden
            if(getHighestSet() >= 10*getSmallBlind()) {
                myAction = 1;
            }
        }
    }
    else {
        if(sBluffStatus && myOdds < myNiveau[1]) {

            // 		cout << "sBLUFF!" << endl;

		getRandNumber(1,8,1,&rand,0,0,0);
            bet = rand*getSmallBlind();
            // bet zu klein
            if(bet < 2*getSmallBlind()) {
                bet = 2*getSmallBlind();
            }
            // all in bei nur wenigen Chips
            if(myCash/(2*getSmallBlind()) <= 6) {
                bet = myCash;
            }
            // all in bei knappem bet
            if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;
        }

    }


	    /*
        if(DEBUG_MODE) {
        
        		switch(myUniqueID) {
        
                case 0: {
        			}
        			break;
                case 1: {
        
        				switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_FOLD;
        						//                                                bet = 20;
                                //                                                if(getHighestSet() > 20) {
                                //                                                        myAction = PLAYER_ACTION_CALL;
        						//                                                }
                            }
                            break;
        				case 2: {
        						// 						myAction = PLAYER_ACTION_BET;
        						// 						raise = 25;
        					}
                            break;
        				default: {
        					}
                        }
        			}
                    break;
        		case 2: {
        
        				switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_FOLD;
                                // 						raise = 40;
        						//						bet = 40;
                                // 						if(getHighestSet() > 100) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				default: {
                            }
        				}
        
        			}
                    break;
        		case 3: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_FOLD;
        						// 						bet = 10;
                                // 						if(getHighestSet() > 500) {
        						// 							myAction = PLAYER_ACTION_RAISE;
                                //                                                        raise = 10000;
        						// 						}
                            }
        					break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
        					break;
                        default: {
        					}
                        }
        
        
        			}
                    break;
        		case 4: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_FOLD;
        //                        bet = 120;
        //                        if(getHighestSet() > 0) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                        }
        					}
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
        				default: {
                            }
        				}
        
        
                    }
        			break;
        		case 5: {
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_BET;
                                                        bet = 20;
                                                        if(getHighestSet() > 0) {
        													myAction = PLAYER_ACTION_CALL;
        												}
                            }
        					break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
                            break;
        				default: {
        					}
                        }
        
        
        			}
        			break;
                case 6: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_RAISE;
                                bet = 20;
        						if(getHighestSet() > 20) {
        							myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        						}
                            }
        					break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
        					break;
                        default: {
        					}
                        }
        
        
                    }
                    break;
        		case 7: {
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_CALL;
        //                        bet = 20;
        //                        if(getHighestSet() > 20) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        //                        }
        					}
                            break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
        					break;
                        default: {
        					}
        				}
        
        
        			}
                    break;
                case 8: {
        				switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_FOLD;
        //                        bet = 20;
        //                        if(getHighestSet() > 20) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        //                        }
                            }
        					break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
        					break;
                        default: {
        					}
                        }
        
        
        			}
                    break;
        		case 9: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_RAISE;
        						bet = 60;
        						if(getHighestSet() > 40) {
        							myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        						}
                            }
        					break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
        					break;
                        default: {
        					}
                        }
        
        
        			}
                    break;
        		default: {}
        		}
        
        
        	}
        
        	// minimum raise setting and resetting
        	//        if(myAction == 5) {
        	//
        	//                if(raise < currentHand->getCurrentBeRo()->getMinimumRaise()) {
        	//                        raise = currentHand->getCurrentBeRo()->getMinimumRaise();
        	//                }
        	//                currentHand->getCurrentBeRo()->setMinimumRaise(raise);
        	//
        	//        }
        	//
			//        if(myAction == 4) { currentHand->getCurrentBeRo()->setMinimumRaise(bet); }
    */

	evaluation(bet, raise);

}



void PokerAI::riverEngine() {

	// 	int tempArray[6];
	// 	int boardCards[5];
    // 	int i;

    // 	for(i=0; i<2; i++) tempArray[i] = myCards[i];
    // 	currentBoard->getMyCards(boardCards);
    // 	for(i=0; i<4; i++) tempArray[2+i] = boardCards[i];

    // 	for(i=0; i<5; i++) cout << tempArray[i] << " ";
    // 	cout << endl;

    // 	cout << myID << ": ";

    // 	turnCardsValue(tempArray);


    int raise = 0;
    int bet = 0;
    // 	int i;
    int rand;
    int pBluff;


    calcMyOdds();

    // Niveaus setzen + Dude + Anzahl Gegenspieler
    // 1. Fold -- Call
    myNiveau[0] = 53 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;
    // 2. Check -- Bet
    myNiveau[1] = 56 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;
    // 3. Call -- Raise
    myNiveau[2] = 69 + myDude4/* - 6*(currentHand->getActivePlayerList().size() - 2)*/;


    // count number of active human players
  /*	size_t countHumanPlayers = 0;
    for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
        if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN) {
			countHumanPlayers++;
        }
    }
	if(countHumanPlayers) {
        // local or network game and only one human player is active --> set aggValue
        if(countHumanPlayers == 1) {

            for(it_c=currentHand->getActivePlayerList()->begin(); it_c!=currentHand->getActivePlayerList()->end(); it_c++) {
				if((*it_c)->getMyType() == PLAYER_TYPE_HUMAN &&  (*it_c)->getMyAction() != PLAYER_ACTION_FOLD) {
                    int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
					myNiveau[0] -= aggValue;
                    myNiveau[1] -= aggValue;
					myNiveau[2] -= aggValue;
				}
			}
			// network game
        } else {
			myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
        }
	}   */
     myNiveau[0] -= 3;
			myNiveau[1] -= 3;
			myNiveau[2] -= 3;
    // Aggresivität des humanPlayers auslesen -> nur wenn er aktiv ist !
    // 	it_c = currentHand->getActivePlayerIt(0);
    // 	if( it_c != currentHand->getActivePlayerList()->end() ) {
    // 		if( (*it_c)->getMyAction() != PLAYER_ACTION_FOLD ) {
    // 			int aggValue = (int)((( (*it_c)->getMyAggressive()*1.0)/7.0 - 1.0/currentHand->getActivePlayerList()->size())*21.0);
    // 			for(i=0; i<3; i++) {
    // 				myNiveau[i] -= aggValue;
    // 			}
    // 		}
    //
    // 	}



    //	cout << "Spieler " << myID << ": Dude " << myDude4 << "\t Wert " <<  myHoleCardsValue << "\t Niveau " << myNiveau[0] << " " << myNiveau[1] << " " << myNiveau[2] << "\t Agg " << aggValue << " " << endl;

    // eigenes mögliches highestSet
    int individualHighestSet = getHighestSet();
    if(individualHighestSet > myCash) individualHighestSet = myCash;

    // aktiv oder passiv?
    if(getHighestSet() > 0) {

        // Verhaeltnis Set / Cash
        if(myCash/individualHighestSet >= 25) {
            myNiveau[0] += (25-myCash/individualHighestSet)/10;
        } else {
            myNiveau[0] += (25-myCash/individualHighestSet)/2;
        }

        // Verhaeltnis Set / Cash für raise
        if(myCash/individualHighestSet < 11) {
            myNiveau[2] += (21-myCash/individualHighestSet)/2;
        }

        // raise (bei hohem Niveau)
        if(myOdds >= myNiveau[2]) {
            // raise-loop unterbinden -> d.h. entweder call oder bei superblatt all in
            if(getHighestSet() >= 12*getSmallBlind()) {
                // all in
                if(myOdds >= myNiveau[2] + 15) {
                    raise = myCash;
                    myAction = 5;
                }
                // nur call
                else {
                    // all in bei knappem call
                    if(myCash-getHighestSet() <= (myCash*1)/5) {
                        raise = myCash;
                        myAction = 5;
                    } else {
                        myAction = 3;
                    }
                }
            }
            // Standard-Raise-Routine
            else {
                // raise-Betrag ermitteln
                raise = (((int)myOdds-myNiveau[2])/2)*2*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
                // 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips
                if(myCash/(2*getSmallBlind()) <= 8) {
                    raise = myCash;
                }
                myAction = 5;
            }
        }
        else {
            // call -> über niveau0, schon einiges gesetzt im flop, schon einiges insgesamt gesetzt
            if(myOdds >= myNiveau[0] || (mySet >= getHighestSet()/2 && myOdds >= myNiveau[0]-5) || (myRoundStartCash-myCash > individualHighestSet && myNiveau[0]-3)) {
                // all in bei knappem call
                if(myCash-getHighestSet() <= (myCash*1)/4) {
                    raise = myCash;
                    myAction = 5;
                }
                else myAction = 3;
            }
            // fold
            else {
                myAction = 1;
            }
        }
    }
    else {
        // bet
        if(myOdds >= myNiveau[1]) {
            bet = (((int)myOdds-myNiveau[1])/3)*2*getSmallBlind();
            if(bet == 0) {
                bet = 2*getSmallBlind();
            }
            // all in bei nur wenigen Chips
            if(myCash/(2*getSmallBlind()) <= 6) {
                raise = myCash;
            }
            // all in bei knappem bet
            if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;
        }
        // check
        else {
            myAction = 2;
            // Position
		   /* if(myButton == 1) {
                // Position-Bluff generieren
                Tools::getRandNumber(1,100,1,&pBluff,0);
                if(pBluff <= 20) {
                    bet = (pBluff/4)*2*getSmallBlind();
                    // bet zu klein
                    if(bet == 0) {
                        bet = 2*getSmallBlind();
                    }
                    // all in bei nur wenigen Chips
                    if(myCash/(2*getSmallBlind()) <= 6) {
                        bet = myCash;
                    }
                    // all in bei knappem bet
                    if(bet > (myCash*4.0)/5.0) {
                        bet = myCash;
                    }
                    myAction = 4;
                }
			}*/
		}

//        // lastPlayerAction für Karten umblättern reihenfolge setzrn
//        currentHand->getCurrentBeRo()->setLastActionPlayer(myUniqueID);

    }

    // auf sBluffStatus testen --> raise statt call und bet statt check

    // aktiv oder passiv?
    if(getHighestSet() > 0) {

        if(sBluffStatus && myOdds < myNiveau[2]) {

            // 		cout << "sBLUFF!" << endl;

            // Gegner setzen -> call
            if(getHighestSet() >= 4*getSmallBlind()) {
                myAction = 3;
            }
            // Standard-Raise-Routine
            else {
                // raise-Betrag ermitteln
				getRandNumber(1,8,1,&rand,0,0,0);
                raise = rand*getSmallBlind();
                // raise-Betrag zu klein -> mindestens Standard-raise
                // 				if(raise < getHighestSet()) {
                // 					raise = getHighestSet();
                // 				}
                // all in bei nur wenigen Chips oder knappem raise
                if(myCash/(2*getSmallBlind()) <= 6 || raise >= (myCash*4)/5) {
                    raise = myCash;
                }
                myAction = 5;
            }

            // extrem hoher set der gegner -> bluff beenden
            if(getHighestSet() >= 10*getSmallBlind()) {
                myAction = 1;
            }
        }
    }
    else {
        if(sBluffStatus && myOdds < myNiveau[1]) {

            // 		cout << "sBLUFF!" << endl;

			getRandNumber(1,8,1,&rand,0,0,0);
            bet = rand*getSmallBlind();
            // bet zu klein
            if(bet < 2*getSmallBlind()) {
                bet = 2*getSmallBlind();
            }
            // all in bei nur wenigen Chips
			if(myCash/(2*getSmallBlind()) <= 6) {
                bet = myCash;
            }
            // all in bei knappem bet
            if(bet > (myCash*4.0)/5.0) {
                bet = myCash;
            }
            myAction = 4;
        }

    }


	    /*
        if(DEBUG_MODE) {
        		switch(myUniqueID) {
                case 0: {
                    } break;
        		case 1: {
        
                        switch(currentHand->getMyID()) {
                        case 1: {
                                myAction = PLAYER_ACTION_CALL;
        						//                                                raise = 40;
                                //                                                if(getHighestSet() > 60) {
                                //                                                        myAction = PLAYER_ACTION_CALL;
        						//                                                }
                            } break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_BET;
        						// 						raise = 25;
                            } break;
        				default: {
                            }
        				}
                    } break;
        		case 2: {
        
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_BET;
                                bet = 100;
        						// 						raise = 40;
                                if(getHighestSet() > 100) {
                                    myAction = PLAYER_ACTION_CALL;
        						}
                            }
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        default: {
        					}
                        }
        
        			}
                    break;
                case 3: {
        				switch(currentHand->getMyID()) {
                        case 1: {
                                myAction = PLAYER_ACTION_CALL;
        						// 						bet = 120;
                                // 						if(getHighestSet() > 0) {
                                // 							myAction = PLAYER_ACTION_RAISE;
        						// 							raise = 10000;
                                // 						}
                            }
        					break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
                            break;
        				default: {
                            }
                        }
        
        
                    }
        			break;
                case 4: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_BET;
                                //						raise = 300;
        						bet = 220;
                                if(getHighestSet() > 0) {
                                    myAction = PLAYER_ACTION_CALL;
        							//                                                        raise = 10000;
                                }
                            }
        					break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
                            break;
        				default: {
                            }
                        }
        
        
                    }
        			break;
                case 5: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_CHECK;
                                // 						bet = 120;
        												if(getHighestSet() > 0) {
                                                            myAction = PLAYER_ACTION_FOLD;
        //                         							raise = 10000;
        												}
                            }
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        default: {
        					}
                        }
        
        
                    }
                    break;
        		case 6: {
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_BET;
                                bet = 40;
                                if(getHighestSet() > 0) {
        							myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
                                }
        					}
                            break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
                            }
        					break;
                        default: {
                            }
        				}
        
        
        			}
                    break;
                case 7: {
        				switch(currentHand->getMyID()) {
                        case 1: {
                                myAction = PLAYER_ACTION_CALL;
        //                        bet = 40;
        //                        if(getHighestSet() > 0) {
        //                            myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        //                        }
                            }
        					break;
                        case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
        						// 						raise = 50;
                                // 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
        						// 						}
                            }
                            break;
        				default: {
                            }
                        }
        
        
                    }
        			break;
                case 8: {
                        switch(currentHand->getMyID()) {
        				case 1: {
                                myAction = PLAYER_ACTION_BET;
                                bet = 40;
        						if(getHighestSet() > 0) {
                                    myAction = PLAYER_ACTION_CALL;
        //                            raise = 10000;
        						}
                            }
                            break;
        				case 2: {
                                // 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
        						// 						if(mySet >= 70) {
                                // 							myAction = PLAYER_ACTION_CALL;
                                // 						}
        					}
                            break;
                        default: {
        					}
                        }
        
        
                    }
                    break;
        		case 9: {
                        switch(currentHand->getMyID()) {
                        case 1: {
        						myAction = PLAYER_ACTION_RAISE;
                                bet = 180;
        						if(getHighestSet() > 40) {
        							myAction = PLAYER_ACTION_RAISE;
                                    raise = 10000;
                                }
        					}
                            break;
                        case 2: {
        						// 						myAction = PLAYER_ACTION_RAISE;
                                // 						raise = 50;
                                // 						if(mySet >= 70) {
        						// 							myAction = PLAYER_ACTION_CALL;
                                // 						}
                            }
        					break;
                        default: {
                            }
        				}
        
        
        			}
                    break;
                default: {}
        		}
        

			}
    */

    evaluation(bet, raise);




}


void PokerAI::preflopEngine3() {

    // 	cout << "nextID " << currentHand->getPlayerArray()[(myID+1)%5]->getMyID() << endl;

    int raise = 0;

    // 	Bauchgefhl (zufÃ¯Â¿Ålig)
    int tempRand;
	getRandNumber(1,10,1,&tempRand,0,0,0);

    // bluff, checkbluff
    int bluff;
	getRandNumber(1,100,1,&bluff,0,0,0);

	// 	cout << "preflop-bluff " << bluff << endl;

    // Potential
	int potential = 10*(4*(myCardsValue.holeCardsClass(myCards[0], myCards[1]))+1*tempRand)/50-myDude;

	int setToHighest =getHighestSet() - mySet;

    // temp fr das Vielfache des Small Blind, sodass HighestSet zu hoch ist
    int tempFold;
    // 	tempFold = (currentHand->getPlayerArray()[0]->getMyAverageSets())/(8*currentHand->getSmallBlind());
	getRandNumber(2,3,1,&tempFold,0);

	// FOLD --> wenn Potential negativ oder HighestSet zu hoch
	if( (potential*setToHighest<0 || (setToHighest > tempFold * getSmallBlind() &&  potential<1) || (setToHighest > 2 * tempFold * getSmallBlind() &&  potential<2) || (setToHighest > 4 * tempFold * getSmallBlind() &&  potential<3) || (setToHighest > 10 * tempFold * getSmallBlind() &&  potential<4))  && myCardsValue.holeCardsClass(myCards[0], myCards[1]) < 9 && bluff > 15) {
        myAction=1;
    }
    else {
        // RAISE --> wenn hohes Potential
        if((potential >= 4 && 6 * getSmallBlind() >= getHighestSet()) || bluff <= 6) {
            // extrem hohes Potential --> groÃ¯Â¿År Raise
            if(potential>=6 || bluff <= 2) {

                // bluff - raise
                if(bluff <=2  && 4 * getSmallBlind() > getHighestSet()) {
                    raise = 3 * getHighestSet();
                }
                else {
                    // bluff - call
                    if(bluff >= 98) {
                        // All In
                        if(getHighestSet() >= myCash) {

                            mySet += myCash;
                            myCash = 0;
                            myAction = 6;

                        }
                        // sonst
                        else {
                            myCash = myCash - getHighestSet() + mySet;
                            mySet = getHighestSet();
                            myAction = 3;
                        }
                    } else {
                        // doch nich raisen, sondern nur checken, weil highestSets bereits sehr hoch !!!
                        if(! (4 * getSmallBlind() > getHighestSet())) {

                            // All In
                            if(getHighestSet() >= myCash) {
				
                                mySet += myCash;
                                myCash = 0;
                                myAction = 6;
				
                            }
                            // sonst
                            else {
                                myCash = myCash - getHighestSet() + mySet;
                                mySet = getHighestSet();
                                myAction = 3;
                            }

                        }
                        else raise = (potential - 4 ) * 2 * getHighestSet();
                    }
                }
            }
            // hohes Potential --> gemäßigter Raise
            else {
                // bluff - raise
                if(bluff <= 6 && 4 * getSmallBlind() > getHighestSet()) {
                    raise = 2*getHighestSet();
                }
                else {
                    // bluff - call
                    if(bluff >= 93) {

                        // All In
                        if(getHighestSet() >= myCash) {

                            mySet += myCash;
                            myCash = 0;
                            myAction = 6;

                        }
                        // sonst
                        else {
                            myCash = myCash - getHighestSet() + mySet;
                            mySet = getHighestSet();
                            myAction = 3;
                        }
                    }
                    else {
                        // doch nich raisen, sondern nur checken, weil highestSets bereits sehr hoch !!!
                        if(! (4 * getSmallBlind() > getHighestSet())) {

                            // All In
                            if(getHighestSet() >= myCash) {
				
                                mySet += myCash;
                                myCash = 0;
                                myAction = 6;
				
                            }
                            // sonst
                            else {
                                myCash = myCash - getHighestSet() + mySet;
                                mySet = getHighestSet();
                                myAction = 3;
                            }
                        }
                        else raise = (potential - 3 ) * getHighestSet();
                    }
                }
            }

            if (raise > 0) {
                // All In
                if(getHighestSet() + raise >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;
				  //	if(mySet > getHighestSet()) currentHand->getCurrentBeRo()->setHighestSet(mySet);

                }
                // sonst
                else {

                    myCash = myCash + mySet - getHighestSet() - raise;
                    mySet = getHighestSet() + raise;
					//currentHand->getCurrentBeRo()->setHighestSet(mySet);
                    myAction = 5;
                }
            }
        }
        //CHECK und CALL
        else {
            // CHECK --> wenn alle Sets glieich bei BigBlind und nich zu hohem Potential
            if(mySet == getHighestSet()) {
                myAction = 2;
            }
            // CALL --> bei normalen Potential
            else {
                // All In
                if(getHighestSet() >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash = myCash - getHighestSet() + mySet;
                    mySet = getHighestSet();
                    myAction = 3;
                }
            }
        }
    }
}

void PokerAI::flopEngine3() {

    // Prozent ausrechnen

    int i, j, k ,l;
    int tempBoardCardsArray[5];
    int tempMyCardsArray[7];
    int tempOpponentCardsArray[7];
	getBoardCards(tempBoardCardsArray);

    tempMyCardsArray[0] = myCards[0];
    tempMyCardsArray[1] = myCards[1];
    tempMyCardsArray[2] = tempBoardCardsArray[0];
    tempMyCardsArray[3] = tempBoardCardsArray[1];
    tempMyCardsArray[4] = tempBoardCardsArray[2];

    tempOpponentCardsArray[2] = tempBoardCardsArray[0];
    tempOpponentCardsArray[3] = tempBoardCardsArray[1];
    tempOpponentCardsArray[4] = tempBoardCardsArray[2];

    int tempMyCardsValue;
    int tempOpponentCardsValue;

    int countAll = 0;
    int countMy = 0;

    for(i=0; i<49; i++) {
        if(i != myCards[0] && i != myCards[1] && i != tempBoardCardsArray[0] && i != tempBoardCardsArray[1] && i != tempBoardCardsArray[2]) {
            for(j=i+1; j<50; j++) {
                if(j != myCards[0] && j != myCards[1] && j != tempBoardCardsArray[0] && j != tempBoardCardsArray[1] && j != tempBoardCardsArray[2]) {
                    for(k=j+1; k<51; k++) {
                        if(k != myCards[0] && k != myCards[1] && k != tempBoardCardsArray[0] && k != tempBoardCardsArray[1] && k != tempBoardCardsArray[2]) {
                            for(l=k+1; l<52; l++) {
                                if(l != myCards[0] && l != myCards[1] && l != tempBoardCardsArray[0] && l != tempBoardCardsArray[1] && l != tempBoardCardsArray[2]) {

                                    countAll++;

                                    tempOpponentCardsArray[0] = i;
                                    tempOpponentCardsArray[1] = j;
                                    tempOpponentCardsArray[5] = k;
                                    tempOpponentCardsArray[6] = l;
                                    tempMyCardsArray[5] = k;
                                    tempMyCardsArray[6] = l;
									tempMyCardsValue = myCardsValue.cardsValue(tempMyCardsArray,0);
                                    tempOpponentCardsValue = myCardsValue.cardsValue(tempOpponentCardsArray,0);

                                    if(tempMyCardsValue>=tempOpponentCardsValue) countMy++;

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    double percent = (countMy*1.0)/(countAll*1.0);
    // 	cout << "Prozent: " << percent << endl;

    int raise = 0;

    // 	Bauchgefhl (zufÃ¯Â¿Ålig)
    int tempRand;
    getRandNumber((int)(percent*10.)-2,(int)(percent*10.)+2,1,&tempRand,0);

    // bluff, checkbluff
    int bluff;
    getRandNumber(1,100,1,&bluff,0);

    // 	cout << "flop-bluff " << bluff << endl;

    // 	Potential
    int potential = (10*(5*(int)(percent*100.)+10*tempRand*2))/700-myDude;

    int setToHighest = getHighestSet() - mySet;

    // temp fr das Vielfache des Small Blind, sodass HighestSet zu hoch ist
    int tempFold;
    // 	tempFold = (currentHand->getPlayerArray()[0]->getMyAverageSets())/(8*getSmallBlind());
    getRandNumber(2,3,1,&tempFold,0);

    // FOLD --> wenn potential negativ oder HighestSet zu hoch
    if(( potential*setToHighest<0 || (setToHighest > tempFold * getSmallBlind() &&  potential<1) || (setToHighest > 3 * tempFold * getSmallBlind() &&  potential<2) || (setToHighest > 9 * tempFold * getSmallBlind() &&  potential<3) || (setToHighest > 20*tempFold * getSmallBlind() &&  potential<4) || (setToHighest > 40 *tempFold * getSmallBlind() &&  potential<5)) && percent < 0.90 && bluff > 18) {
        myAction=1;
    }
    else {
        // CHECK und BET --> wenn noch keiner was gesetzt hat
        if(getHighestSet() == 0) {
            // CHECK --> wenn Potential klein oder check-bluff sonst bet oder bet-bluff
            if((potential<3 || bluff >= 80) && bluff > 15) {
                // check
                myAction = 2;
            }
            // BET --> wenn Potential hoch
            else {
                if(bluff <= 5) mySet = (bluff+1) * getSmallBlind();
                else {
                    if(bluff <=15 ) mySet = 4 * getSmallBlind();
                    // je höher das Potential, desto höher der Einsatz (zur Basis SmallBlind)
                    else mySet = (potential-1) * 2 * getSmallBlind();
                }

                // All In
                if(mySet >= myCash) {
                    mySet = myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash -= mySet;
                    myAction = 4;
                }
			   // currentHand->getCurrentBeRo()->setHighestSet(mySet);
            }

        }
        // CALL und RAISE --> wenn bereits gesetzt wurde
        else {
            // RAISE --> wenn Potential besonders gut
            if((potential >=4 && 2 * tempFold * getSmallBlind() >= getHighestSet()) || (bluff <= 5 && 4 * tempFold * getSmallBlind() >= getHighestSet())) {

                // bluff - raise
                if(bluff <=5) raise = ((bluff+1)/2) * getHighestSet();
                // Betrag, der ber dem aktuell HighestSet gesetzt werden soll
                else raise = ((potential - 2 ) / 2) * getHighestSet();

                // All In
                if(getHighestSet() + raise >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;
				  //  if(mySet > getHighestSet()) currentHand->getCurrentBeRo()->setHighestSet(mySet);

                }
                // sonst
                else {

                    myCash = myCash + mySet - getHighestSet() - raise;
                    mySet = getHighestSet() + raise;
					//currentHand->getCurrentBeRo()->setHighestSet(mySet);
                    myAction = 5;
                }
            }
            // CALL --> bei normalen Potential
            else {

                // All In
                if(getHighestSet() >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash = myCash - getHighestSet() + mySet;
                    mySet = getHighestSet();
                    myAction = 3;
                }
            }
        }
    }


}

void PokerAI::turnEngine3() {

    // Prozent ausrechnen

    int i, j, k;
    int tempBoardCardsArray[5];
    int tempMyCardsArray[7];
    int tempOpponentCardsArray[7];
    getBoardCards(tempBoardCardsArray);

    tempMyCardsArray[0] = myCards[0];
    tempMyCardsArray[1] = myCards[1];
    tempMyCardsArray[2] = tempBoardCardsArray[0];
    tempMyCardsArray[3] = tempBoardCardsArray[1];
    tempMyCardsArray[4] = tempBoardCardsArray[2];
    tempMyCardsArray[5] = tempBoardCardsArray[3];

    tempOpponentCardsArray[2] = tempBoardCardsArray[0];
    tempOpponentCardsArray[3] = tempBoardCardsArray[1];
    tempOpponentCardsArray[4] = tempBoardCardsArray[2];
    tempOpponentCardsArray[5] = tempBoardCardsArray[3];

    int tempMyCardsValue;
    int tempOpponentCardsValue;

    int countAll = 0;
    int countMy = 0;

    for(i=0; i<49; i++) {
        if(i != myCards[0] && i != myCards[1] && i != tempBoardCardsArray[0] && i != tempBoardCardsArray[1] && i != tempBoardCardsArray[2]) {
            for(j=i+1; j<50; j++) {
                if(j != myCards[0] && j != myCards[1] && j != tempBoardCardsArray[0] && j != tempBoardCardsArray[1] && j != tempBoardCardsArray[2]) {
                    for(k=j+1; k<51; k++) {
                        if(k != myCards[0] && k != myCards[1] && k != tempBoardCardsArray[0] && k != tempBoardCardsArray[1] && k != tempBoardCardsArray[2]) {

                            countAll++;

                            tempOpponentCardsArray[0] = i;
                            tempOpponentCardsArray[1] = j;
                            tempOpponentCardsArray[6] = k;
                            tempMyCardsArray[6] = k;
                            tempMyCardsValue = myCardsValue.cardsValue(tempMyCardsArray,0);
                            tempOpponentCardsValue = myCardsValue.cardsValue(tempOpponentCardsArray,0);

                            if(tempMyCardsValue>=tempOpponentCardsValue) countMy++;
                        }
                    }
                }
            }
        }
    }

    double percent = (countMy*1.0)/(countAll*1.0);
    // 	cout << "Prozent: " << percent << endl;

    int raise;

    // 	Bauchgefhl (zufÃ¯Â¿Ålig)
    int tempRand;
    getRandNumber((int)(percent*10.)-2,(int)(percent*10.)+2,1,&tempRand,0);

    // bluff, checkbluff
    int bluff;
    getRandNumber(1,100,1,&bluff,0);

    // 	cout << "turn-bluff " << bluff << endl;

    // 	Potential
    int potential = (10*(5*(int)(percent*100.)+10*tempRand*2))/700-myDude;

    int setToHighest = getHighestSet() - mySet;

    // temp fr das Vielfache des Small Blind, sodass HighestSet zu hoch ist
    int tempFold;
    // 	tempFold = (currentHand->getPlayerArray()[0]->getMyAverageSets())/(7*getSmallBlind());
    getRandNumber(3,4,1,&tempFold,0);

    // FOLD
    // --> wenn potential negativ oder HighestSet zu hoch
    if( (potential*setToHighest<0 || (setToHighest > tempFold * getSmallBlind() &&  potential<1) || (setToHighest > 3 * tempFold * getSmallBlind() &&  potential<2) || (setToHighest > 9 * tempFold * getSmallBlind() &&  potential<3) || (setToHighest > 20*tempFold * getSmallBlind() &&  potential<4) || (setToHighest > 40 *tempFold * getSmallBlind() &&  potential<5)) && percent < 0.90 && bluff > 15) {
        myAction=1;
    }
    else {
        // CHECK und BET --> wenn noch keiner was gesetzt hat
        if(getHighestSet() == 0) {
            // CHECK --> wenn Potential klein
            if((potential<2 || bluff >= 80) && bluff > 10) {
                // check
                myAction = 2;
            }
            // BET --> wenn Potential hoch
            else {

                if(bluff <= 3) mySet = bluff * 2 * getSmallBlind();
                else {
                    if(bluff <=10 ) mySet = ((bluff+2)/3) * getSmallBlind();
                    // je hÃ¯Â¿Åer das Potential, desto hÃ¯Â¿Åher der Einsatz (zur Basis SmallBlind)
                    else mySet = (potential-1) * 3 * getSmallBlind();
                }

                // All In
                if(mySet >= myCash) {
                    mySet = myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash -= mySet;
                    myAction = 4;
                }
			   // currentHand->getCurrentBeRo()->setHighestSet(mySet);
            }

        }
        // CALL und RAISE --> wenn bereits gesetzt wurde
        else {
            // RAISE --> wenn Potential besonders gut
            if((potential >=4 && 2 * tempFold * getSmallBlind() >= getHighestSet()) || (bluff <= 4 && 3 * tempFold * getSmallBlind() >= getHighestSet())) {

                // bluff - raise
                if(bluff <= 4) raise = ((bluff+1)/2) * getHighestSet();
                // Betrag, der ber dem aktuell HighestSet gesetzt werden soll
                else raise = ( potential - 3 ) * getHighestSet();

                // All In
                if(getHighestSet() + raise >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;
				  //  if(mySet > getHighestSet()) currentHand->getCurrentBeRo()->setHighestSet(mySet);

                }
                // sonst
                else {

                    myCash = myCash + mySet - getHighestSet() - raise;
                    mySet = getHighestSet() + raise;
					//currentHand->getCurrentBeRo()->setHighestSet(mySet);
                    myAction = 5;
                }
            }
            // CALL --> bei normalen Potential
            else {
                // All In
                if(getHighestSet() >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash = myCash - getHighestSet() + mySet;
                    mySet = getHighestSet();
                    myAction = 3;
                }
            }
        }
    }

}

void PokerAI::riverEngine3() {

    // Prozent ausrechnen

    int i, j;
    int tempBoardCardsArray[5];
    int tempMyCardsArray[7];
    int tempOpponentCardsArray[7];
	getBoardCards(tempBoardCardsArray);

    tempMyCardsArray[0] = myCards[0];
    tempMyCardsArray[1] = myCards[1];
    tempMyCardsArray[2] = tempBoardCardsArray[0];
    tempMyCardsArray[3] = tempBoardCardsArray[1];
    tempMyCardsArray[4] = tempBoardCardsArray[2];
    tempMyCardsArray[5] = tempBoardCardsArray[3];
    tempMyCardsArray[6] = tempBoardCardsArray[4];

    tempOpponentCardsArray[2] = tempBoardCardsArray[0];
    tempOpponentCardsArray[3] = tempBoardCardsArray[1];
    tempOpponentCardsArray[4] = tempBoardCardsArray[2];
    tempOpponentCardsArray[5] = tempBoardCardsArray[3];
    tempOpponentCardsArray[6] = tempBoardCardsArray[4];

    int tempMyCardsValue;
    int tempOpponentCardsValue;

    int countAll = 0;
    int countMy = 0;

    for(i=0; i<49; i++) {
        if(i != myCards[0] && i != myCards[1] && i != tempBoardCardsArray[0] && i != tempBoardCardsArray[1] && i != tempBoardCardsArray[2]) {
            for(j=i+1; j<50; j++) {
                if(j != myCards[0] && j != myCards[1] && j != tempBoardCardsArray[0] && j != tempBoardCardsArray[1] && j != tempBoardCardsArray[2]) {

                    countAll++;

                    tempOpponentCardsArray[0] = i;
                    tempOpponentCardsArray[1] = j;
                    tempMyCardsValue = myCardsValue.cardsValue(tempMyCardsArray,0);
					tempOpponentCardsValue = myCardsValue.cardsValue(tempOpponentCardsArray,0);

                    if(tempMyCardsValue>=tempOpponentCardsValue) countMy++;
                }
            }
        }
    }

    double percent = (countMy*1.0)/(countAll*1.0);
    // 	cout << "Prozent: " << percent << endl;

    int raise;

    // 	Bauchgefhl (zufÃ¯Â¿Ålig)
    int tempRand;
    getRandNumber((int)(percent*10.)-2,(int)(percent*10.)+2,1,&tempRand,0);

    // bluff, checkbluff
    int bluff;
    getRandNumber(1,100,1,&bluff,0);

    // 	cout << "river-bluff " << bluff << endl;

    // 	Potential
    int potential = (10*(5*(int)(percent*100.)+10*tempRand*1))/600-myDude;

    int setToHighest = getHighestSet() - mySet;

    // temp fr das Vielfache des Small Blind, sodass HighestSet zu hoch ist
    int tempFold;
    // 		tempFold = (currentHand->getPlayerArray()[0]->getMyAverageSets())/(6*getSmallBlind());
	getRandNumber(4,6,1,&tempFold,0);

    // FOLD
    // --> wenn potential negativ oder HighestSet zu hoch
    if( (potential*setToHighest<0 || (setToHighest > tempFold * getSmallBlind() &&  potential<1) || (setToHighest > 3 * tempFold * getSmallBlind() &&  potential<2) || (setToHighest > 9 * tempFold * getSmallBlind() &&  potential<3) || (setToHighest > 20*tempFold * getSmallBlind() &&  potential<4) || (setToHighest > 40 *tempFold * getSmallBlind() &&  potential<5)) && percent < 0.90 && bluff > 15) {
        myAction=1;
    }
    else {
        // CHECK und BET --> wenn noch keiner was gesetzt hat
        if(getHighestSet() == 0) {
            // CHECK --> wenn Potential klein
            if((potential<2 || bluff >= 92) && bluff > 15) {
                // check
                myAction = 2;
            }
            // BET --> wenn Potential hoch
            else {

                if(bluff <= 5) mySet = (bluff+3) * getSmallBlind();
                else {
                    if(bluff <= 15 ) mySet = ((bluff-1)/5) * 2 * getSmallBlind();
                    // je hÃ¯Â¿Åer das Potential, desto hÃ¯Â¿Åher der Einsatz (zur Basis SmallBlind)
                    else mySet = (potential-1) * 4 * getSmallBlind();
                }

                // All In
                if(mySet >= myCash) {
                    mySet = myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash -= mySet;
                    myAction = 4;
                }
				//currentHand->getCurrentBeRo()->setHighestSet(mySet);
            }

        }
        // CALL und RAISE --> wenn bereits gesetzt wurde
        else {
            // RAISE --> wenn Potential besonders gut
			if((potential >=4 && 2 * tempFold * getSmallBlind() >= getHighestSet()) || (bluff <= 2 && 4 * tempFold * getSmallBlind() >= getHighestSet())) {

                // bluff - raise
                if(bluff <= 2 ) raise = bluff * getHighestSet();
                // Betrag, der ber dem aktuell HighestSet gesetzt werden soll
                else raise = ( potential - 3 ) * getHighestSet();

                // All In
                if(getHighestSet() + raise >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;
					//if(mySet > getHighestSet()) currentHand->getCurrentBeRo()->setHighestSet(mySet);

                }
                // sonst
                else {

                    myCash = myCash + mySet - getHighestSet() - raise;
                    mySet = getHighestSet() + raise;
					//currentHand->getCurrentBeRo()->setHighestSet(mySet);
                    myAction = 5;
                }
            }
            // CALL --> bei normalen Potential
            else {
                // All In
                if(getHighestSet() >= myCash) {

                    mySet += myCash;
                    myCash = 0;
                    myAction = 6;

                }
                // sonst
                else {
                    myCash = myCash - getHighestSet() + mySet;
					mySet = getHighestSet();
                    myAction = 3;
                }
            }
        }
    }

}


