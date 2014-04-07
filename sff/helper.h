tstring GetLastErrorString(DWORD dwErrorNo, BOOL* pSeikou = NULL);
std::string getStdString(System::String^ s);
std::wstring getStdWstring(System::String^ s);
void ExceptionMessageBox(System::Exception^ ex);