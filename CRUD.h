#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int number;
  int price;
  char name[100];
  int sign;
  int month, day;
} product;

int createLog(product **p, int *count); // 가계부에 내용을 추가하는 함수
void readLog(product **p, int count); // 가계부의 내용 출력 함수
void updateLog(product **p); // 가계부 내용을 수정하는 함수
void deleteLog(product **p); // 가계부 내용을 삭제하는 함수
void saveLog(product **p, int count); // 가계부의 내용을 저장하는 함수
int loadLog(product **p);// 저장된 내용을 불러오는 함수
int Menu(); // 메뉴를 불러오고 리턴을 가져오는 함수
void searchLog(product **p, int count); // 가계부의 내용을 검색하여 출력하는 함수
void totalLog(product **p, int count); // 가계부의 적힌 총액을 계산하는 함수
void TotalMonth(product **p, int count); // 가계부의 적힌 내용을 기반으로 월 총 소비액을 출력하는 함수
