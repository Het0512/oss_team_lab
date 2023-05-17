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
  printf("입력: 지출(0) / 수입(1)");
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
  printf("===================\n");
  for(int i = 0; i <= count; i++){
    if(p[i].sign == -1){
      continue;
    }
    printf("%d. ", i+1);
    if(p[i].sign == 0){
      printf("지출명: %s, 가격: - %d원, 날짜 : %d월 %d일\n",p[i].name,p[i].price,p[i].month,p[i].day);
    }
    else if(p[i].sign == 1){
      printf("수입명: %s, 가격: + %d원, 날짜 : %d월 %d일\n",p[i].name,p[i].price,p[i].month,p[i].day);
    }
  }
  printf("===================\n");
}

void updateLog(product *p, int count){ // 지출, 수입은 바꿀 수 없고, 이름, 월, 일만 바꿀 수 있게
  int num, check = 0;
  readLog(p, count);
  printf("수정할 가계부의 번호를 입력해주세요 : ");
  scanf("%d", &num);
  if(p[num-1].sign == -1){
    printf("수정할 번호에 내용이 없습니다.\n");
  }
  else{
    if (p[num-1].sign == 0){
      printf("지출 내역 이름 :");
    }
    else if (p[num-1].sign == 1){
      printf("수입 내역 이름 :");
    }
    scanf("%[^\n]s",p[num-1].name);
    printf("가격 :");
    scanf("%d",&p[num-1].price);
    while (1){
      printf("날짜(월):");
      scanf("%d",&p[num-1].month);
      if(p[num-1].month > 12 || p[num-1].month < 1){
          printf("1~12사이로 다시 입력해주세요!!!\n");
          continue;
      }
      else{
          break;
      }
    }
    while (1){
      printf("날짜(일):");
      scanf("%d",&p[num-1].day);
      switch(p[num-1].month){
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12:
              if(p[num-1].day > 31 || p[num-1].day < 1){
                  printf("1~31사이로 다시 입력해주세요!!!\n");
              }
              else{
                  check = 1;
              }
              break;
          case 2:
              if(p[num-1].day > 28 || p[num-1].day < 1){
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
              if(p[num-1].day > 30 || p[num-1].day < 1){
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
}

void searchLog(product *p,int count){
  char names[100], check = 0;;
  printf("찾고자 하는 가계부 내용의 이름을 입력해주세요 :");
  scanf("%[^\n]s",names);
  for(int i = 0; i != count; i++){
    if(p[i].sign == -1){
      continue;
    }
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
      check = 1;
    }
  }
  if(check == 0){
    printf("찾고자 하는 가계부 내용의  이름이 없습니다!\n");
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
  p[number-1].sign = -1; //sign이 -1일때 삭제로 처리.(read에서 -1은 continue 처리)
  printf("삭제됨!\n");
} 

/* deletLog의 다른 버전
void deleteLog(product *p,int count){
  int number;
  readLog(p, count);
  printf("삭제하실 가계부 내역의 번호를 입력해주세요 :");
  scanf("%d",&number);
  printf("\n");
  p[number-1].sign = -1; //sign이 -1일때 삭제로 처리.(read에서 -1은 continue 처리)
  printf("삭제됨!\n");
} 
*/

void saveLog(product *p, int count){
    FILE * file = fopen("log.txt", "wt");

    for(int i = 0; i < count; i++){
        if(t[i].sign == -1){
            continue;
        }
        fprintf(file, "%s %d %d %d\n", p[i].name, p[i].price, p[i].month, p[i].day);
    }
    printf("=> 저장됨!\n");
    fclose(file);
}
