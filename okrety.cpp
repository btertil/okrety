#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdio>

using namespace std;

class ship {

  protected:
      static int iloscInstancji;
      static int shipIdAll;
      int exp;

  public:

    int shipId, posx, posy;
    int mainArt, mainCal, mainDel, mainRang, armore;
    int auxArt, auxDel, auxCal, auxRang, aaArt1, aaArt2;
    int torTub, manuv, classId, hp, hp_max;

    const char *shipName, *className;

    ship()
    {
        iloscInstancji++;
        shipIdAll++;
        shipId=shipIdAll;

        hp_max = 10000;
        hp = hp_max;
        mainArt=0;
        mainCal=0;
        mainDel=0;
        mainRang=0;
        armore=15;
        auxArt=0;
        auxDel=0;
        auxCal=0;
        auxRang=0;
        aaArt1=0;
        aaArt2=0;
        torTub=0;
        manuv=120;
        classId=1;
        className = "Merchant";

	exp = 100;
    }

    virtual ~ship()
    {
        iloscInstancji--;
    }

    float czy_trafi(int, int);
    void mainAtak(ship*);
    void auxAtak(ship*);
    float shipDefence(float, float);
    float airDefence();

    void newExp(int);


};


int ship::iloscInstancji=0;
int ship::shipIdAll=0;




void ship::mainAtak(ship *cel)
{
    float sila, trafia, efekty;

    if (this -> hp > 0) {
        sila = pow(this->mainCal,1.85) * this->mainCal/8;
        printf("%s ==== >> %s\n", this->className, cel->className);
        printf("Salwa %d dzial artyleri glownej calibru %d mm\n", this->mainArt, this->mainCal);

        trafia = this-> czy_trafi(this->mainArt, this->exp);
        efekty = cel -> shipDefence(trafia, sila);
        cel -> hp -= (int)efekty;
    }

    return;
}


void ship::auxAtak(ship *cel)
{
    float sila, trafia, efekty;

    if (this -> hp > 0) {
        sila = pow(this->auxCal,1.85) * this->auxCal/8;
        printf("%s ---- > %s\n", this->className, cel->className);
        printf("Salwa %d dzial artyleri pomocniczej calibru %d mm\n", (int) round(this->auxArt/2), this->auxCal);

        trafia = this-> czy_trafi(this->auxArt, this->exp);
        efekty = cel -> shipDefence(trafia, sila);
        cel -> hp -= (int)efekty;
    }
 
   return;
}


float ship::czy_trafi(int ile, int exp_sh)
{

    int los = rand()%exp_sh+1;
    float ret = ((float)ile/7 * (float)los/100);
    //debug:
    //    printf("los wynosi %i a ret %f\n",los, ret);
    printf("Skutek to %.2f trafienia\n",ret);
    return ret;
}


float ship::shipDefence(float trafienia, float sila)
{
    float zniszczenie;

    if (trafienia < 0.9) zniszczenie = 0;
    else {
        zniszczenie = (trafienia * sila) / ((sqrt((float) this -> exp) * (float) (armore)) + 5) ;
    }

    printf("Zniszczenia %s to %i, pozostale hp: %i (%i pct)\n\n", this -> className, (int)zniszczenie, this -> hp - (int)zniszczenie, (int) round((((float) (hp- (int)zniszczenie)) / ((float) hp_max) * 100)));

    return zniszczenie;
}

float ship::airDefence()
{
    return 0.2;
}

// to do commita
void ship::newExp(int newexp) {
    this -> exp = newexp;
    return;
}



class battleship_1 : public ship {
    public:
    battleship_1()
        {
            hp_max = 14000;
            hp = hp_max;
            mainArt=8;
            mainCal=365;
            mainDel=240;
            mainRang=4;
            armore=220;
            auxArt=30;
            auxDel=60;
            auxCal=152;
            auxRang=2;
            aaArt1=30;
            aaArt2=15;
            torTub=0;
            manuv=600;
            classId=1;
            className = "battleship_1";
        }
};


class battleship_2 : public ship {
    public:
    battleship_2()
        {
            hp_max = 17000;
            hp = hp_max;
            mainArt=9;
            mainCal=406;
            mainDel=240;
            mainRang=4;
            armore=300;
            auxArt=30;
            auxDel=60;
            auxCal=152;
            auxRang=2;
            aaArt1=60;
            aaArt2=35;
            torTub=0;
            manuv=600;
            classId=2;
            className = "battleship_2";
        }
};


class l_cruiser : public ship {
    public:
    l_cruiser()
        {
            hp_max = 12000;
            hp = hp_max;
            mainArt=12;
            mainCal=152;
            mainDel=240;
            mainRang=4;
            armore=60;
            auxArt=0;
            auxDel=0;
            auxCal=0;
            auxRang=2;
            aaArt1=60;
            aaArt2=35;
            torTub=0;
            manuv=600;
            classId=2;
            className = "l_cruiser";
        }
};

class h_cruiser : public ship {
    public:
    h_cruiser()
        {
            hp_max = 14000;
            hp = hp_max;
            mainArt=8;
            mainCal=203;
            mainDel=240;
            mainRang=4;
            armore=80;
            auxArt=10;
            auxDel=0;
            auxCal=102;
            auxRang=2;
            aaArt1=60;
            aaArt2=35;
            torTub=0;
            manuv=600;
            classId=2;
            className = "h_cruiser";
        }
};

class b_cruiser : public ship {
    public:
    b_cruiser()
        {
            hp_max = 14000;
            hp = hp_max;
            mainArt=8;
            mainCal=280;
            mainDel=240;
            mainRang=4;
            armore=60;
            auxArt=12;
            auxDel=0;
            auxCal=127;
            auxRang=2;
            aaArt1=60;
            aaArt2=35;
            torTub=0;
            manuv=600;
            classId=2;
            className = "b_cruiser";
        }
};

void walka (ship *s1, ship *s2)
{
    int tury=0;

    do {
    	cout << "Tura: " << tury+1 << endl;
        if (s1 ->mainArt > 0) s1 ->mainAtak(s2);
        if (s1 ->auxArt > 0) s1 ->auxAtak(s2);
        if (s2 ->mainArt > 0) s2 ->mainAtak(s1);
        if (s2 ->auxArt > 0) s2 ->auxAtak(s1);
        tury++;
    } while (s1 -> hp > 0 && s2 -> hp > 0);

    printf("Walka zakonczona po %i turach\n", tury);
    return;
}


string opcje[] = {
    "merchant",
    "l_cruiser",
    "h_cruiser",
    "b_cruiser",
    "battleship_1",
    "battleship_2"
};

int elements = (int) (sizeof(opcje) / sizeof(string));


struct s_wybor {
    int w1;
    int w2;
};

s_wybor menu(void)
{
    s_wybor opcja;

    // inicjacja na -1 bo czasem zapamiętywał stare wartości
    opcja.w1 = -1;
    opcja.w2 = -1;

    while ( ((opcja.w1 < 0) || (opcja.w1 > elements)) || ((opcja.w2 < 0) || (opcja.w2 > elements)) ) {
        cout << "\n\n";
        for (int i = 0; i < elements; i++) {
            cout << i+1 << ": " << opcje[i] << "\n";
        }
	cout << "\n0 aby zakonczyc...\n";

        cout <<"\nWybierz okret strony 1: ";
        if(!(cin >> opcja.w1)) {
		opcja.w1 = -1;
		cin.clear();
		cin.ignore();
	}
	if (opcja.w1 == 0) exit(0);
        
	cout << "Wybierz okret strony 2: ";
        if(!(cin >> opcja.w2)) {
		opcja.w2 = -1;
		cin.clear();
		cin.ignore();
	}
	if (opcja.w2 == 0) exit(0);

    }

    cout << "\n\n";

    return opcja;
}



int main(int argc, char **argv) {

    ship *s1, *s2;
    s_wybor wybrane;

    cout << "\n\nShips v0.01 - by Bondir";

    do {
    	
	    wybrane = menu();

	    if (wybrane.w1 == 1) s1 = new ship;
	    if (wybrane.w1 == 2) s1 = new l_cruiser;
	    if (wybrane.w1 == 3) s1 = new h_cruiser;
	    if (wybrane.w1 == 4) s1 = new b_cruiser;
	    if (wybrane.w1 == 5) s1 = new battleship_1;
	    if (wybrane.w1 == 6) s1 = new battleship_2;

	    if (wybrane.w2 == 1) s2 = new ship;
	    if (wybrane.w2 == 2) s2 = new l_cruiser;
	    if (wybrane.w2 == 3) s2 = new h_cruiser;
	    if (wybrane.w2 == 4) s2 = new b_cruiser;
	    if (wybrane.w2 == 5) s2 = new battleship_1;
	    if (wybrane.w2 == 6) s2 = new battleship_2;


	    srand(time(NULL));

	    cout << "Walka pomiedzy " << s1 -> className << " a " << s2 -> className << endl;
	    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	    // getchar();
	    // fflush(stdin);

	    if (wybrane.w1 != 1 || wybrane.w2 != 1) {
	        walka(s1, s2);
	    } else {
	        cout << "Statki handlowe oddalają się od siebie nie podejmując żadnych działań...";
	    }

	    delete s1;
	    delete s2;

	    cout << "\n\n**********************************************************\n\n";
	    cout << "Jeszcze raz?";


	    } while (0<1);

    return 0;

}


/* zniszczenia w funkcji shipDefence()

    - uszkodzenia: co uszkodzone, jesli trafi to losowanie:
        - armaty (ilosc i jakie)
        - kadlub (pancerz)
        - mostek (exp)
        - maszynownia (predkosc, manewrowanie)
        - sterowanie (stery, maszyny)
        - zasieg ostrzalu (radar)

zasieg:
    + za rdar
    + za exp

    - jakie ziala
    - lotniskowce
        bombowce, torpedowce, mysliwce
        mysliwce to ochrona torp i bomb
        efektywnosc zalezna od exp
        airDef celu redukuje liczbe samolotórzypisanych do lotniskowca

*/

