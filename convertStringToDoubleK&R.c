#include <stdio.h>
#include <ctype.h>
// compilation errors! TODO FIX
// atof convert string s to double
double my_atof(char s[])
{
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++); //skip white space
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int main()
{
    char str[] = "3.14159"; // Replace with your input string
    double result = my_atof(str);
    printf("The converted double is: %lf\n", result);
    return 0;
}