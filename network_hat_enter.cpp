#include <windows.h>
#include <string>

#define URL "hat.tangar.info"
char aHat[100];

void updateHatAddress() {
    int _start;
    int _end;
    std::string cmdLine = GetCommandLineA();
    std::string option = "-url";
    std::string url;
    if ((_start = cmdLine.find(option)) != std::string::npos) {
        for (int i = _start + option.size() + 1; i < cmdLine.size(); i++) {
            char c = cmdLine[i];
            if (c == ' ')
                break;
            url += c;
        }
        if (url.size() < sizeof(aHat)) {
            strcpy((char *)&aHat, url.c_str());
            return;
        }
    }
    url = URL;
    strcpy((char *)&aHat, url.c_str());
}

const char * aLogin;
const char * aPassword;
std::string cmdLine;
std::string match;
void _stdcall parseLogin(){
	
	
	int _start;
	int _end;
	cmdLine = GetCommandLineA();
    if((_start = cmdLine.find("-login")) != std::string::npos) {
		if((_end = cmdLine.find(" ",_start+7)) != std::string::npos){
			match = cmdLine.substr(_start+7, _end - _start - 7);
		}else{
			match = cmdLine.substr(_start+7);
		}
		aLogin = match.c_str();
		
		if((_start = cmdLine.find("-password")) != std::string::npos) {
		   if((_end = cmdLine.find(" ",_start+10)) != std::string::npos){
			   match = cmdLine.substr(_start+10, _end - _start - 10);
		   }else{
			   match = cmdLine.substr(_start+10);
		   }
		   aPassword = match.c_str();

		}else{
			//get password from registry
			
			//__asm
			//{
			//mov		edx, 0x0043F7ED
			//jmp		edx
			//}
			
		}
		
	}else{
		//get login and password defaults from registry
		/*
		__asm
		{
		mov		edx, 0x0043F755
		jmp		edx
		}
		*/
    }
}
void __declspec(naked) HATENT_login_text()
{

	parseLogin();
	
	__asm
	{

  mov  eax, aLogin
  push eax
  mov  ecx, [ebp-0x124]
  add  ecx, 0x0C
  mov  edx, 0x005AB9E0
  call edx

  mov  eax, aPassword
  push eax
  mov  ecx, [ebp-0x124]
  add  ecx, 0x10
  mov  edx, 0x005AB9E0
  call edx

  //mov  edx, 0x0043F7ED //to password
  mov  edx, 0x0043F885
  jmp  edx
	}

}

void __declspec(naked) HATENT_url_text()
{
    updateHatAddress();
	__asm
	{
		mov		eax, offset aHat
		push	eax
		mov		ecx, [ebp-0x124]
		add		ecx, 4
		mov		edx, 0x005AB9E0
		call	edx

		mov		edx, 0x0043F755
		jmp		edx

		// the following piece of code also replaces login and possibly password (if done to +0x10 addr)
		mov		eax, offset aLogin
		push	eax
		mov		ecx, [ebp-0x124]
		add		ecx, 0x0C
		mov		edx, 0x005AB9E0
		call	edx

		mov		edx, 0x0043F7ED
		jmp		edx
	}
}

void __declspec(naked) HATENT_url_connect()
{
	__asm
	{
		add		esp, 4
		mov     ecx, 0x0069C208
		mov		edx, 0x0051151C
		push	offset aHat // адрес хэта
		call    edx
		mov		dword ptr [ebp-0x224], eax
		mov		edx, 0x00494AF4
		jmp		edx
	}
}