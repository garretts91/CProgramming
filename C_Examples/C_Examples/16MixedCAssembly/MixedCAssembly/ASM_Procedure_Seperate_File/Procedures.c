int add(int a, int b)
{
    int c = 0;

    _asm
    {
        mov eax, a
        add eax, b
        mov c, eax
    }

    return c;
}