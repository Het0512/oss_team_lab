# oss_team_lab_22조

## 1. 주제와 설계 과정
- 주제 : 가계부 프로그램
<img src="https://user-images.githubusercontent.com/130294661/236810009-b6480339-50f6-4790-9d10-044b660c9d6c.jpg" width="250" height="250"/>

- 프로젝트 구현 기능 설명 : CRUD 기능, 데이터 파일 저장/읽어오기, 검색 메뉴 , 총액 계산 프로그램, 월 평균 계산
- 사용 언어 : 'C 언어'
- 사용 환경 : Visual Studio Code
- 22조 : '한규영', '한은택'

## 2. 역할분담
- Repo 소유자 : 한규영 Contributor: 한은택
- CRUD 함수 구현 내용

## 3. 구현 기능

### 구조체의 내용
```
typedef struct{
  int number;
  int price;
  char name[100];
  int sign; // 지출,수입 내용 구현
  int month, day;
  int t;
} product;
```

### CRUD 내용
```
- void ClearLineFromReadBuffer(); // 입력 버퍼 제거 함수
- int createLog(product *p,int count); // 가계부에 내용을 추가하는 함수
- void readLog(product *p,int count); // 가계부의 내용 출력 함수
- void updateLog(product *p, int count); // 가계부 내용을 수정하는 함수
- void deleteLog(product *p,int count); // 가계부 내용을 삭제하는 함수
- void saveLog(product *p, int count); // 가계부의 내용을 저장하는 함수
- int loadLog(product *p);// 저장된 내용을 불러오는 함수
```

### 추가 함수와 기능들
```
- int Menu(); // 메뉴를 불러오고 리턴을 가져오는 함수
- void searchLog(product *p, int count); // 가계부의 내용을 검색하여 출력하는 함수
- void totalLog(product *p,int count); // 가계부의 적힌 총액을 계산하는 함수
- int totalMonth(product *p, int month,int count); // 가계부의 적힌 내용을 기반으로 월 총 소비액을 출력하는 함수
```
