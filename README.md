# Bamtang_Games_GameDev_Q_3_TIC_TAC_TOE_(MICHI)_C++
Algorithm (written in C++) that prints a list (in a text file) of all possible Tic-Tac-Toe moves - My Answer to the Bamtang Games' [Game Programmer Exam (originally published in 2018)](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf):

## Question number 3.
## 3. MICHI

[Spanish original Question:]

###### Imprime una lista (en un archivo de texto) de todas las jugadas posibles de Tic-Tac-Toe (Michi) ordenadas de la siguiente manera:

<pre>  N    X 0 X 0 X 0 X 0 X Win
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
</pre>

  Donde la primera columna es el número de la jugada y las siguientes nueve columnas son las jugadas realizadas por el jugador X y O consecutivamente. El dígito cero indica que no se realizó ninguna jugada en ese turno (pues el juego concluyó antes) y un dígito del 1-9 indica que se ha realizado la jugada en la posición definida por el siguiente tablero numerado:

<pre>
-------------
| 1 | 2 | 3 |  
-------------
| 4 | 5 | 6 |  
-------------
| 7 | 8 | 9 |  
-------------
</pre>

##### Tu función debe imprimir además en la columna final el resultado de la partida:
  
##### (X: cuando X gane, O: cuando O gane, E: empate).

#### Implementar la función: listAllTicTacToeGames( fileName )

<strong> (6 PUNTOS) </strong>

*******************************************************************************

#### Notes:
#### 1- This source code was written in <strong> Visual Studio C++ 2010 </strong> (IDE), to build an executable file.

#### 2- [Game Programmer Exam Questions (originally published in 2018)](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf).

#### 3- [Bamtang Games' current Game Programmer Exam, as reference](https://www.bamtang.com/jobs/game-programmer).

*******************************************************************************
Source Code By:	 Alejandro E. Almarza Martín
*******************************************************************************


MIT License

Copyright (c) 2020 AlMartson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
