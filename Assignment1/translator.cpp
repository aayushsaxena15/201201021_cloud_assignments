#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{	ifstream f1("32_bit.asm");
    ofstream f2("64bit_converted.asm");
    string s;
	if(f1.is_open())
	{	while(getline(f1, s))
        {   const char *l = s.c_str();
            if(!strcmp(l, "msg db \"Hello World\", 0xa"))
                f2 << "msg: db \"Hello World\", 0xa" << "\n";
            else if(!strcmp(l, "len equ $-msg"))
                f2 << "len: equ $-msg" << "\n";
            else if(!strcmp(l, "mov eax, 4"))
                f2 << "mov rax, 1" << "\n";
            else if(!strcmp(l, "mov ebx, 1"))
                f2 << "mov rbx, 1" << "\n";
            else if(!strcmp(l, "mov edx, len"))
                f2 << "mov rdi, len" << "\n";
            else if(!strcmp(l, "mov ecx, msg"))
                f2 << "mov rsi, msg" << "\n";
            else if(!strcmp(l, "int 80h"))
                f2 << "syscall" << "\n";
            else if(!strcmp(l, "mov ebx, 0"))
                f2 << "mov rbx, 0" << "\n";
            else if(!strcmp(l, "mov eax, 1"))
                f2 << "mov rax, 60" << "\n";
            else
                f2 << l << "\n";
        }
        f1.close();
        f2.close();
	}
    else 
        cout<<"Unable to open file!\n"; 
	return 0;
}
