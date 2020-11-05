#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define Subway 98     
#define m 999    


int gotoxy(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	return 0;
}

void clearLine(int x, int y)
{
	int i;
	gotoxy(x, y);
	for (i = 0; i<30; i++)
		putchar(' ');
	gotoxy(x, y);
}

int main()
{
	int i, j, k, s = 0, e = 0, min;
	int visit[Subway];     
	int distance[Subway]; 
	int via[Subway];     
	char start[20], end[20], exit[20]="종료",name[99][20] = {
		{ 0 }, { "소요산" }, { "동두천" }, { "보산" }, { "동두천중앙" },
		{ "지행" }, { "덕정" }, { "덕계" }, { "양주" }, { "녹양" },
		{ "가능" }, { "의정부" }, { "회룡" }, { "망월사" }, { "도봉산" },
		{ "도봉" }, { "방학" }, { "창동" }, { "녹천" }, { "월계" },
		{ "광운대" }, { "석계" }, { "신이문" }, { "외대앞" }, { "회기" }
		, { "청량리" }, { "제기동" }, { "신설동" }, { "동묘앞" }, { "동대문" },
		{ "종로5가" }, { "종로3가" }, { "종각" }, { "시청" }, { "서울역" },
		{ "남영" }, { "용산" }, { "뇨량진" }, { "대방" }, { "신길" },
		{ "영등포" }, { "신도림" }, { "구로" }, { "구일" }, { "개봉" },
		{ "오류동" }, { "온수" }, { "역곡" }, { "소사" }, { "부천" },
		{ "중동" }, { "송내" }, { "부개" }, { "부평" }, { "백운" },
		{ "동암" }, { "간석" }, { "주안" }, { "도화" }, { "제물포" },
		{ "도원" }, { "동인천" }, { "인천" }, { "가산디지털단지" }, { "독산" },
		{ "금천구청" }, { "광명" }, { "석수" }, { "관악" }, { "안양" },
		{ "명학" }, { "금정" }, { "군포" }, { "당정" }, { "의왕" },
		{ "성균관대" }, { "화서" }, { "수원" }, { "세류" }, { "병점" },
		{ "서동탄" }, { "세마" }, { "오산대" }, { "오산" }, { "진위" },
		{ "송탄" }, { "서정리" }, { "지제" }, { "평택" }, { "성환" },
		{ "직산" }, { "두정" }, { "천안" }, { "봉명" }, { "쌍용" },
		{ "아산" }, { "배방" }, { "온양온천" }, { "신창" }
	};

	FILE *pt;
	pt = fopen("C:\\subway4.txt", "r");
	int data[Subway][Subway];
	for (i = 0; i < Subway; i++)
	for (j = 0; j < Subway; j++)
		fscanf(pt, "%d", &data[i][j]);

	int y = 1;
	gotoxy(0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+                                                         +\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		gotoxy(17, 3);
		printf("[출발역] 을 입력하세요");
		while (y == 1)
		{
			gotoxy(26, 6);
			scanf("%s", start);
			clearLine(25, 6);
			for (s = 0; s <= Subway; s++)
			{
				if (strcmp(start, name[s]) == 0)
				{
					y = 0;
					clearLine(17, 3);
					break;
				}
			}

			if (y == 1)
			{
				gotoxy(17, 3);
				printf("[출발역] 을 다시 입력하세요");
			}
		}

		y = 1;
		gotoxy(17, 3);
		printf("[도착역] 을 입력하세요");
		while (y == 1)
		{
			gotoxy(26, 6);
			scanf("%s", end);
			clearLine(26, 6);
			for (e = 0; e <= Subway; e++)
			{
				if (strcmp(end, name[e]) == 0)
				{
					y = 0;
					clearLine(17, 3);
					break;
				}
			}
			if (y == 1)
			{
				gotoxy(17, 3);
				printf("[도착역] 을 다시 입력하세요");
			}
		}


	
		for (j = 0; j < Subway; j++)
		{
			visit[j] = 0;
			distance[j] = m;
		}
	
		distance[s - 1] = 0;

		
		for (i = 0; i < Subway; i++)
		{
		
			min = m;
			for (j = 0; j < Subway; j++)
			{
				if (visit[j] == 0 && distance[j] < min) {
					k = j;
					min = distance[j];
				}
			}

			visit[k] = 1;            

			if (min == m)				
			{
				printf("\n\n연결되지 않은 역입니다.\n");  break;
			}

		
			for (j = 0; j<Subway; j++)
			{
				if (distance[j] > distance[k] + data[k][j])
				{
					distance[j] = distance[k] + data[k][j];
					via[j] = k;
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		gotoxy(3, 3);
		printf("[%s역] 출발,", name[s]);
		gotoxy(3, 4);
		printf("[%s역] 도착", name[e]);
		gotoxy(3, 5);
		printf("%d 정거장 소요", distance[e - 1]);
		{
			int path[Subway], cnt = 0;
			k = e - 1;

			while (1)
			{
				path[cnt++] = k;
				if (k == s - 1)break;
				k = via[k];
			}
			gotoxy(0, 8);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			for (i = 9; i <= 24; i++)
			{
				clearLine(0, i);
				clearLine(30, i);
			}
			gotoxy(0, 11);
			printf("정거장 경로\n\n");
			for (i = cnt - 1; i >= cnt - 6; i--)
			{
				printf("%s -> ", name[path[i] + 1]);
			}
			for (i = cnt - 6; i >= 1; i--)
			{
				printf("%s -> ", name[path[i] + 1]);
			}
			printf("%s\n\n", name[path[i] + 1]);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}

