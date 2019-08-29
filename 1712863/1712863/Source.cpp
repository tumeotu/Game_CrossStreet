#include<iostream>
#include <fstream>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include <conio.h> 
#include<dos.h>
#include<string>
#include"graphics.h"
#include<Windows.h>
#include"console.h"
#include <mmsystem.h>
#include <cstdlib>
#pragma comment(lib, "WinMM.Lib")
using namespace std;
int const width = 100;
int const hight = 21;
int speedcar = 2;
int batdau=-1, den = 400, den1 = 500;
int room = 1;
int CM = 14, CC = 9;
#define hinh play.hd.a
bool gamever;
struct toado
{
	int x, y;// x là hoanh do y la tung do
	int xo, yo; // toa do ban dau
};
struct player
{
	toado td;
	string ten;
	int songuoi;
	int room;
};
player play[12];
int Soxe[3];
bool tu = false;
struct XE
{
	toado td;
};
// khoi tao va ve
void khoitaogame()
{
	gamever = false;
	tu = false;
}
void khoitaoplayer(player &play)
{
	play.td.x = width / 2;
	play.td.y = hight - 3;
}
void drawxe(XE &xe)
{
	SetColor(CC);
	gotoXY(xe.td.x - 2, xe.td.y - 1);
	cout << " " << char(218) << char(196) << char(191) << " ";
	gotoXY(xe.td.x - 2, xe.td.y);
	cout << char(218) << " " << " " << " " << char(191);
	gotoXY(xe.td.x - 2, xe.td.y + 1);
	cout << char(192) << "O" << char(196) << "O" << char(190);
}
void drawxe1(XE &xe)
{
	SetColor(9);
	gotoXY(xe.td.x - 2, xe.td.y - 1);
	cout << " ___ ";
	gotoXY(xe.td.x - 2, xe.td.y);
	cout << "|  |]";
	gotoXY(xe.td.x - 2, xe.td.y + 1);
	cout << " o-o ";
}
void khoitaomang(XE car[], int toadoX, int toadoY, int &soxe)
{
	for (int i = 0; i < soxe; i++)
	{
		car[i].td.x = toadoX - 20 * (i);
		car[i].td.y = toadoY;
	}
}
void drawcar(XE *car, int soxe)
{
	for (int i = 0; i < soxe; i++)
	{
		drawxe(car[i]);
	}
}
void drawplayer(player &play)
{
	SetColor(CM);
	gotoXY(play.td.x - 1, play.td.y - 1);
	cout << " o ";
	gotoXY(play.td.x - 1, play.td.y);
	cout << "~|~";
	gotoXY(play.td.x - 1, play.td.y + 1);
	cout << "/ \\";
}
void deleteplayer(player &play)
{
	SetColor(12);
	gotoXY(play.td.xo - 1, play.td.yo - 1);
	cout << "   ";
	gotoXY(play.td.xo - 1, play.td.yo);
	cout << "   ";
	gotoXY(play.td.xo - 1, play.td.yo + 1);
	cout << "   ";
}
void deletexe(XE &xe)
{
	SetColor(12);
	gotoXY(xe.td.xo - 2, xe.td.yo - 1);
	cout << "     ";
	gotoXY(xe.td.xo - 2, xe.td.yo);
	cout << "     ";
	gotoXY(xe.td.xo - 2, xe.td.yo + 1);
	cout << "     ";
}
void drawroom()
{

	//gotoXY(0, 0);
	//// đặt màu nền cho màn hình
	//SetBGColor(0);
	//for (int i = 0; i < width; i++) {
	//	for (int j = 0; j < hight; j++) {
	//		gotoxy(i, j);
	//		printf(" ");
	//	}
	//}
	gotoXY(0, 0);
	SetColor(2);
	for (int i = 0; i < hight - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i % 4 == 0)
			{
				if (j == 0)
					cout << char(195);
				if (j == width - 1)
					cout << char(180);
				else
					cout << char(254);
			}
			else
			{
				if (j == 0)
					cout << char(179);
				if (j == width - 1)
					cout << char(179);
				else
				{
					cout << " ";
				}

			}
		}
		gotoXY(0, i + 1);
	}
	for (int i = 0; i < width; i++)
	{
		if (i == 0)
			cout << char(195);
		if (i == width - 1)
			cout << char(180);
		else
			cout << char(254);
	}
}
void draw()
{
	SetColor(11);
	gotoXY(40, 3);
	cout << "  _____          __  __ ______ ";
	gotoXY(40, 4);
	cout << " / ____|   /\\   |  \\/  |  ____|";
	gotoXY(40, 5);
	cout << "| |  __   /  \\  | \\  / | |__   ";
	gotoXY(40, 6);
	cout << "| | |_ | / /\\ \\ | |\\/| |  __|  ";
	gotoXY(40, 7);
	cout << "| |__| |/ ____ \\| |  | | |____ ";
	gotoXY(40, 8);
	cout << " \\_____/_/    \\_|_|  |_|______|";

	//

	gotoXY(7, 10);
	cout << "  _____ _____   ____   _____ _____ _____ _   _  _____    _____ _______ _____  ______ ______ _______ ";
	gotoXY(7, 11);
	cout << " / ____|  __ \\ / __ \\ / ____/ ____|_   _| \\ | |/ ____|  / ____|__   __|  __ \\|  ____|  ____|__   __|";
	gotoXY(7, 12);
	cout << "| |    | |__) | |  | | (___| (___   | | |  \\| | |  __  | (___    | |  | |__) | |__  | |__     | |   ";
	gotoXY(7, 13);
	cout << "| |    |  _  /| |  | |\___ \\ \\___ \ \\ | | | . ` | | |_ |  \\___\\ |  | |  |  _  /|  __| |  __|    | |   ";
	gotoXY(7, 14);
	cout << "| |____| | \\ \\| |__| |____) ____) |_| |_| |\\  | |__| |  ____) |  | |  | | \\ \\| |____| |____   | |   ";
	gotoXY(7, 15);
	cout << " \\_____|_|  \\_\\\\____/|_____|_____/|_____|_| \\_|\\_____| |_____/   |_|  |_|  \\_|______|______|  |_|   ";

	//
	SetColor(14);
	gotoXY(40, 17);
	cout << " __  __ ______ _   _ _    _ ";
	gotoXY(40, 18);
	cout << "|  \\/  |  ____| \\ | | |  | |";
	gotoXY(40, 19);
	cout << "| \\  / | |__  |  \\| | |  | |";
	gotoXY(40, 20);
	cout << "| |\\/| |  __| | . ` | |  | |";
	gotoXY(40, 21);
	cout << "| |  | | |____| |\\  | |__| |";
	gotoXY(40, 22);
	cout << "|_|  |_|______|_| \\_|\\____/ ";
	SetColor(12);
	gotoXY(47, 24);
	cout << "1. Bat Dau";
	gotoXY(47, 25);
	cout << "2. Huong Dan";
	gotoXY(47, 26);
	cout << "3. Load Game";
	gotoXY(47, 27);
	cout << "4. Tuy chon";
	gotoXY(47, 28);
	cout << "5. Thoat Game";
	gotoXY(100, 32);
	cout << "Truong Van Tu - 1712999";
	gotoXY(100, 33);
	cout << "     IT - HCMUS";
}
// xu li
int dem(int &a)
{
	int b;
	if (a == 1)
	{
		b = 0;
		room = 1;
		return  b;
	}
	if (a == 2)
	{
		b = 0;
		room = 2;
		return b;
	}
	if (a == 3)
	{
		b = 1;
		room = 2;
		return b;
	}
	if (a == 4)
	{
		b = 0;
		room = 3;
		return b;
	}
	if (a == 5)
	{
		b = 1;
		room = 3;
		return b;
	}
	if (a == 6)
	{
		b = 2;
		room = 3;
		return b;
	}
	if (a == 7)
	{
		b = 0; room = 4;
		return b;
	}
	if (a == 8)
	{
		b = 1;
		room = 4;
		return b;
	}
	if (a == 9)
	{
		b = 2;
		room = 4;
		return b;
	}
	if (a == 10)
	{
		b = 3;
		room = 4;
		return b;
	}
}
void dendo(int &k)
{
	if (k > 0)
	{
		SetColor(0);
		gotoXY(98, 7);
		cout << char(254);
		SetColor(10);
		gotoXY(98, 5);
		cout << char(254);
		SetColor(0);
		gotoXY(98, 15);
		cout << char(254);
		SetColor(10);
		gotoXY(98, 13);
		cout << char(254);
	}
	else
	{
		SetColor(0);
		gotoXY(98, 13);
		cout << char(254);
		SetColor(12);
		gotoXY(98, 15);
		cout << char(254);
		SetColor(0);
		gotoXY(98, 5);
		cout << char(254);
		SetColor(12);
		gotoXY(98, 7);
		cout << char(254);
		SetColor(0);
	}
}
void dendo1(int &k)
{
	if (k > 0)
	{
		SetColor(0);
		gotoXY(1, 11);
		cout << char(254);
		SetColor(10);
		gotoXY(1, 9);
		cout << char(254);
		/*SetColor(0);
		gotoXY(98, 15);
		cout << char(254);
		SetColor(10);
		gotoXY(98, 13);
		cout << char(254);*/
	}
	else
	{
		/*SetColor(0);
		gotoXY(98, 13);
		cout << char(254);
		SetColor(12);
		gotoXY(98, 15);
		cout << char(254);*/
		SetColor(0);
		gotoXY(1, 9);
		cout << char(254);
		SetColor(12);
		gotoXY(1, 11);
		cout << char(254);
		SetColor(0);
	}
}
void SaveGame(player &play1)
{
	gotoXY(105, 15);
	cout << "Nhap ten cua ban: ";
	getline(cin, play1.ten);
	string chuoi = ".txt";
	play1.ten += chuoi;
	ofstream Save;
	Save.open(play1.ten);
	Save << play1.room << endl;
	play1.songuoi = dem(play1.room);
	Save << play1.songuoi << endl;
	for (int i = play1.room - play1.songuoi; i < play1.room; i++)
	{
		Save << play[i].td.x << endl;
	}
	gotoXY(105, 15);
	cout << "                         ";
}
void Pause()
{
	int pau = 1;
	while (pau > 0)
	{
		int a = hight / 2;
		int b = width / 2 - 3;

		SetColor(rand() % 15);
		gotoXY(b - 1, a - 1);
		cout << "-------";
		gotoXY(b, a);
		cout << "PAUSE" << endl;
		gotoXY(b - 1, a + 1);
		cout << "-------";
		gotoXY(2, hight + 2);

		if (kbhit())
		{
			int key = _getch();

			if (key == 'Q' || key == 'q')
			{
				pau = -1;
				gotoXY(b - 1, a - 1);
				cout << "           ";
				gotoXY(b, a);
				cout << "      " << endl;
				gotoXY(b - 1, a + 1);
				cout << "           ";
				gotoXY(2, hight + 2);
			}
		}
		Sleep(300);
	}
}
void next()
{
	int Next = 7;
	PlaySound(TEXT("next.WAV"), NULL, SND_FILENAME | SND_ASYNC);
	while (Next > 0)
	{
		Next--;
		int a = hight / 2;
		int b = width / 2 - 3;

		SetColor(rand() % 15);
		gotoXY(b - 1, a - 1);
		cout << "----------";
		gotoXY(b, a);
		cout << "QUA MAN" << endl;
		gotoXY(b - 1, a + 1);
		cout << "----------";
		gotoXY(2, hight + 2);
		Sleep(615);
	}
}
int LoadGame(int a)
{
	player play1;
	tu = true;
	gotoXY(a, 15);
	cout << "Nhap ten file ban muon load: ";
	getline(cin, play1.ten);
	string chuoi = ".txt";
	play1.ten += chuoi;
	ifstream Load;
	Load.open(play1.ten);
	if (Load.fail())
	{
		gotoXY(a, 16);
		std::cout << "Khong co nguoi choi ten ban bua nhap" << std::endl;
		Sleep(500);
		gotoXY(a, 15);
		cout << "                                          ";
		gotoXY(a, 16);
		cout << "                                          ";
		return 0;
	}
	Load >> batdau;
	play[batdau].room = batdau;
	Load >> play[batdau].songuoi;
	gotoXY(a, 40);
	cout << play[batdau].songuoi;
	for (int i = batdau - play[batdau].songuoi; i < batdau; i++)
	{
		Load >> play[i].td.x;
		play[i].td.y = 2;
	}
	gotoXY(a, 15);
	cout << "                                        ";
	return play[batdau].room;
}
// ve 
void Loading()
{
	clrscr();
	gotoXY(width / 2 - 5, hight / 2);
	cout << "";
	int i = 0;

	while (i<25)
	{
		SetColor(10);
		gotoXY(width / 2 - 5 + i + 10, hight / 2);
		cout << char(219);
		gotoXY(width / 2 - 5 + i + 10, hight / 2 + 1);
		cout << char(219);
		gotoXY(width / 2, hight / 2 + 2);
		gotoXY(width / 2 + 13, hight / 2 + 4);
		cout << "Loading...";
		i++;
		Sleep(250);
	}
}
void drawroom1()
{
	SetColor(11);
	gotoXY(106, 1);
	cout << " _____   ____   ____  __  __   __ ";
	gotoXY(106, 2);
	cout << "|  __ \\ / __ \\ / __ \\|  \\/  | /_ |";
	gotoXY(106, 3);
	cout << "| |__) | |  | | |  | | \\  / |  | |";
	gotoXY(106, 4);
	cout << "|  _  /| |  | | |  | | |\\/| |  | | ";
	gotoXY(106, 5);
	cout << "| | \\ \\| |__| | |__| | |  | |  | |";
	gotoXY(106, 6);
	cout << "|_|  \\_\\\\____/ \\____/|_|  |_|  |_|";
}
void drawroom2()
{
	SetColor(11);
	gotoXY(106, 1);
	cout << " _____   ____   ____  __  __   ___  ";
	gotoXY(106, 2);
	cout << "|  __ \\ / __ \\ / __ \\|  \\/  | |__ \\ ";
	gotoXY(106, 3);
	cout << "| |__) | |  | | |  | | \\  / |    ) |";
	gotoXY(106, 4);
	cout << "|  _  /| |  | | |  | | |\\/| |   / / ";
	gotoXY(106, 5);
	cout << "| | \\ \\| |__| | |__| | |  | |  / /_ ";
	gotoXY(106, 6);
	cout << "|_|  \\_\\\\____/ \\____/|_|  |_| |____|";
}
void drawroom3()
{
	SetColor(11);
	gotoXY(105, 1);
	cout << " _____   ____   ____  __  __   ____  ";
	gotoXY(105, 2);
	cout << "|  __ \\ / __ \\ / __ \\|  \\/  | |___ \\ ";
	gotoXY(105, 3);
	cout << "| |__) | |  | | |  | | \\  / |   __| |";
	gotoXY(105, 4);
	cout << "|  _  /| |  | | |  | | |\\/| |  |__ < ";
	gotoXY(105, 5);
	cout << "| | \\ \\| |__| | |__| | |  | |  ___) |";
	gotoXY(105, 6);
	cout << "|_|  \\_\\\\____/ \\____/|_|  |_| |____/ ";
}
void drawroom4()
{
	SetColor(11);
	gotoXY(105, 1);
	cout << " _____   ____   ____  __  __   _  _   ";
	gotoXY(105, 2);
	cout << "|  __ \\ / __ \\ / __ \\|  \\/  | | || |  ";
	gotoXY(105, 3);
	cout << "| |__) | |  | | |  | | \\  / | | || |_ ";
	gotoXY(105, 4);
	cout << "|  _  /| |  | | |  | | |\\/| | |__   _|";
	gotoXY(105, 5);
	cout << "| | \\ \\| |__| | |__| | |  | |    | |  ";
	gotoXY(105, 6);
	cout << "|_|  \\_\\\\____/ \\____/|_|  |_|    |_|  ";
}
void vedich()
{
	SetColor(11);
	gotoXY(15, 15);
	cout << " _______        __  __   ____ _____ ______ _______   _   _   _ ";
	gotoXY(15, 16);
	cout << "|__   __| /\\   |  \\/  | |  _ |_   _|  ____|__   __| | | | | | |";
	gotoXY(15, 17);
	cout << "   | |   /  \\  | \\  / | | |_) || | | |__     | |    | | | | | |";
	gotoXY(15, 18);
	cout << "   | |  / /\\ \\ | |\\/| | |  _ < | | |  __|    | |    | | | | | |";
	gotoXY(15, 19);
	cout << "   | | / ____ \\| |  | | | |_) _| |_| |____   | |    |_| |_| |_|";
	gotoXY(15, 20);
	cout << "   |_|/_/    \\_|_|  |_| |____|_____|______|  |_|    (_) (_) (_)";
	gotoXY(15, 25);
}
void quaman(player &play)
{

}
void BangHienThi()
{
	SetColor(12);
	gotoXY(105, 9);
	cout << "------------------------------------";
	gotoXY(105, 10);
	cout << "|";
	gotoXY(105 + 35, 10);
	cout << "|";
	gotoXY(105, 11);
	cout << "|";
	gotoXY(105 + 35, 11);
	cout << "|";
	gotoXY(105, 12);
	cout << "|";
	gotoXY(105 + 35, 12);
	cout << "|";
	gotoXY(105, 13);
	cout << "|";
	gotoXY(105 + 35, 13);
	cout << "|";
	gotoXY(105, 14);
	cout << "------------------------------------";
	SetColor(14);
	gotoXY(109, 10);
	cout << "Press 'Q' to PAUSE game";
	gotoXY(109, 11);
	cout << "Press 'T' to save game";
	gotoXY(109, 12);
	cout << "Press 'F' to load game";
	gotoXY(109, 13);
	cout << "Press 'R' to exit game";
}
void playagain(int &a)
{
	int i = 1;
	clrscr();
	SetColor(12);
	gotoXY(width / 2 - 10, hight / 2 - 2);
	cout << "------------------------------";
	gotoXY(width / 2 - 10, hight / 2 + 2);
	cout << "------------------------------";
	SetColor(14);
	gotoXY(width / 2 - 5, hight / 2 - 1);
	cout << "1. quay ve MENU";
	gotoXY(width / 2 - 5, hight / 2);
	cout << "2. Thoat game";
	while (i > 0)
	{
		if (kbhit())
		{
			int key = _getch();

			if (key == '1')
			{
				a = 3;
				clrscr();
				i = -1;
			}
			if (key == '2')
			{
				a = -2;
				clrscr();
				vedich();
				i = -1;
			}
		}
	}
}
void option()
{
	clrscr();
	clrscr();
	int n = 1, u, v;

	gotoXY(10, 11);
	cout << "------------BANG MAU------------";
	gotoXY(10, 12);
	cout << "   Ten mau           Ma mau";
	gotoXY(12, 13);
	cout << "   Red               12";
	gotoXY(12, 14);
	cout << "   Black             0";
	gotoXY(12, 15);
	cout << "   White             15";
	gotoXY(12, 16);
	cout << "   Blue              9";
	gotoXY(12, 17);
	cout << "   Green             10";
	gotoXY(12, 18);
	cout << "   Yelow             14";
	gotoXY(12, 19);
	cout << "   Siver blue        11";
	gotoXY(12, 20);
	cout << "---------------------------";
	gotoXY(12, 22);
	cout << "Ban chon mau cho xe va nhan vat bang cach nhap ma mau cua tung loai";
	gotoXY(12, 23);
	cout << "- Mau xe: ";
	cin >> u;
	gotoXY(12, 24);
	cout << "- Mau nhan vat: ";
	cin >> v;
	CC = u;
	CM = v;
	gotoXY(12, 25);
	cout << "BAM 1 DE QUAY VE MENU";
	while (n > 0)
	{
		if (kbhit())
		{
			int a = _getch();
			if (a == '1')
			{
				n = -1;
			}
		}
	}
}
// xu li
void vacham(int &a)
{
	int kq = dem(a);
	for (int i = a - 1; i >= a - kq; i--)
	{
		if (play[a].td.x == play[i].td.x)
		{
			if (play[a].td.y == play[i].td.y);
			{
				gamever = true;
			}
		}
	}
}
void dieukhien(player &play)
{
	if (kbhit())
	{
		int key = _getch();

		if (key == 'W' || key == 'w'&&play.td.y >3)
		{
			PlaySound(TEXT("tu.WAV"), NULL, SND_FILENAME | SND_ASYNC);
			play.td.xo = play.td.x;
			play.td.yo = play.td.y;
			play.td.y -= 4;
		}
		if (key == 'S' || key == 's'&&play.td.y<hight - 4)
		{
			PlaySound(TEXT("tu.WAV"), NULL, SND_FILENAME | SND_ASYNC);
			play.td.xo = play.td.x;
			play.td.yo = play.td.y;
			play.td.y += 4;
		}
		if (key == 'A' || key == 'a'&&play.td.x >= 4)
		{
			PlaySound(TEXT("tu.WAV"), NULL, SND_FILENAME | SND_ASYNC);
			play.td.xo = play.td.x;
			play.td.yo = play.td.y;
			play.td.x -= 3;
		}
		if (key == 'D' || key == 'd'&&play.td.x<width - 3)
		{
			PlaySound(TEXT("tu.WAV"), NULL, SND_FILENAME | SND_ASYNC);
			play.td.xo = play.td.x;
			play.td.yo = play.td.y;
			play.td.x += 3;
		}
		if (key == 'R' || key == 'r')
		{
			gamever = true;
		}
		if (key == 'F' || key == 'f')
		{
			LoadGame(105);
		}
		if (key == 'T' || key == 't')
		{
			SaveGame(play);
		}
		if (key == 'Q' || key == 'q')
		{
			Pause();
		}
		deleteplayer(play);
		drawplayer(play);
	}
}
void runxe(XE &xe, int toadoX, int toadoY)
{
	xe.td.xo = xe.td.x;
	xe.td.yo = xe.td.y;
	//xe.td.x += 2;
	den = den - 1;
	if (den <400 && den>0)
	{
		deletexe(xe);
		xe.td.x += 2;
		if (xe.td.x >= 3 && xe.td.x <= width - 4)
		{
			deletexe(xe);
			drawxe(xe);

		}
		if (xe.td.x > width - 3)
		{
			deletexe(xe);
			xe.td.x = toadoX;
			xe.td.y = toadoY;
		}
	}
	else
	{
		xe.td.x += 0;
		if (den < -400)
		{
			den = 400;
		}
	}
	dendo(den);
}
void runxe1(XE &xe, int toadoX, int toadoY)
{
	xe.td.xo = xe.td.x;
	xe.td.yo = xe.td.y;
	//xe.td.x += 2;
	den1 = den1 - 1;
	if (den1 <500 && den1>0)
	{
		deletexe(xe);
		xe.td.x -= 2;
		if (xe.td.x > 3 && xe.td.x <= width - 3)
		{
			deletexe(xe);
			drawxe(xe);

		}
		if (xe.td.x < 3)
		{
			deletexe(xe);
			xe.td.x = toadoX;
			xe.td.y = toadoY;
		}
	}
	else
	{
		xe.td.x += 0;
		if (den1 < -500)
		{
			den1 = 500;
		}
	}
	dendo1(den1);
}
void runcar(XE car[], int &soxe, int toadoX, int toadoY)
{

	for (int i = 0; i < soxe; i++)
	{
		runxe(car[i], 3, toadoY);
	}
}
void runcar1(XE car[], int &soxe, int toadoX, int toadoY)
{

	for (int i = 0; i < soxe; i++)
	{
		runxe1(car[i], 97, toadoY);
	}
	//BangHienThi();
}
void xuli(XE *car, player &play, int soxe)
{
	for (int i = 0; i < soxe; i++)
	{
		if ((car[i].td.y == play.td.y))
		{
			for (int i = -2; i < 3; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if ((car[i].td.x + i == play.td.x + j))
					{
						gamever = true;
					}
				}
			}
		}
	}
}
void endgame()
{
	int Next = 7;
	PlaySound(TEXT("die.WAV"), NULL, SND_FILENAME | SND_ASYNC);
	while (Next > 0)
	{
		Next--;
		int a = hight / 2;
		int b = width / 2 - 3;

		SetColor(rand() % 15);
		gotoXY(b - 1, a - 1);
		cout << "----------";
		gotoXY(b, a);
		cout << "YOU LOSE" << endl;
		gotoXY(b - 1, a + 1);
		cout << "----------";
		gotoXY(2, hight + 2);
		Sleep(370);
	}
}
void game()
{
	clrscr();
	int speed;
	XE *car0 = (XE*)malloc(0 * sizeof(XE));
	XE *car1 = (XE*)malloc(0 * sizeof(XE));
	XE *car2 = (XE*)malloc(0 * sizeof(XE));
	if (tu == false)
	{
		batdau = 1;
	}
	int i = batdau;
	for (int i = batdau; i < 50; i++)
	{
		if (i == 1)
		{
			speed = 220;
			Soxe[0] = 3;
			Soxe[1] = 4;
			Soxe[2] = 3;
		}
		if (i > 1 && i <= 3)
		{
			speed = 150;
			Soxe[0] = 4;
			Soxe[1] = 5;
			Soxe[2] = 4;
		}
		if (i > 4 && i <= 6)
		{
			speed = 100;
			Soxe[0] = 4;
			Soxe[1] = 5;
			Soxe[2] = 4;
		}
		if (i >= 7 && i <= 11)
		{
			speed = 60;
			Soxe[0] = 4;
			Soxe[1] = 5;
			Soxe[2] = 4;
		}
		car0 = (XE*)realloc(car0, Soxe[0] * sizeof(XE));
		car1 = (XE*)realloc(car1, Soxe[1] * sizeof(XE));
		car2 = (XE*)realloc(car2, Soxe[2] * sizeof(XE));
		// ve màn chơi
		drawroom();
		if (room == 1)
		{
			BangHienThi();
			drawroom1();
		}
		if (room == 2)
		{
			BangHienThi();
			drawroom2();
		}
		if (room == 3)
		{
			BangHienThi();
			drawroom3();
		}
		if (room == 4)
		{
			BangHienThi();
			drawroom4();
		}
		// khoi tao vi tri cua nguoi choi
		khoitaoplayer(play[i]);
		play[i].room = i;
		//khoitaoxelanthu1
		khoitaomang(car0, 80, 6, Soxe[0]);
		//khoitaoxelanthu2
		khoitaomang(car1, 80, 10, Soxe[1]);
		//khoitaoxelanthu 3
		khoitaomang(car2, 80, 14, Soxe[2]);
		SetColor(10);
		// ve người chơi
		drawplayer(play[i]);
		if (tu == true)
		{
			for (int i = batdau-1; i >= batdau - play[batdau].songuoi; i--)
			{
				drawplayer(play[i]);
			}
			tu = false;
		}
		while (!gamever)
		{
			// dieu khien người
			dieukhien(play[i]);
			// xe chạy
			gotoXY(95, 5);
			runcar(car0, Soxe[0], 3, 6);
			gotoXY(95, 5);
			runcar1(car1, Soxe[1], 3, 10);
			gotoXY(95, 5);
			runcar(car2, Soxe[2], 3, 14);
			gotoXY(95, 5);
			// xử lí chết
			xuli(car0, play[i], Soxe[0]);
			xuli(car1, play[i], Soxe[1]);
			xuli(car2, play[i], Soxe[2]);
			// thoát game
			if (tu == true)
			{
				game();
			}
			if (play[i].td.y == 2)
			{
				vacham(i);
				if (gamever == true)
					break;
				if (gamever == false)
				{
					if (i == 1 || i == 3 || i == 6)
					{
						next();
						room += 1;
						den = 400;
						den1 = 500;
						break;
					}
					else
					{
						i++;
						play[i].room = i;
						khoitaoplayer(play[i]);
						drawplayer(play[i]);
					}
				}
			}
			Sleep(speed);
		}
		if (gamever == true)
		{
			break;
		}
	}
	free(car0);
	free(car1);
	free(car2);
	endgame();
}
void roomsub()
{
	clrscr();
	int n = 1;
	clrscr();
	gotoXY(20, 10);
	cout << "Ban su dung cac phim A W S D de di chuyen";
	gotoXY(20, 11);
	cout << "Bam R de thoat game";
	gotoXY(20, 12);
	cout << "Bam Q de dung game";
	gotoXY(20, 13);
	cout << "Bam E de Save game";
	gotoXY(20, 14);
	cout << "Bam F de Load game";
	gotoXY(20, 15);
	cout << "Huong dan: Ban su dung cac phim di chuyen de di chuyen";
	gotoXY(20, 16);
	cout << "qua cac lan xe dang chay. Khi ban di chuyen toi lan xe";
	gotoXY(20, 17);
	cout << "cuoi cung ban se ket thuc mot man choi va qua man tiep theo";
	gotoXY(20, 18);
	cout << "Bam 1 de quay ve";
	while (n > 0)
	{
		if (kbhit())
		{
			int b = _getch();
			if (b == '1')
			{
				n = -1;
			}
		}
	}
}
void roominfor()
{
	int i = 1;
	while (i>0)
	{
		draw();
		PlaySound(TEXT("Meo.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		Sleep(200);
		gotoXY(0, 0);
		int m = _getch();
		if (m == '1')
		{
			Loading();
			tu = false;
			khoitaogame();
			game();
			playagain(i);
		}
		if (m == '2')
		{
			roomsub();
			clrscr();
		}
		if (m == '3')
		{
			clrscr();
			LoadGame(10);
			if (batdau !=-1)
			{
				game();
			}
			Sleep(500);
		}
		if (m == '4')
		{
			option();
			clrscr();
		}
		if (m == '5')
		{
			i = -2;
			clrscr();
			vedich();
		}
	}
}
int main()
{
	// ẩn con trỏ chuột
	ShowCur(false);
	// fix màn hình console
	FixConsoleWindow();
	// bat dau game
	roominfor();
	// thoát game
	return 0;
}