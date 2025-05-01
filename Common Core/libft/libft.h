#ifndef	LIBFT_H
#define	LIBFT_H



int	ft_atoi(const char *str);
void	*ft_bzero(void *s, size_t n);
void	*ft_bzero(void *s, size_t n);
int	ft_isalnum (int str);
int	ft_isalpha(int str);
int	ft_isascii(int str);
int	ft_isdigit(int str);
int	ft_isprint(int str);
char	*ft_itoa(int n);
void	*memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int,char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif