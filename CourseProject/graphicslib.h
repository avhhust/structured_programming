#include "mainlib.h"

void setCursor(int x, int y);
void setColor(int text, int background);
void stand(int x, int y, int k, int l, const char* str);
void drawMenu(int pos_x1, int pos_x2, int pos_y1, int pos_y2, int text, int backg);
void drawHeadTab();
void printRawsTab(PC* CATALOG, int n);
void printchar(int i);
int preMenuSel();
int preMenuInp();
int preMenuSort(int l);
int preMenuDel();
int menuField();
int preMenuEdit();
int preMenuSel();
int preMenuSel2();
int preMenuOut();
int menuFieldCap();
int menuFieldType();