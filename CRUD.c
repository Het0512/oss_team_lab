#include <stdio.h>
typedef struct{
  int count;
  int price;
  char name[100];
  int month, day;
} product;

/* 수입(+)인지 지출(-)인지 구분하는 변수 sign추가
typedef struct{
  int count;
  int price;
  char name[100];
  char sign;
  int month, day;
} product;
*/

int menu(){
  int menu;
  printf("========== Menu ===========\n");
  printf("0. 종료 \n");
  printf("1. 가계부 추가 \n");
  printf("2. 가계부 리스트 확인 \n");
  printf("3. 가계부 항목 삭제 \n");
  printf("4. 가계부 내용 검색 \n");
  printf("5. 가계부 내용 수정 \n");
  printf("6. 전체 총액 계산 \n");
  printf("7. 월 평균 총 소비액 계산 \n");
  printf("===========================\n");
  printf("Insert Command :");
  scanf("%d",&menu);
  printf("\n");
  return menu;
}

int createLog(product *p,int count){
  printf("지출 내역 이름 :");
  scanf("%[^\n]s",p[count].name);
  printf("\n");
  printf("지출된 가격 :");
  scanf("%d",&p[count].price);
  printf("\n");
  printf("지출된 날짜(월):");
  scanf("%d",&p[count].month);
  printf("\n");
  printf("지출된 날짜(일):");
  scanf("%d",&p[count].day);
  printf("\n");
}

/* 가계부에 지출만 있지 않으니 수입인지 지출인지 물어보는 코드 추가
int createLog(product *p,int count){
  printf("지출 내역 이름 :");
  scanf("%[^\n]s",p[count].name);
  printf("수입 or 지출 (수입이면 +, 지출이면 -) : ");
  scanf("%c",&p[count].sign);
  printf("가격 :");
  scanf("%d",&p[count].price);
  printf("날짜(월):");
  scanf("%d",&p[count].month);
  printf("날짜(일):");
  scanf("%d",&p[count].day);
}
*/
