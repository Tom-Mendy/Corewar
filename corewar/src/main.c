/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#include "my_project.h"
#include "corewar.h"
// int check_cmp_dup(int argc, char *argv[], int i, int **prog_count)
// {
//     return OK;
// }

// int check_cmp_help(int argc, char *argv[], int i, int **prog_count)
// {
//     int prog_number = 0;
//     int load_address = 0;
//     char *prog_name = 0;
//     if (i + 3 < argc && my_str_cmp(argv[i + 2], "-a") == 0) {
//         if (my_str_is_num(argv[i + 1]) != 1)
//             return KO;
//         if (my_str_is_num(argv[i + 3]) != 1) {
//             load_address = 8;
//             prog_name = argv[i + 3];
//         }else {
//             load_address = atoi(argv[i + 3]);
//             prog_name = argv[i + 4];
//         }
//         prog_number = atoi(argv[i + 1]);
//         printf("Program %d loaded at address %d with name %s\n", prog_number, load_address, prog_name);
//         i += 4;
//         (*prog_count)++;
//     } else {
//         printf("Incorrect usage of -n\n");
//         return KO;
//     }
//     return OK;
// }

// int check_cmp(int argc, char *argv[], int i, int *dump_cycles, int *prog_count)
// {
//     if (my_str_cmp(argv[i], "-dump") == 0) {
//         if (i + 1 < argc) {
//             *dump_cycles = atoi(argv[i + 1]);
//             i++;
//         } else {
//             printf("Missing argument for -dump\n");
//             return KO;
//         }
//     } else if (my_str_cmp(argv[i], "-n") == 0) {
//         if (check_cmp_help(argc, argv, i, &prog_count) == KO)
//             return KO;
//     }
//     return (OK);
// }

// int parcing_argv(int argc, char *argv[])
// {
//     int dump_cycles = 0;
//     int prog_count = 0;

//     for (int i = 1; i < argc; i++) {
//         if (check_cmp(argc, argv, i, &dump_cycles, &prog_count) == KO)
//             return KO;
//     }
//     printf("Dump cycles: %d\n", dump_cycles);
//     printf("Total programs: %d\n", prog_count);
//     return OK;
// }

int main(int const argc, char const *argv[])
{
    // return parcing_argv(argc, argv);
    if (my_str_cmp(argv[1], "-h") == 0 && argc == 2)
        return display_help();
    if (parcing_argv(argc, argv) == KO)
        return KO;
    return OK;
    if (argc < 5) {
        if (write(2, "Not enough argument.\n", 22) == -1)
            return KO;
        return KO;
    }
    return start_vm(argv);
}
