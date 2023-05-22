#include <stdio.h>
#include <string.h>

typedef struct{
  int number;
  int price;
  char name[100];
  int sign;
  int month, day;
  int t;
} product;
void ClearLineFromReadBuffer(); // 입력 버퍼 제거 함수
int createLog(Product *p); // 가계부에 내용을 추가하는 함수
void readLog(Product *p); // 가계부의 내용 출력 함수
int updateLog(Product *p); // 가계부 내용을 수정하는 함수
int deleteLog(Product *p); // 가계부 내용을 삭제하는 함수
void saveLog(Product *p, int count); // 가계부의 내용을 저장하는 함수
int loadLog(Product *p);// 저장된 내용을 불러오는 함수
int Menu(); // 메뉴를 불러오고 리턴을 가져오는 함수
void searchLog(Product *p, int count); // 가계부의 내용을 검색하여 출력하는 함수
int totalLog(Product *p); // 가계부의 적힌 총액을 계산하는 함수
int TotalMonth(Product *p, int month); // 가계부의 적힌 내용을 기반으로 월 총 소비액을 출력하는 함수
