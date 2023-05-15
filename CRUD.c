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
  int order, check = 0;
  p[count].number = count;
  p[count].sign = -1;
  printf("입력: 지출(0) / 수입(0)");
  scanf("%d",&order);
  p[count].sign = order;
  if (order == 0){
    printf("지출 내역 이름 :");
  }
  else if (order == 1){
    printf("수입 내역 이름 :");
  }
  scanf("%[^\n]s",p[count].name);
  printf("가격 :");
  scanf("%d",&p[count].price);
  while (1){
     printf("날짜(월):");
     scanf("%d",&p[count].month);
     if(p[count].month > 12 || p[count].month < 1){
        printf("1~12사이로 다시 입력해주세요!!!\n");
        continue;
     }
     else{
        break;
     }
  }
  while (1){
    printf("날짜(일):");
    scanf("%d",&p[count].day);
    switch(p[count].month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(p[count].day > 31 || p[count].day < 1){
                printf("1~31사이로 다시 입력해주세요!!!\n");
            }
            else{
                check = 1;
            }
            break;
        case 2:
            if(p[count].day > 28 || p[count].day < 1){
                printf("1~28사이로 다시 입력해주세요!!!\n");
            }
            else{
                check = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(p[count].day > 30 || p[count].day < 1){
                printf("1~30사이로 다시 입력해주세요!!!\n");
            }
            else{
                check = 1;
            }
            break;
    }
    if(check = 1){
        break;
    }
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
    else if(p[count].sign == -1){
      continue;
    }
  }
}

void searchLog(product *p,int count){
  char names[100];
  printf("찾고자 하는 가계부 내용의 이름을 입력해주세요 :");
  scanf("%[^\n]s",names);
  for(int i = 0; i != count; i++){
    if (strcmp(p[i].name,names) == 0){
      if(p[i].sign == 0){
        printf("===================\n");
        printf("지출명: %s, 가격: - %d원, 날짜 : %d월 %d일\n",p[i].name,p[i].price,p[i].month,p[i].day);
        printf("===================\n");
      }
      else if(p[count].sign == 1){
        printf("===================\n");
        printf("수입명: %s, 가격: + %d원, 날짜 : %d월 %d일\n",p[i].name,p[i].price,p[i].month,p[i].day);
        printf("===================\n");
      }
    }
  }
}

void deleteLog(product *p,int count){
  int number;
  printf("========================\n");
  for (int i = 0; i != count; i++){
    if (p[i].sign >= 0){
      printf("%d. %s\n",i+1,p[i].name);
    }
  }
  printf("========================\n");
  printf("삭제하실 가계부 내역의 번호를 입력해주세요 :");
  scanf("%d",&number);
  printf("\n");
  p[number-1].sign = -1;
  printf("삭제됨!\n");
} 