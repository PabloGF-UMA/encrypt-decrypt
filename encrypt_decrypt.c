#include <stdio.h>
#include <string.h>
#include "encrypt.h"
#include "decrypt.h"

int main()
{
    char response[10];  // Allocate space for a single string
    printf("\nWould you like to encrypt (E), decrypt (D), or finish (F)?\n");

    while (scanf("%9s", response) == 1)  // Read up to 9 characters to avoid overflow
    {
        // Clear the newline character left in the buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (strcmp(response, "E") == 0)
        {
            char msg[80];
            printf("Enter your message: ");
            if (fgets(msg, sizeof(msg), stdin))
            {
                // Remove newline character from fgets if present
                size_t len = strlen(msg);
                if (len > 0 && msg[len - 1] == '\n')
                    msg[len - 1] = '\0';

                encrypt(msg);
                printf("This is the encrypted message:%s\n", msg);
            }
        }
        else if (strcmp(response, "D") == 0)
        {
            char word[80];
            printf("Enter the word you want to decrypt: ");
            if (scanf("%79s", word) == 1)
            {
                decrypt(word);
                printf("Your decrypted message is: %s\n", word);
            }
        }
        else if (strcmp(response, "F") == 0)
        {
            printf("Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Not a valid response, please try again:\n");
        }

        printf("\nWould you like to encrypt (E), decrypt (D), or finish (F)?\n");
    }
    
    return 0;
}
