#include <stdio.h>
typedef struct{
  int number;
  int price;
  char name[100];
  int sign;
  int month, day;
} product;

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
  int order;
  p[count].number = count;
  printf("입력: 지출(0) / 수입(0)");
  scanf("%d",&order);
  p[count].sign = order;
  if (order == 0){
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
  else if (order == 1){
    printf("수입 내역 이름 :");
    scanf("%[^\n]s",p[count].name);
    printf("\n");
    printf("가격 :");
    scanf("%d",&p[count].price);
    printf("\n");
    printf("날짜(월):");
    scanf("%d",&p[count].month);
    printf("\n");
    printf("날짜(일):");
    scanf("%d",&p[count].day);
    printf("\n");
  }
}
void readLog(product *p,int count){
  for(int i = 1; i <= count; i++){
    int listn = count - 1;
    if(p[count].sign == 0){
      printf("===================\n");
      printf("지출명: %s, 가격: - %d원, 날짜 : %d월 %d일\n",p[listn].name,p[listn].price,p[listn].month,p[listn].day);
      printf("===================\n");
    }
    else if(p[count].sign == 1){
      printf("===================\n");
      printf("수입명: %s, 가격: + %d원, 날짜 : %d월 %d일\n",p[listn].name,p[listn].price,p[listn].month,p[listn].day);
      printf("===================\n");
    }
  }
}
