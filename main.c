#include "CRUD.h"

int main(void) {
  product p[100];
  int count = 0;
  int search_menu;
  while(1){
    search_menu = menu();
    if (search_menu == 0){
      printf("종료됨!\n");
      break;
    }
    else if(search_menu == 1){
      createLog(p,count);
      count++;
    }
    else if(search_menu == 2){
      readLog(p, count);
    }
    else if(search_menu == 3){
      deleteLog(p, count);
    }
    else if(search_menu == 4){
      searchLog(p, count);
    }
    else if(search_menu == 5){
      updateLog(p,count);
    }
    else if(search_menu == 6){
      totalLog(p, count);
    }
    else if(search_menu == 7){
      int month;
      printf("월을 입력하세요: ");
      scanf("%d", &month);
      ClearLineFromReadBuffer();
      printf("\n");
      TotalMonth(p,month,count);
    }
    else if(search_menu == 8){
      saveLog(p, count);
    }
    else if(search_menu == 9){
      loadLog(p);
    }
  }
  return 0;
}
