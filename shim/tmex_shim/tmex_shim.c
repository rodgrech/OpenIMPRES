#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static CRITICAL_SECTION g_log_lock;
static int g_log_ready = 0;
static int g_session = 0x1234;
static unsigned char g_rom[8] = {0x10, 0x38, 0x1B, 0x02, 0x00, 0x80, 0x81, 0xFF};

static void log_line(const char *fmt, ...)
{
    char path[MAX_PATH];
    FILE *f;
    va_list args;

    if (!g_log_ready) {
        InitializeCriticalSection(&g_log_lock);
        g_log_ready = 1;
    }

    EnterCriticalSection(&g_log_lock);
    GetModuleFileNameA((HMODULE)0, path, sizeof(path));
    {
        char *slash = strrchr(path, '\\');
        if (slash) {
            slash[1] = '\0';
        } else {
            path[0] = '\0';
        }
    }
    lstrcatA(path, "tmex_shim.log");

    f = fopen(path, "ab");
    if (f) {
        va_start(args, fmt);
        vfprintf(f, fmt, args);
        va_end(args);
        fputs("\r\n", f);
        fclose(f);
    }
    LeaveCriticalSection(&g_log_lock);
}

BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved)
{
    (void)inst;
    (void)reserved;
    if (reason == DLL_PROCESS_ATTACH) {
        log_line("ibfs32 shim loaded");
    }
    return TRUE;
}

__declspec(dllexport) short __stdcall _GetFamilySpec(int family, void *spec, int len)
{
    log_line("_GetFamilySpec(family=%d, spec=%p, len=%d)", family, spec, len);
    if (spec && len > 0) {
        ZeroMemory(spec, len);
    }
    return 1;
}

__declspec(dllexport) short __stdcall Get_Version(void)
{
    log_line("Get_Version()");
    return 322;
}

__declspec(dllexport) long __stdcall TMExtendedStartSession(short port_num, short port_type, void *reserved)
{
    log_line("TMExtendedStartSession(port=%d,type=%d,reserved=%p) -> %d", port_num, port_type, reserved, g_session);
    return g_session;
}

__declspec(dllexport) short __stdcall TMEndSession(long session)
{
    log_line("TMEndSession(session=%ld)", session);
    return 1;
}

__declspec(dllexport) short __stdcall TMValidSession(long session)
{
    log_line("TMValidSession(session=%ld)", session);
    return session == g_session;
}

__declspec(dllexport) short __stdcall TMSetup(long session)
{
    log_line("TMSetup(session=%ld)", session);
    return 1;
}

__declspec(dllexport) short __stdcall TMReadDefaultPort(short *port_num, short *port_type)
{
    log_line("TMReadDefaultPort(port_num=%p, port_type=%p)", port_num, port_type);
    if (port_num) *port_num = 1;
    if (port_type) *port_type = 5;
    return 1;
}

__declspec(dllexport) short __stdcall TMPortSetup(short port_num, short port_type)
{
    log_line("TMPortSetup(port=%d,type=%d)", port_num, port_type);
    return 1;
}

__declspec(dllexport) short __stdcall TMTouchReset(long session)
{
    log_line("TMTouchReset(session=%ld) -> presence", session);
    return 1;
}

__declspec(dllexport) short __stdcall TMTouchBit(long session, short bit)
{
    log_line("TMTouchBit(session=%ld,bit=%d)", session, bit);
    return bit ? 1 : 0;
}

__declspec(dllexport) short __stdcall TMTouchByte(long session, short byte_value)
{
    log_line("TMTouchByte(session=%ld,byte=0x%02X)", session, byte_value & 0xFF);
    return 0xFF;
}

__declspec(dllexport) short __stdcall TMBlockStream(long session, unsigned char *buffer, short len)
{
    int i;
    log_line("TMBlockStream(session=%ld,buffer=%p,len=%d)", session, buffer, len);
    if (buffer && len > 0) {
        for (i = 0; i < len; i++) {
            if (buffer[i] == 0xFF) buffer[i] = 0xFF;
        }
    }
    return 1;
}

__declspec(dllexport) short __stdcall TMBlockIO(long session, unsigned char *buffer, short len)
{
    log_line("TMBlockIO(session=%ld,buffer=%p,len=%d)", session, buffer, len);
    return TMBlockStream(session, buffer, len);
}

__declspec(dllexport) short __stdcall TMRom(long session, unsigned char *rom)
{
    log_line("TMRom(session=%ld,rom=%p)", session, rom);
    if (rom) {
        CopyMemory(rom, g_rom, sizeof(g_rom));
    }
    return 1;
}

__declspec(dllexport) short __stdcall TMFirst(long session, void *state)
{
    log_line("TMFirst(session=%ld,state=%p)", session, state);
    return 1;
}

__declspec(dllexport) short __stdcall TMNext(long session, void *state)
{
    log_line("TMNext(session=%ld,state=%p)", session, state);
    return 0;
}

#define STUB(name) __declspec(dllexport) short __stdcall name(void) { log_line(#name "()"); return 0; }

STUB(TMAccess)
STUB(TMAttribute)
STUB(TMAutoOverDrive)
STUB(TMCRC)
STUB(TMChangeDirectory)
STUB(TMClose)
STUB(TMCloseFile)
STUB(TMCreateFile)
STUB(TMCreateProgramJob)
STUB(TMDeleteFile)
STUB(TMDirectoryMR)
STUB(TMDoProgramJob)
STUB(TMExtendedReadPage)
STUB(TMFamilySearchSetup)
STUB(TMFirstAlarm)
STUB(TMFirstFile)
STUB(TMFormat)
STUB(TMGetAdapterSpec)
STUB(TMGetFamilySpec)
STUB(TMGetTypeVersion)
STUB(TMLine)
STUB(TMNextAlarm)
STUB(TMNextFile)
STUB(TMOneWireCom)
STUB(TMOneWireLevel)
STUB(TMOpenFile)
STUB(TMOverAccess)
STUB(TMProgramBlock)
STUB(TMProgramByte)
STUB(TMProgramPulse)
STUB(TMReNameFile)
STUB(TMReadFile)
STUB(TMReadPacket)
STUB(TMSearch)
STUB(TMSearchState)
STUB(TMSkipFamily)
STUB(TMStartSession)
STUB(TMStrongAccess)
STUB(TMStrongAlarmAccess)
STUB(TMTerminateAddFile)
STUB(TMWriteAddFile)
STUB(TMWriteFile)
STUB(TMWritePacket)
