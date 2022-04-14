#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
	int cont = 1;  //전체 프로그램을 다시시작할지 정함. clear 화면에서 0입력시 무한루프 종료
	while (cont) {
		int size, count = 0;  //사용자가 입력한 판 크기, 이동 횟수
		char out = 'a';  //시작화면으로 갈지 정함. b가 될 시 시작화면

		srand(static_cast<unsigned int>(time(NULL)));

		while (1) {
			cout << "                              _                    " << endl;
			cout << "                             | |                   " << endl;
			cout << "  _ __    _   _   _ __ ___   | |__     ___   _ __  " << endl;
			cout << " | '_ ↘ | | | | | '_ ` _ ↘ | '_ ↘  / _ ↘| '__|   " << endl;
			cout << " | | | | | |_| | | | | | | | | |_) | |  __/ | |    " << endl;
			cout << " |_| |_| ↘__,_| |_| |_| |_| |_.__/  ↘___| |_|     " << endl;
			cout << "                              _        " << endl;
			cout << "                             | |       " << endl;
			cout << "  _ __    _   _   ____  ____ | |   ___ " << endl;
			cout << " | '_ ↘ | | | | |_  / |_  / | |  / _ ↘" << endl;
			cout << " | |_) | | |_| |  / /   / /  | | |  __/" << endl;
			cout << " | .__/  ↘__,_| /___| /___| |_| ↘___| " << endl;
			cout << " | |                                   " << endl;
			cout << " |_|                                   " << endl << endl;
			cout << "(룰)" << endl;
			cout << "없는 숫자는 랜덤이며, W(상) A(좌) S(하) D(우)로 이동한다." << endl;
			cout << "숫자들을 왼쪽부터 순서대로 정렬하고 ★는 없는 숫자칸에 위치하면 끝!" << endl;
			cout << "처음화면으로 돌아오고 싶으면 b를 눌러" << endl << endl;

			cout << "크기는 얼만큼 할까? (3이상 9이하,  0입력시 종료) : ";  //size를 입력받고 범위 외 입력시 재입력받음
			cin >> size;
			if (size < 3 || size > 9) {
				if (size == 0)
					break;
				cout << endl << "3 이상 9이하라고...";
				while (getchar() != '\n');
				getchar();
				system("cls");
			}
			else if (!size) {
				cout << endl << "앙 기모띠~";
				while (getchar() != '\n');
				getchar();
				system("cls");
			}
			else
				break;
		}
		if (size == 0) {  //size 0을 입력받을 시 프로그램 종료
			break;
		}

		int site = rand() % (size * size);  //★이 될 위치

		int* puzzle = (int*)malloc(sizeof(int) * size * size);  //puzzle에 일단 1부터 size*size까지 순서대로 넣음
		for (int i = 0; i < size * size; i++) {
			puzzle[i] = i + 1;
		}

		for (int i = 0; i < 1000; i++) {  //site위치의 puzzle값을 위,아래,왼쪽,오른쪽으로 랜덤하게 1000번 그 방향으로 갈 수 있는 상황이면 이동시킴.
			int stemp;
			int shuffle = 0;  //1부터 4까지 랜덤으로 생성될 변수. 각 숫자마다 방향이 있음 
			shuffle = rand() % 4 + 1;
			switch (shuffle) {
			case 1:  //위
				if (site > size - 1) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site - size];
					puzzle[site - size] = stemp;
					site -= size;
				}
				break;
			case 2:  //아래
				if (site < size * size - size) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site + size];
					puzzle[site + size] = stemp;
					site += size;
				}
				break;
			case 3:  //왼쪽
				if (site % size != 0) {
					stemp = puzzle[site];
					puzzle[site] = puzzle[site - 1];
					puzzle[site - 1] = stemp;
					site--;
				}
				break;
			case 4:  //오른쪽
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

		/***********퍼즐화면 시작*********/
		while (1) {
			bool win = true;                      //퍼즐이 다 풀렸나 확인하는 곳, puzzle의 그 다음 순서의 숫자가 전부 1씩 늘어 날시 win은 true유지
			for (int i = 0; i < size * size - 1; i++) {
				if (puzzle[i] + 1 != puzzle[i + 1]) {
					win = false;
					break;
				}
			}
			if (win == true) {
				break;
			}

			cout << "  ";                         //퍼즐출력 시작하는곳, 윗줄 블럭
			for (int i = 0; i < size; i++) {
				cout << "■   ";
			}
			cout << endl;
			for (int i = 0; i < size * size; i++) {
				if (i % size == 0) {              //왼쪽줄 블럭
					cout << "■";
				}
				if (puzzle[i] == puzzle[site]) {  //site위치의 puzzle ★로 표시
					cout << "★";
				}
				else {                            //나머지 위치는 두자리수로 표시
					cout.width(2);
					cout.fill('0');
					cout << puzzle[i];
					cout << "";
				}
				if (i % size == size - 1) {        //오른쪽줄 블럭
					cout << "■";
					if (i == size * size - 1)      //마지막줄 숫자는 블럭과 밀착시키기 위해 endl을 한번만 실행
						cout << endl;
					else
						cout << endl << endl;
				}
				else                               //오른쪽 라인 숫자가 아닐시 수와 수 사이를 띄우기 위해 공백 넣기
					cout << "   ";
			}
			cout << "  ";                          //아래줄 블럭
			for (int i = 0; i < size; i++) {
				cout << "■   ";
			}
			cout << endl;

			char input = _getch();  //사용자가 입력할 방향
			if (input == 'b' || input == 'B') {    //b입력시 초기화면으로 가야하기때문에 break. b로 넘어가면 clear화면 스킵됨.
				out = 'b';
				break;
			}
			count++;  //input입력 후 count값이 1씩 늘어남

			int temp = 0;  //입력된 알파벳에따라 이동
			switch (input) {
			case 'W':
			case 'w':
			case 'ㅈ':
				if (size - 1 < site) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site - size];
					puzzle[site - size] = temp;
					site -= size;
				}
				break;
			case 'S':
			case 's':
			case 'ㄴ':
				if (site < size * size - size) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site + size];
					puzzle[site + size] = temp;
					site += size;
				}
				break;
			case 'A':
			case 'a':
			case 'ㅁ':
				if (site % size != 0) {
					temp = puzzle[site];
					puzzle[site] = puzzle[site - 1];
					puzzle[site - 1] = temp;
					site--;
				}
				break;
			case 'D':
			case 'd':
			case 'ㅇ':
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

		if (out != 'b') {  //clear한 상황일시
			while (1) {  //cont에 옳은값 적용시 break
				cout << "  /$$$$$$  /$$       /$$$$$$$$  /$$$$$$  /$$$$$$$ " << endl;
				cout << " /$$__  $$| $$      | $$_____/ /$$__  $$| $$__  $$" << endl;
				cout << "| $$ ↘__/| $$      | $$      | $$ ↘ $$| $$ ↘ $$" << endl;
				cout << "| $$      | $$      | $$$$$   | $$$$$$$$| $$$$$$$/" << endl;
				cout << "| $$      | $$      | $$__/   | $$__  $$| $$__  $$" << endl;
				cout << "| $$    $$| $$      | $$      | $$  | $$| $$ ↘ $$" << endl;
				cout << "|  $$$$$$/| $$$$$$$$| $$$$$$$$| $$  | $$| $$  | $$" << endl;
				cout << "↘______/ |________/|________/|__/  |__/|__/  |__/" << endl << endl;
				cout << size << " X " << size << "크기 클리어 완료! (총 " << count << "번 이동)" << endl << endl;

				cout << "한번더?(1 : 계속, 0 : 종료) : ";
				cin >> cont;
				if (cont != 1 && cont != 0) {  //cont에 옳지않은값 입력시 clear화면 반복 실행
					cout << "1아니면 0만 입력해라";
					while (getchar() != '\n');
					getchar();
					system("cls");
				}
				else {  //0또는 1입력시 화면 클리어
					system("cls");
					break;
				}
			}
		}
		else  //b로 넘어온 상황일시
			system("cls");
	}
}