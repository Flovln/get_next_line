# get_next_line

Project for Ecole 42 - PARIS.

EN:
Get_next_line's goal was to code a function which returns a line ended by a newLine, read from a file descriptor. It reads 
characters from one or multiple given file descriptors until the file ends or that one newLine is encountered,
then saves the line through the string's pointers given as parameter.

Calling the function in the following loop enables to read and display the whole file content:
    while (get_next_line(fd, &str) > 0)
        ft_putstr(str);
This function works even when multiple fd are used within the same program.

FR:
Ce projet a pour but de nous faire coder une fonction qui renvoit une ligne terminée par un retour à la ligne lue depuis 
un descripteur de fichier.
