#ifndef FILE_H
#define FILE_H

#ifdef __cplusplus
extern "C" {
#endif
	typedef enum
	{
		FILE_CREATION_SUCCESS_CODE,
		FILE_CREATION_FAILED_CODE
	}File_Creation_Code;

#define FILE_NAME_LENGTH 256
#define TXT_FORMAT ".txt"
#define CSV_FORMAT ".csv"

	sint32_t C_FileCreation(uint8_t);
	_bool writeToCSVFile();
	_bool readfromCSVFile();
	_bool READTXTFile();
	void SetArrays(void* Array, int ArraySize, char ptrType);
	void FillAnyArray(void*, sint32_t, sint8_t);
	sint32_t CreatingFileUsingCPPStyle();
	_bool SerializeStructData();
	sint32_t main(void);
	_bool WriteTXTFile();
	_bool writeBinaryFile(char* ,student*, sint32_t total);

#ifdef __cplusplus
}
#endif

#endif
