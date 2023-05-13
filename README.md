# oss_team_lab_22조

## 1. 주제와 설계 과정
- 주제 : 가계부 프로그램
<img src="https://user-images.githubusercontent.com/130294661/236810009-b6480339-50f6-4790-9d10-044b660c9d6c.jpg" width="250" height="250"/>

- 프로젝트 구현 기능 설명 : CRUD 기능, 데이터 파일 저장/읽어오기, 검색 메뉴 , 총액 계산 프로그램, 월 평균 계산
- 사용 언어 : 'C 언어'
- 22조 : '한규영', '한은택'

## 2. 역할분담
- Repo 소유자 : 한규영 Contributor: 한은택
- CRUD 함수 구현 내용

## 3. 구현 기능

### 구조체 내용
```
typedef struct{
  int number;
  int price;
  char name[100];
  int sign;
  int month, day;
} product;
```

### CRUD 내용
```
- int createLog(Product *p); // 가계부에 내용을 추가하는 함수
- void readLog(Product *p); // 가계부의 내용 출력 함수
- int updateLog(Product *p); // 가계부 내용을 수정하는 함수
- int deleteLog(Product *p); // 가계부 내용을 삭제하는 함수
- void saveLog(Product *p, int count); // 가계부의 내용을 저장하는 함수
- int loadLog(Product *p);// 저장된 내용을 불러오는 함수
```

### 추가 함수와 기능들
```
- int Menu(); // 메뉴를 불러오고 리턴을 가져오는 함수
- void searchLog(Product *p, int count); // 가계부의 내용을 검색하여 출력하는 함수
- int totalLog(Product *p); // 가계부의 적힌 총액을 계산하는 함수
- int TotalMonth(Product *p, int month); // 가계부의 적힌 내용을 기반으로 월마다 총 소비액을 출력하는 함수
```
