#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char name[20];
    int age;
} Students;

void add_students(Students *user)
{
    FILE *check;

    check = fopen("studentd.txt", "r+");

    if (check == NULL)
    {
        for (int i = 0; user->name[i] != '\0'; i++)
        {
            if (user->name[i] == ' ')
            {
                user->name[i] = '_';
            }
        }
        fclose(check);
        FILE *users;
        users = fopen("students.txt", "w");
        fprintf(users, "%d %s %d\n", user->id, user->name, user->age);
        printf("Muvafaqiyatli qoshildi!\n");
        fclose(users);
    }
    else
    {
        for (int i; user->name[i] != '\0'; i++)
        {
            if (user->name[i] == ' ')
            {
                user->name[i] = '_';
            }
        }
        int id, age;
        char name[20];

        bool tekshirish = false;

        while (fscanf(check, "%d %s %d", &id, name, &age) == 3)
        {
            if(id == user->id)
            {
                printf("Bunday id mavjud!\n");
                tekshirish = true;
                break;
            }
        }
        if (tekshirish == false)
        {
            fprintf(check, "%d %s %d\n", user->id, user->name, user->age);
            printf("Muvaffaqiyatli qoshildi!\n");
        }
        fclose(check);
    }
}

int main()
{
    system("cls");

    char skip;
    int check;

    while (true)
    {
        printf("1. Student qo'shish\n2. Barcha studentlarni ko'rish\n3. ID bo'yicha qidirish\n4. Chiqish\n=>");
        scanf("%d", &check);
        if (check == 1)
        {
            system("cls");
            Students user;
            printf("ID kiriting: ");
            scanf("%d", &user.id);
            system("cls");
            printf("Ism familyangizni kiriting: ");
            scanf("%s", user.name);
            system("cls");
            printf("Yoshingizni kiriting: ");
            scanf("%d", &user.age);
            system("cls");
            add_students(&user);
            getchar();
            printf("\nDavom etish uchun bosing ...");
            scanf("%c", &skip);
            system("cls");
        }
        else if (check == 4)
        {
            break;
        }
    }
}