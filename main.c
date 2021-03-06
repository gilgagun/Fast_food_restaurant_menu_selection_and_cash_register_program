// 패스트푸드 전문점의 메뉴선택 및 금전등록기 프로그램

#define _CRT_SECURE_NO_WARNINGS   // sprintf 관련 오류를 방지하기 위해 맨 위에 정의
#include <stdio.h>                // 표준 입출력 관련 내장함수를 사용하기 위한 헤더파일 불러오기
#include <stdlib.h>               // 표준 라이브러리 관련 내장함수를 사용하기 위한 헤더파일 불러오기
#include <string.h>               // 문자열 관련 내장함수를 사용하기 위한 헤더파일 불러오기
#define BURGERSET_INDEX 20        // BURGERSET_INDEX라는 상수를 20로 정의
#define CHICKENSET_INDEX 6        // CHICKENSET_INDEX라는 상수를 6으로 정의
#define BURGER_INDEX 18           // BURGER_INDEX라는 상수를 18로 정의
#define CHICKEN_INDEX 6           // CHICKEN_INDEX라는 상수를 6으로 정의
#define DESSERT_INDEX 19          // DESSERT_INDEX라는 상수를 19로 정의
#define DRINK_INDEX 15            // DRINK_INDEX라는 상수를 15로 정의

typedef struct Menu {   // 메뉴 이름,메뉴 가격,메뉴 수량을 저장하기 위해 구조체 Menu 정의. typedef을 사용하여 struct Menu --> Menu
	char* menuName;   // 메뉴 이름(문자열)을 가리키는 포인터 변수 선언
	int menuPrice;    // 메뉴 가격  
	int menuCount;    // 메뉴 수량
}Menu;

// Menu형 구조체 배열 6개를 전역으로 선언과 동시에 초기화. 초기화해줄 때, 구조체 Menu 안에 선언된 변수의 순서와 동일한 순서로 초기화해줘야 함
// 버거세트 구조체 배열
Menu BurgerSet[BURGERSET_INDEX] = { {"100)스위트 어스 어썸 버거 세트",7400,0},{"101)밀리터리 버거 세트",8100,0},{"102)폴더버거 핫치킨 세트",7500,0},{"103)폴더버거 비프 세트",7500,0},
									{"104)리아미라클버거 세트",7400,0},{"105)와규 에디션2 세트",7600,0},{"106)더블X2 세트",7500,0},{"107)새우버거 세트",5900,0},
									{"108)치킨버거 세트",5100,0},{"109)T-Rex 버거 세트",5900,0},{"110)AZ버거 세트",8300,0},{"111)클래식 치즈버거 세트",6400,0},
									{"112)한우연인팩",13900,0},{"113)한우불고기 콤보",8000,0},{"114)한우불고기 세트",8700,0},{"115)한우명품팩",15600,0},
									{"116)원조빅불 세트",7600,0},{"117)핫크리스피버거세트",6700,0},{"118)데리버거 세트",4900,0},{"119)불고기버거 세트",5900,0} };
// 치킨세트 구조체 배열
Menu ChickenSet[CHICKENSET_INDEX] = { {"200)1인혼닭 세트",11500,0},{"201)패밀리팩",13600,0},{"202)치킨풀팩",18800,0},{"203)치킨하프팩",9300,0},
									{"204)순살치킨 풀팩",15900,0},{"205)순살치킨 하프팩",8900,0} };
// 햄버거 구조체 배열
Menu Burger[BURGER_INDEX] = { {"300)스위트 어스 어썸 버거",5600,0},{"301)밀리터리 버거",6400,0},{"302)폴더버거 핫치킨",5700,0},{"303)폴더버거 비프",5700,0},
							{"304)리아미라클버거",5600,0},{"305)와규 에디션 2",5800,0},{"306)더블X2",5500,0},{"307)새우버거",3900,0},
							{"308)치킨버거",2900,0},{"309)T-Rex",3700,0},{"310)클래식 치즈버거",4400,0},{"311)한우불고기",7000,0}, 
							{"312)모짜렐라 인 더 버거-베이컨",6000,0},{"313)AZ버거",6600,0},{"314)원조빅불",5800,0},{"315)핫크리스피버거",4900,0},
							{"316)불고기 버거",3900,0},{"317)데리버거",2500,0} };
// 치킨 구조체 배열
Menu Chicken[CHICKEN_INDEX] = { {"400)1인혼닭",10000,0},{"401)치킨휠레(4조각)",4500,0},{"402)화이어윙(2조각)",2500,0},{"403)화이어윙(4조각)",4500,0},
								{"404)치킨1조각",2300,0},{"405)치킨휠레(2조각)",2500,0} };
// 디저트 구조체 배열
Menu Dessert[DESSERT_INDEX] = { {"500)찐氷",3800,0},{"501)치킨인더에그",3000,0},{"502)지파이 하바네로(L)",4300,0},{"503)지파이 고소한맛(S)",3400,0},
								{"504)치킨 너겟",1200,0},{"505)롱 치즈스틱(1조각)",1800,0},{"506)콘샐러드",1700,0},{"507)선데이아이스크림(스트로베리)",1500,0},
								{"508)쉑쉑치킨(칠리)",2500,0},{"509)쉑쉑치킨(치즈)",2500,0},{"510)쉑쉑치킨(어니언)",2500,0},{"511)양념감자",2000,0},
								{"512)오징어링",2200,0},{"513)치즈스틱",2000,0},{"514)포테이토",1500,0},{"515)토네이도(초코쿠키)",2300,0},
								{"516)토네이도(녹차)",2300,0},{"517)토네이도(스트로베리)",2400,0},{"518)소프트콘",700,0} };
// 드링크 구조체 배열
Menu Drink[DRINK_INDEX] = { {"600)아이스티",2200,0},{"601)아이스 아메리카노 L",2500,0},{"602)핫초코",2000,0},{"603)오렌지주스(400ml PET)",2500,0},
									{"604)우유",1500,0},{"605)사이다(R)",1700,0},{"606)콜라(R)",1700,0},{"607)밀크쉐이크(딸기)",2100,0},
									{"608)밀크쉐이크(초코)",2100,0},{"609)밀크쉐이크(바닐라)",2100,0},{"610)아메리카노",2000,0},{"611)아이스 아메리카노",2000,0},
									{"612)카페라떼",2400,0},{"613)아이스 카페라떼",2400,0},{"614)레몬에이드",2500,0} };

int menu_display(void);              // 메뉴 목록을 불러오는 함수 선언
void order(void);                    // 1. 추가 를 눌렀을 때 작동하는 함수 선언
void cancel(void);                   // 2. 취소 를 눌렀을 때 작동하는 함수 선언
void portfolio(void);                // 3. 입력종료 를 눌렀을 때 작동하는 함수 선언
void calcPriceTotal(int n, int c);   // 메뉴 수량,총 금액을 계산하기 위한 함수 선언
int total = 0;                       // 총 금액을 의미하는 정수형 변수 total을 전역변수로 선언 후, 초기값을 0으로 설정

int main(void) {   // 메인 함수
	int c;

	while ((c = menu_display()) != 3) {   // menu_display()의 반환값이 3이 아니면 계속 반복
		switch (c) {                      // switch문을 사용하여 c의 값에 따라 각각 다른 함수를 호출
			case 1: order();              // c의 값이 1이면 order() 함수 호출
				break;                    // break문을 걸어두지 않으면 아래에 있는 case들도 실행이 되어버리니 꼭 break문을 작성해서 switch문을 탈출하게 해야함
			case 2: cancel();             // c의 값이 2이면 cancel() 함수 호출
				break;
			default: break;               // c의 값에 1,2가 아닌 다른 잘못된 값이 들어오면 기본적으로 switch문 탈출
		}
	}
	printf("\n");
	portfolio();   // c 값이 3이 되어 while문을 탈출하면 portfolio() 함수 호출

	return 0;
}

int menu_display(void) {   // 메뉴 목록을 불러오는 함수 정의
	Menu* m = NULL;        // Menu형 구조체 배열을 가리킬 포인터 변수 m을 NULL로 초기화
	int select = 0;        // 번호를 0으로 초기화

	system("cls");         // 함수가 실행될 때마다 메뉴 목록을 보기 좋게 출력하기 위해 콘솔창에 있는 항목을 다 지워주는 함수
	printf("\n======================================================================== LOTTERIA POS ========================================================================\n\n");

	m = BurgerSet;         // 포인터 변수 m이 구조체 배열 BurgerSet의 주소를 가리킴
	printf("\n- 버거세트\n");
	for (int i = 0; i < BURGERSET_INDEX; i++) {   // BURGERSET_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n");

	m = ChickenSet;        // 포인터 변수 m이 구조체 배열 ChickenSet의 주소를 가리킴
	printf("\n- 치킨세트\n");
	for (int i = 0; i < CHICKENSET_INDEX; i++) {   // CHICKENSET_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n");

	m = Burger;            // 포인터 변수 m이 구조체 배열 Burger의 주소를 가리킴
	printf("\n- 햄버거\n");
	for (int i = 0; i < BURGER_INDEX; i++) {   // BURGER_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n");

	m = Chicken;           // 포인터 변수 m이 구조체 배열 Chicken의 주소를 가리킴
	printf("\n- 치킨\n");
	for (int i = 0; i < CHICKEN_INDEX; i++) {   // CHICKEN_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n");

	m = Dessert;           // 포인터 변수 m이 구조체 배열 Dessert의 주소를 가리킴
	printf("\n- 디저트\n");
	for (int i = 0; i < DESSERT_INDEX; i++) {   // DESSERT_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n");

	m = Drink;             // 포인터 변수 m이 구조체 배열 Drink의 주소를 가리킴
	printf("\n- 드링크\n");
	for (int i = 0; i < DRINK_INDEX; i++) {   // DRINK_INDEX만큼 반복
		printf("%-32s%5d\t", (m + i)->menuName, (m + i)->menuPrice);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 4 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n\n\n");

	printf("지불할 총액 :\t%d\n\n", total);   // 지불할 총액 출력(초기값: 0)

	printf("1. 추가  2. 취소  3. 입력종료\n");
	printf("번호 선택 후 Enter : ");
	scanf_s("%d", &select);                   // 번호 선택

	return select;                            // 선택한 번호 반환
}

void order(void) {   // 1. 추가 를 눌렀을 때 작동하는 함수 정의
	int num = 0;     // 메뉴 번호를 0으로 초기화
	int count = 0;   // 수량을 0으로 초기화
	
	printf("메뉴 번호 입력후 Enter(0: cancel) : ");
	scanf_s("%d", &num);   // 메뉴 번호 입력

	if (num == 0)   // num이 0이라면?
		return;     // main 으로 돌아감

	printf("수량 입력후 Enter> ");
	scanf_s("%d", &count);   // 수량 입력

	calcPriceTotal(num, count);   // 메뉴 수량,총 금액을 계산하기 위한 함수 호출
}

void cancel(void) {    // 2. 취소 를 눌렀을 때 작동하는 함수 정의
	Menu* q = NULL;                    // Menu형 구조체 배열을 가리킬 포인터 변수 q를 NULL로 초기화
	int number = 0;                    // 취소할 메뉴 번호를 0으로 초기화
	int cancel_menu;                   // number 값을 저장하기 위한 변수 cancel_menu 선언
	char str_cancel_menu[4] = { 0 };   // cancel_menu를 문자열로 바꿔서 저장할 배열을 0으로 초기화
	int digit = 0;                     // cancel_menu의 자릿수를 계산하기 위한 변수 digit을 0으로 초기화

	printf("선택한 메뉴\n");
	q = BurgerSet;                     // 포인터 변수 q가 구조체 배열 BurgerSet의 주소를 가리킴
	for (int i = 0; i < BURGERSET_INDEX; i++) {   // BURGERSET_INDEX만큼 반복
		if ((q + i)->menuCount != 0)              // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}
	q = ChickenSet;                    // 포인터 변수 q가 구조체 배열 ChickenSet의 주소를 가리킴
	for (int i = 0; i < CHICKENSET_INDEX; i++) {   // CHICKENSET_INDEX만큼 반복
		if ((q + i)->menuCount != 0)               // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}
	q = Burger;                        // 포인터 변수 q가 구조체 배열 Burger의 주소를 가리킴
	for (int i = 0; i < BURGER_INDEX; i++) {   // BURGER_INDEX만큼 반복
		if ((q + i)->menuCount != 0)           // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}
	q = Chicken;                       // 포인터 변수 q가 구조체 배열 Chicken의 주소를 가리킴
	for (int i = 0; i < CHICKEN_INDEX; i++) {   // CHICKEN_INDEX만큼 반복
		if ((q + i)->menuCount != 0)            // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}
	q = Dessert;                       // 포인터 변수 q가 구조체 배열 Dessert의 주소를 가리킴
	for (int i = 0; i < DESSERT_INDEX; i++) {   // DESSERT_INDEX만큼 반복
		if ((q + i)->menuCount != 0)            // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}
	q = Drink;                         // 포인터 변수 q가 구조체 배열 Drink의 주소를 가리킴
	for (int i = 0; i < DRINK_INDEX; i++) {   // DRINK_INDEX만큼 반복
		if ((q + i)->menuCount != 0)          // q가 가리키는 곳의 menuCount(수량)가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (q + i)->menuName, (q + i)->menuCount, ((q + i)->menuCount) * ((q + i)->menuPrice));
	}

	printf("취소할 메뉴버튼 입력 후 Enter(0: cancel) > ");
	scanf_s("%d", &number);   // 취소할 메뉴 번호 입력

	if (number == 0)        // number가 0이라면?
		return;             // main 으로 돌아감
	cancel_menu = number;   // cancel_menu에 number 값 저장

	for (int i = 10; number > 0; digit++)   // number의 자릿수 계산
		number = number / i;
	if (digit != 3)                         // number가 세자리 수가 아니라면?
		return;                             // main 으로 돌아감(메뉴 번호는 다 세자리 수이기 때문)

	sprintf(str_cancel_menu, "%d", cancel_menu);       // 정수 cancel_menu를 str_cancel_menu에 문자열 형태로 저장
	if (strncmp(str_cancel_menu, "1", 1) == 0) {       // 문자열 str_cancel_menu와 문자열 "1"의 첫글자가 같다면?
		q = BurgerSet;                                 // 포인터 변수 q가 구조체 배열 BurgerSet의 주소를 가리킴
		for (int i = 0; i < BURGERSET_INDEX; i++) {    // BURGERSET_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {   // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);    // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                  // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
	else if (strncmp(str_cancel_menu, "2", 1) == 0) {  // 문자열 str_cancel_menu와 문자열 "2"의 첫글자가 같다면?
		q = ChickenSet;                                // 포인터 변수 q가 구조체 배열 ChickenSet의 주소를 가리킴
		for (int i = 0; i < CHICKENSET_INDEX; i++) {   // CHICKENSET_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {   // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);    // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                  // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
	else if (strncmp(str_cancel_menu, "3", 1) == 0) {  // 문자열 str_cancel_menu와 문자열 "3"의 첫글자가 같다면?
		q = Burger;                                    // 포인터 변수 q가 구조체 배열 Burger의 주소를 가리킴
		for (int i = 0; i < BURGER_INDEX; i++) {       // BURGER_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {   // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);    // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                  // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
	else if (strncmp(str_cancel_menu, "4", 1) == 0) {  // 문자열 str_cancel_menu와 문자열 "4"의 첫글자가 같다면?
		q = Chicken;                                   // 포인터 변수 q가 구조체 배열 Chicken의 주소를 가리킴
		for (int i = 0; i < CHICKEN_INDEX; i++) {      // CHICKEN_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {  // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);   // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                 // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
	else if (strncmp(str_cancel_menu, "5", 1) == 0) {  // 문자열 str_cancel_menu와 문자열 "5"의 첫글자가 같다면?
		q = Dessert;                                   // 포인터 변수 q가 구조체 배열 Dessert의 주소를 가리킴
		for (int i = 0; i < DESSERT_INDEX; i++) {      // DESSERT_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {  // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);   // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                 // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
	else if (strncmp(str_cancel_menu, "6", 1) == 0) {  // 문자열 str_cancel_menu와 문자열 "6"의 첫글자가 같다면?
		q = Drink;                                     // 포인터 변수 q가 구조체 배열 Drink의 주소를 가리킴
		for (int i = 0; i < DRINK_INDEX; i++) {        // DRINK_INDEX만큼 반복
			if (strncmp(str_cancel_menu, (q + i)->menuName, 3) == 0) {  // q가 가리키는 곳의 menuName과 문자열 str_cancel_menu의 첫 세글자가 같다면?
				total -= ((q + i)->menuPrice) * ((q + i)->menuCount);   // (메뉴 가격 * 메뉴 수량)을 총 합계에서 빼기
				(q + i)->menuCount = 0;                                 // 메뉴 수량 = 0 으로 설정
				break;
			}
		}
	}
}

void portfolio(void) {   // 3. 입력종료 를 눌렀을 때 작동하는 함수 정의
	Menu* k = NULL;      // Menu형 구조체 배열을 가리킬 포인터 변수 k를 NULL로 초기화
	int money = 0;       // 고객이 지불한 돈을 0으로 초기화
	int balance = 0;     // 잔돈을 0으로 초기화

	if (total == 0) {    // 만약 총 합계가 0원이라면?
		printf("고객이 지불할 금액은 0원 입니다. 입력을 종료합니다.\n");
		return;          // main 으로 돌아가서 프로그램 끝내기
	}

	printf("고객이 지불할 총액은\t%d원 입니다.\n", total);
	printf("고객으로부터 받은 금액을 입력 후 Enter> ");
	scanf_s("%d", &money);     // 고객으로부터 받은 금액 입력
	balance = money - total;   // 잔돈 구하기

	printf("\n명세표\n");      // 명세표 출력
	printf("-----------------------------------------------\n");

	k = BurgerSet;             // 포인터 변수 k가 구조체 배열 BurgerSet의 주소를 가리킴
	for (int i = 0; i < BURGERSET_INDEX; i++) {   // BURGERSET_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}
	k = ChickenSet;            // 포인터 변수 k가 구조체 배열 ChickenSet의 주소를 가리킴
	for (int i = 0; i < CHICKENSET_INDEX; i++) {  // CHICKENSET_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}
	k = Burger;                // 포인터 변수 k가 구조체 배열 Burger의 주소를 가리킴
	for (int i = 0; i < BURGER_INDEX; i++) {      // BURGER_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}
	k = Chicken;               // 포인터 변수 k가 구조체 배열 Chicken의 주소를 가리킴
	for (int i = 0; i < CHICKEN_INDEX; i++) {     // CHICKEN_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}
	k = Dessert;               // 포인터 변수 k가 구조체 배열 Dessert의 주소를 가리킴
	for (int i = 0; i < DESSERT_INDEX; i++) {     // DESSERT_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}
	k = Drink;                 // 포인터 변수 k가 구조체 배열 Drink의 주소를 가리킴
	for (int i = 0; i < DRINK_INDEX; i++) {       // DRINK_INDEX만큼 반복
		if ((k + i)->menuCount != 0)              // k가 가리키는 곳의 menuCount가 0이 아니라면?
			// 메뉴 이름, 수량, (수량 * 메뉴 가격) 출력
			printf("%s\t*%4d =\t%d\n", (k + i)->menuName, (k + i)->menuCount, ((k + i)->menuCount) * ((k + i)->menuPrice));
	}

	printf("-----------------------------------------------\n");
	printf("금액 :\t%d\n", total);     // 총 합계 출력
	printf("잔돈 :\t%d\n", balance);   // 잔돈 출력
}

void calcPriceTotal(int n, int c) {    // 메뉴 수량,총 금액을 계산하기 위한 함수 정의
	Menu* p = NULL;                    // Menu형 구조체 배열을 가리킬 포인터 변수 p를 NULL로 초기화
	int number = n;                    // n을 number에 저장
	int digit = 0;                     // n의 자릿수를 계산하기 위한 변수 digit을 0으로 초기화
	char str_number[4] = { 0 };        // number를 문자열로 바꿔서 저장할 배열을 0으로 초기화

	for (int i = 10; n > 0; digit++)   // n의 자릿수 계산
		n = n / i;
	if (digit != 3)                    // n이 세자리 수가 아니라면?
		return;                        // main 으로 돌아감(메뉴 번호는 다 세자리 수이기 때문)

	sprintf(str_number, "%d", number);             // 정수 number를 str_number에 문자열 형태로 저장
	if (strncmp(str_number, "1", 1) == 0) {        // 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = BurgerSet;                             // 포인터 변수 p가 구조체 배열 BurgerSet의 주소를 가리킴
		for (int i = 0; i < BURGERSET_INDEX; i++) {                     // BURGERSET_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {       // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                 // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);   // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
	else if (strncmp(str_number, "2", 1) == 0) {   // 문자열 str_number와 문자열 "2"의 첫글자가 같다면?
		p = ChickenSet;                            // 포인터 변수 p가 구조체 배열 ChickenSet의 주소를 가리킴
		for (int i = 0; i < CHICKENSET_INDEX; i++) {                    // CHICKENSET_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {       // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                 // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);   // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
	else if (strncmp(str_number, "3", 1) == 0) {   // 문자열 str_number와 문자열 "3"의 첫글자가 같다면?
		p = Burger;                                // 포인터 변수 p가 구조체 배열 Burger의 주소를 가리킴
		for (int i = 0; i < BURGER_INDEX; i++) {                       // BURGER_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {      // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);  // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
	else if (strncmp(str_number, "4", 1) == 0) {   // 문자열 str_number와 문자열 "4"의 첫글자가 같다면?
		p = Chicken;                               // 포인터 변수 p가 구조체 배열 Chicken의 주소를 가리킴
		for (int i = 0; i < CHICKEN_INDEX; i++) {                      // CHICKEN_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {      // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);  // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
	else if (strncmp(str_number, "5", 1) == 0) {   // 문자열 str_number와 문자열 "5"의 첫글자가 같다면?
		p = Dessert;                               // 포인터 변수 p가 구조체 배열 Dessert의 주소를 가리킴
		for (int i = 0; i < DESSERT_INDEX; i++) {                      // DESSERT_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {      // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);  // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
	else if (strncmp(str_number, "6", 1) == 0) {   // 문자열 str_number와 문자열 "6"의 첫글자가 같다면?
		p = Drink;                                 // 포인터 변수 p가 구조체 배열 Drink의 주소를 가리킴
		for (int i = 0; i < DRINK_INDEX; i++) {                        // DRINK_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->menuName, 3) == 0) {      // p가 가리키는 곳의 menuName과 문자열 str_number의 첫 세글자가 같다면?
				(p + i)->menuCount = c;                                // menuCount에 c 저장
				total += ((p + i)->menuPrice) * ((p + i)->menuCount);  // 합계에 (메뉴 가격 * 수량) 더해서 저장
				break;
			}
		}
	}
}