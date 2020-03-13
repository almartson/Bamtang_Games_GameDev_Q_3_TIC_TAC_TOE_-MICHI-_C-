/******************************************************************************
  Bamtang Games Entrance Test.

  Question number 3.

  3. MICHI

  [Spanish original Question:]

  Imprime una lista (en un archivo de texto) de todas las jugadas posibles de tictac-
toe (michi) ordenadas de la siguiente manera:

  N    X 0 X 0 X 0 X 0 X Win
000001 1 2 3 4 5 6 7 0 0 X
000002 1 2 3 4 5 6 8 7 9 X
000003 1 2 3 4 5 6 8 9 7 X
000004 1 2 3 4 5 6 9 0 0 X
000005 1 2 3 4 5 7 6 8 9 X
000006 1 2 3 4 5 7 6 9 8 E
...
255165 9 8 7 6 5 4 1 0 0 X
255166 9 8 7 6 5 4 2 1 3 X
255167 9 8 7 6 5 4 2 3 1 X
255168 9 8 7 6 5 4 3 0 0 X


  Donde la primera columna es el número de la jugada y las siguientes nueve
columnas son las jugadas realizadas por el jugador X y O consecutivamente. El
dígito cero indica que no se realizó ninguna jugada en ese turno (pues el juego
concluyó antes) y un dígito del 1-9 indica que se ha realizado la jugada en la
posición definida por el siguiente tablero numerado:
-------------
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------

  Tu función debe imprimir además en la columna final el resultado de la
partida:
(X: cuando X gane, O: cuando O gane, E: empate).
Implementar la función: listAllTicTacToeGames( fileName )
(6 PUNTOS)

*******************************************************************************
   By:	 Alejandro E. Almarza Martín
*******************************************************************************
*******************************************************************************/

#include <TCHAR.H> // Implicit or explicit include
#include <string>
#include <iostream>
#include <iomanip>      // std::setfill, std::setw

#include <direct.h>
#include <fstream>	

#include "fileManager.h"

using namespace std;


/********************** Global variables **********************/

/**
 * Size oof the Array to: store the moves order.
 */
const int _MY_MOVES_ORDER_ARRAY_SIZE = 10;


/********************** CONSTANTS **********************/
//
// Global variables to all Scripts (#define has a HIGHER scope than 'const'):

/**
 * Player CHAR:  'O'
 */
#define _MY_PLAYER_O 'O'

/**
 * Player CHAR:  'X'
 */
#define _MY_PLAYER_X 'X'


/**
 * Board Size specifications.
 */
#define _ROWS_TOTAL_COUNT 3  // 3
#define _COLUMNS_TOTAL_COUNT 3  // 3
//
#define _TOP_ROW 2  // 2
#define _TOP_COLUMN 2  // 2

/********************** VARIABLES **********************/

int nWinO = 0, nWinX = 0, nDraw = 0;

/**
 * Array which symbolices the Board.
**/
char _myArrayOfMichiBoardRowsColumns0to2[ _ROWS_TOTAL_COUNT ][ _COLUMNS_TOTAL_COUNT ];


/********************** Funcions and Procedures Prototypes **********************/


/**
 * Initializes a One-Dimension Array.
**/
void InitializeOneDimensionArrayInt10( int (&array)[_MY_MOVES_ORDER_ARRAY_SIZE] )
{

	// Rows:
	//
	for (int i = 0; i < _MY_MOVES_ORDER_ARRAY_SIZE; i++)
	{

		array[i] = 0; 	// '\0';

	}//End for 1 Rows

}//End Procedure


/**
/ * Initializes a One-Dimension Array.
**/
void InitializeOneDimensionArrayChar10( char (&array)[_MY_MOVES_ORDER_ARRAY_SIZE] )
{

	// Rows:
	//
	for (int i = 0; i < _MY_MOVES_ORDER_ARRAY_SIZE; i++)
	{

		array[i] = '0';	 // '\0';

	}//End for 1 Rows

}//End Procedure


/**
/ * Initializes a One-Dimension Array.
**/
void InitializeOneDimensionArrayInt3( int (&array)[_ROWS_TOTAL_COUNT] )
{

	// Rows:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT ; i++)
	{

		array[i] = 0;	 // '\0';

	}//End for 1 Rows

}//End Procedure



/**
 * Initializes a Two-Dimension Array.
**/
void InitializeTwoDimensionArray( char (&array)[ _ROWS_TOTAL_COUNT ][ _COLUMNS_TOTAL_COUNT ] )
{

	// Rows:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT ; i++)
	{

		// Go throught each Column:
		//
		for (int j = 0; j < _COLUMNS_TOTAL_COUNT ; j++)
		{

			array[i][j] = '0'; 	 // '\0';

		}//End for 2 Columns

	}//End for 1 Rows

}//End Procedure


/**PROCEDURES FOR POSITIONING CHARACTERS ON THE BOARD**********************************/



/**
/ * Returns True if the Board is FULL (and we already checked to see if anybody won): It would be a TIE.
**/
bool Draw( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT] )
{

	// Rows:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT ; i++)
	{

		// Go throught each Column: There MUST be a Full Line formed
		//
		for (int j = 0; j < _COLUMNS_TOTAL_COUNT ; j++)
		{

			// Termination:
			//
			if ( board[i][j] == '0'	 /*'\0'*/ )
			{

				// There is an empty space, to be filled!
				//
				return false;

			}//End if ( thisFullLineIsTheWinner )

		}//End for 2 Columns

	}//End for 1 Rows

	// Termination:
	// If this did not ended yet: it means that the board is FULL, it is a TIE.
	//
	return true;

}//End Procedure


/**
/ * Returns True if a DIAGONAL Line is formed by the Player ('O' or 'X').
 ** This Diagonal Lines go from: UpLeft -> To -> DownRight
**/
bool WinByUpLeftToDownRightDiagonalLine( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &player )
{
	// Declare and Initialize the Flag.
	//
	bool thisFullLineIsTheWinner = true;

	// Go throught the Diagonal Line: There MUST be a Full Line formed:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT ; i++)
	{

		thisFullLineIsTheWinner = thisFullLineIsTheWinner && ( board[i][ _TOP_ROW - i] == player );

	}//End for

	// Termination:
	//
	if ( thisFullLineIsTheWinner )
	{
		
		return true;

	}//End if ( thisFullLineIsTheWinner )
	else
	{
		return false;

	}//End else of if ( thisFullLineIsTheWinner )

}//End Procedure


/**
/ * Returns True if a DIAGONAL Line is formed by the Player ('O' or 'X').
 ** This Diagonal Lines go from: DownLeft -> To -> UpRight
**/
bool WinByDownLeftToUpRightDiagonalLine( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &player )
{
	// Declare and Initialize the Flag.
	//
	bool thisFullLineIsTheWinner = true;

	// Go throught the Diagonal Line: There MUST be a Full Line formed:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT; i++)
	{

		thisFullLineIsTheWinner = thisFullLineIsTheWinner && ( board[i][i] == player );

	}//End for

	// Termination:
	//
	if ( thisFullLineIsTheWinner )
	{

		return true;

	}//End if ( thisFullLineIsTheWinner )
	else
	{
		return false;

	}//End else of if ( thisFullLineIsTheWinner )

}//End Procedure


/**
/ * Returns True if a HORIZONTAL Line is formed by the Player ('O' or 'X')
**/
bool WinByVerticalLine( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &player )
{

	bool thisFullLineIsTheWinner = false;

	// Columns:
	//
	for (int j = 0; j < _COLUMNS_TOTAL_COUNT; j++)
	{
		// Initialize the Flag.
		//
		thisFullLineIsTheWinner = true;

		// Go throught each Row: There MUST be a Full Line formed:
		//
		for (int i = 0; i < _ROWS_TOTAL_COUNT; i++)
		{

			thisFullLineIsTheWinner = thisFullLineIsTheWinner && ( board[i][j] == player );

		}//End for 2 Columns

		// Termination:
		//
		if ( thisFullLineIsTheWinner )
		{

			return true;

		}//End if ( thisFullLineIsTheWinner )

	}//End for 1 Rows

	// Termination:
	// If this did not ended yet: it means that there is no Line.
	//
	return false;

}//End Procedure


/**
/ * Returns True if a HORIZONTAL Line is formed by the Player ('O' or 'X')
**/
bool WinByHorizontalLine( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &player )
{

	bool thisFullLineIsTheWinner = false;

	// Rows:
	//
	for (int i = 0; i < _ROWS_TOTAL_COUNT ; i++)
	{
		// Initialize the Flag.
		//
		thisFullLineIsTheWinner = true;

		// Go throught each Column: There MUST be a Full Line formed
		//
		for (int j = 0; j < _COLUMNS_TOTAL_COUNT ; j++)
		{

			thisFullLineIsTheWinner = thisFullLineIsTheWinner && ( board[i][j] == player );

		}//End for 2 Columns

		// Termination:
		//
		if ( thisFullLineIsTheWinner )
		{

			return true;

		}//End if ( thisFullLineIsTheWinner )

	}//End for 1 Rows

	// Termination:
	// If this did not ended yet: it means that there is no Line.
	//
	return false;

}//End Procedure


/**
/ * Returns True if a Lines is formed by the Player ('O' or 'X')
**/
bool Win( const char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &player )
{

	//// Delete or Comment this Line, just for Debugging purposes:
	////
	//bool answerDebug = ( WinByHorizontalLine( board, player ) 
	//	||		WinByVerticalLine( board, player ) 
	//	||		WinByUpLeftToDownRightDiagonalLine( board, player )
	//	||		WinByDownLeftToUpRightDiagonalLine( board, player )
	//);
	//return answerDebug;


	return (	WinByHorizontalLine( board, player ) 
		||		WinByVerticalLine( board, player ) 
		||		WinByUpLeftToDownRightDiagonalLine( board, player )
		||		WinByDownLeftToUpRightDiagonalLine( board, player )
	);

}//End Procedure


/**
 * Toggle Player
**/
void TogglePlayerName( char &toMove )
{
	if ( toMove == _MY_PLAYER_O )
	{

		toMove = _MY_PLAYER_X;

	}
	else
	{

		toMove = _MY_PLAYER_O;

	}//End else

}//End Procedure


/**
 * Toggle Player
**/
char TogglePlayerName( const char &toMove )
{

	if ( toMove == _MY_PLAYER_O )
	{

		return _MY_PLAYER_X;

	}
	else
	{

		return _MY_PLAYER_O;

	}//End else

}//End Procedure					


/**
 * Draws the Header of the Board.
**/
void DrawBoardHeader()
{

	std::cout << "  N    X 0 X 0 X 0 X 0 X Win\n";

}//End Procedure


/**
 * Draws the Header of the Board.
**/
void DrawBoardHeader( ofstream &myfile )
{

	myfile << "  N    X 0 X 0 X 0 X 0 X Win\n";

}//End Procedure


/**
 * Draws the RESULT of a GAME in a Line.
**/
void DrawBoardFullWinLoseLine( ofstream &myfile, const int myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ], const char myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ], const int &numberOfGamesPlayedUntilNow )
{

	// Print:
	// 1- Game #
	//
	myfile << std::setw(6) << std::setfill('0') << numberOfGamesPlayedUntilNow << " ";
	//
	// 2- All Moves Horizontally, in a Line. It assumes THE GAME STARTED WITH player = 'X'. *********-<<<<<<<<--------
	//
	for (int i = 1; i < _MY_MOVES_ORDER_ARRAY_SIZE; i++)
	{

		// Print Position or Move, Starting from 'X':
		//
		myfile << myArrayMoveBoardPositions[ i ] << " ";

	}//End for
	//
	// 3- Print WHO WINS?:
	//
	myfile << myArrayPlayerWhoMoved[ 0 ] << "\n";

}//End Procedure



/**
 * Draws the RESULT of a GAME in a Line.
**/
void DrawBoardFullWinLoseLine( const int myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ], const char myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ], const int &numberOfGamesPlayedUntilNow )
{

	// Print:
	// 1- Game #
	//
	std::cout << std::setw(6) << std::setfill('0') << numberOfGamesPlayedUntilNow << " ";
	//
	// 2- All Moves Horizontally, in a Line. It assumes THE GAME STARTED WITH player = 'X'. *********-<<<<<<<<--------
	//
	for (int i = 1; i < _MY_MOVES_ORDER_ARRAY_SIZE; i++)
	{

		// Print Position or Move, Starting from 'X':
		//
		std::cout << myArrayMoveBoardPositions[ i ] << " ";

	}//End for
	//
	// 3- Print WHO WINS?:
	//
	std::cout << myArrayPlayerWhoMoved[ 0 ] << "\n";

}//End Procedure


/**
 * Calculates the necessary values to Print WHO WON the Game.
**/
void CalculateFullWinLoseLine( int myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ], char myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ], int &numberOfGamesPlayedUntilNow, const int &myLastMoveNumber, const char &myGameWinnernumberOfGamesPlayedUntilNow, const int &numberOfGamesPlayed )
{

	// Store in the ->'Order of Move'<-, and the 'Player' who did it.
	//
	myArrayMoveBoardPositions[ 0 ] = myLastMoveNumber;
	//
	// Store in the 'Order of Move', and the ->'Player'<- who did it.
	//
	myArrayPlayerWhoMoved[ 0 ] = myGameWinnernumberOfGamesPlayedUntilNow;
	//
	// Calculate the number of GAMES Played so far...
	//
	numberOfGamesPlayedUntilNow = numberOfGamesPlayed;

}//End Procedure


/**
 * It Prints to Console the Board Layout.
 */
void PrintBoardLayoutConsole()
{
    string myBoardLayout = "     |     |     \n";
    myBoardLayout += "  1  |  2  |  3  \n";
    myBoardLayout += "_____|_____|_____\n";
    myBoardLayout += "     |     |     \n";
    myBoardLayout += "  4  |  5  |  6  \n";
    myBoardLayout += "_____|_____|_____\n";
    myBoardLayout += "     |     |     \n";
    myBoardLayout += "  7  |  8  |  9  \n";
    myBoardLayout += "     |     |     \n\n";

	std::cout << myBoardLayout;

}//End Procedure


/**
* Prototype of: Answer to the Test, Question number 3: MICHI.
* Drawback: It Prints to Console, not to Text File.
* It will be replaced by a better one, see below.
*/
void CalculateAllTicTacToeGamesPrintToConsole( char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &toMove,  int myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ], char myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ], const int &moveNumber )
{

	// Algorithm:
	//
	if ( Win( board, _MY_PLAYER_O ) )
	{

		// WinO + 1
		//
		nWinO++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		// Calculate the number of GAMES Played so far...
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), _MY_PLAYER_O, (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End if ( Win( board, 'O' ) )
	else if ( Win( board, _MY_PLAYER_X ) )
	{

		// Win X + 1
		//
		nWinX++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), _MY_PLAYER_X, (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End if ( Win( board, 'X' ) )
	else if ( Draw( board ) )
	{
		// Another TIE +1:
		//
		nDraw++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), 'E', (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End else
	else
	{
		// Playing PROCESS:
		//
		for (int i = 0; i < _ROWS_TOTAL_COUNT; i++)
		{

			for (int j = 0; j < _COLUMNS_TOTAL_COUNT; j++)
			{

				if ( board[i][j] == '0' /*'\0'*/ )	// /*(char) 0 */
				{

					// Play one move:
					//
					board[i][j] = toMove;
					//
					// Store in the ->'Order of Move'<-, and the 'Player' who did it.
					//
					myArrayMoveBoardPositions[ moveNumber ] = ( (i * _COLUMNS_TOTAL_COUNT) + (j + 1) );
					//
					// Store in the 'Order of Move', and the ->'Player'<- who did it.
					//
					myArrayPlayerWhoMoved[ moveNumber ] = toMove;
					//
					// Update Move Number
					//
					//moveNumber++;


					// Call again the Recursive Function: now with the player TOGGLED ('X' <-> 'O' (_MY_PLAYER_O) )
					//
					// TogglePlayerName( toMove );
					CalculateAllTicTacToeGamesPrintToConsole(board, TogglePlayerName( toMove ), myArrayMoveBoardPositions, myArrayPlayerWhoMoved, (moveNumber + 1) );
					//
					// After the Move, a new Recursive instance of the Board Game is being played in a Parallel Universe :)
					//...then: We must UNDO the Move; and pass to the Next [Row][Column].
					//...There is no need to change the Board in this particular instance, only in the Recursive called one.
					//...Another reason for not changing the Board in this "if": Board is Local, but has a High Scope to the "CalculateAllTicTacToeGamesPrintToConsoleGames(board, 'X' o.... 'O');", SO if we change it here: It WILL CHANGE inside the rest of the calls too (we do not want that, otherwise we couln't get the full Permutative Output).
					//
					// Conclusion: Undoing everything, to go to the next Iteration of this 2 For's:
					//
					board[i][j] = '0';	 // '\0';		// /*(char) 0 */
					//
					// UN-Store in the ->'Order of Move'<-, and the 'Player' who did it.
					//
					myArrayMoveBoardPositions[ moveNumber ] = 0;
					//
					// UN-Store in the 'Order of Move', and the ->'Player'<- who did it.
					//
					myArrayPlayerWhoMoved[ moveNumber ] = '0';

				}//End if ( board[i][j] == '\0' )

			}//End for 2

		}//End for 1
	
	}//End else

}//End Procedure


/**
* Answer to the Test, Question number 3: MICHI  (a.k.a.: TIC TAC TOE).
* It handles the process of writing the Output to a Text File.
*/
void CalculateAllTicTacToeGamesInATextFile( ofstream &myfile, char board[_ROWS_TOTAL_COUNT][_COLUMNS_TOTAL_COUNT], const char &toMove,  int myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ], char myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ], const int &moveNumber )
{

	// Algorithm:
	//
	if ( Win( board, _MY_PLAYER_O ) )
	{

		// WinO + 1
		//
		nWinO++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		// Calculate the number of GAMES Played so far...
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), _MY_PLAYER_O, (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myfile, myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End if ( Win( board, 'O' ) )
	else if ( Win( board, _MY_PLAYER_X ) )
	{

		// Win X + 1
		//
		nWinX++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), _MY_PLAYER_X, (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myfile, myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End if ( Win( board, 'X' ) )
	else if ( Draw( board ) )
	{
		// Another TIE +1:
		//
		nDraw++;


		// Update STATS for knowing who the LOSER is: Store in the ->'Order of Move'<-, and the 'Player' who did it: Winning. In Position = ZERO.
		//
		int numberOfGamesPlayedUntilNow = 0;
		//(nWinO + nWinX + nDraw)
		//
		CalculateFullWinLoseLine( myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow, ( moveNumber - 1 ), 'E', (nWinO + nWinX + nDraw) );


		// Print the Whole BOARD
		//
		DrawBoardFullWinLoseLine( myfile, myArrayMoveBoardPositions, myArrayPlayerWhoMoved, numberOfGamesPlayedUntilNow );

		return;

	}//End else
	else
	{
		// Playing PROCESS:
		//
		for (int i = 0; i < _ROWS_TOTAL_COUNT; i++)
		{

			for (int j = 0; j < _COLUMNS_TOTAL_COUNT; j++)
			{

				if ( board[i][j] == '0' /*'\0'*/ )	// /*(char) 0 */
				{

					// Play one move:
					//
					board[i][j] = toMove;
					//
					// Store in the ->'Order of Move'<-, and the 'Player' who did it.
					//
					myArrayMoveBoardPositions[ moveNumber ] = ( (i * _COLUMNS_TOTAL_COUNT) + (j + 1) );
					//
					// Store in the 'Order of Move', and the ->'Player'<- who did it.
					//
					myArrayPlayerWhoMoved[ moveNumber ] = toMove;
					//
					// Update Move Number
					//
					//moveNumber++;


					// Call again the Recursive Function: now with the player TOGGLED ('X' <-> 'O' (_MY_PLAYER_O) )
					//
					// TogglePlayerName( toMove );
					CalculateAllTicTacToeGamesInATextFile( myfile, board, TogglePlayerName( toMove ), myArrayMoveBoardPositions, myArrayPlayerWhoMoved, (moveNumber + 1) );
					//
					// After the Move, a new Recursive instance of the Board Game is being played in a Parallel Universe :)
					//...then: We must UNDO the Move; and pass to the Next [Row][Column].
					//...There is no need to change the Board in this particular instance, only in the Recursive called one.
					//...Another reason for not changing the Board in this "if": Board is Local, but has a High Scope to the "CalculateAllTicTacToeGamesPrintToConsoleGames(board, 'X' o.... 'O');", SO if we change it here: It WILL CHANGE inside the rest of the calls too (we do not want that, otherwise we couln't get the full Permutative Output).
					//
					// Conclusion: Undoing everything, to go to the next Iteration of this 2 For's:
					//
					board[i][j] = '0';	 // '\0';		// /*(char) 0 */
					//
					// UN-Store in the ->'Order of Move'<-, and the 'Player' who did it.
					//
					myArrayMoveBoardPositions[ moveNumber ] = 0;
					//
					// UN-Store in the 'Order of Move', and the ->'Player'<- who did it.
					//
					myArrayPlayerWhoMoved[ moveNumber ] = '0';

				}//End if ( board[i][j] == '\0' )

			}//End for 2

		}//End for 1
	
	}//End else

}//End Procedure



/**
* Deprecated: Answer to the Test, Question number 3: MICHI  (a.k.a.: TIC TAC TOE).
* Deprecation reason: The original Challenge is to write a Functin that takes the FileName as an String (type) Input.
 * See an optimized Function down Below.
*/
void ListAllTicTacToeGames( ofstream &fileName )
{

	// Necessary Variables:
	//
	char player = _MY_PLAYER_X;

	//// Draw Header of Board:
	////
	//DrawBoardHeader( fileName );

	// _myArrayMoveBoardPositions	:	Board POSITIONS. It will store the ORDER of MOVES in the Game.	[ 7 1 2 3 4 5]
	//
	int _myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ];
	//
	// Initialization:
	//
	InitializeOneDimensionArrayInt10( _myArrayMoveBoardPositions );
	//
	// _myArrayPlayerWhoMoved	:	Name of the Player who made every move.	[ X X O X O X O ]
	//
	char _myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ];
	//
	// Initialization:
	//
	InitializeOneDimensionArrayChar10( _myArrayPlayerWhoMoved );
	//
	// Mover Number: For easy Reference:
	//
	int _myMoverOrder = 1;
	//
	// Initilize Main Board-Array:
	//
	InitializeTwoDimensionArray( _myArrayOfMichiBoardRowsColumns0to2 );

	// This is the ANSWER TO QUESTION # 3:
	//
	CalculateAllTicTacToeGamesInATextFile( fileName, _myArrayOfMichiBoardRowsColumns0to2, player, _myArrayMoveBoardPositions, _myArrayPlayerWhoMoved, _myMoverOrder );

}//End Procedure


/**
* (Final) Answer to the Test, Question number 3: MICHI  (a.k.a.: TIC TAC TOE).
*/
void ListAllTicTacToeGames( const string &fileName )
{

	// Validation: Try to Open an Existing file; or CREATE it if it does ot exist:
	//
	bool tryToWriteToFile = OpenFileForWritingOrCreateIt( fileName );

	// Flag Variable to know if the opening file process was successful in the end.
	//...if it was not: The Output will be displayed on the CMD Console:
	//
	bool printFullOutputToConsole = false;

	/***********************************/

	// Variables Initialization:

	// Necessary Variables:
	//
	char player = _MY_PLAYER_X;

	// _myArrayMoveBoardPositions	:	Board POSITIONS. It will store the ORDER of MOVES in the Game.	[ 7 1 2 3 4 5]
	//
	int _myArrayMoveBoardPositions[ _MY_MOVES_ORDER_ARRAY_SIZE ];
	//
	// Initialization:
	//
	InitializeOneDimensionArrayInt10( _myArrayMoveBoardPositions );
	//
	// _myArrayPlayerWhoMoved	:	Name of the Player who made every move.	[ X X O X O X O ]
	//
	char _myArrayPlayerWhoMoved[ _MY_MOVES_ORDER_ARRAY_SIZE ];
	//
	// Initialization:
	//
	InitializeOneDimensionArrayChar10( _myArrayPlayerWhoMoved );
	//
	// Moves Number: For easy Reference:
	//
	int _myMovesOrder = 1;
	//
	// Initilize Main Board-Array:
	//
	InitializeTwoDimensionArray( _myArrayOfMichiBoardRowsColumns0to2 );

	/***********************************/

	// Check to see if we can Open, Create a FIle... or not.
	//
	if ( tryToWriteToFile )
	{

		// Declare & Initialize: File Object
		//
		ofstream myfile ( fileName );
		//
		// Validation:
		//
		if ( OpenFileForWritingNotClosing( myfile ) )
		{

			// Tell the player where the File will be saved:
			//
			std::cout << "\nNOTES:\n\n1- The File will be created (if it does not currently exist) and saved in this\nPath:\n->\n" <<  GetFullCurrentFullPathName( fileName ) << std::endl;
			std::cout << "\n2- You may check the 'Tic Tac Toe' (a.k.a. 'Michi') game results and variants in the text file specified before.\n";
			//
			std::cout << "\n3- Please be patient, and wait a minute until the process is finished.................\n";

			// Draw Header of Board:
			//
			DrawBoardHeader( myfile );

			// This is the ANSWER TO QUESTION # 3:
			//
			CalculateAllTicTacToeGamesInATextFile( myfile, _myArrayOfMichiBoardRowsColumns0to2, player, _myArrayMoveBoardPositions, _myArrayPlayerWhoMoved, _myMovesOrder );
			//
			// Print to Console some feedback:
			//
			std::cout << "\n\n***************************************\n\nThere are [ " << (nWinO+nWinX+nDraw) << " ]\npossible games (excluding symmetry), of which \n  * O wins " << nWinO << "\n  * X wins " << nWinX << "\n  * and " << nDraw << " are drawn.";


			// Close the Text File:
			//
			CloseFileForWriting( myfile );

		}//End if
		else 
		{
			// Could not open file:
			//
			printFullOutputToConsole = true;
			std::cout <<"\n" << "\n->\nCannot open file, file does not exist.\nThere is an I/O issue........";

		}//End else

	}
	else
	{
		// IT COULD NOT CREATE THE FILE.
		//
		printFullOutputToConsole = true;
		std::cout <<"\n" << "\n->\nCannot Create the file.\nThere is an I/O issue........";

	}//End else


	// Last correction: if the file could not be opened: Print the Results to the Console:
	//
	if (printFullOutputToConsole)
	{

		/********************************/

		// Variables reinitialization:
		// Necessary Variables:
		//
		nWinO = 0, nWinX = 0, nDraw = 0;
		//
		player = _MY_PLAYER_X;

		// _myArrayMoveBoardPositions	:	Board POSITIONS. It will store the ORDER of MOVES in the Game.	[ 7 1 2 3 4 5]
		//
		// Initialization:
		//
		InitializeOneDimensionArrayInt10( _myArrayMoveBoardPositions );
		//
		// _myArrayPlayerWhoMoved	:	Name of the Player who made every move.	[ X X O X O X O ]
		//
		// Initialization:
		//
		InitializeOneDimensionArrayChar10( _myArrayPlayerWhoMoved );
		//
		// Moves Number: For easy Reference:
		//
		_myMovesOrder = 1;
		//
		// Initilize Main Board-Array:
		//
		InitializeTwoDimensionArray( _myArrayOfMichiBoardRowsColumns0to2 );

		/********************************/

		std::cout << "\n";

		// Draw Header of Board:
		//
		DrawBoardHeader();

		// This is the ANSWER TO QUESTION # 3:
		//		
		CalculateAllTicTacToeGamesPrintToConsole( _myArrayOfMichiBoardRowsColumns0to2, player, _myArrayMoveBoardPositions, _myArrayPlayerWhoMoved, _myMovesOrder );
		//
		// Print to Console some feedback:
		//
		std::cout << "\n\n***************************************\n\nThere are [ " << (nWinO+nWinX+nDraw) << " ]\npossible games (excluding symmetry), of which \n  * O wins " << nWinO << "\n  * X wins " << nWinX << "\n  * and " << nDraw << " are drawn.";


		// Tell the player WHAT IS COMMING ON:
		//
		std::cout << "\nNOTE:\n\n* The File could not be created (there was an I/O Error, please read further, up above).\nFor that reason the Output will be displayed in this Console / CMD.\n";

	}//End if (printFullOutputToConsole)
	//else {}

}//End Procedure



int main()
{
	// Get INPUT from Keyboard:
	//
	std::cout << "\n***************************************\nBy: Alejandro E. Almarza Martin";
	std::cout << "\n***************************************\n\n";
	std::cout << "Bamtang Games Entrance Test:\nANSWER TO THE C++ GAME DEV EXAM QUESTION: __3__ MICHI.\n\n";
	std::cout << "OBSERVATION: The INPUT String is HARDCODED, meaning that It is inside the Script: main.cpp.\n";
	std::cout << "\n05/03/2020\n\n***************************************\n";
	std::cout << "\nVerbose OUTPUT:\n";

	// Name of the File to Write the Output to:
	//
	const string fileName = "ListAllTicTacToeGames.txt";

	//// Main Procedure call: Solution to the Question asked:
	////
	ListAllTicTacToeGames( fileName );

	// Pause Console:
	//
	std::cout << "\n\n***************************************\n\nBy: Alejandro E. Almarza Martin\n\n";
	std::cout << "\nPress the <ENTER> key to Terminate the Program.";
	// Pause:
	//
	cin.get();

	return 0;

}//End main
