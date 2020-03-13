//MyFunctions.cpp

#include <TCHAR.H> // Implicit or explicit include
#include <windows.h>
#include <tchar.h>
// Not necessary: (just for t_printf()..) #include <stdio.h>

#include <string>
#include <iostream>
#include <direct.h>
#include <fstream>		// myfile.is_open()
#include <windows.h>	// GetFullPathName() function

#include "fileManager.h"

#define BUFSIZE 4096
#define MAXPATHLEN 512

using namespace std;


/**************************FUNCIONS********************************/


//std::string get_working_path()
//{
//	char temp[MAXPATHLEN];
//	return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
//
//}//End Procedure


/**
 * Function to convert string to TCHAR* type.
*/
TCHAR* StringToTCHAROptimum( const std::string &myString )
{
	// string to TCHAR:
	//
	TCHAR *param = new TCHAR[ myString.size() + 1 ];
	param[myString.size()] = 0;

	//As much as we'd love to, we can't use memcpy() because
	//sizeof(TCHAR)==sizeof(char) may not be true:
	//
	std::copy( myString.begin(), myString.end(), param);

	return param;

}//End Procedure


/**
 * Function to convert TCHAR* to string type.
*/
std::string TCHARToStringOptimum( TCHAR* myTCHAR )
{
	wstring myWString(&myTCHAR[0]); //convert to wstring
	string myString(myWString.begin(), myWString.end()); //and convert to string.
	//
	return myString;

}//End Procedure


/**
 * Opens and then CLoses a File for Testing: does it exist?
 */
bool ValidateAlreadyOpenFileNotClosing( std::fstream &myfile )
{

	if (myfile.is_open())
	{

		//myfile << "\n";

		return true;

	}//End if (myfile.is_open())
	else
	{
		return false;

	}//End else

}//End Procedure


/**
 * Opens a File for Printing out the Games' results.
 */
bool OpenFileForWritingNotClosing( std::ofstream &myfile )
{

	if (myfile.is_open())
	{
		//myfile << "\n";

		return true;

	}//End if (myfile.is_open())
	else
	{
		cout << "\nI/O Error:   Unable to open file";

		return false;

	}//End else

}//End Procedure


/**
 * Opens a File for Printing out the Games' results.
 */
bool CloseFileForWriting( std::ofstream &myfile )
{	

	if (myfile.is_open())
	{
		myfile.close();

		return true;

	}//End if (myfile.is_open())
	else
	{
		cout << "\nUnable to Close file because it was not Opened... (in the first place)";

		return false;

	}//End else

}//End Procedure


/**
 * Function that searches for a file in a given PATH (input); and opens it.
 * If it does not exist, this algorithm creates it (a new File).
 */
bool OpenFileForWritingOrCreateIt( const std::string &fileName )
{
	/////char fileName[ ] = "Informacije.txt";
	fstream appendFileToWorkWith;

	// Open the File, as a test:
	//
	appendFileToWorkWith.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);

	// If file does not exist, Create new file
	//
	if ( !appendFileToWorkWith )
	{
		cout << "\n->\nCannot open file, file does not exist. Creating new file........";

		appendFileToWorkWith.open(fileName,  fstream::in | fstream::out | fstream::trunc);
		appendFileToWorkWith <<"\n" << "\n->\nCannot open file, file does not exist. Creating new file........";

		// Last Test, to see if the File was created:
		// Open the File, as a test:
		//
		if ( ValidateAlreadyOpenFileNotClosing( appendFileToWorkWith ) )
		{

			// Close it:
			//
			appendFileToWorkWith.close();

			return true;
		}
		else
		{
			// Close it:
			//
			appendFileToWorkWith.close();

			return false;

		}//End else
	}
	else
	{
		// Use existing file
		//
		cout<<"\nSuccess in creating / opening file.\n ' "<< fileName <<" '... has been found.\n";
		cout<<"\nAppending writing and working with existing file."<<"\n---\n";
		//appendFileToWorkWith << "Appending writing and working with existing file."<<"\n---\n";
		//
		// Close it:
		//
		appendFileToWorkWith.close();
		cout<<"\n";

	}//End Else

	return true;

}//End Function


/**
 * Function that searches for a file in a given PATH (input); and returns the FULL: 'DRIVELeter://...PATH/NAME.extension'
 * NOTEs
 ***1- If the given parameter (fileName) does not exist in Drive, it will return the Current Log Directory Path used.
 ***2- If GetFullPathName returns an error, this function will return an empty: const string: ""
 */
const std::string GetFullCurrentFullPathName( const std::string &fileName )
{

	// Convert File Name from String to TCHAR:
	//
	TCHAR *myFilePathAsTCHAR = StringToTCHAROptimum( fileName );

    DWORD  retval=0;
    BOOL   success; 
    TCHAR  buffer[BUFSIZE]=TEXT(""); 
    TCHAR  buf[BUFSIZE]=TEXT(""); 
    TCHAR** lppPart={NULL};


	// Retrieve the full path name for a file. 
	// The file does not need to exist.
	//
    retval = GetFullPathName( myFilePathAsTCHAR,
                 BUFSIZE,
                 buffer,
                 lppPart );
    
    if (retval == 0)
    {
        // Handle an error condition.
		//
        printf ("\nGetFullPathName failed (%d)\n", GetLastError());

		return "";
    }
    else 
    {
		// Success.
		//
        //_tprintf(TEXT("\nThe full path name is:  %s\n"), buffer);

        //if (lppPart != NULL && *lppPart != 0)
        //{
        //    _tprintf(TEXT("The final component in the path name is:  %s\n"), *lppPart);
        //}

		// Return the string / Full Path Name of the File:
		//
		return TCHARToStringOptimum( buffer );

    }//End else of if (retval == 0)

}//End Function
