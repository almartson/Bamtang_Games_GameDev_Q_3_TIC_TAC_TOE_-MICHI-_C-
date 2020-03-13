////.h
// Headers

//std::string get_working_path();
std::string TCHARToStringOptimum( TCHAR* myTCHAR );
TCHAR* StringToTCHAROptimum( const std::string &myString );

bool ValidateAlreadyOpenFileNotClosing( std::fstream &myfile );
bool OpenFileForWritingNotClosing( std::ofstream &myfile );
bool CloseFileForWriting( std::ofstream &myfile );

bool OpenFileForWritingOrCreateIt( const std::string &fileName );
const std::string GetFullCurrentFullPathName( const std::string &fileName );
