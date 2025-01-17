#include <stdio.h>
#include <string.h>

// https://theasciicode.com.ar/
// https://petlatkea.notion.site/str_to_integer-26e4ce4394be47fd97149a6b498f899e

int is_digit(char c) {
    int val = c - '0';
    
    if (val > 0 && val < 58) {
        return 1;
    } else {
        return 0;
    }
}

int str_to_integer(char* str) {
    int value = 0;
    int startIndex = 0;
    int isNegative = 0;

    // for (int i = 0; str[i] != '\0'; i++)
    // {
    //     value *= 10;
    //     printf("Talværdi er %d\n", (str[i] - '0'));
    //     printf("#%d er %d \n", i, str[i]);

    //     value += (str[i] - '0');
    // }

    if (*str == '-') {
        startIndex = 1;
        isNegative = 1;
    }

    for (int i = startIndex; is_digit(str[i]); i++)
    {
        value *= 10;
        printf("Talværdi er %d\n", (str[i] - '0'));
        printf("#%d er %d \n", i, str[i]);

        value += (str[i] - '0');
    }

    if (isNegative == 1) {
        value *= -1;
    }
    
    return value;
}

// str[] skal indeholde asci værdier for talene
// Basically retur værdi
void int_to_string(int number, char* str, int len) {
    int remain = number;
    str += len;
    do
    {
        int digit = remain % 10;
        *str = digit + 48;
        str--;
        remain /= 10;
    } while (remain > 0);

    *str = '\0';
}

int main(int argc, char const *argv[])
{
    char str[] = "-123433";
    int val = str_to_integer(str);

    printf("%s svarer til %d\n", str, val);



    puts("========");

    char res[255];

    int_to_string(23345, res, 4);
    printf("%s\n", res);

    return 0;
}
