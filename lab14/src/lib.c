#include "lib.h"

void struct_folder(char *directory_name, int count_of_space)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(directory_name);
    if (folder != NULL)
    {
        while ((entry = readdir(folder)))
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                printf("%*c", count_of_space, ' ');
                printf("%s\n", entry->d_name);
                char *under_directory_name = (char *)calloc(strlen(directory_name) + 1 + strlen(entry->d_name), sizeof(char) + 1);
                strcat(under_directory_name, directory_name);
                strcat(under_directory_name, "/");
                strcat(under_directory_name, entry->d_name);
                struct_folder(under_directory_name, count_of_space + 1);
                free(under_directory_name);
            }
        }
    }

    closedir(folder);
}

void print_size_of_directory()
{
    char *directory_name =  malloc(256 * sizeof(char));
    printf("%s\n", "Введіть ім'я каталогу:");
    scanf("%s", directory_name);

    double directory_size = calculate_directory_size(directory_name);
    directory_size /= 1024.0;

    printf("%s : %3.2f%s\n", "Розмір директорії", directory_size, " КБ");
    free(directory_name);
}

double calculate_directory_size(char *directory_name)
{
    double directory_size = 0.0;

    DIR *folder;
    struct dirent *entry;

    folder = opendir(directory_name);
    if (folder == NULL)
    {
        FILE *file;
        file = fopen(directory_name, "r");

        if (file != NULL)
        {
            directory_size += (double)calculate_file_size(file);
            fclose(file);
        }
    }
    else
    {
        while ((entry = readdir(folder)))
        {

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                char *under_directory_name = (char *)calloc(strlen(directory_name) + 1 + strlen(entry->d_name), sizeof(char) + 1);

                strcat(under_directory_name, directory_name);
                strcat(under_directory_name, "/");
                strcat(under_directory_name, entry->d_name);

                directory_size += calculate_directory_size(under_directory_name);
                free(under_directory_name);
            }
        }
    }
    closedir(folder);
    return directory_size;
}

long int calculate_file_size(FILE *file)
{
    long int save_pos = ftell(file);
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, save_pos, SEEK_SET);
    return file_size;
}

