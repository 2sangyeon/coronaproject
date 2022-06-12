/* [평가항목 1] : 과제 설명


   컴퓨터 프로그래밍 평가과제(배점25점)
   학과 : 컴퓨터공학부
   학번 : 202202453
   이름 : 이상연

   과제 주제 : 전국 코로나 지역별 확진 현황을 알아볼 수 있는 프로그램 제작


*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 18 //전처리
#include <stdio.h>
#include <string.h> // strcmp를 쓰기 위한 헤더파일

// 구조체 정의
struct reg_hwak { // [평가 항목 5] : 구조체 사용
    char reg[5];
    int nu_hwak;
    int sin_hwak;
    int total_people;
};

struct reg_hwak corona[SIZE] = // [평가 항목 3] : 배열 사용
{
   {"경기",4952525,1690,13581496},
   {"서울",3638248,1160,9496877},
   {"부산",1098582,417,3338167},
   {"경남",1095670,440,3298016},
   {"인천",1076815,278,2955167},
   {"경북",784540,573,2616177},
   {"대구",765691,396,2376676},
   {"충남",717883,285,2119661},
   {"전북",602105,272,1779230},
   {"전남",598087,279,1827674},
   {"충북",557513,246,1597033},
   {"광주",534873,192,1436012},
   {"강원",520091,360,1539005},
   {"대전",513785,268,1448933},
   {"울산",381307,297,1116428},
   {"제주",236983,143,677766},
   {"세종",139565,82,379340},
   {"검역",11197,4}
};
 
struct reg_hwak* p[SIZE]; // [평가 항목 4] : 포인터 사용

//함수 선언
void menu(void);

int main(void)
{

    FILE* fp; // 파일포인터 fp
    fp = fopen("rona.txt", "a");

    /*int nuhwak = 0, sinhwak = 0;
    scanf(fp, "누적확진자 = %d / 신규확진자 = %d", (& nuhwak, &sinhwak));*/ // [평가 항목 7] : 파일 입출력(X)   -------   [평가 항목 8] : 다중 소스 파일(X)
    int choice, i, region;
    p[0] = corona;

    while (1)
    {
        menu();
        printf("메뉴를 선택하시오:");
        scanf("%d", &choice);

        if (choice == 1)
        {
            for (i = 0; i < SIZE; i++)
            {
                printf("%s 00:00 기준 %s의 누적확진자수는 %d(명), 신규확진자수는 %d(명) 입니다.\n", __DATE__, corona[i].reg, corona[i].nu_hwak, corona[i].sin_hwak);
            }
            break;
        }


        else if (choice == 2)
        {
            printf("어느 지역의 확진자 현황을 보시겠습니까?\n");
            printf("경기 = 0\n서울 = 1\n부산 = 2\n경남 = 3\n인천 = 4\n경북 = 5\n대구 = 6\n충남 = 7\n전북 = 8\n전남 = 9\n충북 = 10\n광주 = 11\n강원 = 12\n대전 = 13\n울산 = 14\n제주 = 15\n세종 = 16\n");
            scanf("%d", &region);

                if (region >= 0 && region <= 16)
                {
                    printf("%s 00:00 기준 %s의 누적확진자수는 %d(명), 신규확진자수는 %d(명) 입니다.\n", __DATE__, (*p)[region].reg, (*p)[region].nu_hwak, (*p)[region].sin_hwak); // [평가 항목 6] : 포인터 활용
                    printf("인구수 대비 확진자 비율은 %f%입니다.\n", (float)(((*p)[region].nu_hwak) / (float)((*p)[region].total_people)));
                }
                else
                {
                    printf("다시 실행하세요.");
                    break;
                }
          
        }

        else
        {
            printf("다시 실행하세요.");
            break;
        }

    }
    return 0;

}

void menu(void) // [평가항목 2] : 함수 사용
{
    printf("======================\n");
    printf("1. 전체지역\n");
    printf("2. 지역선택\n");
    printf("======================\n");
}