#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

// This function is called before SecureEngineInitialize.
// This function receives the name of the executable binary (EXE or DLL) that contains the plugin.
extern "C" __declspec(dllexport)
bool __stdcall SecureEngineGetProtectedFileNameA(
	char* ApplicationName) // Pointer to a null-terminated string with the name of the executable binary that contains the plugin.
{
	MessageBoxA(NULL, ApplicationName, "SecureEngineGetProtectedFileNameA", MB_OK | MB_ICONINFORMATION);
	return true;		// Continue execution
}


// This function receives the fingerprint or watermark that was inserted in protection time.
extern "C" __declspec(dllexport)
bool __stdcall SecureEngineGetFingerPrintA(
	char* pFingerprint) // Pointer to a buffer to receive the inserted fingerprint.
{
	MessageBoxA(NULL, pFingerprint, "SecureEngineGetFingerPrintA", MB_OK | MB_ICONINFORMATION);
	return true; // TRUE = The protection code will continue running, FALSE = the application will exit immediately.
}


// This function is called when the protection starts, before your application has been processed (decrypted, decompressed, etc) to be executed in memory.
// This can be a good place if you want to add your own protection checks, etc.
extern "C" __declspec(dllexport) 
bool __stdcall SecureEngineInitialize(void)
{
	MessageBoxA(NULL, "Calling SecureEngineInitialize", "SecureEngineInitialize", MB_OK | MB_ICONINFORMATION);
	return true; // TRUE = The protection code will continue running, FALSE = the application will exit immediately.
}


// This function is called when the protection boot loader has been executed, your application is ready to have control of the CPU.
extern "C" __declspec(dllexport) 
bool __stdcall SecureEngineFinalize(void)
{
	MessageBoxA(NULL, "Calling SecureEngineFinalize", "SecureEngineFinalize", MB_OK | MB_ICONINFORMATION);
	return true; // TRUE = The protection code will continue running, FALSE = the application will exit immediately.
}


// This function is called when a Customized Dialog is going to be displayed by the protection.
// This function receives the message that is going to be displayed by the protection in ANSI format (SecureEngineShowMessageA) or UNICODE format (SecureEngineShowMessageW)
extern "C" __declspec(dllexport) 
bool __stdcall SecureEngineShowCustomMessageA(
	int	  MsgId, // Identifier for the message that is going to be displayed. Please, refer to the CustomMessagesConstantsDefinitions.h
	char* MsgBody) // Pointer to a null-terminated string with the message that is going to be displayed.
{
	MessageBoxA(NULL, MsgBody, "SecureEngineShowCustomMessageA", MB_OK | MB_ICONINFORMATION);
	return true; // TRUE = Message has been handled. The protection won't display it
}

// !!!!!!!!!!!!!!!!! ONLY FOR 32-BIT !!!!!!!!!!!!!!!!!

// This function allows you to specify an encryption key to encrypt/decrypt specific areas in your application.
// This function is called in protection time to get the encryption key from your plugin.
// In runtime, the protection will call your embedded plugin to retrieve the encryption key to decrypt your application.
extern "C" __declspec(dllexport) 
bool __stdcall SecureEngineGetEncryptionKey(
	int	  ZoneId, // Identifies the zone for where the encryption key is required.
	char* pOutputEncryptionKey) // Pointer to an allocated buffer where the encryption key will be copied.
{
	strcpy(pOutputEncryptionKey, "Custom Encryption Key");
	return true; // TRUE = The protection code will continue running, FALSE = the application will exit immediately.
}