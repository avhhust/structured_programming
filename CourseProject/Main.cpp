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
		stand(42, 10, 12, 7, "Додавання даних");
		stand(42, 12, 0, 15, "Вивід даних");
		stand(42, 14, 0, 15, "Відбір даних");
		stand(42, 16, 0, 15, "Видалення даних");
		stand(42, 18, 0, 15, "Сортування даних");
		stand(42, 20, 0, 15, "Редагування даних");
		stand(42, 22, 0, 15, "Вихід");
		int cur = 1, p = 1;

		while (p) {
			int k = _getch();
			if (k == 80) {
				if (cur < 7) {
					cur++;
					if (cur == 2) {
						stand(42, 10, 0, 15, "Додавання даних");
						stand(42, 12, 12, 7, "Вивід даних");
					}
					else if (cur == 3) {
						stand(42, 12, 0, 15, "Вивід даних");
						stand(42, 14, 12, 7, "Відбір даних");
					}
					else if (cur == 4) {
						stand(42, 14, 0, 15, "Відбір даних");
						stand(42, 16, 12, 7, "Видалення даних");
					}
					else if (cur == 5) {
						stand(42, 16, 0, 15, "Видалення даних");
						stand(42, 18, 12, 7, "Сортування даних");
					}
					else if (cur == 6) {
						stand(42, 18, 0, 15, "Сортування даних");
						stand(42, 20, 12, 7, "Редагування даних");
					}
					else if (cur == 7) {
						stand(42, 20, 0, 15, "Редагування даних");
						stand(42, 22, 12, 7, "Вихід");
					}
				}
			}
			else if (k == 72) {
				if (cur > 1) {
					cur--;
					if (cur == 6) {
						stand(42, 20, 12, 7, "Редагування даних");
						stand(42, 22, 0, 15, "Вихід");
					}
					else if (cur == 5) {
						stand(42, 18, 12, 7, "Сортування даних");
						stand(42, 20, 0, 15, "Редагування даних");
					}
					else if (cur == 4) {
						stand(42, 16, 12, 7, "Видалення даних");
						stand(42, 18, 0, 15, "Сортування даних");
					}
					else if (cur == 3) {
						stand(42, 14, 12, 7, "Відбір даних");
						stand(42, 16, 0, 15, "Видалення даних");
					}
					else if (cur == 2) {
						stand(42, 12, 12, 7, "Вивід даних");
						stand(42, 14, 0, 15, "Відбір даних");
					}
					else if (cur == 1) {
						stand(42, 10, 12, 7, "Додавання даних");
						stand(42, 12, 0, 15, "Вивід даних");
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