#include "mainlib.h"
#include "filelib.h"
#include "graphicslib.h"
#include "validlib.h"

struct PC {
	int number;//����� ������ ��� �������������
	char manufacture[45];//����� ����� ���������
	int type;//��� ����'�����
	double capacity_ram;//��'�� ���������� ���'��
	int capacity_hdd;//��'�� ������������
	char TV_ch[3];//�������� ��-������ (��� ��� �)
};
//--------------------------------------------------------------
void Input(int point)
{
	setColor(15, 0);
	system("cls");
	if (point == 1)
	{
		inputData(2);
	}
	else if (point == 2)
	{
		inputData(1);
	}
	else if (point != 0) {
		setColor(11, 0);
		printf("��� ������ ������!");
		_getch();
	}
}
void Output(int point)
{
	int N = strkol();
	PC* CATALOG = readFromFile(N);
	if (point == 1) {
		setColor(15, 0);
		system("cls");
		drawHeadTab();
		printRawsTab(CATALOG, N);
	}
	else {
		int l = preMenuOut();
		if (l == 1) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG, N);
			_getch();
		}
		else if (l == 2) {
			setColor(15, 0);
			system("cls");
			char fname[256];
			printf("������ ����� �����, � ���� ���� ������� �� ������(���������� �� �������): ");
			scanf("%s", fname);
			strcat(fname, ".txt");
			printToTxtF(CATALOG, N, fname);
			setColor(11, 0);
			printf("��� ������ �������� � ���� %s!", fname);
			_getch();
		}
	}
}
void Sort()
{
	int N = strkol();
	if (N == 0) {
		stand(0, 0, 12, 0, "���� ����� �������!!!");
		_getch();
		return;
	}
	PC* CATALOG = readFromFile(N);
	PC* tmp = new PC[N];
	int r = 0, l = 0, temp = 0;
	l = menuField();
	if (l == 1) {
		int i, j;
		temp = preMenuSort(l);
		//����������� ���������� ������� �����
		if (temp == 1) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].number < CATALOG[j - r].number)// < - ��� ���������� �� ����������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else if (temp == 2) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].number > CATALOG[j - r].number)// > - ��� ���������� �� ��������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
	}
	else if (l == 2)
	{
		temp = preMenuSort(l);
		//����������� ���������� ����������
		if (temp == 1)
		{
			for (int i = 0; i < N - 1; i++)
				for (int j = i + 1; j < N; j++)
				{
					if (strcmp(CATALOG[i].manufacture, CATALOG[j].manufacture) < 0) // < � ��� ������������� �� ����������
					{
						tmp[0] = CATALOG[i];
						CATALOG[i] = CATALOG[j];
						CATALOG[j] = tmp[0];
					}
				}
		}
		else if (temp == 2) {
			for (int i = 0; i < N - 1; i++)
				for (int j = i + 1; j < N; j++)
				{
					if (strcmp(CATALOG[i].manufacture, CATALOG[j].manufacture) > 0) // > � ��� ������������� �� ���������
					{
						tmp[0] = CATALOG[i];
						CATALOG[i] = CATALOG[j];
						CATALOG[j] = tmp[0];
					}
				}
		}
		else return;
	}
	else if (l == 3) {
		unsigned i, j;
		temp = preMenuSort(l);
		//����������� ���������� ������� �����
		if (temp == 1) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].type < CATALOG[j - r].type)// < - ��� ���������� �� ����������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else if (temp == 2) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].type > CATALOG[j - r].type)// > - ��� ���������� �� ��������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
	}
	else if (l == 4)
	{
		temp = preMenuSort(l);
		unsigned i, j;
		//����������� ���������� ������� �����
		if (temp == 1) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].capacity_ram < CATALOG[j - r].capacity_ram)// < - ��� ���������� �� ����������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else if (temp == 2) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].capacity_ram > CATALOG[j - r].capacity_ram)// > - ��� ���������� �� ��������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else return;
	}
	else if (l == 5)
	{
		unsigned i, j;
		temp = preMenuSort(l);
		//����������� ���������� ������� �����
		if (temp == 1) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].capacity_hdd < CATALOG[j - r].capacity_hdd)// < - ��� ���������� �� ����������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else if (temp == 2) {
			for (r = N / 2; r > 0; r /= 2) {
				for (i = r; i < N; i++) {
					tmp[0] = CATALOG[i];
					for (j = i; j >= r; j -= r) {
						if (tmp[0].capacity_hdd > CATALOG[j - r].capacity_hdd)// > - ��� ���������� �� ��������
						{
							CATALOG[j] = CATALOG[j - r];
						}
						else break;
					}
					CATALOG[j] = tmp[0];
				}
			}
		}
		else return;
	}
	else if (l == 6)
	{
		temp = preMenuSort(l);
		//����������� ���������� ����������
		if (temp == 1)
		{
			for (int i = 0; i < N - 1; i++)
				for (int j = i + 1; j < N; j++)
				{
					if (strcmp(CATALOG[i].TV_ch, "���") < 0) // < � ��� ������������� �� ����������
					{
						tmp[0] = CATALOG[i];
						CATALOG[i] = CATALOG[j];
						CATALOG[j] = tmp[0];
					}
				}
		}
		else if (temp == 2) {
			for (int i = 0; i < N - 1; i++)
				for (int j = i + 1; j < N; j++)
				{
					if (strcmp(CATALOG[i].TV_ch, "�") > 0) // > � ��� ������������� �� ���������
					{
						tmp[0] = CATALOG[i];
						CATALOG[i] = CATALOG[j];
						CATALOG[j] = tmp[0];
					}
				}
		}
		else return;
	}
	if (l != -1 && temp != -1) {
		printToFile(CATALOG, N);
		Output(1);
		_getch();
	}
	delete[] tmp;
}
void Edit()
{
	int N = strkol();
	if (N == 0) {
		stand(0, 0, 12, 0, "���� ����� �������!!!");
		_getch();
		return;
	}
	int k = 0, r, h = 0, l = 0, g = 0;
	PC* CATALOG = readFromFile(N);
	char str[50];
	Output(1);
	setCursor(22, N + 4);
	printf("������ ��� ��, ����� ����� ������ ������: ");
	while (1)
	{
		scanf("%s", str);
		if (checkNum(str)) {
			r = atoi(str);
			break;
		}
		else {
			g++;
			setColor(12, 0);
			setCursor(22, N + 4+g);
			printf("\a������� ��������� ���...�������� ������: ");
			setColor(15, 0);
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (r == CATALOG[i].number) h++;
	}
	if (h == 0) {
		setCursor(22, N + 5+g);
		printf("� ��� �� ���� ������ ����������������� ����");
		_getch();
	}
	else {
		l = preMenuEdit();
		system("cls");
		setColor(15, 0);
		if (l == 1) {
			char str[50];
			printf("������ ���� ����� �����-���������: ");
			while (1)
			{
				scanf("%s", str);
				if (checkWord(str) == false) {
					setColor(12, 0);
					printf("\a������� ����������� �����!!!...�������� ������: ");
					setColor(15, 0);
				}
				else {
					for (int i = 0; i < N; i++)
						if (CATALOG[i].number == r) {
							strcpy(CATALOG[i].manufacture, str);
						}
					break;
				}
			}
		}
		if (l == 2) {
			printf("������ ����� ��� ��\n(1) ��������� (2) �������� (3) ������ (4) �������: : ");
			while (1) {
				scanf("%s", str);
				if (checkNum(str) == 1 && (atoi(str) <= 4 && atoi(str) >= 1)) {
					for (int i = 0; i < N; i++)
						if (CATALOG[i].number == r) {
							CATALOG[i].type = atoi(str);
						}
					break;
				}
				else {
					setColor(12, 0);
					printf("\a������� ��������� ���...�������� ������: ");
					setColor(15, 0);
				}
			}
		}
		if (l == 3) {
			printf("������ ����� ����� ���������� ���'��: ");
			while (1) {
				scanf("%s", str);
				if (checkFNum(str) == 1 && (atof(str) > 0 && atof(str) <= 256)) {
					for (int i = 0; i < N; i++)
						if (CATALOG[i].number == r) {
							CATALOG[i].capacity_ram = atof(str);
						}
					break;
				}
				else {
					setColor(12, 0);
					printf("\a������� ��������� ���...�������� ���: ");
					setColor(15, 0);
				}
				fflush(stdin);
			}
		}
		if (l == 4) {
			printf("������ ����� ����� ������������: ");
			while (1) {
				scanf("%s", str);
				if (checkNum(str) == 1 && atoi(str) > 0) {
					for (int i = 0; i < N; i++)
						if (CATALOG[i].number == r) {
							CATALOG[i].capacity_hdd = atoi(str);
						}
					break;
				}
				else {
					setColor(12, 0);
					printf("\a������� ��������� ���...�������� ���: ");
					setColor(15, 0);
				}
			}
		}
		if (l == 5) {
			printf("������ ��� ��� ��� �������� ��-������(���/�): ");
			while (1)
			{
				scanf("%s", str);
				if ((strcmp(str, "���") == 0 || strcmp(str, "�") == 0)) {
					for (int i = 0; i < N; i++)
						if (CATALOG[i].number == r) {
							strcpy(CATALOG[i].TV_ch, str);
						}
					break;
				}
				else {

					setColor(12, 0);
					printf("\a������� ����������� �����!!!...�������� ������: ");
					setColor(15, 0);
				}
			}
		}
		printToFile(CATALOG, N);
		setColor(11, 0);
		if (l < 6) {
			setColor(11, 0);
			printf("��� ������ ������!");
			_getch();
		}
	}
}
void Delete(int& N)
{
	PC* CATALOG = readFromFile(N);
	if (N == 0) {
		stand(0, 0, 12, 0, "���� ����� �������!!!");
		_getch();
		return;
	}
	PC t;
	PC* CATALOG2 = new PC[N];
	int tmp = preMenuDel();
	int ch = 0, n = 0, m = 0, temp;
	double chf = 0;
	char str[50], * str_1;
	if (tmp == 1) {
		Output(1);
		setColor(15, 0);
		setCursor(22, N + 4);
		printf("������ ��� ��, ����� ����� ������ ��������: ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1) { ch = atoi(str); break; }
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���!!!...��������� �� ���: ");
				setColor(15, 0);
			}
		}
		for (int i = 0; i < N; i++)
			if (CATALOG[i].number == ch && (i + 1) < N) {
				t = CATALOG[i];
				CATALOG[i] = CATALOG[i + 1];
				CATALOG[i + 1] = t;
			}
		if (CATALOG[N - 1].number == ch) {
			printToFile(CATALOG, --N);
			Output(1);
			setColor(11, 0);
			setCursor(22, N + 4);
			printf("����� ��� �� � ������� ������� %d ������ ��������!", ch);
		}
		else {
			setColor(15, 0);
			system("cls");
			stand(0, 0, 12, 0, "� ��� �� ���� �� � ����� ������� �������!!!");
		}
	}
	else if (tmp == 2) {
		Output(1);
		setCursor(22, N + 4);
		int g = 0;
		printf("������ ����� �����-��������� ��: ");
		while (1) {
			scanf("%s", str);
			if (checkWord(str) == false) {
				g++;
				setCursor(22, N + 4+g);
				setColor(12, 0);
				printf("\a������� ����������� �����!!!...�������� ������: ");
				setColor(15, 0);
			}
			else break;
		}
		for (int i = 0; i < N; i++)
			if ((strcmp(CATALOG[i].manufacture, str) != 0)) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
			else if ((strcmp(CATALOG[i].manufacture, str) == 0)) m++;
		if (m == N) {
			printToFile(CATALOG2, 0);
			Output(1);
			setCursor(22, (N + 4) - (N - m));
			setColor(15, 0);
			printf("����� ��� �� ����� %s ������ ��������!", str);
		}
		else if (n != 0 && n != N) {
			printToFile(CATALOG2, n);
			Output(1);
			setCursor(22, (N + 4) - (N - n));
			setColor(15, 0);
			printf("������ ��� �� ����� %s ������ ��������!", str);
		}
		else {
			system("cls");
			setColor(12, 0);
			printf("� ��� �� �� �� ����� %s", str);
		}
	}
	else if (tmp == 3) {
		Output(1);
		setCursor(22, N + 4);
		printf("������� ��� �� ������ ��� ���������\n");
		setCursor(22, N + 5);
		printf("(1 - ���������, 2 - ��������, 3 - ������, 4 - �������): ");
		while (1)
		{
			scanf("%s", str);
			if (checkNum(str) == 1 && (atoi(str) <= 4 && atoi(str) >= 1)) {
				ch = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				setCursor(22, N + 4);
				printf("������ ����� (1, 2, 3, 4) ��� ������ �������: ");
				setColor(15, 0);
			}
		}
		if (ch == 1) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].type != 1) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].type != ch) m++;
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ������� ��");
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				setCursor(22, n + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ������� ��");
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� ���� ��������� ��");
			}
		}
		else if (ch == 2) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].type != 2) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].type == 2) m++;
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ���������");
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				setCursor(22, n + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ���������");
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� ���� ������ ��� ���������");
			}
		}
		else if (ch == 3) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].type != 3) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].type == 3) m++;
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� �������");
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				setCursor(22, n + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� �������");
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� ���� ������ ��� �������");
			}
		}
		else if (ch == 4) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].type != 4) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].type == 4) m++;
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ����� ��");
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				setCursor(22, n + 4);
				setColor(15, 0);
				printf("������ �������� ������ ��� ����� ��");
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� ���� ������ ��� ����� ��");
			}
		}
	}
	else if (tmp == 4) {
		setColor(15, 0);
		system("cls");
		printf("������ ����� ��� ��������� �� ��'��� RAM( < 12))\n(̳� ������ �� ������ ������� ���� �������)\nRAM ");
		while (1) {
			gets_s(str);
			temp = checkCondition(str);
			str_1 = strchr(str, ' ');
			if (temp == 0) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...�������������� ������� \" < = > \" �� �����.\nRAM ");
				setColor(15, 0);
				continue;
			}
			else if (str_1 == NULL) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...̳� ������ �� ������ ������� ���� �������\nRAM ");
				setColor(15, 0);
				continue;
			}
			else {
				str_1 = strchr(str, ' ');
				if (checkFNum(str_1) == 0) {
					chf = atof(str_1);
					break;
				}
			}
		}
		if (temp == 1) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_ram >= chf) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_ram < chf) m++;
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM ������ %.1f ��", chf);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				N = strkol();
				Output(1);
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM ������ %.1f ��", chf);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� RAM ������ %.1f ��", chf);
			}
		}
		else if (temp == 2) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_ram <= chf) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_ram > chf) {
					m++;
				}
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM ������ %.1f ��", chf);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM ������ %.1f ��", chf);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� RAM ������ %.1f ��", chf);
			}
		}
		else if (temp == 3) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_ram != chf)
				{
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_ram == chf)
				{
					m++;
				}
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM = %.1f ��", chf);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� RAM = %.1f ��", chf);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� RAM = %.1f ��", chf);
			}
		}
	}
	else if (tmp == 5) {
		setColor(15, 0);
		system("cls");
		printf("������ ����� ��� ��������� �� ��'��� HDD( = 256)\n(̳� ������ �� ������ ������� ���� �������)\nHDD ");
		while (1) {
			gets_s(str);
			temp = checkCondition(str);
			temp = checkCondition(str);
			str_1 = strchr(str, ' ');
			if (temp == 0) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...�������������� ������� \" < = > \" �� �����.\nHDD ");
				setColor(15, 0);
				continue;
			}
			else if (str_1 == NULL) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...̳� ������ �� ������ ������� ���� �������\nHDD ");
				setColor(15, 0);
				continue;
			}
			else {
				str_1 = strchr(str, ' ');
				if (checkFNum(str_1) == 0) {
					ch = atoi(str_1);
					break;
				}
			}
		}
		if (temp == 1) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_hdd >= ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_hdd < ch) {
					m++;
				}
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD ������ %d ��", ch);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD ������ %d ��", ch);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� HDD ������ %d ��", ch);
			}
		}
		else if (temp == 2) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_hdd <= ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_hdd > ch) {
					m++;
				}
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD ������ %d ��", ch);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD ������ %d ��", ch);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� HDD ������ %d ��", ch);
			}
		}
		else if (temp == 3) {
			for (int i = 0; i < N; i++)
				if (CATALOG[i].capacity_hdd != ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
				else if (CATALOG[i].capacity_hdd == ch) {
					m++;
				}
			if (m == N) {
				printToFile(CATALOG2, 0);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD = %d ��", ch);
			}
			else if (n != 0 && n != N) {
				printToFile(CATALOG2, n);
				Output(1);
				N = strkol();
				setCursor(22, N + 4);
				setColor(15, 0);
				printf("�������� ������ � ���� ��'�� HDD = %d��", ch);
			}
			else {
				system("cls");
				setColor(12, 0);
				printf("� ��� �� �� ��, � ���� ����� HDD = %d ��", ch);
			}
		}
	}
	else if (tmp == 6) {
		char str2[5];
		Output(1);
		setCursor(22, N + 4);
		printf("�������� ������ ��� �� ( 1 - � �� | 2 - ��� �� ): ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1 && (atoi(str) == 1 || atoi(str) == 2)) {
				ch = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				setCursor(22, N + 4);
				printf("������ ����� 1 ��� 2 ��� ������ �������: ");
				setColor(15, 0);
			}
		}
		if (ch == 1) strcpy(str2, "���");
		else strcpy(str2, "�");
		for (int i = 0; i < N; i++) {
			if (strcmp(CATALOG[i].TV_ch, str2) != 0) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
			else if (strcmp(CATALOG[i].TV_ch, str2) == 0) m++;
		}
		if (m == N) {
			printToFile(CATALOG2, 0);
			Output(1);
			setCursor(22, (N + 4) - N - m);
			setColor(15, 0);
			if (ch == 1) {
				printf("������ �������� ������ ��� �� � �������� ��-�������");
			}
			else { printf("������ �������� ������ ��� �� ��� ��-������"); }
		}
		else if (n != 0 && n != N) {
			printToFile(CATALOG2, n);
			Output(1);
			setCursor(22, (N + 4) - (N - n));
			setColor(15, 0);
			if (ch == 1) printf("������ �������� ������ ��� �� � �������� ��-�������");
			else printf("������ �������� ������ ��� �� ��� ��-������");
		}
		else {
			system("cls");
			setColor(12, 0);
			if (ch == 1) printf("� ��� �� ���� �� � ��-�������!!!");
			else printf("� ��� �� ���� �� ��� ��-������!!!");
		}
	}
	else if (tmp == 0) {
		system("cls");
		printToFile(CATALOG, 0);
		Output(1);
		stand(22, 4, 11, 0, "�� ������ �������!");
	}
	if (tmp != -1) _getch();
	delete[] CATALOG2;
}
void Select()
{
	int N = strkol();
	if (N == 0) {
		stand(0, 0, 12, 0, "���� ����� �������!!!");
		_getch();
		return;
	}
	PC* CATALOG = readFromFile(N);
	PC* CATALOG2 = new PC[N];
	char str[50], * str_1;
	int ch, temp, n = 0, j = 0;
	double chf = 0;
	int tmp = preMenuSel();
	if (tmp == 1) {
		setColor(15, 0);
		system("cls");
		printf("������ ��� ��: ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1) {
				ch = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���!!!...��������� �� ���: ");
				setColor(15, 0);
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].number == ch) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� �� � ����� ������� �������!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 2) {
		setColor(15, 0);
		system("cls");
		printf("������ ����� �����-���������: ");
		while (1) {
			scanf("%s", str);
			if (checkWord(str) == false) {
				setColor(12, 0);
				printf("\a������� ����������� �����!!!...�������� ������: ");
				setColor(15, 0);
			}
			else break;
		}
		for (int i = 0; i < N; i++) {
			if (strcmp(CATALOG[i].manufacture, str) == 0)
			{
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		if (n != 0) {
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� �� ���� �����!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 3) {
		setColor(15, 0);
		system("cls");
		printf("������� ��� ��\n");
		printf("(1 - ���������, 2 - ��������, 3 - ������, 4 - �������): ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1 && (atoi(str) <= 4 && atoi(str) >= 1)) {
				ch = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("������ ����� (1, 2, 3, 4) ��� ������ �������: ");
				setColor(15, 0);
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].type == ch) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		if (n != 0) {
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� �� ������ ����!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 4) {
		setColor(15, 0);
		system("cls");
		printf("������ ����� �� ���� ����� �� ��'��� RAM( > 4)\n(̳� ������ �� ������ ������� ���� �������)\nRAM ");
		while (1) {
			gets_s(str);
			temp = checkCondition(str);
			str_1 = strchr(str, ' ');
			if (temp == 0) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...�������������� ������� \" < = > \" �� �����.\nRAM ");
				setColor(15, 0);
				continue;
			}
			else if (str_1 == NULL) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...̳� ������ �� ������ ������� ���� �������\nRAM ");
				setColor(15, 0);
			}
			else {
				str_1 = strchr(str, ' ');
				if (checkFNum(str_1) == 0) {
					chf = atof(str_1);
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (temp == 3) {
				if (CATALOG[i].capacity_ram == chf) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			else if (temp == 1) {
				if (CATALOG[i].capacity_ram < chf) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			else if (temp == 2) {
				if (CATALOG[i].capacity_ram > chf) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
		}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� �� � ����� ��'���� RAM!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 5) {
		setColor(15, 0);
		system("cls");
		printf("������ ����� �� ���� ����� �� ��'��� �����( > 4)\n(̳� ������ �� ������ ������� ���� �������)\nHDD ");
		while (1) {
			gets_s(str);
			temp = checkCondition(str);
			str_1 = strchr(str, ' ');
			if (temp == 0) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...�������������� ������� \" < = > \" �� �����.\nHDD ");
				setColor(15, 0);
				continue;
			}
			else if (str_1 == NULL) {
				setColor(12, 0);
				printf("����� ������� ����������!!!...̳� ������ �� ������ ������� ���� �������\nHDD ");
				setColor(15, 0);
				continue;
			}
			else {
				if (checkFNum(str_1) == 0) {
					ch = atoi(str_1);
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (temp == 3) {
				if (CATALOG[i].capacity_hdd == ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			else if (temp == 1) {
				if (CATALOG[i].capacity_hdd < ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			else if (temp == 2) {
				if (CATALOG[i].capacity_hdd > ch) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
		}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� �� � ����� ��'���� �����!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 6) {
		char str2[5];
		setColor(15, 0);
		system("cls");
		printf("������ ����� �� ���� ��\n( 1 - � ��-������� | 2 - ��� ��-������ ): ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1 && (atoi(str) == 1 || atoi(str) == 2)) {
				ch = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("������ ����� 1 ��� 2 ��� ������ �������: ");
				setColor(15, 0);
			}
		}
		if (ch == 1) strcpy(str2, "���");
		else strcpy(str2, "�");
		for (int i = 0; i < N; i++)
			if (strcmp(CATALOG[i].TV_ch, str2) == 0) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
		}
		else {
			setColor(12, 0);
			if (ch == 1) {
				printf("� ��� �� ���� �� � �������� ��-�������!!!");
			}
			else if (ch == 2) {
				printf("� ��� �� ���� �� ��� ��������� ��-������!!!");
			}
			setColor(15, 0);
		}
	}
	else if (tmp == 7) {
		setColor(15, 0);
		system("cls");
		for (int i = 0; i < N; i++)
			if (strcmp(CATALOG[i].TV_ch, "���") == 0 && CATALOG[i].type == 1) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
			setCursor(22, n + 4);
			if (n >= 5) printf("�������� %d ������", n);
			else if (n == 1) printf("�������� %d �����", n);
			else printf("�������� %d ������", n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� ��������� �� � ��-�������!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 8) {
		setColor(15, 0);
		system("cls");
		char fname[] = { "Select.txt" };
		for (int i = 0; i < N; i++)
			if ((strcmp(CATALOG[i].manufacture, "Acer") == 0 || strcmp(CATALOG[i].manufacture, "Lenovo") == 0) && CATALOG[i].type == 3) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		if (n != 0) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, n);
			printToTxtF(CATALOG2, n, fname);
			setCursor(22, n + 4);
			if (n >= 5) printf("�������� %d ������ �� ������ ������ � ��������� ����", n);
			else printf("�������� %d ������ �� ������ ������ � ��������� ����", n);
		}
		else {
			setColor(12, 0);
			printf("� ��� �� ���� ������� ����� Acer ��� Lenovo!!!");
			setColor(15, 0);
		}
	}
	else if (tmp == 9) {
		setColor(15, 0);
		system("cls");
		int tmp2 = menuFieldCap();
		if (tmp2 == 1) {
			CATALOG2 = search(j, 1);
		}
		else if (tmp2 == 2) {
			CATALOG2 = search(j, 2);
		}
		else if (tmp2 == 3) {
			CATALOG2 = search(j, 3);
		}
		if (tmp2 != -1) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, j);
		}
		else if (tmp2 == -1) tmp = -1;
	}
	else if (tmp == 10) {
		setColor(15, 0);
		system("cls");
		int tmp2 = menuFieldCap();
		if (tmp2 == 1) {
			CATALOG2 = search(j, 4);
		}
		else if (tmp2 == 2) {
			CATALOG2 = search(j, 5);
		}
		else if (tmp2 == 3) {
			CATALOG2 = search(j, 6);
		}
		if (tmp2 != -1) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, j);
		}
		else if (tmp2 == -1) tmp = -1;
	}
	else if (tmp == 11) {
		setColor(15, 0);
		system("cls");
		int tmp2 = menuFieldCap();
		if (tmp2 == 1) {
			CATALOG2 = search(j, 7);
		}
		else if (tmp2 == 2) {
			CATALOG2 = search(j, 8);
		}
		else if (tmp2 == 3) {
			CATALOG2 = search(j, 9);
		}
		if (tmp2 != -1) {
			setColor(15, 0);
			system("cls");
			drawHeadTab();
			printRawsTab(CATALOG2, j);
		}
		else if (tmp2 == -1) tmp = -1;
	}
	else if (tmp == 12) {
		setColor(15, 0);
		system("cls");
		int tmp2 = menuFieldType();
		if (tmp2 < 5 && tmp2>0) {
			for (int i = 0; i < N; i++) {
				if (CATALOG[i].type == tmp2) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			search(CATALOG2, n, 1);
		}
		else if (tmp2 == 5) {
			search(CATALOG, N, 3);
		}
		else if (tmp2 == -1) tmp = -1;
	}
	else if (tmp == 13) {
		setColor(15, 0);
		system("cls");
		int tmp2 = menuFieldType();
		if (tmp2 < 5 && tmp2 > 0) {
			for (int i = 0; i < N; i++) {
				if (CATALOG[i].type == tmp2) {
					CATALOG2[n] = CATALOG[i];
					n++;
				}
			}
			search(CATALOG2, n, 2);
		}
		else if (tmp2 == 5) {
			search(CATALOG, N, 4);
		}
		else if (tmp2 == -1) tmp = -1;
	}
	if (tmp != -1) _getch();
	delete[] CATALOG2;
}
void inputData(int ch)
{
	int N = strkol();
	int kol, i, num;
	char str[50];
	FILE* fp;
	if ((fp = fopen("DataBase", "a+b")) == NULL) {
		stand(0, 0, 12, 0, "\a������� �������� ����� DataBase!");
		exit(0);
	}
	printf("������ ������� ������: ");
	while (1) {
		scanf("%s", str);
		if (checkNum(str) == 1) {
			kol = atoi(str);
			break;
		}
		else {
			setColor(12, 0);
			printf("\a������� ��������� ���!!!...��������� �� ���: ");
			setColor(15, 0);
		}
	}
	printf("\n");
	PC* CATALOG = new PC[kol];
	for (i = 0; i < kol; i++)
	{
		num = checkIndex(i, N);
		CATALOG[i].number = num;
		printf("������ ����� �����-���������: ");
		while (1) {
			scanf("%s", CATALOG[i].manufacture);
			if (checkWord(CATALOG[i].manufacture) == false) {
				setColor(12, 0);
				printf("\a������� ����������� �����!!!...�������� ������: ");
				setColor(15, 0);
			}
			else break;
		}
		printf("������ ��� ��\n(1) ��������� (2) �������� (3) ������ (4) �������: ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1 && (atoi(str) <= 4 && atoi(str) >= 1)) {
				CATALOG[i].type = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���...�������� ������: ");
				setColor(15, 0);
			}
		}
		printf("������ ����� ���������� ���'��: ");
		while (1) {
			scanf("%s", str);
			if (checkFNum(str) == 1 && (atof(str) > 0 && atof(str) <= 256)) {
				CATALOG[i].capacity_ram = atof(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���...�������� ���: ");
				setColor(15, 0);
			}
		}
		printf("������ ����� ������������: ");
		while (1) {
			scanf("%s", str);
			if (checkNum(str) == 1 && atoi(str) > 0) {
				CATALOG[i].capacity_hdd = atoi(str);
				break;
			}
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���...�������� ���: ");
				setColor(15, 0);
			}
		}
		printf("������ �������� ��-������(���/�): ");
		while (1) {
			scanf("%s", CATALOG[i].TV_ch);
			if ((strcmp(CATALOG[i].TV_ch, "���") == 0 || strcmp(CATALOG[i].TV_ch, "�") == 0)) break;
			else {
				setColor(12, 0);
				printf("\a������� ��������� ���...�������� ���: ");
				setColor(15, 0);
			}
		}
		if (ch == 1) {
			fwrite(&CATALOG[i], sizeof(PC), 1, fp);
		}
		printf("\n");
	}
	if (ch == 2)
	{
		PC* CATALOG2 = new PC[N];
		i = 0;
		while (i < N) {
			if (i == 0) rewind(fp);
			fread(&CATALOG2[i], sizeof(PC), 1, fp);
			i++;
		}
		fclose(fp);
		if ((fp = fopen("DataBase", "wb")) == NULL) {
			stand(0, 0, 12, 0, "\a������� �������� ����� DataBase!");
			exit(0);
		}
		for (int i = 0; i < kol; i++)
		{
			fwrite(&CATALOG[i], sizeof(PC), 1, fp);
		}
		fclose(fp);
		if ((fp = fopen("DataBase", "ab")) == NULL) {
			stand(0, 0, 12, 0, "\a������� �������� ����� DataBase!");
			exit(0);
		}
		for (int i = 0; i < N; i++)
		{
			fwrite(&CATALOG2[i], sizeof(PC), 1, fp);
		}
		N += kol;
		delete[] CATALOG2;
	}
	fclose(fp);
	delete[] CATALOG;
}
//----------------------������� �������------------------------
void setCursor(int x, int y) //��������� ������� �� ������� ��������� x,y
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
}
void setColor(int text, int background)
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, (WORD)((background << 4) | text));
}
void printchar(int i)
{
	SetConsoleOutputCP(866);
	switch (i)
	{
	case 1:
		cout << (char)179; //�
		break;
	case 2:
		cout << (char)196; //=
		break;
	case 3:
		cout << (char)218; //�
		break;
	case 4:
		cout << (char)217; //_l
		break;
	case 5:
		cout << (char)192; //L
		break;
	case 6:
		cout << (char)191; //�
		break;
	case 7:
		cout << (char)195; //l-
		break;
	case 8:
		cout << (char)180; //l-
		break;
	case 9:
		cout << (char)219; //_l
		break;
	case 0:
		cout << (char)223; //L
		break;
	case 10:
		cout << (char)220; //�
		break;
	case 11:
		cout << (char)194;
		break;
	case 12:
		cout << (char)197;
		break;
	}
}
void stand(int x, int y, int k, int l, const char* str)
{
	HANDLE  H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = 0;
	ci.dwSize = 100;
	SetConsoleCursorInfo(H, &ci); //������ �������� ������
	setCursor(x, y);
	setColor(k, l);
	cout << str << "\n";
}
void printToFile(PC* CATALOG, int N) {
	FILE* fp;
	if ((fp = fopen("DataBase", "w+b")) == NULL) {
		stand(0, 0, 12, 0, "\a������� �������� ����� DataBase!");
		exit(0);
	}
	for (int i = 0; i < N; i++)
	{
		fwrite(&CATALOG[i], sizeof(PC), 1, fp);
	}
	fclose(fp);
}
int strkol()
{
	int count = 1;
	char c;
	FILE* f1;
	PC tmp;
	f1 = fopen("DataBase", "rb");
	if (f1 == NULL) {
		if ((f1 = fopen("DataBase", "w+b")) == NULL) {
			stand(0, 0, 12, 0, "\a������� �������� ��������� ����!");
			exit(0);
		}
		return 0;
	}
	while (fread(&tmp, sizeof(PC), 1, f1)) {
		count++;
	}
	fclose(f1);
	return --count;
}
int checkCondition(char str[])
{
	if (strncmp(str, "<", 1) == 0) {
		return 1;
	}
	else if (strncmp(str, ">", 1) == 0) {
		return 2;
	}
	else if (strncmp(str, "=", 1) == 0) {
		return 3;
	}
	else return 0;
}
int checkIndex(int i, int N) {
	PC* CATALOG = readFromFile(N);
	int num = (N + i) + 1;
	for (int j = 0; j < N; j++)
		if (CATALOG[j].number == num) num++;
	return num;
}
bool checkWord(char c[])
{
	bool ch = true;
	//���� �������� ����� ����� �� ��������� �� �������
	for (int j = 0; c[j] != 0; j++)
		if (!(IsCharAlpha(c[j])) && c[j] != char(95))// ���� IsCharAlpha �� ����� (���� ������� �������� �� ����� �������) ������ 0
		{
			ch = false;
			break;
		}
	return ch;
}
int checkNum(char* str)
{
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i])) {
			k++;
		}
	}
	if (k == strlen(str)) return 1;
	else return 0;
}
int checkFNum(char* str)
{
	int k = 0;
	char kr[1] = { '.' };
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i]) || str[i] == kr[0]) k++;
	}
	if (k == strlen(str)) return 1;
	else return 0;
}
void printToTxtF(PC* CATALOG2, int n, char* fname) {
	FILE* f1;
	f1 = fopen(fname, "a+");
	for (int i = 0; i < n; i++) {
		fprintf(f1, "%d\t%s\t\t%d\t\t%.1lf\t\t%d\t\t%s\n", CATALOG2[i].number, CATALOG2[i].manufacture, CATALOG2[i].type, CATALOG2[i].capacity_ram, CATALOG2[i].capacity_hdd, CATALOG2[i].TV_ch);
	}
	fclose(f1);
}
PC* readFromFile(int& N)
{
	N = strkol();
	FILE* f1;
	PC* CATALOG = new PC[N];
	if ((f1 = fopen("DataBase", "rb")) == NULL) {
		stand(0, 0, 12, 0, "\a������� �������� ����� DataBase!");
		exit(0);
	}
	for (int i = 0; i < N; i++)
		fread(&CATALOG[i], sizeof(PC), 1, f1);
	fclose(f1);
	return CATALOG;
}
//---------------------------------------------------------------
void drawMenu(int pos_x1, int pos_x2, int pos_y1, int pos_y2, int text, int backg)
{
	system("cls");
	system("color 08");
	SetConsoleOutputCP(866);
	setColor(text, backg);
	for (int i = pos_x1; i < pos_x2; i++) {
		for (int j = pos_y1; j < pos_y2; j++) {
			setCursor(i, j);
			cout << " ";
		}
	}
	setColor(text, backg);
	for (int i = pos_x1; i < pos_x2; i++)
	{
		for (int j = pos_y1; j < pos_y2 + 1; j += 2) {
			setCursor(i, j);
			printchar(2);
		}
		for (int i = pos_y1; i < pos_y2 + 1; i++)
		{
			if (i % 2 == 1)
			{
				setCursor(pos_x1 - 1, i);
				printchar(7);
				setCursor(pos_x2, i);
				printchar(8);
			}
			else
			{
				setCursor(pos_x1 - 1, i);
				printchar(1);
				setCursor(pos_x2, i);
				printchar(1);
			}
		}
		for (int i = pos_y1 - 1; i < pos_y2 + 2; i++)
		{
			setCursor(pos_x1 - 2, i);
			printchar(9);
			setCursor(pos_x2 + 1, i);
			printchar(9);
		}
		for (int i = pos_x1 - 1; i < pos_x2 + 1; i++)
		{
			setCursor(i, pos_y1 - 1);
			printchar(0);
			setCursor(i, pos_y2 + 1);
			printchar(10);
		}
		setCursor(pos_x1 - 1, pos_y1);
		printchar(3);
		setCursor(pos_x2, pos_y1);
		printchar(6);
		setCursor(pos_x2, pos_y2);
		printchar(4);
		setCursor(pos_x1 - 1, pos_y2);
		printchar(5);
	}
	SetConsoleOutputCP(1251);
}
void drawHeadTab()
{
	SetConsoleOutputCP(866);
	setColor(0, 2);
	setCursor(22, 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 52; j++)
		{
			if (i == 0 && j == 0) printchar(3);
			else if (i == 3 && j == 0) printchar(7);
			else if (j == 52 && i == 0) printchar(6);
			else if (i == 3 && j == 52) printchar(8);

			if ((j == 3 || j == 19 || j == 24 || j == 33 || j == 42) && i == 0) printchar(11);
			else if ((j == 0 || j == 3 || j == 19 || j == 24 || j == 33 || j == 42 || j == 52) && (i == 1 || i == 2)) printchar(1);
			else if ((j == 3 || j == 19 || j == 24 || j == 33 || j == 42) && i == 3) printchar(12);

			if (i != 1 && i != 2 && j < 52) printchar(2);
			else if (j != 52) printf(" ");
		}
		printf("\n");
		setCursor(22, i + 1);
	}
	SetConsoleOutputCP(1251);
	setCursor(23, 1);
	printf("���");
	setCursor(28, 1);
	printf("Գ���-��������");
	setCursor(45, 1);
	printf("���");
	setCursor(45, 2);
	printf("��");
	setCursor(51, 1);
	printf("������");
	setCursor(51, 2);
	printf("RAM(��)");
	setCursor(61, 1);
	printf("������");
	setCursor(61, 2);
	printf("HDD(��)");
	setCursor(71, 1);
	printf("��-�����");
	setCursor(22, 4);
}
void printRawsTab(PC* CATALOG, int n)
{
	SetConsoleOutputCP(1251);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			setColor(0, 7);
			setCursor(22, i + 4);
			printchar(1);
			printf("%3d", CATALOG[i].number);
			printchar(1);
			printf("%-16s", CATALOG[i].manufacture);
			printchar(1);
			printf("%5d", CATALOG[i].type);
			printchar(1);
			printf("%9.1f", CATALOG[i].capacity_ram);
			printchar(1);
			printf("%9d", CATALOG[i].capacity_hdd);
			printchar(1);
			SetConsoleOutputCP(1251);
			printf("%-10s", CATALOG[i].TV_ch);
			printchar(1);
			setColor(15, 0);
		}
		else {
			setColor(0, 8);
			setCursor(22, i + 4);
			printchar(1);
			printf("%3d", CATALOG[i].number);
			printchar(1);
			printf("%-16s", CATALOG[i].manufacture);
			printchar(1);
			printf("%5d", CATALOG[i].type);
			printchar(1);
			printf("%9.1f", CATALOG[i].capacity_ram);
			printchar(1);
			printf("%9d", CATALOG[i].capacity_hdd);
			printchar(1);
			SetConsoleOutputCP(1251);
			printf("%-10s", CATALOG[i].TV_ch);
			printchar(1);
			setColor(15, 0);
		}
	}
	SetConsoleOutputCP(1251);
}
int preMenuInp()
{
	drawMenu(42, 67, 9, 15, 8, 15);
	stand(42, 10, 12, 7, "�� �������");
	stand(42, 12, 0, 15, "� �����");
	stand(42, 14, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 3) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "�� �������");
				stand(42, 12, 12, 7, "� �����");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "� �����");
				stand(42, 14, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 2) {
				stand(42, 12, 12, 7, "� �����");
				stand(42, 14, 0, 15, "�����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "�� �������");
				stand(42, 12, 0, 15, "� �����");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else return 0;
}
int preMenuSort(int l)
{
	char str_1[] = "�������� � ��";
	char str_2[] = "�������� ��� ��";
	if (l != 6) {
		strcpy(str_1, "�� ����������");
		strcpy(str_2, "�� ��������");
	}
	drawMenu(42, 67, 9, 15, 8, 15);
	stand(42, 10, 12, 7, str_1);
	stand(42, 12, 0, 15, str_2);
	stand(42, 14, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0;
	l == 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 3) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, str_1);
				stand(42, 12, 12, 7, str_2);
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, str_2);
				stand(42, 14, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 2) {
				stand(42, 12, 12, 7, str_2);
				stand(42, 14, 0, 15, "�����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, str_1);
				stand(42, 12, 0, 15, str_2);
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else return -1;
}
int preMenuDel()
{
	drawMenu(42, 67, 9, 15, 8, 15);
	stand(42, 10, 12, 7, "������ �����");
	stand(42, 12, 0, 15, "�� ������");
	stand(42, 14, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 3) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "������ �����");
				stand(42, 12, 12, 7, "�� ������");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "�� ������");
				stand(42, 14, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 2) {
				stand(42, 12, 12, 7, "�� ������");
				stand(42, 14, 0, 15, "�����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "������ �����");
				stand(42, 12, 0, 15, "�� ������");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return menuField();
	else if (l == 2) return 0;
	else return -1;
}
int menuField()
{
	drawMenu(42, 67, 9, 23, 8, 15);
	stand(42, 10, 12, 7, "��� ��");
	stand(42, 12, 0, 15, "Գ���-��������");
	stand(42, 14, 0, 15, "��� ��");
	stand(42, 16, 0, 15, "������ RAM");
	stand(42, 18, 0, 15, "������ HDD");
	stand(42, 20, 0, 15, "��-�����");
	stand(42, 22, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 7) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "��� ��");
				stand(42, 12, 12, 7, "Գ���-��������");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "Գ���-��������");
				stand(42, 14, 12, 7, "��� ��");
			}
			else if (cur == 4) {
				stand(42, 14, 0, 15, "��� ��");
				stand(42, 16, 12, 7, "������ RAM");
			}
			else if (cur == 5) {
				stand(42, 16, 0, 15, "������ RAM");
				stand(42, 18, 12, 7, "������ HDD");
			}
			else if (cur == 6) {
				stand(42, 18, 0, 15, "������ HDD");
				stand(42, 20, 12, 7, "��-�����");
			}
			else if (cur == 7) {
				stand(42, 20, 0, 15, "��-�����");
				stand(42, 22, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 6) {
				stand(42, 20, 12, 7, "��-�����");
				stand(42, 22, 0, 15, "�����");
			}
			else if (cur == 5) {
				stand(42, 18, 12, 7, "������ HDD");
				stand(42, 20, 0, 15, "��-�����");
			}
			else if (cur == 4) {
				stand(42, 16, 12, 7, "������ RAM");
				stand(42, 18, 0, 15, "������ HDD");
			}
			else if (cur == 3) {
				stand(42, 14, 12, 7, "��� ��");
				stand(42, 16, 0, 15, "������ RAM");
			}
			else if (cur == 2) {
				stand(42, 12, 12, 7, "Գ���-��������");
				stand(42, 14, 0, 15, "��� ��");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "��� ��");
				stand(42, 12, 0, 15, "Գ���-��������");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else if (l == 3) return 3;
	else if (l == 4) return 4;
	else if (l == 5) return 5;
	else if (l == 6) return 6;
	else return -1;
}
int preMenuEdit() {

	drawMenu(42, 67, 9, 21, 8, 15);
	stand(42, 10, 12, 7, "Գ���-��������");
	stand(42, 12, 0, 15, "��� ��");
	stand(42, 14, 0, 15, "������ RAM");
	stand(42, 16, 0, 15, "������ HDD");
	stand(42, 18, 0, 15, "��-�����");
	stand(42, 20, 0, 15, "�����");

	int k = 0, cur = 1, p = 1, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80)
		{
			if (cur < 6) {
				cur++;
				if (cur == 2) {
					stand(42, 10, 0, 15, "Գ���-��������");
					stand(42, 12, 12, 7, "��� ��");
				}
				else if (cur == 3) {
					stand(42, 12, 0, 15, "��� ��");
					stand(42, 14, 12, 7, "������ RAM");
				}
				else if (cur == 4) {
					stand(42, 14, 0, 15, "������ RAM");
					stand(42, 16, 12, 7, "������ HDD");
				}
				else if (cur == 5) {
					stand(42, 16, 0, 15, "������ HDD");
					stand(42, 18, 12, 7, "��-�����");
				}
				else if (cur == 6) {
					stand(42, 18, 0, 15, "��-�����");
					stand(42, 20, 12, 7, "�����");
				}
			}
		}
		else if (k == 72)
		{
			if (cur > 1) {
				cur--;
				if (cur == 5) {
					stand(42, 18, 12, 7, "��-�����");
					stand(42, 20, 0, 15, "�����");
				}
				else if (cur == 4) {
					stand(42, 16, 12, 7, "������ HDD");
					stand(42, 18, 0, 15, "��-�����");
				}
				else if (cur == 3) {
					stand(42, 14, 12, 7, "������ RAM");
					stand(42, 16, 0, 15, "������ HDD");
				}
				else if (cur == 2) {
					stand(42, 12, 12, 7, "��� ��");
					stand(42, 14, 0, 15, "������ RAM");
				}
				else if (cur == 1) {
					stand(42, 10, 12, 7, "Գ���-��������");
					stand(42, 12, 0, 15, "��� ��");
				}
			}
		}
		else if (k == 13) {
			system("cls");
			system("color 1");
			l = cur;
			system("cls");
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	return l;
}
int preMenuSel() {
	drawMenu(42, 67, 9, 15, 8, 15);
	stand(42, 10, 12, 7, "������ �����");
	stand(42, 12, 0, 15, "������ �����");
	stand(42, 14, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 3) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "������ �����");
				stand(42, 12, 12, 7, "������ �����");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "������ �����");
				stand(42, 14, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 2) {
				stand(42, 12, 12, 7, "������ �����");
				stand(42, 14, 0, 15, "�����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "������ �����");
				stand(42, 12, 0, 15, "������ �����");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return menuField();
	else if (l == 2) return preMenuSel2();
	else return -1;
}
int preMenuSel2() {
	drawMenu(37, 73, 9, 25, 8, 15);
	stand(37, 10, 12, 7, "������� �� � ��-�������");
	stand(37, 12, 0, 15, "������� ���� Acer, Lenovo");
	stand(37, 14, 0, 15, "����������� �������� �� ����");
	stand(37, 16, 0, 15, "̳������� �������� �� ����");
	stand(37, 18, 0, 15, "������ �������� �� ����");
	stand(37, 20, 0, 15, "��� �� � ���������� ����������������");
	stand(37, 22, 0, 15, "��� �� � ��������� ����������������");
	stand(37, 24, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p) {
		k = _getch();
		if (k == 80) {
			if (cur < 8) {
				cur++;
			}
			if (cur == 2) {
				stand(37, 10, 0, 15, "������� �� � ��-�������");
				stand(37, 12, 12, 7, "������� ���� Acer, Lenovo");
			}
			else if (cur == 3) {
				stand(37, 12, 0, 15, "������� ���� Acer, Lenovo");
				stand(37, 14, 12, 7, "����������� �������� �� ����");
			}
			else if (cur == 4) {
				stand(37, 14, 0, 15, "����������� �������� �� ����");
				stand(37, 16, 12, 7, "̳������� �������� �� ����");
			}
			else if (cur == 5) {
				stand(37, 16, 0, 15, "̳������� �������� �� ����");
				stand(37, 18, 12, 7, "������ �������� �� ����");
			}
			else if (cur == 6) {
				stand(37, 18, 0, 15, "������ �������� �� ����");
				stand(37, 20, 12, 7, "��� �� � ���������� ����������������");
			}
			else if (cur == 7) {
				stand(37, 20, 0, 15, "��� �� � ���������� ����������������");
				stand(37, 22, 12, 7, "��� �� � ��������� ����������������");
			}
			else if (cur == 8) {
				stand(37, 22, 0, 15, "��� �� � ��������� ����������������");
				stand(37, 24, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 7) {
				stand(37, 22, 12, 7, "��� �� � ��������� ����������������");
				stand(37, 24, 0, 15, "�����");
			}
			else if (cur == 6) {
				stand(37, 20, 12, 7, "��� �� � ���������� ����������������");
				stand(37, 22, 0, 15, "��� �� � ��������� ����������������");
			}
			else if (cur == 5) {
				stand(37, 18, 12, 7, "������ �������� �� ����");
				stand(37, 20, 0, 15, "��� �� � ���������� ����������������");
			}
			else if (cur == 4) {
				stand(37, 16, 12, 7, "̳������� �������� �� ����");
				stand(37, 18, 0, 15, "������ �������� �� ����");
			}
			else if (cur == 3) {
				stand(37, 14, 12, 7, "����������� �������� �� ����");
				stand(37, 16, 0, 15, "̳������� �������� �� ����");
			}
			else if (cur == 2) {
				stand(37, 12, 12, 7, "������� ���� Acer, Lenovo");
				stand(37, 14, 0, 15, "����������� �������� �� ����");
			}
			else if (cur == 1) {
				stand(37, 10, 12, 7, "������� �� � ��-�������");
				stand(37, 12, 0, 15, "������� ���� Acer, Lenovo");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 7;
	else if (l == 2) return 8;
	else if (l == 3) return 9;
	else if (l == 4) return 10;
	else if (l == 5) return 11;
	else if (l == 6) return 12;
	else if (l == 7) return 13;
	else return -1;

}
int preMenuOut() {
	drawMenu(42, 67, 9, 15, 8, 15);
	stand(42, 10, 12, 7, "�� �����");
	stand(42, 12, 0, 15, "� ��������� ����");
	stand(42, 14, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 3) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "�� �����");
				stand(42, 12, 12, 7, "� ��������� ����");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "� ��������� ����");
				stand(42, 14, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 2) {
				stand(42, 12, 12, 7, "� ��������� ����");
				stand(42, 14, 0, 15, "�����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "�� �����");
				stand(42, 12, 0, 15, "� ��������� ����");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else return 0;
}
int menuFieldCap() {
	drawMenu(42, 67, 9, 17, 8, 15);
	stand(42, 10, 12, 7, "��'�� ������������");
	stand(42, 12, 0, 15, "��'�� RAM");
	stand(42, 14, 0, 15, "������ ����");
	stand(42, 16, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 4) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "��'�� ������������");
				stand(42, 12, 12, 7, "��'�� RAM");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "��'�� RAM");
				stand(42, 14, 12, 7, "������ ����");
			}
			else if (cur == 4) {
				stand(42, 14, 0, 15, "������ ����");
				stand(42, 16, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 3) {
				stand(42, 14, 12, 7, "������ ����");
				stand(42, 16, 0, 15, "�����");
			}
			else if (cur == 2) {
				stand(42, 12, 12, 7, "��'�� RAM");
				stand(42, 14, 0, 15, "������ ����");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "��'�� ������������");
				stand(42, 12, 0, 15, "��'�� RAM");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else if (l == 3) return 3;
	else return -1;
}
int menuFieldType()
{
	drawMenu(42, 67, 9, 21, 8, 15);
	stand(42, 10, 12, 7, "���������");
	stand(42, 12, 0, 15, "��������");
	stand(42, 14, 0, 15, "������");
	stand(42, 16, 0, 15, "�������");
	stand(42, 18, 0, 15, "�� ����");
	stand(42, 20, 0, 15, "�����");

	int cur = 1, p = 1, k = 0, h = 0, l = 0;

	while (p)
	{
		k = _getch();
		if (k == 80) {
			if (cur < 6) {
				cur++;
			}
			if (cur == 2) {
				stand(42, 10, 0, 15, "���������");
				stand(42, 12, 12, 7, "��������");
			}
			else if (cur == 3) {
				stand(42, 12, 0, 15, "��������");
				stand(42, 14, 12, 7, "������");
			}
			else if (cur == 4) {
				stand(42, 14, 0, 15, "������");
				stand(42, 16, 12, 7, "�������");
			}
			else if (cur == 5) {
				stand(42, 16, 0, 15, "�������");
				stand(42, 18, 12, 7, "�� ����");
			}
			else if (cur == 6) {
				stand(42, 18, 0, 15, "�� ����");
				stand(42, 20, 12, 7, "�����");
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
			}
			if (cur == 5) {
				stand(42, 18, 12, 7, "�� ����");
				stand(42, 20, 0, 15, "�����");
			}
			else if (cur == 4) {
				stand(42, 16, 12, 7, "�������");
				stand(42, 18, 0, 15, "�� ����");
			}
			else if (cur == 3) {
				stand(42, 14, 12, 7, "������");
				stand(42, 16, 0, 15, "�������");
			}
			else if (cur == 2) {
				stand(42, 12, 12, 7, "��������");
				stand(42, 14, 0, 15, "������");
			}
			else if (cur == 1) {
				stand(42, 10, 12, 7, "���������");
				stand(42, 12, 0, 15, "��������");
			}
		}
		else if (k == 13) {
			l = cur;
			k = 0;
			cur = 0;
			p = 0;
		}
	}
	if (l == 1) return 1;
	else if (l == 2) return 2;
	else if (l == 3) return 3;
	else if (l == 4) return 4;
	else if (l == 5) return 5;
	else return -1;
}
PC* search(int& j, int point) {
	int N = strkol(), n = 0;
	PC* CATALOG = readFromFile(N);
	PC* CATALOG2 = new PC[N];
	int max_h, min_h, sum_h = 0, ind = 0;
	float max_r, min_r, sum_r = 0, avg;
	j = 0;

	if (point == 1) {
		max_h = CATALOG[0].capacity_hdd;
		for (int i = 0; i < N; i++) {
			if (max_h < CATALOG[i].capacity_hdd) {
				max_h = CATALOG[i].capacity_hdd;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_hdd == max_h) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 2) {
		max_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < N; i++) {
			if (max_r < CATALOG[i].capacity_ram) {
				max_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == (int(max_r * 100) / 100.0)) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 3) {
		max_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < N; i++) {
			if (max_r < CATALOG[i].capacity_ram) {
				max_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == (int(max_r * 100) / 100.0)) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		max_h = CATALOG2[0].capacity_hdd;
		for (int i = 0; i < n; i++) {
			if (max_h < CATALOG2[i].capacity_hdd) {
				max_h = CATALOG2[i].capacity_hdd;
			}
		}
		PC* CATALOG3 = new PC[n];
		for (int i = 0; i < n; i++) {
			if (CATALOG2[i].capacity_hdd == max_h) {
				CATALOG3[j] = CATALOG2[i];
				j++;
			}
		}
		return CATALOG3;
	}
	else if (point == 4) {
		min_h = CATALOG[0].capacity_hdd;
		for (int i = 0; i < N; i++) {
			if (min_h > CATALOG[i].capacity_hdd) {
				min_h = CATALOG[i].capacity_hdd;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_hdd == min_h) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 5) {
		min_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < N; i++) {
			if (min_r > CATALOG[i].capacity_ram) {
				min_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == (int(min_r * 100) / 100.0)) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 6) {
		min_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < N; i++) {
			if (min_r > CATALOG[i].capacity_ram) {
				min_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == (int(min_r * 100) / 100.0)) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		min_h = CATALOG2[0].capacity_hdd;
		for (int i = 0; i < n; i++) {
			if (min_h > CATALOG2[i].capacity_hdd) {
				min_h = CATALOG2[i].capacity_hdd;
			}
		}
		PC* CATALOG3 = new PC[n];
		for (int i = 0; i < n; i++) {
			if (CATALOG2[i].capacity_hdd == min_h) {
				CATALOG3[j] = CATALOG2[i];
				j++;
			}
		}
		return CATALOG3;
	}
	else if (point == 7) {
		for (int i = 0; i < N; i++) {
			sum_h += CATALOG[i].capacity_hdd;
		}
		avg = abs(sum_h / N - CATALOG[0].capacity_hdd);
		for (int i = 0; i < N; i++) {
			if (abs(sum_h / N - CATALOG[i].capacity_hdd) < avg) {
				avg = abs(sum_h / N - CATALOG[i].capacity_hdd);
				ind = i;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_hdd == CATALOG[ind].capacity_hdd) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 8) {
		float sum = 0, avg;
		int ind = 0;
		for (int i = 0; i < N; i++) sum += CATALOG[i].capacity_ram;
		avg = abs(sum / N - CATALOG[0].capacity_ram);
		for (int i = 1; i < N; i++) {
			if (abs(sum / N - CATALOG[i].capacity_ram) < avg) {
				avg = abs(sum / N - CATALOG[i].capacity_ram);
				ind = i;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == CATALOG[ind].capacity_ram) {
				CATALOG2[j] = CATALOG[i];
				j++;
			}
		}
	}
	else if (point == 9) {
		for (int i = 0; i < N; i++) {
			sum_r += CATALOG[i].capacity_ram;
		}
		avg = abs(sum_r / N - CATALOG[0].capacity_ram);
		for (int i = 1; i < N; i++) {
			if (abs(sum_r / N - CATALOG[i].capacity_ram) < avg) {
				avg = abs(sum_r / N - CATALOG[i].capacity_ram);
				ind = i;
			}
		}
		for (int i = 0; i < N; i++) {
			if (CATALOG[i].capacity_ram == CATALOG[ind].capacity_ram) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		for (int i = 0; i < n; i++) {
			sum_h += CATALOG2[i].capacity_hdd;
		}
		avg = abs(sum_h / n - CATALOG2[0].capacity_hdd);
		ind = 0;
		for (int i = 0; i < n; i++) {
			if (abs(sum_h / n - CATALOG2[i].capacity_hdd) < avg) {
				avg = abs(sum_h / n - CATALOG2[i].capacity_hdd);
				ind = i;
			}
		}
		PC* CATALOG3 = new PC[n];
		for (int i = 0; i < n; i++) {
			if (CATALOG2[i].capacity_hdd == CATALOG2[ind].capacity_hdd) {
				CATALOG3[j] = CATALOG2[i];
				j++;
			}
		}
		return CATALOG3;
	}
	return CATALOG2;
}
void search(PC* CATALOG, int kol, int point) {
	int n = 0, j = 0, ind = 0;
	PC* CATALOG2 = new PC[kol];
	int max_h, min_h;
	float max_r, min_r;
	if (point == 1) {
		max_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < kol; i++) {
			if (max_r < CATALOG[i].capacity_ram) {
				max_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < kol; i++) {
			if (CATALOG[i].capacity_ram == (int(max_r * 100) / 100.0)) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		max_h = CATALOG2[0].capacity_hdd;
		for (int i = 0; i < n; i++) {
			if (max_h < CATALOG2[i].capacity_hdd) {
				max_h = CATALOG2[i].capacity_hdd;
			}
		}
		PC* CATALOG3 = new PC[n];
		for (int i = 0; i < n; i++) {
			if (CATALOG2[i].capacity_hdd == max_h) {
				CATALOG3[j] = CATALOG2[i];
				j++;
			}
		}
		setColor(15, 0);
		system("cls");
		drawHeadTab();
		printRawsTab(CATALOG3, j);
		delete[] CATALOG3;
	}
	else if (point == 3) {
		int n2 = 0;
		PC* CATALOG3 = new PC[n];
		for (int j = 1; j <= 4; j++) {
			n = 0;
			max_r = CATALOG[0].capacity_ram;
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].type == j) {
					if (max_r < CATALOG[i].capacity_ram) {
						max_r = CATALOG[i].capacity_ram;
					}
				}
			}
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].type == j) {
					if (CATALOG[i].capacity_ram == (int(max_r * 100) / 100.0)) {
						CATALOG2[n] = CATALOG[i];
						n++;
					}
				}
			}
			max_h = CATALOG2[0].capacity_hdd;
			ind = CATALOG2[0].number;
			for (int i = 0; i < n; i++) {
				if (max_h < CATALOG2[i].capacity_hdd) {
					max_h = CATALOG2[i].capacity_hdd;
					ind = CATALOG2[i].number;
				}
			}
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].number == ind) {
					CATALOG3[n2] = CATALOG[i];
					n2++;
				}
			}
		}
		setColor(15, 0);
		system("cls");
		drawHeadTab();
		printRawsTab(CATALOG3, n2);
	}
	else if (point == 2) {
		min_r = CATALOG[0].capacity_ram;
		for (int i = 0; i < kol; i++) {
			if (min_r > CATALOG[i].capacity_ram) {
				min_r = CATALOG[i].capacity_ram;
			}
		}
		for (int i = 0; i < kol; i++) {
			if (CATALOG[i].capacity_ram == (int(min_r * 100) / 100.0)) {
				CATALOG2[n] = CATALOG[i];
				n++;
			}
		}
		min_h = CATALOG2[0].capacity_hdd;
		for (int i = 0; i < n; i++) {
			if (min_h > CATALOG2[i].capacity_hdd) {
				min_h = CATALOG2[i].capacity_hdd;
			}
		}
		PC* CATALOG3 = new PC[n];
		for (int i = 0; i < n; i++) {
			if (CATALOG2[i].capacity_hdd == min_h) {
				CATALOG3[j] = CATALOG2[i];
				j++;
			}
		}
		setColor(15, 0);
		system("cls");
		drawHeadTab();
		printRawsTab(CATALOG3, j);
		delete[] CATALOG3;
	}
	else if (point == 4) {
		int n2 = 0;
		PC* CATALOG3 = new PC[n];
		for (int j = 1; j <= 4; j++) {
			n = 0;
			min_r = CATALOG[0].capacity_ram;
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].type == j) {
					if (min_r > CATALOG[i].capacity_ram) {
						min_r = CATALOG[i].capacity_ram;
					}
				}
			}
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].type == j) {
					if (CATALOG[i].capacity_ram == (int(min_r * 100) / 100.0)) {
						CATALOG2[n] = CATALOG[i];
						n++;
					}
				}
			}
			min_h = CATALOG2[0].capacity_hdd;
			ind = CATALOG2[0].number;
			for (int i = 0; i < n; i++) {
				if (min_h > CATALOG2[i].capacity_hdd) {
					min_h = CATALOG2[i].capacity_hdd;
					ind = CATALOG2[i].number;
				}
			}
			for (int i = 0; i < kol; i++) {
				if (CATALOG[i].number == ind) {
					CATALOG3[n2] = CATALOG[i];
					n2++;
				}
			}
		}
		setColor(15, 0);
		system("cls");
		drawHeadTab();
		printRawsTab(CATALOG3, n2);
	}
	delete[] CATALOG2;
}