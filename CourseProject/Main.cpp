#include "mainlib.h"
#include "graphicslib.h"
#include "filelib.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("mode con cols=110 lines=40");
	int h = 0, N = strkol();
	while (!h)
	{
		drawMenu(42, 67, 9, 23, 8, 15);
		stand(42, 10, 12, 7, "��������� �����");
		stand(42, 12, 0, 15, "���� �����");
		stand(42, 14, 0, 15, "³��� �����");
		stand(42, 16, 0, 15, "��������� �����");
		stand(42, 18, 0, 15, "���������� �����");
		stand(42, 20, 0, 15, "����������� �����");
		stand(42, 22, 0, 15, "�����");
		int cur = 1, p = 1;

		while (p) {
			int k = _getch();
			if (k == 80) {
				if (cur < 7) {
					cur++;
					if (cur == 2) {
						stand(42, 10, 0, 15, "��������� �����");
						stand(42, 12, 12, 7, "���� �����");
					}
					else if (cur == 3) {
						stand(42, 12, 0, 15, "���� �����");
						stand(42, 14, 12, 7, "³��� �����");
					}
					else if (cur == 4) {
						stand(42, 14, 0, 15, "³��� �����");
						stand(42, 16, 12, 7, "��������� �����");
					}
					else if (cur == 5) {
						stand(42, 16, 0, 15, "��������� �����");
						stand(42, 18, 12, 7, "���������� �����");
					}
					else if (cur == 6) {
						stand(42, 18, 0, 15, "���������� �����");
						stand(42, 20, 12, 7, "����������� �����");
					}
					else if (cur == 7) {
						stand(42, 20, 0, 15, "����������� �����");
						stand(42, 22, 12, 7, "�����");
					}
				}
			}
			else if (k == 72) {
				if (cur > 1) {
					cur--;
					if (cur == 6) {
						stand(42, 20, 12, 7, "����������� �����");
						stand(42, 22, 0, 15, "�����");
					}
					else if (cur == 5) {
						stand(42, 18, 12, 7, "���������� �����");
						stand(42, 20, 0, 15, "����������� �����");
					}
					else if (cur == 4) {
						stand(42, 16, 12, 7, "��������� �����");
						stand(42, 18, 0, 15, "���������� �����");
					}
					else if (cur == 3) {
						stand(42, 14, 12, 7, "³��� �����");
						stand(42, 16, 0, 15, "��������� �����");
					}
					else if (cur == 2) {
						stand(42, 12, 12, 7, "���� �����");
						stand(42, 14, 0, 15, "³��� �����");
					}
					else if (cur == 1) {
						stand(42, 10, 12, 7, "��������� �����");
						stand(42, 12, 0, 15, "���� �����");
					}
				}
			}
			else if (k == 13) {
				setColor(15, 0);
				system("cls");
				switch (cur) 
				{
					case 1:{
						int l = preMenuInp();
						Input(l);
						break;
					}
					case 2:
						Output(2);
						break;
					case 3:
						Select();
						break;
					case 4:
						Delete(N);
						break;
					case 5:
						Sort();
						break;
					case 6:
						Edit();
						break;
					case 7:{
						setColor(1, 0);
						system("cls");
						exit(1);
						break;
					}
				}
				system("cls");
				k = 0;
				cur = 0;
				p = 0;
			}
		}
	}
	return 0;
}