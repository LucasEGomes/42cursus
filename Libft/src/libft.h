#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/**
 * Checks for an alphabetic character using ASCII encoding.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is alphabetic, and zero if not.
*/
int		ft_isalpha(int c);
/**
 * Checks for a digit 0 through 9.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is a digit, and zero if not.
*/
int		ft_isdigit(int c);
/**
 * Checks for an alphabetic or a digit 0 through 9 character using ASCII
 * encoding.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is alphabetic or a digit, and zero if not.
*/
int		ft_isalnum(int c);
/**
 * Checks for an ASCII character.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is ascii, and zero if not.
*/
int		ft_isascii(int c);
/**
 * Checks for a printable character using ASCII encoding.
 * @param c Value of an unsigned char or EOF.
 * @return Nonzero if c is printable, and zero if not.
*/
int		ft_isprint(int c);
/**
 * Calculates the length of the string pointed by s, excluding the terminating
 * null byte ('\0').
 * @param s String to calculate the length.
 * @return Number of bytes in the string.
*/
size_t	ft_strlen(const char *s);
/**
 * Convert lowercase letter to uppercase using ASCII encoding. If c is neither 
 * an unsigned char nor EOF, the behavior is undefined.
 * @param c Letter to convert.
 * @return Converted letter if possible, and c if not.
*/
int		ft_toupper(int c);
/**
 * Convert uppercase letter to lowercase using ASCII encoding. If c is neither 
 * an unsigned char nor EOF, the behavior is undefined.
 * @param c Letter to convert.
 * @return Converted letter if possible, and c if not.
*/
int		ft_tolower(int c);
/**
 * Fills the first bytes of the memory area with a constant byte.
 * @param s Memory area.
 * @param c Byte used to fill.
 * @param n Bytes to be filled.
 * @return Pointer to the memory area.
*/
void	*ft_memset(void *s, int c, size_t n);
/**
 * Fills the first bytes of the memory area with 0.
 * @param s Memory area.
 * @param n Bytes to be filled.
 * @return Pointer to the memory area.
*/
void	*ft_bzero(void *s, size_t n);
/**
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 * @param dest Destiny memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to memory area dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap. Copy like having a temporary array.
 * @param dest Destiny memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to memory area dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * Copy size - 1 bytes from the string src to dst,
 * NUL-terminating the result.
 * @param dst Destiny string.
 * @param src Source string.
 * @param size Bytes to copy.
 * @return Total length of the string src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/**
 * Appends the string src to the end of dst. Append at most 
 * size - ft_strlen(dst) - 1 bytes, NUL-terminating the result.
 * NUL-terminating the result. If traverses size bytes without finding a NUL,
 * the destination string will not be NUL-terminated.
 * @param dst Destiny string.
 * @param src Source string.
 * @param size Bytes to copy.
 * @return Total length of the appended string dest and src, or size if 
 * traverses size bytes without finding a NUL.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * Find the first occurrence of the byte c in the string s.
 * Do not work with wide or multibyte characters.
 * @param s String where to search.
 * @param c Byte to search.
 * @return Pointer to the matched byte on the string, or NULL if not found.
*/
char	*ft_strchr(const char *s, int c);
/**
 * Find the last occurrence of the byte c in the string s.
 * Do not work with wide or multibyte characters.
 * @param s String where to search.
 * @param c Byte to search.
 * @return Pointer to the matched byte on the string, or NULL if not found.
*/
char	*ft_strchr(const char *s, int c);

#endif
