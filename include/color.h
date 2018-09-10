#ifndef COLOR_H_  
#define COLOR_H_

// Text decoration
#define TD_DEFAULT "\x1b[0m"
#define TD_BOLD "\x1b[1m"
#define TD_UNDERLINE "\x1b[4m"
#define TD_BLINK "\x1b[5m"
#define TD_BOLDOFF "\x1b[21m"
#define TD_UNDERLINEOFF "\x1b[24m"
#define TD_BLINKOFF "\x1b[25m"

// Text color
#define TC_BLACK "\x1b[30m"
#define TC_RED "\x1b[31m"
#define TC_GREEN "\x1b[32m"
#define TC_YELLOW "\x1b[33m"
#define TC_BLUE "\x1b[34m"
#define TC_MAGENTA "\x1b[35m"
#define TC_CYAN "\x1b[36m"
#define TC_WHITE "\x1b[37m"
#define TC_DEFAULT "\x1b[39m"
#define TC_LGRAY "\x1b[90m"
#define TC_LRED "\x1b[91m"
#define TC_LGREEN "\x1b[92m"
#define TC_LYELLOW "\x1b[93m"
#define TC_LBLUE "\x1b[94m"
#define TC_LMAGENTA "\x1b[95m"
#define TC_LCYAN "\x1b[96m"
#define TC_LWHITE "\x1b[97m"

// Background Colors
#define BCK_BLACK "\x1b[40m"
#define BCK_RED "\x1b[41m"
#define BCK_GREEN "\x1b[42m"
#define BCK_YELLOW "\x1b[43m"
#define BCK_BLUE "\x1b[44m"
#define BCK_MAGENTA "\x1b[45m"
#define BCK_CYAN "\x1b[46m"
#define BCK_WHITE "\x1b[47m"
#define BCK_DEFAULT "\x1b[49m"
#define BCK_LGRAY "\x1b[100m"
#define BCK_LRED "\x1b[101m"
#define BCK_LGREEN "\x1b[102m"
#define BCK_LYELLOW "\x1b[103m"
#define BCK_LBLUE "\x1b[104m"
#define BCK_LMAGENTA "\x1b[105m"
#define BCK_LCYAN "\x1b[106m"
#define BCK_LWHITE "\x1b[107m"

#define removeDecoration() printf(TD_DEFAULT)

#endif