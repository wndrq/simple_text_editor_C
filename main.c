#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    system("cls"); // для Windows, используйте "clear" для Unix/Linux
}

void read_file(const char *file_name) {
    char buffer[2048];
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("File not found");
        return;
    }
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_file(const char *file_name, const char *string) {
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        perror("File not found");
        return;
    }
    fprintf(file, "\n%s\n", string); // Добавляем новую строку после каждой записи
    fclose(file);
}

int main() {
    char string[1024];
    const char *file_name = "./test.txt";

    while (1) {
        printf("\n> ");
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = 0; // Удаляем символ новой строки

        if (strcmp(string, "q") == 0) {
            break; // Выход из цикла, если введен 'q'
        }
        write_file(file_name, string);
        clear_screen();
        read_file(file_name);
    }

    return 0;
}
