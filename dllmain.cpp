// NoRadio for GTA SA. Method: https://www.blast.hk/threads/42035/post-402651

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

constexpr auto DISABLE_RADIO_ADDR = 0x4EB63D;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH: {
			DWORD dwProtect = PAGE_EXECUTE_READWRITE;
			DWORD dwOldProtect;
			DWORD dwSize = 3;

			VirtualProtect(reinterpret_cast<void*>(DISABLE_RADIO_ADDR), dwSize, dwProtect, &dwOldProtect);

			*(unsigned char*)(DISABLE_RADIO_ADDR) = 0xB2;
			*(unsigned char*)(DISABLE_RADIO_ADDR + 0x01) = 0x0D;
			*(unsigned char*)(DISABLE_RADIO_ADDR + 0x02) = 0x90;

			VirtualProtect(reinterpret_cast<void*>(DISABLE_RADIO_ADDR), dwSize, dwOldProtect, nullptr);

			break;
		}
	}

	return TRUE;
}
