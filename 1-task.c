#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    
    FILE *message;

    message = fopen("message.txt", "r");

    if (message == NULL)
    {
        printf("xatolik aniqlandi!");
        return 0;
    }

    FILE *fl;

    fl = fopen("encrypted.txt", "w");

    if (fl == NULL)
    {
        printf("xatolik aniqlandi!");
        return 0;
    }

    char text[20];
    while (fgets(text, sizeof(text), message) != NULL)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                int belgi = text[i] + 3;
                if (belgi > 122)
                {
                    belgi = belgi % 122 + 96;
                    text[i] = belgi;
                }
                else
                {
                    text[i] += 3;
                }
            }
        }
        fprintf(fl, "%s", text);
    }
    fclose(fl);
}