#include "crud.h"

int main(void) {
  product * p[20];

  int count = 0;
  int search_menu;

  count = loadLog(p);
  while(1){
    search_menu = Menu();
    if (search_menu == 0){
      for(int i = 0; i < count; i++){
        free(p[i]);
      }
      printf("종료됨!\n");
      break;
    }
    else if(search_menu == 1){
      createLog(p, &count);
    }
    else if(search_menu == 2){
      readLog(p, count);
    }
    else if(search_menu == 3){
      readLog(p, count);
      updateLog(p);
    }
    else if(search_menu == 4){
      readLog(p, count);
      deleteLog(p);
    }
    else if(search_menu == 5){
      searchLog(p, count);
    }
    else if(search_menu == 6){
      totalLog(p, count);
    }
    else if(search_menu == 7){
      TotalMonth(p, count);
    }
    else if(search_menu == 8){
      saveLog(p, count);
    }
  }
  return 0;
}
