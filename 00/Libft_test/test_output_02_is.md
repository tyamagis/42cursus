## test16 : isalpha
#### int isalpha(int c)

### [test cases]
#### [i, 'c', return]
[ -9, '?', 0], [ -8, '?', 0], [ -7, '?', 0], [ -6, '?', 0], [ -5, '?', 0], [ -4, '?', 0], [ -3, '?', 0], [ -2, '?', 0], [ -1, '?', 0], [  0, ' ', 0]
[  1, '', 0], [  2, '', 0], [  3, '', 0], [  4, '', 0], [  5, '', 0], [  6, '', 0], [  7, '', 0], [  8, '', 0], [  9, '	', 0], [ 10, '
', 0]
[ 11, '', 0], [ 12, '', 0], [ 13, '', 0], [ 14, '', 0], [ 15, '', 0], [ 16, '', 0], [ 17, '', 0], [ 18, '', 0], [ 19, '', 0], [ 20, '', 0]
[ 21, '', 0], [ 22, '', 0], [ 23, '', 0], [ 24, '', 0], [ 25, '', 0], [ 26, '', 0], [ 27, '', 0], [ 28, '', 0], [ 29, '', 0], [ 30, '', 0]
[ 31, '', 0], [ 32, ' ', 0], [ 33, '!', 0], [ 34, '"', 0], [ 35, '#', 0], [ 36, '$', 0], [ 37, '%', 0], [ 38, '&', 0], [ 39, ''', 0], [ 40, '(', 0]
[ 41, ')', 0], [ 42, '*', 0], [ 43, '+', 0], [ 44, ',', 0], [ 45, '-', 0], [ 46, '.', 0], [ 47, '/', 0], [ 48, '0', 0], [ 49, '1', 0], [ 50, '2', 0]
[ 51, '3', 0], [ 52, '4', 0], [ 53, '5', 0], [ 54, '6', 0], [ 55, '7', 0], [ 56, '8', 0], [ 57, '9', 0], [ 58, ':', 0], [ 59, ';', 0], [ 60, '<', 0]
[ 61, '=', 0], [ 62, '>', 0], [ 63, '?', 0], [ 64, '@', 0], [ 65, 'A', 1], [ 66, 'B', 1], [ 67, 'C', 1], [ 68, 'D', 1], [ 69, 'E', 1], [ 70, 'F', 1]
[ 71, 'G', 1], [ 72, 'H', 1], [ 73, 'I', 1], [ 74, 'J', 1], [ 75, 'K', 1], [ 76, 'L', 1], [ 77, 'M', 1], [ 78, 'N', 1], [ 79, 'O', 1], [ 80, 'P', 1]
[ 81, 'Q', 1], [ 82, 'R', 1], [ 83, 'S', 1], [ 84, 'T', 1], [ 85, 'U', 1], [ 86, 'V', 1], [ 87, 'W', 1], [ 88, 'X', 1], [ 89, 'Y', 1], [ 90, 'Z', 1]
[ 91, '[', 0], [ 92, '\', 0], [ 93, ']', 0], [ 94, '^', 0], [ 95, '_', 0], [ 96, '`', 0], [ 97, 'a', 1], [ 98, 'b', 1], [ 99, 'c', 1], [100, 'd', 1]
[101, 'e', 1], [102, 'f', 1], [103, 'g', 1], [104, 'h', 1], [105, 'i', 1], [106, 'j', 1], [107, 'k', 1], [108, 'l', 1], [109, 'm', 1], [110, 'n', 1]
[111, 'o', 1], [112, 'p', 1], [113, 'q', 1], [114, 'r', 1], [115, 's', 1], [116, 't', 1], [117, 'u', 1], [118, 'v', 1], [119, 'w', 1], [120, 'x', 1]
[121, 'y', 1], [122, 'z', 1], [123, '{', 0], [124, '|', 0], [125, '}', 0], [126, '~', 0], [127, '', 0], [128, '?', 0], 
## test17 : isdigit
#### int isdigit(int c)

i:   0 ' ', return:0
i:   1 '', return:0	i:   2 '', return:0	i:   3 '', return:0	i:   4 '', return:0
i:   5 '', return:0	i:   6 '', return:0	i:   7 '', return:0	i:   8 '', return:0
i:   9 '	', return:0	i:  10 '
', return:0	i:  11 '', return:0	i:  12 '', return:0
i:  13 '', return:0	i:  14 '', return:0	i:  15 '', return:0	i:  16 '', return:0
i:  17 '', return:0	i:  18 '', return:0	i:  19 '', return:0	i:  20 '', return:0
i:  21 '', return:0	i:  22 '', return:0	i:  23 '', return:0	i:  24 '', return:0
i:  25 '', return:0	i:  26 '', return:0	i:  27 '', return:0	i:  28 '', return:0
i:  29 '', return:0	i:  30 '', return:0	i:  31 '', return:0	i:  32 ' ', return:0
i:  33 '!', return:0	i:  34 '"', return:0	i:  35 '#', return:0	i:  36 '$', return:0
i:  37 '%', return:0	i:  38 '&', return:0	i:  39 ''', return:0	i:  40 '(', return:0
i:  41 ')', return:0	i:  42 '*', return:0	i:  43 '+', return:0	i:  44 ',', return:0
i:  45 '-', return:0	i:  46 '.', return:0	i:  47 '/', return:0	i:  48 '0', return:1
i:  49 '1', return:1	i:  50 '2', return:1	i:  51 '3', return:1	i:  52 '4', return:1
i:  53 '5', return:1	i:  54 '6', return:1	i:  55 '7', return:1	i:  56 '8', return:1
i:  57 '9', return:1	i:  58 ':', return:0	i:  59 ';', return:0	i:  60 '<', return:0
i:  61 '=', return:0	i:  62 '>', return:0	i:  63 '?', return:0	i:  64 '@', return:0
i:  65 'A', return:0	i:  66 'B', return:0	i:  67 'C', return:0	i:  68 'D', return:0
i:  69 'E', return:0	i:  70 'F', return:0	i:  71 'G', return:0	i:  72 'H', return:0
i:  73 'I', return:0	i:  74 'J', return:0	i:  75 'K', return:0	i:  76 'L', return:0
i:  77 'M', return:0	i:  78 'N', return:0	i:  79 'O', return:0	i:  80 'P', return:0
i:  81 'Q', return:0	i:  82 'R', return:0	i:  83 'S', return:0	i:  84 'T', return:0
i:  85 'U', return:0	i:  86 'V', return:0	i:  87 'W', return:0	i:  88 'X', return:0
i:  89 'Y', return:0	i:  90 'Z', return:0	i:  91 '[', return:0	i:  92 '\', return:0
i:  93 ']', return:0	i:  94 '^', return:0	i:  95 '_', return:0	i:  96 '`', return:0
i:  97 'a', return:0	i:  98 'b', return:0	i:  99 'c', return:0	i: 100 'd', return:0
i: 101 'e', return:0	i: 102 'f', return:0	i: 103 'g', return:0	i: 104 'h', return:0
i: 105 'i', return:0	i: 106 'j', return:0	i: 107 'k', return:0	i: 108 'l', return:0
i: 109 'm', return:0	i: 110 'n', return:0	i: 111 'o', return:0	i: 112 'p', return:0
i: 113 'q', return:0	i: 114 'r', return:0	i: 115 's', return:0	i: 116 't', return:0
i: 117 'u', return:0	i: 118 'v', return:0	i: 119 'w', return:0	i: 120 'x', return:0
i: 121 'y', return:0	i: 122 'z', return:0	i: 123 '{', return:0	i: 124 '|', return:0
i: 125 '}', return:0	i: 126 '~', return:0	i: 127 '', return:0	i: 128 '?', return:0

## test18 : isalnum
#### int isalnum(int c)

i:   0 ' ', return:0
i:   1 '', return:0	i:   2 '', return:0	i:   3 '', return:0	i:   4 '', return:0
i:   5 '', return:0	i:   6 '', return:0	i:   7 '', return:0	i:   8 '', return:0
i:   9 '	', return:0	i:  10 '
', return:0	i:  11 '', return:0	i:  12 '', return:0
i:  13 '', return:0	i:  14 '', return:0	i:  15 '', return:0	i:  16 '', return:0
i:  17 '', return:0	i:  18 '', return:0	i:  19 '', return:0	i:  20 '', return:0
i:  21 '', return:0	i:  22 '', return:0	i:  23 '', return:0	i:  24 '', return:0
i:  25 '', return:0	i:  26 '', return:0	i:  27 '', return:0	i:  28 '', return:0
i:  29 '', return:0	i:  30 '', return:0	i:  31 '', return:0	i:  32 ' ', return:0
i:  33 '!', return:0	i:  34 '"', return:0	i:  35 '#', return:0	i:  36 '$', return:0
i:  37 '%', return:0	i:  38 '&', return:0	i:  39 ''', return:0	i:  40 '(', return:0
i:  41 ')', return:0	i:  42 '*', return:0	i:  43 '+', return:0	i:  44 ',', return:0
i:  45 '-', return:0	i:  46 '.', return:0	i:  47 '/', return:0	i:  48 '0', return:1
i:  49 '1', return:1	i:  50 '2', return:1	i:  51 '3', return:1	i:  52 '4', return:1
i:  53 '5', return:1	i:  54 '6', return:1	i:  55 '7', return:1	i:  56 '8', return:1
i:  57 '9', return:1	i:  58 ':', return:0	i:  59 ';', return:0	i:  60 '<', return:0
i:  61 '=', return:0	i:  62 '>', return:0	i:  63 '?', return:0	i:  64 '@', return:0
i:  65 'A', return:1	i:  66 'B', return:1	i:  67 'C', return:1	i:  68 'D', return:1
i:  69 'E', return:1	i:  70 'F', return:1	i:  71 'G', return:1	i:  72 'H', return:1
i:  73 'I', return:1	i:  74 'J', return:1	i:  75 'K', return:1	i:  76 'L', return:1
i:  77 'M', return:1	i:  78 'N', return:1	i:  79 'O', return:1	i:  80 'P', return:1
i:  81 'Q', return:1	i:  82 'R', return:1	i:  83 'S', return:1	i:  84 'T', return:1
i:  85 'U', return:1	i:  86 'V', return:1	i:  87 'W', return:1	i:  88 'X', return:1
i:  89 'Y', return:1	i:  90 'Z', return:1	i:  91 '[', return:0	i:  92 '\', return:0
i:  93 ']', return:0	i:  94 '^', return:0	i:  95 '_', return:0	i:  96 '`', return:0
i:  97 'a', return:1	i:  98 'b', return:1	i:  99 'c', return:1	i: 100 'd', return:1
i: 101 'e', return:1	i: 102 'f', return:1	i: 103 'g', return:1	i: 104 'h', return:1
i: 105 'i', return:1	i: 106 'j', return:1	i: 107 'k', return:1	i: 108 'l', return:1
i: 109 'm', return:1	i: 110 'n', return:1	i: 111 'o', return:1	i: 112 'p', return:1
i: 113 'q', return:1	i: 114 'r', return:1	i: 115 's', return:1	i: 116 't', return:1
i: 117 'u', return:1	i: 118 'v', return:1	i: 119 'w', return:1	i: 120 'x', return:1
i: 121 'y', return:1	i: 122 'z', return:1	i: 123 '{', return:0	i: 124 '|', return:0
i: 125 '}', return:0	i: 126 '~', return:0	i: 127 '', return:0	i: 128 '?', return:0

## test19 : isascii
#### int isascii(int c)

i:   0 ' ', return:1
i:   1 '', return:1	i:   2 '', return:1	i:   3 '', return:1	i:   4 '', return:1
i:   5 '', return:1	i:   6 '', return:1	i:   7 '', return:1	i:   8 '', return:1
i:   9 '	', return:1	i:  10 '
', return:1	i:  11 '', return:1	i:  12 '', return:1
i:  13 '', return:1	i:  14 '', return:1	i:  15 '', return:1	i:  16 '', return:1
i:  17 '', return:1	i:  18 '', return:1	i:  19 '', return:1	i:  20 '', return:1
i:  21 '', return:1	i:  22 '', return:1	i:  23 '', return:1	i:  24 '', return:1
i:  25 '', return:1	i:  26 '', return:1	i:  27 '', return:1	i:  28 '', return:1
i:  29 '', return:1	i:  30 '', return:1	i:  31 '', return:1	i:  32 ' ', return:1
i:  33 '!', return:1	i:  34 '"', return:1	i:  35 '#', return:1	i:  36 '$', return:1
i:  37 '%', return:1	i:  38 '&', return:1	i:  39 ''', return:1	i:  40 '(', return:1
i:  41 ')', return:1	i:  42 '*', return:1	i:  43 '+', return:1	i:  44 ',', return:1
i:  45 '-', return:1	i:  46 '.', return:1	i:  47 '/', return:1	i:  48 '0', return:1
i:  49 '1', return:1	i:  50 '2', return:1	i:  51 '3', return:1	i:  52 '4', return:1
i:  53 '5', return:1	i:  54 '6', return:1	i:  55 '7', return:1	i:  56 '8', return:1
i:  57 '9', return:1	i:  58 ':', return:1	i:  59 ';', return:1	i:  60 '<', return:1
i:  61 '=', return:1	i:  62 '>', return:1	i:  63 '?', return:1	i:  64 '@', return:1
i:  65 'A', return:1	i:  66 'B', return:1	i:  67 'C', return:1	i:  68 'D', return:1
i:  69 'E', return:1	i:  70 'F', return:1	i:  71 'G', return:1	i:  72 'H', return:1
i:  73 'I', return:1	i:  74 'J', return:1	i:  75 'K', return:1	i:  76 'L', return:1
i:  77 'M', return:1	i:  78 'N', return:1	i:  79 'O', return:1	i:  80 'P', return:1
i:  81 'Q', return:1	i:  82 'R', return:1	i:  83 'S', return:1	i:  84 'T', return:1
i:  85 'U', return:1	i:  86 'V', return:1	i:  87 'W', return:1	i:  88 'X', return:1
i:  89 'Y', return:1	i:  90 'Z', return:1	i:  91 '[', return:1	i:  92 '\', return:1
i:  93 ']', return:1	i:  94 '^', return:1	i:  95 '_', return:1	i:  96 '`', return:1
i:  97 'a', return:1	i:  98 'b', return:1	i:  99 'c', return:1	i: 100 'd', return:1
i: 101 'e', return:1	i: 102 'f', return:1	i: 103 'g', return:1	i: 104 'h', return:1
i: 105 'i', return:1	i: 106 'j', return:1	i: 107 'k', return:1	i: 108 'l', return:1
i: 109 'm', return:1	i: 110 'n', return:1	i: 111 'o', return:1	i: 112 'p', return:1
i: 113 'q', return:1	i: 114 'r', return:1	i: 115 's', return:1	i: 116 't', return:1
i: 117 'u', return:1	i: 118 'v', return:1	i: 119 'w', return:1	i: 120 'x', return:1
i: 121 'y', return:1	i: 122 'z', return:1	i: 123 '{', return:1	i: 124 '|', return:1
i: 125 '}', return:1	i: 126 '~', return:1	i: 127 '', return:1	i: 128 '?', return:0

## test20 : isprint
#### int isprint(int c)

i:   0 ' ', return:0
i:   1 '', return:0	i:   2 '', return:0	i:   3 '', return:0	i:   4 '', return:0
i:   5 '', return:0	i:   6 '', return:0	i:   7 '', return:0	i:   8 '', return:0
i:   9 '	', return:0	i:  10 '
', return:0	i:  11 '', return:0	i:  12 '', return:0
i:  13 '', return:0	i:  14 '', return:0	i:  15 '', return:0	i:  16 '', return:0
i:  17 '', return:0	i:  18 '', return:0	i:  19 '', return:0	i:  20 '', return:0
i:  21 '', return:0	i:  22 '', return:0	i:  23 '', return:0	i:  24 '', return:0
i:  25 '', return:0	i:  26 '', return:0	i:  27 '', return:0	i:  28 '', return:0
i:  29 '', return:0	i:  30 '', return:0	i:  31 '', return:0	i:  32 ' ', return:1
i:  33 '!', return:1	i:  34 '"', return:1	i:  35 '#', return:1	i:  36 '$', return:1
i:  37 '%', return:1	i:  38 '&', return:1	i:  39 ''', return:1	i:  40 '(', return:1
i:  41 ')', return:1	i:  42 '*', return:1	i:  43 '+', return:1	i:  44 ',', return:1
i:  45 '-', return:1	i:  46 '.', return:1	i:  47 '/', return:1	i:  48 '0', return:1
i:  49 '1', return:1	i:  50 '2', return:1	i:  51 '3', return:1	i:  52 '4', return:1
i:  53 '5', return:1	i:  54 '6', return:1	i:  55 '7', return:1	i:  56 '8', return:1
i:  57 '9', return:1	i:  58 ':', return:1	i:  59 ';', return:1	i:  60 '<', return:1
i:  61 '=', return:1	i:  62 '>', return:1	i:  63 '?', return:1	i:  64 '@', return:1
i:  65 'A', return:1	i:  66 'B', return:1	i:  67 'C', return:1	i:  68 'D', return:1
i:  69 'E', return:1	i:  70 'F', return:1	i:  71 'G', return:1	i:  72 'H', return:1
i:  73 'I', return:1	i:  74 'J', return:1	i:  75 'K', return:1	i:  76 'L', return:1
i:  77 'M', return:1	i:  78 'N', return:1	i:  79 'O', return:1	i:  80 'P', return:1
i:  81 'Q', return:1	i:  82 'R', return:1	i:  83 'S', return:1	i:  84 'T', return:1
i:  85 'U', return:1	i:  86 'V', return:1	i:  87 'W', return:1	i:  88 'X', return:1
i:  89 'Y', return:1	i:  90 'Z', return:1	i:  91 '[', return:1	i:  92 '\', return:1
i:  93 ']', return:1	i:  94 '^', return:1	i:  95 '_', return:1	i:  96 '`', return:1
i:  97 'a', return:1	i:  98 'b', return:1	i:  99 'c', return:1	i: 100 'd', return:1
i: 101 'e', return:1	i: 102 'f', return:1	i: 103 'g', return:1	i: 104 'h', return:1
i: 105 'i', return:1	i: 106 'j', return:1	i: 107 'k', return:1	i: 108 'l', return:1
i: 109 'm', return:1	i: 110 'n', return:1	i: 111 'o', return:1	i: 112 'p', return:1
i: 113 'q', return:1	i: 114 'r', return:1	i: 115 's', return:1	i: 116 't', return:1
i: 117 'u', return:1	i: 118 'v', return:1	i: 119 'w', return:1	i: 120 'x', return:1
i: 121 'y', return:1	i: 122 'z', return:1	i: 123 '{', return:1	i: 124 '|', return:1
i: 125 '}', return:1	i: 126 '~', return:1	i: 127 '', return:0	i: 128 '?', return:0

## test21 : toupper
#### int toupper(int c)

i:   0 ' ', return:0
i:   1 '', return:1	i:   2 '', return:2	i:   3 '', return:3	i:   4 '', return:4
i:   5 '', return:5	i:   6 '', return:6	i:   7 '', return:7	i:   8 '', return:8
i:   9 '	', return:9	i:  10 '
', return:10	i:  11 '', return:11	i:  12 '', return:12
i:  13 '', return:13	i:  14 '', return:14	i:  15 '', return:15	i:  16 '', return:16
i:  17 '', return:17	i:  18 '', return:18	i:  19 '', return:19	i:  20 '', return:20
i:  21 '', return:21	i:  22 '', return:22	i:  23 '', return:23	i:  24 '', return:24
i:  25 '', return:25	i:  26 '', return:26	i:  27 '', return:27	i:  28 '', return:28
i:  29 '', return:29	i:  30 '', return:30	i:  31 '', return:31	i:  32 ' ', return:32
i:  33 '!', return:33	i:  34 '"', return:34	i:  35 '#', return:35	i:  36 '$', return:36
i:  37 '%', return:37	i:  38 '&', return:38	i:  39 ''', return:39	i:  40 '(', return:40
i:  41 ')', return:41	i:  42 '*', return:42	i:  43 '+', return:43	i:  44 ',', return:44
i:  45 '-', return:45	i:  46 '.', return:46	i:  47 '/', return:47	i:  48 '0', return:48
i:  49 '1', return:49	i:  50 '2', return:50	i:  51 '3', return:51	i:  52 '4', return:52
i:  53 '5', return:53	i:  54 '6', return:54	i:  55 '7', return:55	i:  56 '8', return:56
i:  57 '9', return:57	i:  58 ':', return:58	i:  59 ';', return:59	i:  60 '<', return:60
i:  61 '=', return:61	i:  62 '>', return:62	i:  63 '?', return:63	i:  64 '@', return:64
i:  65 'A', return:65	i:  66 'B', return:66	i:  67 'C', return:67	i:  68 'D', return:68
i:  69 'E', return:69	i:  70 'F', return:70	i:  71 'G', return:71	i:  72 'H', return:72
i:  73 'I', return:73	i:  74 'J', return:74	i:  75 'K', return:75	i:  76 'L', return:76
i:  77 'M', return:77	i:  78 'N', return:78	i:  79 'O', return:79	i:  80 'P', return:80
i:  81 'Q', return:81	i:  82 'R', return:82	i:  83 'S', return:83	i:  84 'T', return:84
i:  85 'U', return:85	i:  86 'V', return:86	i:  87 'W', return:87	i:  88 'X', return:88
i:  89 'Y', return:89	i:  90 'Z', return:90	i:  91 '[', return:91	i:  92 '\', return:92
i:  93 ']', return:93	i:  94 '^', return:94	i:  95 '_', return:95	i:  96 '`', return:96
i:  97 'a', return:65	i:  98 'b', return:66	i:  99 'c', return:67	i: 100 'd', return:68
i: 101 'e', return:69	i: 102 'f', return:70	i: 103 'g', return:71	i: 104 'h', return:72
i: 105 'i', return:73	i: 106 'j', return:74	i: 107 'k', return:75	i: 108 'l', return:76
i: 109 'm', return:77	i: 110 'n', return:78	i: 111 'o', return:79	i: 112 'p', return:80
i: 113 'q', return:81	i: 114 'r', return:82	i: 115 's', return:83	i: 116 't', return:84
i: 117 'u', return:85	i: 118 'v', return:86	i: 119 'w', return:87	i: 120 'x', return:88
i: 121 'y', return:89	i: 122 'z', return:90	i: 123 '{', return:123	i: 124 '|', return:124
i: 125 '}', return:125	i: 126 '~', return:126	i: 127 '', return:127	i: 128 '?', return:128

## test22 : tolwer
#### int tolower(int c)

i:   0 ' ', return:0
i:   1 '', return:1	i:   2 '', return:2	i:   3 '', return:3	i:   4 '', return:4
i:   5 '', return:5	i:   6 '', return:6	i:   7 '', return:7	i:   8 '', return:8
i:   9 '	', return:9	i:  10 '
', return:10	i:  11 '', return:11	i:  12 '', return:12
i:  13 '', return:13	i:  14 '', return:14	i:  15 '', return:15	i:  16 '', return:16
i:  17 '', return:17	i:  18 '', return:18	i:  19 '', return:19	i:  20 '', return:20
i:  21 '', return:21	i:  22 '', return:22	i:  23 '', return:23	i:  24 '', return:24
i:  25 '', return:25	i:  26 '', return:26	i:  27 '', return:27	i:  28 '', return:28
i:  29 '', return:29	i:  30 '', return:30	i:  31 '', return:31	i:  32 ' ', return:32
i:  33 '!', return:33	i:  34 '"', return:34	i:  35 '#', return:35	i:  36 '$', return:36
i:  37 '%', return:37	i:  38 '&', return:38	i:  39 ''', return:39	i:  40 '(', return:40
i:  41 ')', return:41	i:  42 '*', return:42	i:  43 '+', return:43	i:  44 ',', return:44
i:  45 '-', return:45	i:  46 '.', return:46	i:  47 '/', return:47	i:  48 '0', return:48
i:  49 '1', return:49	i:  50 '2', return:50	i:  51 '3', return:51	i:  52 '4', return:52
i:  53 '5', return:53	i:  54 '6', return:54	i:  55 '7', return:55	i:  56 '8', return:56
i:  57 '9', return:57	i:  58 ':', return:58	i:  59 ';', return:59	i:  60 '<', return:60
i:  61 '=', return:61	i:  62 '>', return:62	i:  63 '?', return:63	i:  64 '@', return:64
i:  65 'A', return:97	i:  66 'B', return:98	i:  67 'C', return:99	i:  68 'D', return:100
i:  69 'E', return:101	i:  70 'F', return:102	i:  71 'G', return:103	i:  72 'H', return:104
i:  73 'I', return:105	i:  74 'J', return:106	i:  75 'K', return:107	i:  76 'L', return:108
i:  77 'M', return:109	i:  78 'N', return:110	i:  79 'O', return:111	i:  80 'P', return:112
i:  81 'Q', return:113	i:  82 'R', return:114	i:  83 'S', return:115	i:  84 'T', return:116
i:  85 'U', return:117	i:  86 'V', return:118	i:  87 'W', return:119	i:  88 'X', return:120
i:  89 'Y', return:121	i:  90 'Z', return:122	i:  91 '[', return:91	i:  92 '\', return:92
i:  93 ']', return:93	i:  94 '^', return:94	i:  95 '_', return:95	i:  96 '`', return:96
i:  97 'a', return:97	i:  98 'b', return:98	i:  99 'c', return:99	i: 100 'd', return:100
i: 101 'e', return:101	i: 102 'f', return:102	i: 103 'g', return:103	i: 104 'h', return:104
i: 105 'i', return:105	i: 106 'j', return:106	i: 107 'k', return:107	i: 108 'l', return:108
i: 109 'm', return:109	i: 110 'n', return:110	i: 111 'o', return:111	i: 112 'p', return:112
i: 113 'q', return:113	i: 114 'r', return:114	i: 115 's', return:115	i: 116 't', return:116
i: 117 'u', return:117	i: 118 'v', return:118	i: 119 'w', return:119	i: 120 'x', return:120
i: 121 'y', return:121	i: 122 'z', return:122	i: 123 '{', return:123	i: 124 '|', return:124
i: 125 '}', return:125	i: 126 '~', return:126	i: 127 '', return:127	i: 128 '?', return:128

