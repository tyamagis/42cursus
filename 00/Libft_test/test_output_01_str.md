## test 8 : strlen#### size_t strlen(const char *s)s1 = "", strlen(s1) = 0
s2 = "a", strlen(s2) = 1
s3 = "", strlen(s3) = 0
s4 = "abcdefghij", strlen(s4) = 10
## test 9 : strlcpy#### size_t strlcpy(char *dst, const char *src, size_t dstsize)set char dst1 = 123
set const char src1 = 1234567
set size_t dstsize1 = strlen(dst1) = (3)
dst1_len = 3, src1_len = 7, dstsize = 3 
strlcpy done.
test 1 : ret is 7 
## test10 : strlcat#### size_t strlcat(char *dst, const char *src, size_t dstsize)## test11 : strchr#### char *strchr(const char *s, int c)## test12 : strrchr#### char *strrchr(const char *s, int c)## test13 : strnstr#### char *strnstr(const char *haystack, const char *needle, size_t len)## test14 : strncmp#### int strncmp(const char *s1, const char *s2, size_t n)