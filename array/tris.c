#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define BOARD_SIZE 3    //Dimensione del campo da gioco

/*                                              *\
** Le 4 priorita' usate dall'IA per decidere    **
** la mossa migliore da effettuare.             **
** _LOW e' la priorita' minima, assegnata       **
** ad ogni mossa che non conduca a combo        **
** _MED e' la priorita' medai, assegnata        **
** ad ogni mossa che porta a formare una coppia **
** _HIGH per le mosse che portano a impedire    **
** la vittoria dell'avversario                  **
** _MAX per le mosse che portano a vincere      **
\*                                              */

#define PRIOR_LOW 1
#define PRIOR_MED 2
#define PRIOR_HIGH 3
#define PRIOR_MAX 4

/*                                      *\
**  Crea la rappresentazione visuale    **
**  del campo da gioco, contenuto       **
**  nell'array gameBoard                **
\*                                      */

void createTable(int gameBoard[BOARD_SIZE][BOARD_SIZE]){
    int i, j;
    printf(" --- --- ---\n");

    for(i=0; i < BOARD_SIZE; i++){
        printf("|");
        for(j=0; j < BOARD_SIZE; j++){
            if(gameBoard[i][j] != 0){
                if(gameBoard[i][j] == 1){           //Se il valore di una cella dell'array del tavolo da gioco
                    printf(" X ");                  //equivale a 1, stampa " X "
                }                                   //Se e' uguale a 2, stampa " O "
                else if(gameBoard[i][j] == 2){      //Se e' uguale a 0 (nessuna mossa effettuata), stampa 3 spazi
                    printf(" O ");
                }
            }
            else{
                printf("   ");
            }
           printf("|");
        }
        printf("\n");
        printf(" --- --- ---\n");
    }
}

/*                                              *\
**  Funzione per "svuotare" un array            **
**  (ovvero riempire tutte le sue celle con 0)  **
\*                                              */

void emptyArray(int arr[BOARD_SIZE][BOARD_SIZE]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            arr[i][j] = 0;
        }
    }
}

/*                                                      *\
**  Funzione per sostituire il valore di una variabile  **
**  (il cui puntatore e' stato dato in ingresso)        **
**  con un altro valore, a patto che quest'ultimo       **
**  sia maggiore del valore attuale della variabile     **
**                                                      **
**  La funzione accetta il puntatore al valore della    **
**  variabile (*variabile) invece che una variabile     **
**  "normale".                                              **
**  Questo permette di modificare il valore della       **
**  variabile data in ingresso senza dover avere        **
**  return e operazioni di assegnazione                 **
\*                                                      */

void ifLesserReplace(int *variable, int confront){
    if(*variable < confront){
        *variable = confront;
    }
}

/*                                                          *\
**  Funzione per cambiare la priorita' di una mossa         **
**  ed eventualmente impostare una nuova priorita' massima  **
**                                                          **
**  Anche in questo caso la funzione accetta pointer e      **
**  non variabili.                                          **
\*                                                          */

void changePriority(int *prioritySlot, int priority, int *highestPriority){
    ifLesserReplace(prioritySlot, priority);
    ifLesserReplace(highestPriority, priority);
}

/*                                                          *\
**  Funzione per controllare se la cella e' del giocatore   **
\*                                                          */

int isPlayer(int cell, int player){
    if(cell == player){
        return 1;
    }

    return 0;
}

/*                                                          *\
**  La funzione ritorna 1 se la cella contiene una pedina   **
**  qualunque(alleata o avversaria che sia)                 **
**  Ritorna 0 se la cella e' vuota o contiene un altro      **
**  valore                                                  **
\*                                                          */

int isPlayerOrEnemy(int cell, int player, int enemy){
    if(cell == player || cell == enemy){
        return 1;
    }

    return 0;
}

/*                                                          *\
**  Funzione per controllare se 3 celle sono uguali         **
**                                                          **
**  Se il terzo parametro e' -1, il confronto viene         **
**  effettuato fra 2 sole celle                             **
\*                                                          */

int areEqual(int cell1, int cell2, int cell3){
    if(cell3 == -1) cell3 = cell1;

    if(cell1 == cell2 && cell1 == cell3){
        return 1;
    }

    return 0;
}

/*                                                          *\
**  Analizza un set di 3 celle, definite tramite            **
**  coordinate iniziali e incrementi delle stesse           **
**  Imposta le priorita' nell'array dato e ritorna          **
**  La priorita' massima.                                   **
**  Le priorita' 5 e 6 indicano la fine del gioco           **
**  per vittoria di uno dei giocatori                       **
**                                                          **
**  Il codice non e' il massimo della bellezza e puo'       **
**  essere difficile da leggere. Sto cercando di crearne    **
**  una versione piu' comprensibile.                        **
\*                                                          */

int analyzeAndSetPriorities(int gameBoard[BOARD_SIZE][BOARD_SIZE], int priorityArray[BOARD_SIZE][BOARD_SIZE], int player, int enemy, int startingX, int startingY, int XIncrement, int YIncrement){
    int x,y;
    int cell1X, cell1Y, cell2X, cell2Y, cell3X, cell3Y;
    int cell1, cell2, cell3;
    int highestPriority = 0;

    /*                      *\
    **  Definizione celle   **
    \*                      */

    cell1X = startingX;
    cell1Y = startingY;

    cell2X = startingX + XIncrement;
    cell2Y = startingY + YIncrement;


    cell3X = startingX + (2 * XIncrement);
    cell3Y = startingY + (2 * YIncrement);

    cell1 = gameBoard[cell1X][cell1Y];
    cell2 = gameBoard[cell2X][cell2Y];
    cell3 = gameBoard[cell3X][cell3Y];

    if(isPlayerOrEnemy(cell1, player, enemy)){  //La cella 1 e' piena
        if(isPlayerOrEnemy(cell2, player, enemy)){  //La cella 2 e' piena
            if(isPlayerOrEnemy(cell3, player, enemy)){  //La cella 3 e' piena
                if(areEqual(cell1,cell2,cell3)){    //Le 3 celle appartengono allo stesso giocatore
                    if(isPlayer(cell1,player)){
                        return 5;
                    }
                    else{
                        return 6;
                    }
                }
            }
            else{   //La cella 3 e' vuota
                if(cell1 == cell2){
                    if(isPlayer(cell1,player)){ //Le due celle piene appartengono al giocatore
                        changePriority(&priorityArray[cell3X][cell3Y], PRIOR_MAX, &highestPriority);
                    }
                    else{
                        changePriority(&priorityArray[cell3X][cell3Y], PRIOR_HIGH, &highestPriority);
                    }
                }
                else{ // Le due celle piene sono uguali, mossa inutile.
                    changePriority(&priorityArray[cell3X][cell3Y], PRIOR_LOW, &highestPriority);
                }
            }
        }
        else{ //La cella 2 e' vuota -- La cella 1 e' piena
            if(isPlayerOrEnemy(cell3,player,enemy)){ //La cella 3 e' piena
                if(cell1 == cell3){
                    if(isPlayer(cell1,player)){
                        changePriority(&priorityArray[cell2X][cell2Y], PRIOR_MAX, &highestPriority);
                    }
                    else{
                        changePriority(&priorityArray[cell2X][cell2Y], PRIOR_HIGH, &highestPriority);
                    }
                }
                else{ //Le celle piene sono diverse fra loro, mossa inutile
                    changePriority(&priorityArray[cell2X][cell2Y], PRIOR_LOW, &highestPriority);
                }
            }
            else{ //Le celle 2 e 3 aono vuote -- La cella 1 e' piena
                if(isPlayer(cell1,player)){
                    changePriority(&priorityArray[cell2X][cell2Y], PRIOR_MED, &highestPriority);
                    changePriority(&priorityArray[cell3X][cell3Y], PRIOR_MED, &highestPriority);
                }
                else{
                    changePriority(&priorityArray[cell2X][cell2Y], PRIOR_LOW, &highestPriority);
                    changePriority(&priorityArray[cell3X][cell3Y], PRIOR_LOW, &highestPriority);
                }
            }
        }
    }
    else{ //La cella 1 e' vuota
        if(isPlayerOrEnemy(cell2,player,enemy)){ //La cella 2 e' piena
            if(isPlayerOrEnemy(cell3,player,enemy)){ //La cella 3 e' piena
                if(cell2 == cell3){
                    if(isPlayer(cell2,player)){
                        changePriority(&priorityArray[cell1X][cell1Y], PRIOR_MAX, &highestPriority);
                    }
                    else{
                        changePriority(&priorityArray[cell1X][cell1Y], PRIOR_HIGH, &highestPriority);
                    }
                }
                else{ //Le celle piene sono diverse, mossa inutile.
                    changePriority(&priorityArray[cell1X][cell1Y], PRIOR_LOW, &highestPriority);
                }
            }
            else{ //Celle 1 e 3 vuote -- Cella 2 piena
                if(isPlayer(cell2,player)){
                    changePriority(&priorityArray[cell1X][cell1Y], PRIOR_MED, &highestPriority);
                    changePriority(&priorityArray[cell3X][cell3Y], PRIOR_MED, &highestPriority);
                }
                else{
                    changePriority(&priorityArray[cell1X][cell1Y], PRIOR_LOW, &highestPriority);
                    changePriority(&priorityArray[cell3X][cell3Y], PRIOR_LOW, &highestPriority);
                }
            }
        }
        else{ //Celle 1 e 2 vuote
            if(isPlayerOrEnemy(cell3,player,enemy)){ //Cella 3 piena
                if(isPlayer(cell3,player)){
                    changePriority(&priorityArray[cell2X][cell2Y], PRIOR_MED, &highestPriority);
                    changePriority(&priorityArray[cell1X][cell1Y], PRIOR_MED, &highestPriority);
                }
                else{
                    changePriority(&priorityArray[cell2X][cell2Y], PRIOR_LOW, &highestPriority);
                    changePriority(&priorityArray[cell1X][cell1Y], PRIOR_LOW, &highestPriority);
                }
            }
            else{ //Tutte le celle sono vuote
                changePriority(&priorityArray[cell1X][cell1Y], PRIOR_LOW, &highestPriority);
                changePriority(&priorityArray[cell2X][cell2Y], PRIOR_LOW, &highestPriority);
                changePriority(&priorityArray[cell3X][cell3Y], PRIOR_LOW, &highestPriority);
            }
        }
    }

    return highestPriority;
}

/*                                                  *\
**  Imposta le priorita' delle mosse su ogni riga   **
**  Da in return la priorita' piu' alta rilevata.   **
\*                                                  */

int checkRow(int gameBoard[BOARD_SIZE][BOARD_SIZE], int thisLineIndex, int player, int enemy, int priorityArray[BOARD_SIZE][BOARD_SIZE]){
    int highestPriority = 0;

    highestPriority = analyzeAndSetPriorities(gameBoard,priorityArray,player,enemy,0,thisLineIndex,1,0);

    return highestPriority;
}

/*                                                      *\
**  Uguale a checkRow, ma lavora sulle colonne          **
\*                                                      */

int checkColumn(int gameBoard[BOARD_SIZE][BOARD_SIZE], int thisColumnIndex, int player, int enemy, int priorityArray[BOARD_SIZE][BOARD_SIZE]){
    int highestPriority = 0;

    highestPriority = analyzeAndSetPriorities(gameBoard,priorityArray,player,enemy,thisColumnIndex,0,0,1);

    return highestPriority;
}

/*                                                                      *\
**  Uguale a checkRow, ma analizza entrambe le diagonali del quadrato   **
\*                                                                      */

int checkDiagonal(int gameBoard[BOARD_SIZE][BOARD_SIZE], int player, int enemy, int priorityArray[BOARD_SIZE][BOARD_SIZE]){
    int highestPriority = 0;

    /*                                  *\
    **      Diagonale [0,0] / [2,2]     **
    \*                                  */

    ifLesserReplace(&highestPriority, analyzeAndSetPriorities(gameBoard,priorityArray,player,enemy,0,0,1,1));

    /*                                  *\
    **      Diagonale [2,0] / [0,2]     **
    \*                                  */

    ifLesserReplace(&highestPriority, analyzeAndSetPriorities(gameBoard,priorityArray,player,enemy,2,0,-1,1));

    return highestPriority;
}

/*                                                                                                  *\
**  Individua la mossa migliore tramite il sistema di priorita' dato                                **
**  dalle funzioni check (row, column, diagonal).                                                   **
**  La mossa migliore e' quella dalla priorita' piu' alta.                                          **
**  Nel caso in cui piu' mosse abbiano la stessa priorita', ne viene scelta una a caso.             **
\*                                                                                                  */

int bestMove(int player, int gameBoard[BOARD_SIZE][BOARD_SIZE], int bestCell[2]){
    int mPriority[BOARD_SIZE][BOARD_SIZE];
    int i = 0, j = 0;
    int enemy;
    int highestPriority = 0;

    long rnd;   //Variabile per contenere il risultato della funzione rand()

    if(player == 1){
        enemy = 2;
    }
    else if(player == 2){
        enemy = 1;
    }

    emptyArray(mPriority);  //Inizializza l'array delle priorita' a 0 in ogni sua cella

    //I cicli controllano tutte le righe e colonne chiamando le funzioni checkRow e checkColumn

    for(i = 0; i < BOARD_SIZE; i++){
        ifLesserReplace(&highestPriority, checkRow(gameBoard, i, player, enemy, mPriority));

        for(j = 0; j < BOARD_SIZE; j++){
            ifLesserReplace(&highestPriority, checkColumn(gameBoard, j, player, enemy, mPriority));
        }
    }

    //Analisi delle diagonali tramite checkDiagonal

    ifLesserReplace(&highestPriority, checkDiagonal(gameBoard, player, enemy, mPriority));

    if(highestPriority >= 5){
        //Termina la partita
        return 5;
    }
    printf("Highest status: %d\n", highestPriority);

    //Inserisce in un array le mosse con priorita' massima

    int highestPriorityMoves[9];
    int highestPriorityMovesNumber = 0;


    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(mPriority[i][j] == highestPriority){
                /*La mossa e' memorizzata come un numero a 2 cifre
                  La prima cifra e' la x, la seconda la y           */
                highestPriorityMoves[highestPriorityMovesNumber] = (i * 10) + j;

                highestPriorityMovesNumber++;
            }/*Fine analisi mosse con priorita massima*/
        }
    }

    //Estrae un numero pseudo-randomico compreso fra 0 e il numero di mosse con priorita' piu' alta (escluso)

    rnd = rand() % highestPriorityMovesNumber;

    //Inizializza l'array contenete le coord. della mossa scelta

    //Se la mossa scelta e' un numero < 10 (ovvero la x era 0) imposta la x a 0, altrimenti la imposta come la prima cifra del numero
    (highestPriorityMoves[rnd] < 10) ? (bestCell[0] = 0) : (bestCell[0] = highestPriorityMoves[rnd] / 10);

    //Per la y invece, nel caso sia < 10 la y equivale al numero stesso, altrimenti equivale all'ultima cifra del numero
    (highestPriorityMoves[rnd] < 10) ? (bestCell[1] = highestPriorityMoves[rnd]) : (bestCell[1] = highestPriorityMoves[rnd] % 10);

    /*Fine analisi mossa migliore*/

    return 1;
}

/*                                                                                  *\
**  Utilizza la funzione bestMove per individuare la mossa migliore                 **
**  e la inserisce nell'array del campo di gioco.                                   **
**  Se la priorita' data in return da bestMove e' maggiore di 3 (fasulla)           **
**  ritorna -1 (segnale di terminazione della partita per vittoria di un giocatore) **
\*                                                                                  */

int elaborateMove(int gameBoard[BOARD_SIZE][BOARD_SIZE], int pc){
    int i, bestMv[2];

    if(bestMove(pc,gameBoard,bestMv) < 5){
        gameBoard[bestMv[0]][bestMv[1]] = pc;
    }
    else{
        return -1;
    }
}

/*                                                                          *\
**  Chiede al giocatore di inserire un numero compreso fra 0 e 8.           **
**  Il numero viene trasformato in coordinate del campo di gioco            **
**  e viene inserito nello stesso il simbolo corrispondente al giocatore    **
**  Se il numero inserito corrisponde a una casella gia' riempita, stampa   **
**  un messaggio e richiama se stessa.                                      **
**  Se il numero inserito e' -1, ritorna -1 (terminazione partita)          **
\*                                                                          */

int makeMove(int gameBoard[BOARD_SIZE][BOARD_SIZE], int player){
    int row, column, pos;

    printf("Scegli una casella (0-8): ");
    scanf("%d", &pos);

    if(pos < 3){
        row = 0;
        column = pos;
    }
    else if(pos >= 3 && pos < 6){
        row = 1;
        column = pos % 3;
    }
    else if(pos >= 6 && pos < 9){
        row = 2;
        column = pos % 3;
    }
    else if(pos >= 9 || pos < -1){
        printf("Il numero inserito non corrisponde ad una casella.\n");
        makeMove(gameBoard, player);
    }
    else if(pos == -1){
        return -1;
    }

    if(gameBoard[row][column] == 0){
        gameBoard[row][column] = player;
    }
    else{
        printf("La casella selezionata e' gia' piena. Inserire un\'altra casella.\n");
        makeMove(gameBoard, player);
    }
}

/*                                              *\
**  Analizza il campo di gioco.                 **
**  Se e' pieno (nessuna casella disponibile)   **
**  ritorna 1, altrimenti ritorna 0             **
\*                                              */

int gameBoardFull(int gameBoard[BOARD_SIZE][BOARD_SIZE]){
    int i,j;

    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            if(gameBoard[i][j] == 0){
                return 0;
            }
        }
    }

    return 1;
}

/*                                                          *\
**  Controlla la presenza di tris sul campo di gioco        **
**  tramite le funzioni check.                              **
**  Ritorna 1 (vittoria giocatore 1) se ottiene return 4    **
**  Ritorna 2 (vittoria giocatore 2) se ottiene return 5    **
**  Ritorna 0 (nessun vincitore) negli altri casi           **
\*                                                          */

int checkForWinner(int gameBoard[BOARD_SIZE][BOARD_SIZE]){
    int i, j;
    int priorityArray[BOARD_SIZE][BOARD_SIZE];

    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            if(checkRow(gameBoard, i, 2, 1, priorityArray) == 5 || checkColumn(gameBoard, j, 2, 1, priorityArray) == 5 || checkDiagonal(gameBoard,2,1,priorityArray) == 5){
                printf("Vittoria del giocatore 1! (O)\n\n");
                return 1;
            }
            else if(checkRow(gameBoard, i, 2, 1, priorityArray) == 6 || checkColumn(gameBoard, j, 2, 1, priorityArray) == 6 || checkDiagonal(gameBoard,2,1,priorityArray) == 6){
                printf("Vittoria del giocatore 2! (X)\n\n");
                return 2;
            }
        }
    }

    if(checkDiagonal(gameBoard, 2, 1, priorityArray) == 5){
        return 1;
    }
    else if(checkDiagonal(gameBoard, 2, 1, priorityArray) == 6){
        return 2;
    }

    return 0;
}

/*                                                          *\
**  Stampa una legenda dei numeri associati ad ogni casella **
**  del campo di gioco                                      **
\*                                                          */

int printInstructions(){
    int gameBoard[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};

    int i, j;
    printf(" --- --- ---\n");

    for(i=0; i < 3; i++){
        printf("|");
        for(j=0; j < 3; j++){
           printf("%3d", gameBoard[i][j]);
           printf("|");
        }
        printf("\n");
        printf(" --- --- ---\n");
    }
}

int gameBoard[BOARD_SIZE][BOARD_SIZE];
int player = 1, pc = 2;
int turn = 0;
int mod;
int moveResult;

int main(){
    //imposta il seme del random al tempo attuale. Necessario per la funzione rand()
    srand(time(0));

    /*                                                                                  *\
    **  Ciclo principale, chiede la modalita' di gioco e inizializza il ciclo di gioco  **
    **  Decide casualmente il giocatore iniziale.                                       **
    \*                                                                                  */

    do{
        emptyArray(gameBoard);
        printf("Seleziona modalita:\n 0 -- umano vs pc\n 1 -- umano vs umano\n 2 -- pc vs pc\n");
        scanf("%d", &mod);
        if(mod == -1){
            break;
        }

        if(rand() % 2 + 1 == 1){
            turn = 1;
            printf("Giocatore 2 inizia per primo.\n");
        }
        else{
            turn = 0;
            printf("Giocatore 1 inizia per primo.\n");
        }

        /*                                                                                      *\
        **  Ciclo di gioco. Inizia cercando un vincitore.                                       **
        **  In base alla modalita' selezionata e al turno, richiede un input al giocatore umano **
        **  o calcola le mosse dell'IA.                                                         **
        **  Stampa il campo da gioco e infine controlla se il e' pieno                          **
        \*                                                                                      */

        do{
            if(checkForWinner(gameBoard) == 1 || checkForWinner(gameBoard) == 2){
                break;
            }

            if(turn == 0 && pc == 2 || turn == 1 && pc == 1){
                printf("-------------------\n");
                (mod == 0 || mod == 2) ? printf("Turno del computer\n") : printf("Turno del giocatore 1\n");
                printf("-------------------\n");

                if(mod == 1) printInstructions();

                (mod == 0 || mod == 2) ? (moveResult = elaborateMove(gameBoard, pc)) : (moveResult = makeMove(gameBoard, pc));
            }
            else if(turn == 0 && player == 2 || turn == 1 && player == 1){

                printf("-------------------\n");
                (mod == 2) ? printf("Turno del computer\n") : printf("Turno del giocatore 2\n");
                printf("-------------------\n");

                printInstructions();

                (mod == 2) ? (moveResult = elaborateMove(gameBoard, player)) : (moveResult = makeMove(gameBoard, player));
            }

            if(moveResult != -1){
                if(turn == 0){
                    turn = 1;
                }
                else{
                    turn = 0;
                }
            }
            else{
                printf("Partita terminata.\n");
                turn = -1;
            }

            createTable(gameBoard);

            if(gameBoardFull(gameBoard) && turn != -1){
                checkForWinner(gameBoard);
                turn = -1;
            }
        }while(turn != -1);
        turn = 0;
    }while(mod != -1);

    getchar();
}
