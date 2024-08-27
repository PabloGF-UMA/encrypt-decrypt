# Encrypt & decrypt

This repository contains a program that allows for the encryption and decryption of messages using a simple XOR function.

The encrypt function modifies the original string in place by XORing each character with the value 31.

Let's say the input string is "Hello". The encryption process runs as follows:
  The ASCII value of 'H' (72) is XORed with 31, resulting in a new character.
  The process is repeated for each character in the string.
  
For example:
  'H' (ASCII 72) XOR 31 → 103 (a non-printable character, just for illustration)
  'e' (ASCII 101) XOR 31 → 122 (ASCII for 'z')
  And so on for each character in the string.
  
For decryption, if you run the encrypt function again on the encrypted string, the original message is restored. This is because XORing the same value twice cancels out the effect.
