#define ESC 27
#define QUIT 3
#define WIRED_MODE 5
#define FILLED_MODE 6
#define TOP_VIEW 7
#define LEFT_SIDE_VIEW 8
#define BEHIND_VIEW 9
#define PRESPECTIVE_VIEW 10

void mainMenu(int option);
void viewMenu(int option);
void polygonModeMenu(int option);
void createMenu();

extern double rotate_y;
extern double rotate_x;
extern double zoom;
