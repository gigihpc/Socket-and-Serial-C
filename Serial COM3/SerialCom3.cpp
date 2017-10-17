#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class setting_port{

 

public:
	void open_port();
	void setting_parameter();
	/*void setting_timeout();
	void write_data();
	void read_data();*/


};

void setting_port ::open_port(){
	HANDLE hSerial;
	
	hSerial = CreateFile("COM3",
	GENERIC_READ | GENERIC_WRITE,
	0,
	0,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	0);
	if(hSerial==INVALID_HANDLE_VALUE){
	if(GetLastError()==ERROR_FILE_NOT_FOUND){
//serial port does not exist. Inform user.
		}
	}
}

void setting_port ::setting_parameter(){
	DCB dcbSerialParams = {0};

	dcbSerial.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
//error getting state
		}
	dcbSerialParams.BaudRate=CBR_9600;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
if(!SetCommState(hSerial, &dcbSerialParams)){
//error setting serial port state
}

}

/*void setting_port::setting_timeout(){
	COMMTIMEOUTS timeouts={0};
timeouts.ReadIntervalTimeout=50;
timeouts.ReadTotalTimeoutConstant=50;
timeouts.ReadTotalTimeoutMultiplier=10;
timeouts.WriteTotalTimeoutConstant=50;
timeouts.WriteTotalTimeoutMultiplier=10;
if(!SetCommTimeouts(hSerial, &timeouts)){
//error occureed. Inform user
}
}

void setting_port::read_data(){
	DWORD dwRead;
BOOL fWaitingOnRead = FALSE;
OVERLAPPED osReader = {0};

// Create the overlapped event. Must be closed before exiting
// to avoid a handle leak.
osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

if (osReader.hEvent == NULL)
   // Error creating overlapped event; abort.

if (!fWaitingOnRead) {
   // Issue read operation.
   if (!ReadFile(hSerial, lpBuf, READ_BUF_SIZE, &dwRead, &osReader)) {
      if (GetLastError() != ERROR_IO_PENDING)     // read not delayed?
         // Error in communications; report it.
      else
         fWaitingOnRead = TRUE;
   }
   else {    
      // read completed immediately
      HandleASuccessfulRead(lpBuf, dwRead);
    }
}

}

void setting_port::write_data(){

	BOOL WriteABuffer(char * lpBuf, DWORD dwToWrite)
{
   OVERLAPPED osWrite = {0};
   DWORD dwWritten;
   DWORD dwRes;
   BOOL fRes;

   // Create this write operation's OVERLAPPED structure's hEvent.
   osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   if (osWrite.hEvent == NULL)
      // error creating overlapped event handle
      return FALSE;

   // Issue write.
   if (!WriteFile(hSerial, lpBuf, dwToWrite, &dwWritten, &osWrite)) {
      if (GetLastError() != ERROR_IO_PENDING) { 
         // WriteFile failed, but isn't delayed. Report error and abort.
         fRes = FALSE;
      }
      else
         // Write is pending.
         dwRes = WaitForSingleObject(osWrite.hEvent, INFINITE);
         switch(dwRes)
         {
            // OVERLAPPED structure's event has been signaled. 
            case WAIT_OBJECT_0:
                 if (!GetOverlappedResult(hSerial, &osWrite, &dwWritten, FALSE))
                       fRes = FALSE;
                 else
                  // Write operation completed successfully.
                  fRes = TRUE;
                 break;
            
            default:
                 // An error has occurred in WaitForSingleObject.
                 // This usually indicates a problem with the
                // OVERLAPPED structure's event handle.
                 fRes = FALSE;
                 break;
         }
      }
   }
   else
      // WriteFile completed immediately.
      fRes = TRUE;

   CloseHandle(osWrite.hEvent);
   return fRes;
}

}*/

void main(){
	//class setting_port pil;
	//char lpBuf1;
	
	//cout<<"Masukkan kata:"<<lpbuf1;
	//cin>>lpBuf1;
	
	

}