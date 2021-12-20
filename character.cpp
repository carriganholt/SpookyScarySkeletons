// Character Function File
// Carrigan Holt

#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include "character.h"

using namespace std;

// Clear Screen
#define CLEAR_SCREEN if(system("cls")){system("clear");}

// Player VS Enemy Battle
int enemyBattle(Player p1, Enemy e) {
	
	srand(time(NULL));
	int temp = p1.health;
	e.health = rand() % 10 + 1;

	CLEAR_SCREEN
	PlaySoundA("battle.wav", NULL, SND_ASYNC);

	while (p1.health > 0 && e.health > 0) {

		e.attack = rand() % 5 + 1;
		
		cout << endl << endl;
		cout << "        A spooky scary skeleton attacks!" << endl << endl;
		cout << "                 _,.-------.,_ " << endl;
		cout << "              ,-~             ~-. " << endl;
		cout << "            ,^                   ^. " << endl;
		cout << "           /~'   ~'    .    ' ~  '~\\ " << endl;
		cout << "           Y  ,--._    I    _.--.  Y " << endl;
		cout << "           | Y     ~-. | ,-~     Y | " << endl;
		cout << "           | |        }:{        | | " << endl;
		cout << "           j l       / | \\       ! l " << endl;
		cout << "        .-~  (__,.--' .^. '--.,__)  ~-. " << endl;
		cout << "       (           / / | \\ \\           ) " << endl;
		cout << "        \\.____,   ~  \\/'\\/  ~   .____,/ " << endl;
		cout << "         ^.____                 ____.^ " << endl;
		cout << "            | |T ~\\  !   !  /~ T| | " << endl;
		cout << "            | |l   _ _ _ _ _   !| | " << endl;
		cout << "            | l \\/V V V V V V\\/ j | " << endl;
		cout << "            l  \\ \\|_|_|_|_|_|/ /  ! " << endl;
		cout << "             \\  \\[T T T T T TI/  / " << endl;
		cout << "              \\  `^-^-^-^-^-^'  / " << endl;
		cout << "               \\               / " << endl;
		cout << "                \\.           ,/ " << endl;
		cout << "                  '^-.___,-^' " << endl << endl;

		// Player Attack
		e.health -= p1.attack;
		cout << "            You attack for " + to_string(p1.attack) + " damage!" << endl << endl;
		cout << "                 Player HP: " + to_string(p1.health) << endl;
		cout << "               Skeleton HP: ";

		if (e.health < 0) {
			cout << "0";
		}
		else {
			cout << to_string(e.health);
		}

		cout << endl << endl << "        ";
		system("pause");
		CLEAR_SCREEN

			if (e.health > 0) {

				cout << endl << endl;
				cout << "        A spooky scary skeleton attacks!" << endl << endl;
				cout << "                 _,.-------.,_ " << endl;
				cout << "              ,-~             ~-. " << endl;
				cout << "            ,^                   ^. " << endl;
				cout << "           /~'   ~'    .    ' ~  '~\\ " << endl;
				cout << "           Y  ,--._    I    _.--.  Y " << endl;
				cout << "           | Y     ~-. | ,-~     Y | " << endl;
				cout << "           | |        }:{        | | " << endl;
				cout << "           j l       / | \\       ! l " << endl;
				cout << "        .-~  (__,.--' .^. '--.,__)  ~-. " << endl;
				cout << "       (           / / | \\ \\           ) " << endl;
				cout << "        \\.____,   ~  \\/'\\/  ~   .____,/ " << endl;
				cout << "         ^.____                 ____.^ " << endl;
				cout << "            | |T ~\\  !   !  /~ T| | " << endl;
				cout << "            | |l   _ _ _ _ _   !| | " << endl;
				cout << "            | l \\/V V V V V V\\/ j | " << endl;
				cout << "            l  \\ \\|_|_|_|_|_|/ /  ! " << endl;
				cout << "             \\  \\[T T T T T TI/  / " << endl;
				cout << "              \\  `^-^-^-^-^-^'  / " << endl;
				cout << "               \\               / " << endl;
				cout << "                \\.           ,/ " << endl;
				cout << "                  '^-.___,-^' " << endl << endl;

				// Enemy Attack
				p1.health -= e.attack;
				cout << "       The skeleton attacks for " + to_string(e.attack) + " damage!" << endl << endl;
				cout << "                 Player HP: ";

				if (p1.health < 0) {
					cout << "0";
				}
				else {
					cout << to_string(p1.health);
				}

				cout << endl << "               Skeleton HP: " + to_string(e.health) << endl << endl << "        ";
				system("pause");
				CLEAR_SCREEN
			}
	}

	PlaySoundA("gameplay.wav", NULL, SND_LOOP | SND_ASYNC);
	return temp - p1.health;
}

// Player VS Boss Battle
int bossBattle(Player p1, Boss b) {

	int temp = p1.health;

	CLEAR_SCREEN
	PlaySoundA("battle.wav", NULL, SND_ASYNC);

	while (p1.health > 0 && b.health > 0) {

		b.attack = rand() % 11 + 5;

		cout << endl << endl;
		cout << "    The spookyiest scariest skeleton attacks!" << endl << endl;                         
		cout << "                 (  (| " << endl;
		cout << "             )   )\\/ ( ( ( " << endl;
		cout << "        (   ((  /     ))\\))  (  )    ) " << endl;
		cout << "         \\   )\\(          |  ))( )  (| " << endl;
		cout << "          ))/   |          )/  \\((  ) \\ " << endl;
		cout << "         (      .        -.     V  )/  )( " << endl;
		cout << "        /     .   \\            .       \\)) " << endl;
		cout << "      )(      (  | |   )            .    ( " << endl;
		cout << "     )(    ,'))     \\ /          \\( `.    ) " << endl;
		cout << "     (\\>  ,'/__      ))            __`.  / " << endl;
		cout << "    ( \\   | /  ___   ( \\/     ___   \\ | ( ( " << endl;
		cout << "     \\.)  |/  /   \\__      __/   \\   \\|  )) " << endl;
		cout << "       \\. |>  \\      | __ |      /   <|  / " << endl;
		cout << "        ) /    \\____/ :..: \\____/     \\ < " << endl;
		cout << "      \\ (|__  .      / ;: \          __| ) " << endl;
		cout << "       )\\)  ~--_     --  --      _--~    / " << endl;
		cout << "       (    |  ||               ||  |   ( " << endl;
		cout << "        \\.  |  ||_             _||  |  / " << endl;
		cout << "          > :  |  ~V+-I_I_I-+V~  |  : (. " << endl;
		cout << "         (  \\:  T\\   _     _   /T  : ./ " << endl;
		cout << "          \\  :    T^T T-+-T T^T    ;< " << endl;
		cout << "           \\..`_       -+-       _' " << endl;
		cout << "              . `--=.._____..=--'. " << endl << endl;

		// Player Attack
		b.health -= p1.attack; 
		cout << "            You attack for " + to_string(p1.attack) + " damage!" << endl << endl;
		cout << "                 Player HP: " + to_string(p1.health) << endl;
		cout << "               Skeleton HP: ";

		if (b.health < 0) {
			cout << "0";
		}
		else {
			cout << to_string(b.health);
		}
			
		cout << endl << endl << "        ";
		system("pause");
		CLEAR_SCREEN

			if (b.health > 0) {

				cout << endl << endl;
				cout << "    The spookyiest scariest skeleton attacks!" << endl << endl;
				cout << "                 (  (| " << endl;
				cout << "             )   )\\/ ( ( ( " << endl;
				cout << "        (   ((  /     ))\\))  (  )    ) " << endl;
				cout << "         \\   )\\(          |  ))( )  (| " << endl;
				cout << "          ))/   |          )/  \\((  ) \\ " << endl;
				cout << "         (      .        -.     V  )/  )( " << endl;
				cout << "        /     .   \\            .       \\)) " << endl;
				cout << "      )(      (  | |   )            .    ( " << endl;
				cout << "     )(    ,'))     \\ /          \\( `.    ) " << endl;
				cout << "     (\\>  ,'/__      ))            __`.  / " << endl;
				cout << "    ( \\   | /  ___   ( \\/     ___   \\ | ( ( " << endl;
				cout << "     \\.)  |/  /   \\__      __/   \\   \\|  )) " << endl;
				cout << "       \\. |>  \\      | __ |      /   <|  / " << endl;
				cout << "        ) /    \\____/ :..: \\____/     \\ < " << endl;
				cout << "      \\ (|__  .      / ;: \          __| ) " << endl;
				cout << "       )\\)  ~--_     --  --      _--~    / " << endl;
				cout << "       (    |  ||               ||  |   ( " << endl;
				cout << "        \\.  |  ||_             _||  |  / " << endl;
				cout << "          > :  |  ~V+-I_I_I-+V~  |  : (. " << endl;
				cout << "         (  \\:  T\\   _     _   /T  : ./ " << endl;
				cout << "          \\  :    T^T T-+-T T^T    ;< " << endl;
				cout << "           \\..`_       -+-       _' " << endl;
				cout << "              . `--=.._____..=--'. " << endl << endl;

				// Boss Attack
				p1.health -= b.attack;
				cout << "       The skeleton attacks for " + to_string(b.attack) + " damage!" << endl << endl;
				cout << "                 Player HP: ";

				if (p1.health < 0) {
					cout << "0";
				}
				else {
					cout << to_string(p1.health);
				}

				cout << endl << "               Skeleton HP: " + to_string(b.health) << endl << endl << "        ";
				system("pause");
				CLEAR_SCREEN
			}
	}

	PlaySoundA("gameplay.wav", NULL, SND_LOOP | SND_ASYNC);
	return temp - p1.health;
}