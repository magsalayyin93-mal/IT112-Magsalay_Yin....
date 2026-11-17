#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char idNumber[50];
    char completeName[100];
    char section[50];
    int choice;

    file = fopen("student_records.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    do {
        printf("Enter Student Number: ");
        fgets(idNumber, sizeof(idNumber), stdin);
        idNumber[strcspn(idNumber, "\n")] = '\0';

        printf("Enter Complete Name: ");
        fgets(completeName, sizeof(completeName), stdin);
        completeName[strcspn(completeName, "\n")] = '\0';

        printf("Enter Section: ");
        fgets(section, sizeof(section), stdin);
        section[strcspn(section, "\n")] = '\0';

        fprintf(file, "ID Number: %s\n", idNumber);
        fprintf(file, "Complete Name: %s\n", completeName);
        fprintf(file, "Section: %s \n\n", section);

        printf("\n***Record added and saved successfully.***\n\n");

        printf("Add another student? [Enter 1 for Yes, 0 for No]: ");
        scanf("%d", &choice);
        getchar();
        printf("\n");

    } while (choice == 1);

    fclose(file);

    printf("All student records have been saved.\n");

    return 0;
}