#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bits(char ch)
{
    unsigned char i, bit;
    bit = 0x80;
    for (i = 0; i <= 7; i++, bit >>= 1)
    {
        printf("%d", (ch & bit) ? 1 : 0);
        if ((i + 1) % 4 == 0)
            printf("");
    }
}
void show_bytes(byte_pointer start, int len)
{
    int i;
    printf("字节数为:%d lt二进制值为: ", len);
    for (i = len - 1; i >= 0; i--)
        show_bits(*(start + i));
    printf("\n");
}
int main(void)
{
    char c1 = 100, c2 = -c1;

    printf("c1 = %d\t", c1);
    show_bytes((byte_pointer)&c1, sizeof(c1));
    printf("c2 = %d\t", c2);
    show_bytes((byte_pointer)&c2, sizeof(c2));
    return 0;
}
