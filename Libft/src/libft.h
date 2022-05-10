/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:31:15 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:31:16 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;

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
 * The null byte is part of the string.
 * @param s String where to search.
 * @param c Byte to search.
 * @return Pointer to the matched byte on the string, or NULL if not found.
*/
char	*ft_strchr(const char *s, int c);
/**
 * Find the last occurrence of the byte c in the string s.
 * Do not work with wide or multibyte characters.
 * The null byte is part of the string.
 * @param s String where to search.
 * @param c Byte to search.
 * @return Pointer to the matched byte on the string, or NULL if not found.
*/
char	*ft_strrchr(const char *s, int c);
/**
 * Compare the first n bytes of strings s1 and s2.
 * The locale is not taken into account.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Bytes to compare.
 * @return If the first n bytes are equal returns 0 (s1 == s2), else return 
 * negative if s1 is greater than s2 (s1 > s2), and 
 * positive if s1 is less than s2 (s1 < s2).
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * Find the byte c first occurrence in the first n bytes of memory area s.
 * Both c and the bytes of the memory area s are interpreted as unsigned char.
 * @param s Memory area.
 * @param c Byte to search.
 * @param n Bytes to scan.
 * @return Pointer to the matching byte, or NULL if not found.
*/
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * Compare the first n bytes of memory areas s1 and s2, each interpreted as 
 * unsigned char.
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Bytes to compare.
 * @return If the first n bytes are equal returns 0 (s1 == s2), else return 
 * negative if s1 is greater than s2 (s1 > s2), and 
 * positive if s1 is less than s2 (s1 < s2).
*/
int	ft_memcmp(const char *s1, const char *s2, size_t n);
/**
 * Locates the first occurrence of the null-terminated string little in the 
 * string big, where not more than len bytes are searched.
 * Bytes after a '\0' are not searched.
 * @param big String where to search.
 * @param little String to search.
 * @param len Bytes to search.
 * @return big if little is an empty string; NULL if little is not in big; 
 * Pointer to the first byte of the first occurrence of little otherwise.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/**
 * Converts the initial portion of the string nptr to int.
 * The string may begin with an arbitrary amount of white space, followed by a
 * single optional '+' or '-' sign.
 * Stops when there is a digit that is not part of base 10.
 * @param nptr String to convert
 * @return Integer from string.
*/
int		ft_atoi(const char *nptr);
/**
 * Allocate memory for an array of nmemb elements of size bytes each and 
 * returns a pointer to the allocated memory. The memory is set to 0.
 * @param nmemb Number of members
 * @param size Size of each member
 * @return Pointer to allocated memory. NULL if the allocation fails or if the 
 * multiplication result in overflow.
*/
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * Duplicate the string s. The pointer can be freed with free(3).
 * @param s String to duplicate
 * @return Pointer to the string. NULL if the allocation fails.
*/
char	*ft_strdup(const char *s);
/**
 * Allocates (with malloc(3)) and returns a substring from the string 's'.
 * The substring begins at index 'start and is of maximum size 'len'.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocations fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * Allocates (with malloc(3)) and returns a new string, which is the result of 
 * the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * Allocates (with malloc(3)) and returns a copy of 's1' with the characters 
 * specified in 'set' removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);
/**
 * Allocates (with malloc(3)) and returns an array of strings obtained by 
 * splitting 's' using the character 'c' as a delimiter.
 * The array must end with a NULL pointer.
 * @param The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the 
 * allocation fails.
*/
char	**ft_split(char const *s, char c);
/**
 * Allocates (with malloc(3)) and returns a string representing the integer 
 * received as an argument. Negative numbers must be handled.
 * @param n the integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
*/
char	*ft_itoa(int n);
/**
 * Applies the function 'f' to each character of the string 's', and passing 
 * its index as first argument to create a new string (with malloc(3)) 
 * resulting from successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'. 
 * Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * Applies the function 'f' on each character of the string passed as argument, 
 * passing its index as first argument. Each character is passed by address to 
 * 'f' to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putchar_fd(char c, int fd);
/**
 * Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putstr_fd(char *s, int fd);
/**
 * Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
*/
void	ft_putnbr_fd(int n, int fd);
/*
	BONUS PART
*/
/**
 * Allocates (with malloc(3)) and returns a new node. The member variable 
 * 'content' is initialized with the value of the parameter 'content'. The 
 * variable 'next' is initialized to NULL.
 * @param content: The content to create the node with.
 * @return The new node.
*/
t_list	*ft_lstnew(void *content);
/**
 * Adds the node 'new' at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new: The address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
*/
int	ft_lstsize(t_list *lst);
/**
 * Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);
/**
 * Adds the node 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * Takes as a parameter a node and frees the memory of the node’s content using 
 * the function ’del’ given as a parameter and free the node. The memory of 
 * 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * Deletes and frees the given node and every successor of that node, using the 
 * function 'del' and free(3). Finally, the pointer to the list must be set to 
 * NULL.
 * @param lst The address of a pointer to a node.
 * @param del the address of the function used to delete the content of the 
 * node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * Iterates the list 'lst' and applies the function 'f' on the content of each 
 * node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * Iterates the list 'lst' and applies the function 'f' on the content of each 
 * node. Creates a new list resulting of the successive applications of the 
 * function 'f'. The 'del' function is used to delete the content of a node if 
 * needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node 
 * if needed.
 * @return The new list. NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
