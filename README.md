HEXIDECIMAL BASE COMMAND :

hexdump -C <file>

--------------------------------------------------------------------------------------

AUTHORIZED FUNCTIONS :

- (f)open, (f)read, (f)write, (f)close
- getline
- lseek, fseek
- malloc, realloc, free
- exit

---------------------------------------------------------------------------------------

PROJECT :

Corewar is a computer simulation in which processors will share memory to run on.
The project is based on a virtual machine in which the champions will fight for
memory in order to win, the last champion being able to signal that he is alive wins
the game. The last champion to execute the "live" instruction is declared winner!

1. Champions:
            The champions are files written in an assembly language specific to our virtual machine.
            The file has the instructions that the champion must follow, and gives it the kowledge
            of when to attack, defend, and/or declare it is still alive.
2. Assembler:
            The assembler is the asm binary that you will do. The purpose of this program is to
            transcribe the champions (the .s files) into a language that the virtual machine can
            understand, byte by byte.
3. Virtual Machine:
            The virtual machine, and second binary (corewar), comes after the assembler and will ask you
            to execute the instructions of each of the champions to understand the machine language that
            you just translated.

---------------------------------------------------------------------------------------

EXAMPLES :

-> Champion:
                // displayed in game
                .name "John Snow"               // name
                .comment "Winter is coming"     // description

                // instructions
                sti r1, %:crow, %1
        crow:   live %234
                ld %0, r3
                zjmp, %:crow
