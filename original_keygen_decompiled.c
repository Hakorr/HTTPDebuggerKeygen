/* 
   Detected compiler: Visual C++
*/

#include <windows.h>
#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

LSTATUS __stdcall getAppVer(LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE lpData);
HLOCAL __stdcall sub_401081(HWND hWnd, DWORD dwMessageId);
void __stdcall __noreturn start(int a1, int a2, int a3, int a4);
INT_PTR __stdcall DialogFunc(HWND, UINT, WPARAM, LPARAM); // idb
BOOL __stdcall sub_4011C1(HWND hDlg);
UINT __stdcall sub_40123E(HWND hDlg);
int __stdcall sub_4012D4(BYTE *lpData, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD cbData); // idb
// INT_PTR __stdcall DialogBoxParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
// BOOL __stdcall EndDialog(HWND hDlg, INT_PTR nResult);
// UINT __stdcall GetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPSTR lpString, int cchMax);
// int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
// BOOL __stdcall SetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
// void __stdcall __noreturn ExitProcess(UINT uExitCode);
// DWORD __stdcall FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, va_list *Arguments);
// HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
// BOOL __stdcall GetVolumeInformationA(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
// HLOCAL __stdcall LocalFree(HLOCAL hMem);
// LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2);
// LSTATUS __stdcall RegCloseKey(HKEY hKey);
// LSTATUS __stdcall RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
// LSTATUS __stdcall RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
// LSTATUS __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
// LSTATUS __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData);
int __stdcall sub_401390(unsigned __int8 *a1);
int __stdcall sub_4013D0(int a1);
int __stdcall sub_401420(int a1, int a2);

//-------------------------------------------------------------------------
// Data declarations

// extern int (*sprintf)(char *const Buffer, const char *const Format, ...);
// extern void (__cdecl *srand)(unsigned int Seed);
// extern int (__cdecl *rand)();
CHAR VolumeNameBuffer[128] =
{
  

  '\0'
}; // idb
DWORD nVolumeNameSize = 128u; // idb
DWORD VolumeSerialNumber = 0u; // idb
DWORD MaximumComponentLength = 0u; // idb
DWORD FileSystemFlags = 0u; // idb
CHAR FileSystemNameBuffer[128] =
{
  

  '\0'
}; // idb
DWORD nFileSystemNameSize = 128u; // idb
CHAR RootPathName[4] = "C:\\"; // idb
CHAR SubKey[] = "SOFTWARE\\MadeForNet\\HTTPDebuggerPro"; // idb
HINSTANCE hInstance = NULL; // idb
char ValueName[255] =
{
  

  '\0'
}; // idb
_UNKNOWN unk_403373; // weak
BYTE byte_403374 = 0u; // idb
CHAR String[10]; // weak
int dword_40347E; // weak
BYTE Data; // idb


//----- (00401000) --------------------------------------------------------
LSTATUS __stdcall getAppVer(LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE lpData)
{
  DWORD v3; // eax
  DWORD cbData; // [esp+100h] [ebp-10h] BYREF
  DWORD Type; // [esp+104h] [ebp-Ch] BYREF
  HKEY phkResult; // [esp+108h] [ebp-8h] BYREF

  v3 = RegOpenKeyExA(HKEY_CURRENT_USER, lpSubKey, 0, 0x101u, &phkResult);
  if ( v3 )
  {
    sub_401081(0, v3);
    lstrcatA((LPSTR)lpData, "Error Opening RegKey!");
  }
  else
  {
    Type = 3;
    cbData = 250;
    if ( RegQueryValueExA(phkResult, lpValueName, 0, &Type, lpData, &cbData) )
      lstrcatA((LPSTR)lpData, "RegKey Does Not Exist");
  }
  return RegCloseKey(phkResult);
}

//----- (00401081) --------------------------------------------------------
HLOCAL __stdcall sub_401081(HWND hWnd, DWORD dwMessageId)
{
  CHAR Buffer[4]; // [esp+0h] [ebp-4h] BYREF

  FormatMessageA(0x1100u, 0, dwMessageId, 0, Buffer, 0, 0);
  MessageBoxA(hWnd, *(LPCSTR *)Buffer, 0, 0x10u);
  return LocalFree(*(HLOCAL *)Buffer);
}

//----- (004010BB) --------------------------------------------------------
void __stdcall __noreturn start(int a1, int a2, int a3, int a4)
{
  CHAR *v4; // edi
  int v5; // ebx
  unsigned __int64 v6; // rax
  INT_PTR v7; // eax

  hInstance = GetModuleHandleA(0);
  getAppVer("Software\\MadeForNet\\HTTPDebuggerPro", "AppVer", &byte_403374);
  v4 = (char *)&unk_403373 + sub_4013D0((int)&byte_403374);
  v5 = 0;
  while ( *v4 != 32 )
  {
    if ( *v4 != 46 )
      String[v5++] = *v4;
    --v4;
  }
  sub_401420((int)String, (int)String);
  dword_40347E = sub_401390((unsigned __int8 *)String);
  v6 = __rdtsc();
  srand(HIDWORD(v6) ^ v6);
  v7 = DialogBoxParamA(hInstance, (LPCSTR)0x65, 0, DialogFunc, 0);
  ExitProcess(v7);
}
// 40347E: using guessed type int dword_40347E;

//----- (0040114F) --------------------------------------------------------
INT_PTR __stdcall DialogFunc(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  if ( a2 == 272 )
    SetDlgItemTextA(hDlg, 1001, &String);
  if ( a2 != 273 )
  {
    if ( a2 != 16 )
      return 0;
    goto LABEL_11;
  }
  if ( a3 != 1 )
  {
    if ( a3 == 1005 )
    {
      sub_40123E(hDlg);
      return 0;
    }
    if ( a3 != 2 )
      return 0;
LABEL_11:
    EndDialog(hDlg, 0);
    return 0;
  }
  sub_4011C1(hDlg);
  return 0;
}

//----- (004011C1) --------------------------------------------------------
BOOL __stdcall sub_4011C1(HWND hDlg)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax

  v1 = rand() % 255;
  v2 = rand() % 255;
  v3 = rand();
  sprintf(
    (char *const)&Data,
    "%02X%02X%02X7C%02X%02X%02X%02X",
    v1,
    v2 ^ 0x7C,
    (unsigned __int8)~(_BYTE)v1,
    v2,
    v3 % 255,
    (unsigned __int8)(v3 % 255) ^ 7,
    v1 ^ (unsigned __int8)~(v3 % 255));
  return SetDlgItemTextA(hDlg, 1002, (LPCSTR)&Data);
}

//----- (0040123E) --------------------------------------------------------
UINT __stdcall sub_40123E(HWND hDlg)
{
  UINT result; // eax
  int cbData; // [esp+0h] [ebp-Ch]

  result = GetDlgItemTextA(hDlg, 1002, (LPSTR)&Data, 20);
  cbData = result;
  if ( result )
  {
    GetVolumeInformationA(
      RootPathName,
      VolumeNameBuffer,
      nVolumeNameSize,
      &VolumeSerialNumber,
      &MaximumComponentLength,
      &FileSystemFlags,
      FileSystemNameBuffer,
      nFileSystemNameSize);
    sprintf(ValueName, "SN%d", dword_40347E ^ ((~VolumeSerialNumber >> 1) + 736) ^ 0x590D4);
    return sub_4012D4(&Data, SubKey, ValueName, cbData);
  }
  return result;
}
// 40347E: using guessed type int dword_40347E;

//----- (004012D4) --------------------------------------------------------
int __stdcall sub_4012D4(BYTE *lpData, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD cbData)
{
  int result; // eax
  HKEY phkResult; // [esp+0h] [ebp-8h] BYREF
  DWORD dwDisposition; // [esp+4h] [ebp-4h] BYREF

  result = RegCreateKeyExA(HKEY_CURRENT_USER, lpSubKey, 0, 0, 0, 0xF003Fu, 0, &phkResult, &dwDisposition);
  if ( !result )
  {
    RegSetValueExA(phkResult, lpValueName, 0, 1u, lpData, cbData);
    return RegCloseKey(phkResult);
  }
  return result;
}

//----- (00401390) --------------------------------------------------------
int __stdcall sub_401390(unsigned __int8 *a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // eax
  _BYTE *v4; // esi

  v1 = 0;
  v2 = 0;
  v3 = *a1;
  v4 = a1 + 1;
  if ( (_BYTE)v3 == 2 )
  {
    LOBYTE(v3) = *v4;
    v2 = -1;
    v4 = a1 + 2;
  }
  while ( (_BYTE)v3 )
  {
    LOBYTE(v3) = v3 - 48;
    v1 = v3 + 10 * v1;
    LOBYTE(v3) = *v4++;
  }
  return v2 ^ (v1 + v2);
}

//----- (004013D0) --------------------------------------------------------
int __stdcall sub_4013D0(int a1)
{
  _BYTE *v1; // eax

  v1 = (_BYTE *)(a1 - 4);
  while ( 1 )
  {
    v1 += 4;
    if ( !*v1 )
      break;
    if ( !v1[1] )
      return (int)&v1[-a1 + 1];
    if ( !v1[2] )
      return (int)&v1[-a1 + 2];
    if ( !v1[3] )
      return (int)&v1[-a1 + 3];
  }
  return (int)&v1[-a1];
}

//----- (00401420) --------------------------------------------------------
int __stdcall sub_401420(int a1, int a2)
{
  int v2; // eax
  char v3; // dl
  unsigned int v4; // eax
  _BYTE *v5; // edi
  int v6; // eax
  int v7; // esi
  char v8; // cl

  v2 = 0;
  do
  {
    v3 = *(_BYTE *)(v2 + a1);
    *(_BYTE *)(v2 + a2) = v3;
    ++v2;
  }
  while ( v3 );
  v4 = v2 - 1;
  v5 = (_BYTE *)(v4 + a2 - 1);
  v6 = -(v4 >> 1);
  v7 = a2 - v6;
  do
  {
    v8 = *(_BYTE *)(v6 + v7);
    *(_BYTE *)(v6 + v7) = *v5;
    *v5-- = v8;
    ++v6;
  }
  while ( v6 );
  return a2;
}

// nfuncs=26 queued=10 decompiled=10 lumina nreq=0 worse=0 better=0
// ALL OK, 10 function(s) have been successfully decompiled
