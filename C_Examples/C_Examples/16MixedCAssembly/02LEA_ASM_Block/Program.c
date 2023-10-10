
void swap(int* x, int* y)
{
    int temp = 0;
   
    _asm
    {
        //mov	eax, DWORD PTR x
        mov eax, DWORD PTR [ebp + 8]

        mov	ecx, DWORD PTR [eax]

        //mov	DWORD PTR temp, ecx
        mov DWORD PTR [ebp - 4], ecx

        //mov	edx, DWORD PTR x
        mov edx, DWORD PTR [ebp + 8]

        //mov	eax, DWORD PTR y
        mov eax, DWORD PTR [ebp + 12]

        mov	ecx, DWORD PTR [eax]

        mov	DWORD PTR [edx], ecx
       
        //mov	edx, DWORD PTR y
        mov edx, DWORD PTR [ebp + 12]

        //mov	eax, DWORD PTR temp
        mov eax, DWORD PTR [ebp - 4]

        mov	DWORD PTR[edx], eax
    }
}

void main()
{
    //int x = 1;
    //int y = 2;

    _asm
    {
        push	ebp
        mov	ebp, esp
        sub	esp, 8
  
        //mov	DWORD PTR _x$[ebp], 1
        mov	DWORD PTR [ebp - 8], 1

        //mov	DWORD PTR _y$[ebp], 2
        mov	DWORD PTR [ebp - 4], 2

        //lea	eax, DWORD PTR _y$[ebp]
        //lea	eax, DWORD PTR [ebp - 4]
        //lea	eax, [ebp - 4]
        mov eax, ebp
        add eax, -4
        push	eax

        //lea	eax, DWORD PTR _x$[ebp]
        //lea	ecx, DWORD PTR [ebp - 8]
        //lea ecx, [ebp - 8]
        mov ecx, ebp
        add ecx, -8
        push	ecx

        call	swap

        add	esp, 8

        xor eax, eax

        mov	esp, ebp
        pop	ebp

        ret	0
    }

    //swap(&x, &y);
}