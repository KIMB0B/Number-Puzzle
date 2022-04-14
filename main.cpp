#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
	int cont = 1;  //��ü ���α׷��� �ٽý������� ����. clear ȭ�鿡�� 0�Է½� ���ѷ��� ����
	while (cont) {
		int size, count = 0;  //����ڰ� �Է��� �� ũ��, �̵� Ƚ��
		char out = 'a';  //����ȭ������ ���� ����. b�� �� �� ����ȭ��

		srand(static_cast<unsigned int>(time(NULL)));

		while (1) {
			cout << "                              _                    " << endl;
			cout << "                             | |                   " << endl;
			cout << "  _ __    _   _   _ __ ___   | |__     ___   _ __  " << endl;
			cout << " | '_ �� | | | | | '_ ` _ �� | '_ ��  / _ ��| '__|   " << endl;
			cout << " | | | | | |_| | | | | | | | | |_) | |  __/ | |    " << endl;
			cout << " |_| |_| ��__,_| |_| |_| |_| |_.__/  ��___| |_|     " << endl;
			cout << "                              _        " << endl;
			cout << "                             | |       " << endl;
			cout << "  _ __    _   _   ____  ____ | |   ___ " << endl;
			cout << " | '_ �� | | | | |_  / |_  / | |  / _ ��" << endl;
			cout << " | |_) | | |_| |  / /   / /  | | |  __/" << endl;
			cout << " | .__/  ��__,_| /___| /___| |_| ��___| " << endl;
			cout << " | |                                   " << endl;
			cout << " |_|                                   " << endl << endl;
			cout << "(��)" << endl;
			cout << "���� ���ڴ� �����̸�, W(��) A(��) S(��) D(��)�� �̵��Ѵ�." << endl;
			cout << "���ڵ��� ���ʺ��� ������� �����ϰ� �ڴ� ���� ����ĭ�� ��ġ�ϸ� ��!" << endl;
			cout << "ó��ȭ������ ���ƿ��� ������ b�� ����" << endl << endl;

			cout << "ũ��� ��ŭ �ұ�? (3�̻� 9����,  0�Է½� ����) : ";  //size�� �Է¹ް� ���� �� �Է½� ���Է¹���
			cin >> size;
			if (size < 3 || size > 9) {
				if (size == 0)
					break;
				cout << endl << "3 �̻� 9���϶��...";
				while (getchar() != '\n');
				getchar();
				system("cls");
			}
			else if (!size) {
				cout << endl << "�� ����~";
				while (getchar() != '\n');
				getchar();
				system("cls");
			}
			else
				break;
		}
		if (size == 0) {  //size 0�� �Է¹��� �� ���α׷� ����
			break;
		}

		int site = rand() % (size * size);  //���� �� ��ġ

		int* puzzle = (int*)malloc(sizeof(int) * size * size);  //puzzle�� �ϴ� 1���� size*size���� ������� ����
		for (int i = 0; i < size * size; i++) {
			puzzle[i] = i + 1;
		}

		for (int i = 0; i < 1000; i++) {  //site��ġ�� puzzle���� ��,�Ʒ�,����,���������� �����ϰ� 1000�� �� �������� �� �� �ִ� ��Ȳ�̸� �̵���Ŵ.
			int stemp;
			int shuffle = 0;  //1���� 4���� �������� ������ ����. �� ���ڸ��� ������ ���� 
			shuffle = rand() % 4 + 1;
			switch (shuffle) {
			case 1:  //��
				if (site > size - 1) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site - size];
					puzzle[site - size] = stemp;
					site -= size;
				}
				break;
			case 2:  //�Ʒ�
				if (site < size * size - size) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site + size];
					puzzle[site + size] = stemp;
					site += size;
				}
				break;
			case 3:  //����
				if (site % size != 0) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site - 1];
					puzzle[site - 1] = stemp;
					site--;
				}
				break;
			case 4:  //������
				if (site % size != size - 1) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site + 1];
					puzzle[site + 1] = stemp;
					site++;
				}
				break;
			}
		}
		system("cls");

		/***********����ȭ�� ����*********/
		while (1) {
			bool win = true;                      //������ �� Ǯ�ȳ� Ȯ���ϴ� ��, puzzle�� �� ���� ������ ���ڰ� ���� 1�� �þ� ���� win�� true����
			for (int i = 0; i < size * size - 1; i++) {
				if (puzzle[i] + 1 != puzzle[i + 1]) {
					win = false;
					break;
				}
			}
			if (win == true) {
				break;
			}

			cout << "  ";                         //������� �����ϴ°�, ���� ��
			for (int i = 0; i < size; i++) {
				cout << "��   ";
			}
			cout << endl;
			for (int i = 0; i < size * size; i++) {
				if (i % size == 0) {              //������ ��
					cout << "��";
				}
				if (puzzle[i] == puzzle[site]) {  //site��ġ�� puzzle �ڷ� ǥ��
					cout << "��";
				}
				else {                            //������ ��ġ�� ���ڸ����� ǥ��
					cout.width(2);
					cout.fill('0');
					cout << puzzle[i];
					cout << "";
				}
				if (i % size == size - 1) {        //�������� ��
					cout << "��";
					if (i == size * size - 1)      //�������� ���ڴ� ���� ������Ű�� ���� endl�� �ѹ��� ����
						cout << endl;
					else
						cout << endl << endl;
				}
				else                               //������ ���� ���ڰ� �ƴҽ� ���� �� ���̸� ���� ���� ���� �ֱ�
					cout << "   ";
			}
			cout << "  ";                          //�Ʒ��� ��
			for (int i = 0; i < size; i++) {
				cout << "��   ";
			}
			cout << endl;

			char input = _getch();  //����ڰ� �Է��� ����
			if (input == 'b' || input == 'B') {    //b�Է½� �ʱ�ȭ������ �����ϱ⶧���� break. b�� �Ѿ�� clearȭ�� ��ŵ��.
				out = 'b';
				break;
			}
			count++;  //input�Է� �� count���� 1�� �þ

			int temp = 0;  //�Էµ� ���ĺ������� �̵�
			switch (input) {
			case 'W':
			case 'w':
			case '��':
				if (size - 1 < site) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site - size];
					puzzle[site - size] = temp;
					site -= size;
				}
				break;
			case 'S':
			case 's':
			case '��':
				if (site < size * size - size) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site + size];
					puzzle[site + size] = temp;
					site += size;
				}
				break;
			case 'A':
			case 'a':
			case '��':
				if (site % size != 0) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site - 1];
					puzzle[site - 1] = temp;
					site--;
				}
				break;
			case 'D':
			case 'd':
			case '��':
				if (site % size != size - 1) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site + 1];
					puzzle[site + 1] = temp;
					site++;
				}
				break;
			}
			system("cls");
		}

		if (out != 'b') {  //clear�� ��Ȳ�Ͻ�
			while (1) {  //cont�� ������ ����� break
				cout << "  /$$$$$$  /$$       /$$$$$$$$  /$$$$$$  /$$$$$$$ " << endl;
				cout << " /$$__  $$| $$      | $$_____/ /$$__  $$| $$__  $$" << endl;
				cout << "| $$ ��__/| $$      | $$      | $$ �� $$| $$ �� $$" << endl;
				cout << "| $$      | $$      | $$$$$   | $$$$$$$$| $$$$$$$/" << endl;
				cout << "| $$      | $$      | $$__/   | $$__  $$| $$__  $$" << endl;
				cout << "| $$    $$| $$      | $$      | $$  | $$| $$ �� $$" << endl;
				cout << "|  $$$$$$/| $$$$$$$$| $$$$$$$$| $$  | $$| $$  | $$" << endl;
				cout << "��______/ |________/|________/|__/  |__/|__/  |__/" << endl << endl;
				cout << size << " X " << size << "ũ�� Ŭ���� �Ϸ�! (�� " << count << "�� �̵�)" << endl << endl;

				cout << "�ѹ���?(1 : ���, 0 : ����) : ";
				cin >> cont;
				if (cont != 1 && cont != 0) {  //cont�� ���������� �Է½� clearȭ�� �ݺ� ����
					cout << "1�ƴϸ� 0�� �Է��ض�";
					while (getchar() != '\n');
					getchar();
					system("cls");
				}
				else {  //0�Ǵ� 1�Է½� ȭ�� Ŭ����
					system("cls");
					break;
				}
			}
		}
		else  //b�� �Ѿ�� ��Ȳ�Ͻ�
			system("cls");
	}
}