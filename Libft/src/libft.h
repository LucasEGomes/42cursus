#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/**
 * Checks for an alphabetic character using ASCII encoding.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is alphabetic, and zero if not.
*/
int	ft_isalpha(int c);
/**
 * Checks for a digit 0 through 9.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is a digit, and zero if not.
*/
int	ft_isdigit(int c);
/**
 * Checks for an alphabetic or a digit 0 through 9 character using ASCII encoding
 * @param c Value of an unsigned char or EOF
 * @return Nonzero if c is alphabetic or a digit, and zero if not
*/
int	ft_isalnum(int c);
/**
 * Checks for an ASCII character
 * @param c Value of an unsigned char or EOF
 * @return Nonzero if c is ascii, and zero if not
*/
int	ft_isascii(int c);

#endif