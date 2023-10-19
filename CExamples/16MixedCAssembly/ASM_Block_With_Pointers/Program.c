
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
    int x = 1;
    int y = 2;

    swap(&x, &y);
}