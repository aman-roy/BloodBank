#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#include <termios.h>
#include <sys/time.h>
#include <errno.h>   
#include <unistd.h> 

#include "../include/utilities.h"
#include "../include/color.h"
#include "../include/tree.h"

#define MAXPW 32

int takeChoice(int start, int end)
{
    char num[10];
    int result;
    int error = 0;
    while(1) 
    {
        if (error)
        {
            printf(TC_RED TD_BOLD"\t\t\t Wrong Choice!\n");
            removeDecoration();
        }

        printf(TD_BOLD "\t\t\tEnter Choice: _\b");
        scanf("%s", num);
        if(strlen(num) > 2)
        {
            error = 1;
            continue;
        }

        for (int i = 0; i < strlen(num); ++i)
        {
            if(!isdigit(num[i]))
            {
                error = 1;
                continue;
            }
        }
        result = atoi(num);

        if(result >= start && result <= end)
            break;
        error = 1;
    }
    removeDecoration();
    return result;
}

void dbError()
{
	printf(TC_RED TD_BOLD"\t\t\tDatabase malfuntion! Create DB first.\n");
    sleep(2);
    removeDecoration();
}

FILE* loadFile(char fName)
{
    FILE *fptr = NULL;
    if (fName == 'a')
    {
        fptr = fopen("./database/acceptor.dat", "rb");
        if (!fptr)
           dbError();
    }
    else if (fName == 'd')
    {
        fptr = fopen("./database/donor.dat", "rb");
        if (!fptr)
           dbError();
    }

    return fptr;
}


void dbSetup()
{
    FILE *fp = fopen("./database/acceptor.dat", "ab+");
    fclose(fp);
    fp = fopen("./database/donor.dat", "ab+");
    fclose(fp);
}

int wantsToChange(char* question)
{
    int ch;
    printf("\t\tYou want to modify %s.[1(yes)/0(no)]: ", question);
    scanf("%d", &ch);
    return ch;
}

int isIdUnique(int newID)
{
    struct idTreeNode* root = getTreeID();
    if (searchTree(root, newID))
        return 0;
    else
        return 1;
}


ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp)
{
    if (!pw || !sz || !fp) return -1;       /* validate input   */
    #ifdef MAXPW
        if (sz > MAXPW) sz = MAXPW;
    #endif

    if (*pw == NULL) {              /* reallocate if no address */
        void *tmp = realloc (*pw, sz * sizeof **pw);
        if (!tmp)
            return -1;
        memset (tmp, 0, sz);    /* initialize memory to 0   */
        *pw = tmp;
    }

    size_t idx = 0;         /* index, number of chars in read   */
    int c = 0;

    struct termios old_kbd_mode;    /* orig keyboard settings   */
    struct termios new_kbd_mode;

    if (tcgetattr (0, &old_kbd_mode)) { /* save orig settings   */
        fprintf (stderr, "%s() error: tcgetattr failed.\n", __func__);
        return -1;
    }   /* copy old to new */
    memcpy (&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);  /* new kbd flags */
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    if (tcsetattr (0, TCSANOW, &new_kbd_mode)) {
        fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
        return -1;
    }

    /* read chars from fp, mask if valid char specified */
    while (((c = fgetc (fp)) != '\n' && c != EOF && idx < sz - 1) ||
            (idx == sz - 1 && c == 127))
    {
        if (c != 127) {
            if (31 < mask && mask < 127)    /* valid ascii char */
                fputc (mask, stdout);
            (*pw)[idx++] = c;
        }
        else if (idx > 0) {         /* handle backspace (del)   */
            if (31 < mask && mask < 127) {
                fputc (0x8, stdout);
                fputc (' ', stdout);
                fputc (0x8, stdout);
            }
            (*pw)[--idx] = 0;
        }
    }
    (*pw)[idx] = 0; /* null-terminate   */

    /* reset original keyboard  */
    if (tcsetattr (0, TCSANOW, &old_kbd_mode)) {
        fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
        return -1;
    }

    if (idx == sz - 1 && c != '\n') /* warn if pw truncated */
        fprintf (stderr, " (%s() warning: truncated at %zu chars.)\n",
                __func__, sz - 1);

    return idx; /* number of chars in passwd    */
}


int getMode()
{
    char username[20];
    printf(TD_BOLD TC_WHITE"\t\t\tEnter username: _____\b\b\b\b\b");
    scanf("%s", username);

    char t;
    scanf("%c", &t);

    char pw[MAXPW] = {0};
    char *p = pw;
    FILE *fp = stdin;
    ssize_t nchr = 0;

    printf ("\t\t\tEnter password: ");
    nchr = getpasswd (&p, MAXPW, '*', fp);

    if(strcmp(username, "admin") == 0 && strcmp(p, "admin") == 0)
        return 1;
    else if(strcmp(username, "guest") == 0 && strcmp(p, "guest") == 0)
        return 2;
    else 
        return 0;
}