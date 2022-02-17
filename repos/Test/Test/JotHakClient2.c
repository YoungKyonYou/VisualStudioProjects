#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#pragma comment(lib, "ws2_32.lib") //ws2_32���̺귯�� ��ũ
#define SERVERIP "127.0.0.1"
#define SERVERPORT 9160
#define BUFSIZE 1024

void input_arrow(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void make_board(int c, int r);
void game_control(void);
void print_stone(int matrix[][20][20]);
int check_end(int matrix[][20][20]);

void errorHandling(char *message) {
	WSACleanup();
	fputs(message, stderr);
	fputc('\n', stderr);
	_getch();
	exit(1);
}

int main(int argc, char **argv) {
	int x = 1, y = 1, other = 0;
	int matrix[2][20][20] = { 0 };
	char key;
	char *stone[2] = { "��", "��" };

	SOCKET client_socket;
	WSADATA wsaData;
	SOCKADDR_IN server_address;

	int conn, nRcv, nSnd;
	unsigned int Addr;
	char buf[BUFSIZE];

	struct hostent *host;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		errorHandling("ws2_32.dll �ʱ�ȭ ����");

	//socket()
	client_socket = socket(PF_INET, SOCK_STREAM, 0); //ipv4 �������� (�������� ü��� PF_INET), TCP�������� ���
	if (client_socket == INVALID_SOCKET)
		errorHandling("socket() ����");

	//connect()
	ZeroMemory(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(SERVERIP);
	server_address.sin_port = htons(SERVERPORT);
	conn = connect(client_socket, (SOCKADDR *)&server_address, sizeof(server_address));
	if (conn == SOCKET_ERROR)
		errorHandling("connect() ����");

	ZeroMemory(buf, BUFSIZE);
	while (1) {
		system("cls");
		gotoxy(1, 1);
		make_board(18, 18);
		gotoxy(x, y);
		printf("%s", stone[other]);
		print_stone(matrix);
		gotoxy(1, 20);
		printf("������ ����");

		//recv()
		nRcv = recv(client_socket, buf, BUFSIZE - 1, 0);
		if (nRcv == SOCKET_ERROR) {
			errorHandling("recv() ����");
			break;
		}
		else {
			char *ptr = strtok(buf, " ");
			x = atoi(ptr);
			ptr = strtok(NULL, " ");
			y = atoi(ptr);

			system("cls");
			gotoxy(1, 1);
			make_board(18, 18);
			gotoxy(x, y);
			printf("%s", stone[other]);
			print_stone(matrix);
			matrix[other][(x + 1) / 2][y] = 1;
			other = 1 - other;

			if (check_end(matrix) == 1) {
				gotoxy(1, 21);
				printf("�浹�� �̰���ϴ�\n");
				break;
			}

			else if (check_end(matrix) == 2) {
				gotoxy(1, 21);
				printf("�鵹�� �̰���ϴ�\n");
				break;
			}
		}
		ZeroMemory(buf, BUFSIZE);

		do {
			system("cls");
			gotoxy(1, 1);
			make_board(18, 18);
			gotoxy(x, y);
			printf("%s", stone[other]);
			print_stone(matrix);
			gotoxy(1, 20);
			printf("����Ű�� �����̰� �����̽� Ű�� ���� ��������.");
			key = getch();

			if (key == 32) {
				matrix[other][(x + 1) / 2][y] = 1;
				other = 1 - other;
				break;
			}
			else if (key >= 72)   input_arrow(key, &x, &y, 37, 19);

		} while (key != 32);
		char tmp_x[2] = { ' ',' ' }, tmp_y[2] = { ' ',' ' };
		sprintf(tmp_x, "%d", x);
		sprintf(tmp_y, "%d", y);
		buf[0] = tmp_x[0];
		if (tmp_x[1] != ' ' && tmp_x[1] != '\0') {
			buf[1] = tmp_x[1];
			buf[2] = ' ';
			buf[3] = tmp_y[0];
			if (tmp_y[1] != ' ' && tmp_y[1] != '\0') {
				buf[4] = tmp_y[1];
				ZeroMemory(buf + 5, BUFSIZE);
			}
			else ZeroMemory(buf + 4, BUFSIZE);
		}
		else {
			buf[1] = ' ';
			buf[2] = tmp_y[0];
			if (tmp_y[1] != ' ' && tmp_y[1] != '\0') {
				buf[3] = tmp_y[1];
				ZeroMemory(buf + 4, BUFSIZE);
			}
			else ZeroMemory(buf + 3, BUFSIZE);
		}

		//send()
		nSnd = send(client_socket, buf, BUFSIZE - 1, 0);
		if (nSnd == SOCKET_ERROR) {
			errorHandling("send() ����\n");
			break;
		}
		if (check_end(matrix) == 1) {
			gotoxy(1, 21);
			printf("�浹�� �̰���ϴ�\n");
			break;
		}

		else if (check_end(matrix) == 2) {
			gotoxy(1, 21);
			printf("�鵹�� �̰���ϴ�\n");
			break;
		}
		ZeroMemory(buf, BUFSIZE);
	}

	closesocket(client_socket);
	WSACleanup();
	printf("��������");
	_getch();
	return 0;
}

// ************************************���� �Լ�**********************************************

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

/* ����Ű �Է¹޴� �Լ�
LEFT      75
RIGHT      77
UP         72
DOWN      80
SPACE      32
*/
void input_arrow(char key, int *x1, int *y1, int x_b, int y_b) {
	switch (key) {
		// ��
	case 72:
		*y1 = *y1 - 1;
		if (*y1 < 1)   *y1 = 1;
		break;

		//��
	case 80:
		*y1 = *y1 + 1;
		if (*y1 > y_b)   *y1 = y_b;
		break;

		// ��
	case 75:
		*x1 = *x1 - 2;
		if (*x1 < 1)   *x1 = 1;
		break;

		// ��
	case 77:
		*x1 = *x1 + 2;
		if (*x1 > x_b)   *x1 = x_b;
		break;

	default: return;
	}
}

/* �ٵ��� ����� �Լ�
�� 0xa3 �� 0xa8 ��0xa4
�� 0xa7 �� 0xab ��0xa9
�� 0xa6 �� 0xaa ��0xa5
��0xa2 �� 0xa1
*/
void make_board(int c, int r) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++)   b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]); printf("%c%c", a, b[1]);

	for (i = 0; i < c - 1; i++) {
		printf("%c%c", a, b[8]);
		printf("%c%c", a, b[1]);
	}
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < r - 1; i++) {
		printf("%c%c", a, b[7]); printf("%c%c", a, b[1]);
		for (j = 0; j < c - 1; j++) {
			printf("%c%c", a, b[11]);
			printf("%c%c", a, b[1]);
		}
		printf("%c%c", a, b[9]);
		printf("\n");
	}

	printf("%c%c", a, b[6]); printf("%c%c", a, b[1]);

	for (i = 0; i < c - 1; i++) {
		printf("%c%c", a, b[10]);
		printf("%c%c", a, b[1]);
	}
	printf("%c%c", a, b[5]);
	printf("\n");
}

// ��/�鵹 ���
void print_stone(int matrix[][20][20]) {
	int i, x, y;
	char *stone[2] = { "��", "��" };

	for (i = 0; i < 2; i++) {
		for (x = 1; x < 20; x++) {
			for (y = 1; y < 20; y++) {
				if (matrix[i][x][y] == 1) {
					gotoxy(x * 2 - 1, y);
					printf("%s", stone[i]);
				}
			}
		}
	}
}



// ���� ���� �Լ�
int check_end(int matrix[][20][20]) {
	int count = 0;

	//���� Ȯ��
	for (int i = 0; i < 2; i++) {
		for (int y = 1; y < 20; y++) {
			count = 0;
			for (int x = 1; x < 20; x++) {
				if (matrix[i][x][y]) count++;
				else count = 0;
				if (count == 5)   return (i + 1);
			}
		}
	}

	//���� Ȯ��
	for (int i = 0; i < 2; i++) {
		for (int x = 1; x < 20; x++) {
			count = 0;
			for (int y = 1; y < 20; y++) {
				if (matrix[i][x][y]) count++;
				else count = 0;
				if (count == 5) return (i + 1);
			}
		}
	}

	//������-�����ʾƷ�(��) Ȯ��
	for (int i = 0; i < 2; i++) {
		for (int x = 1; x < 16; x++) {
			count = 0;
			for (int y = 1; y < 16; y++) {
				int tmp1 = x;
				int tmp2 = y;
				for (int j = 0; j < 5; j++) {
					if (matrix[i][tmp1++][tmp2++]) count++;
					else count = 0;
				}
				if (count == 5) return (i + 1);
			}
		}
	}

	//���ʾƷ�-��������(��) Ȯ��
	for (int i = 0; i < 2; i++) {
		for (int x = 1; x < 16; x++) {
			count = 0;
			for (int y = 5; y < 20; y++) {
				int tmp1 = x;
				int tmp2 = y;
				for (int j = 0; j < 5; j++) {
					if (matrix[i][tmp1++][tmp2--]) count++;
					else count = 0;
				}
				if (count == 5) return (i + 1);
			}
		}
	}
	return 0; //������ �� �������� 0 ��ȯ
}