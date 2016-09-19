/*

Лабораторная работа 2
Структуры, объединения и списки. Файловый ввод-вывод
Варианты заданий

Определить структурированный тип, определить набор функций для работы с массивом структур. 
В  структурированной переменной предусмотреть способ отметки ее как не содержащей данных (т.е. "пустой"). 
Функции должны работать с массивом структур или с отдельной структурой через указатели, а также при необходимости возвращать указатель на структуру.

В перечень функций входят:
- «очистка» структурированных переменных;
- поиск свободной структурированной переменной;
- ввод элементов (полей) структуры с клавиатуры;
- вывод элементов (полей) структуры с клавиатуры;
- поиск в массиве структуры и минимальным значением  заданного поля;
- сортировка массива  структур в порядке возрастания заданного поля (при сортировке можно использовать тот факт, что в Си++ разрешается присваивание структурированных переменных);
- поиск в массиве структур элемента с заданным значением поля или с наиболее близким к нему по значению. 
- удаление заданного элемента;
- изменение (редактирование) заданного элемента.
- вычисление с проверкой и использованием всех элементов массива по заданному условию и формуле (например, общая сумма на всех счетах) -  дается индивидуально.

9. Фамилия И.О., количество оценок, оценки, средний балл, индивидуально - вывод среднего балла по всем оценкам

Компилятор - Microsoft Visual C++ 2010, экспресс-выпуск
Александр Владимирович 4 гр. УЦИТ

*/

#include <conio.h> // getch
#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> // strlen
#include <time.h> // time))
#include <windows.h> // SetConsoleTextAttribute))

#define maxf 30 // максимальное число записей и максимальная длина поля Фамилия И.О.
#define maxo 5

struct klass {
   char fio[maxf]; // Фамилия И.О.
   unsigned c; // количество оценок
   unsigned *bals; // оценки
   float sbal; // средний балл
}; 

void cvetn() {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_BLUE);} // делаем цвет синим, фон белым
void cvetu() {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_GREEN);} // делаем цвет зелёным, фон белым
void cvete() {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_INTENSITY);} // делаем цвет красным, фон белым

void vivoda(struct klass *a) { // вывод всего списка
unsigned j=0,i=0,s=0;

system("cls"); // очищаем экран
printf("+-----------------------------------------------------------------+\n");
printf("| #. Familia I.O.        | Ocenok |        Ocenki       | Sr. bal |\n");
printf("|-----------------------------------------------------------------|\n");
printf("|                        |        |                     |         |\n");

for(i=0;i<maxf;i++) { 
if(a[i].fio[0]>64 && a[i].fio[0]<91) { // выводим только те записи, где первая буква заглавная (не пустые)
printf("| %u. %s ",i+1,a[i].fio);
if(i+1>=10) for (j=0;j<18-strlen(a[i].fio);j++) printf(" "); else for (j=0;j<19-strlen(a[i].fio);j++) printf(" ");
printf("|   %u    |",a[i].c);
if(a[i].c>0) {
for (j=0;j<a[i].c;j++) printf("  %u ",a[i].bals[j]); 
for (j=0;j<5-a[i].c;j++) printf("    ");
printf(" |   %.1f   |\n",a[i].sbal); 
printf("|                        |        |                     |         |\n");
} else {
printf("  -   -   -   -   -  |    -    |\n");
printf("|                        |        |                     |         |\n");
}
}
}
printf("+-----------------------------------------------------------------+\n"); 
}

void vivp(struct klass *a) { // полный вывод всего списка
unsigned j=0,i=0,s=0;

system("cls");
printf("+-----------------------------------------------------------------+\n");
printf("| #. Familia I.O.        | Ocenok |        Ocenki       | Sr. bal |\n");
printf("|-----------------------------------------------------------------|\n");
printf("|                        |        |                     |         |\n");

for(i=0;i<maxf;i++) { 
printf("| %u. %s ",i+1,a[i].fio);
if(i+1>=10) for (j=0;j<18-strlen(a[i].fio);j++) printf(" "); else for (j=0;j<19-strlen(a[i].fio);j++) printf(" ");
printf("|   %u    |",a[i].c);
if(a[i].c>0) {
for (j=0;j<a[i].c;j++) printf("  %u ",a[i].bals[j]); 
for (j=0;j<5-a[i].c;j++) printf("    ");
printf(" |   %.1f   |\n",a[i].sbal); 
printf("|                        |        |                     |         |\n");
} else {
printf("  -   -   -   -   -  |    -    |\n");
printf("|                        |        |                     |         |\n");
}
}
printf("+-----------------------------------------------------------------+\n"); 
}

void rvvod(struct klass *a,unsigned c) { // случайное заполнение всех полей (структура, кол-во заполняемых элементов) 

unsigned r,ran,i,s,j=0;
for(;j<c;j++) {
i=0;s=0;
ran = rand()%10+10; // общее кол-во знаков в Ф.И.О. (букв прбела точек)
while(i<ran) {
if(i==0 || i==ran-5 || i==ran-3) r=rand()%25+65; else r=rand()%25+97; // r=rand()%25+97;
a[j].fio[i]=r;
if(i==ran-4 || i==ran-2) a[j].fio[i]='.';
if(i==ran-6) a[j].fio[i]=32;
if(i==ran-1) a[j].fio[i]=NULL;
i++;
}

r = rand()%6; // кол-во оценок
a[j].c=r;

if(a[j].c>0) {
a[j].bals=(unsigned *)malloc(a[j].c*sizeof(unsigned));
for (i=0;i<a[j].c;i++) {
	r=rand()%5+1; // оценки
	a[j].bals[i]=r;
s+=r; 
}
a[j].sbal=(float)s/a[j].c; // средний балл
} else {
a[j].bals=(unsigned *)malloc(1*sizeof(unsigned));
a[j].bals[0]=0;
a[j].sbal = 0;
}
}

}

void vvod(struct klass *a) { // Ввод по всем пустым записям
unsigned j=0,i,s=0,p=0,l=0;
char b=0;

for(;j<maxf;j++) {
if(b==27 || b==19) break; // При нажатии на ESC выходим из цикла ввода
if(a[j].fio[0]<65 || a[j].fio[0]>90) { // чтобы не перезаписывать занятые записи
system("cls");
i=0;
printf("Vvod zapisi #%u\n\n",j+1);
printf("Vvedite Familiyu I.O.\n\n_\n\nBukv ostalos'\nVihod iz rezhima zapisi bez sohraneniya tekushei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	while(1) {
	l=0;p=0;	
	b = getch();
	system("cls");
	printf("Vvod zapisi #%u\n\n",j+1);


	while(a[j].fio[l]!=NULL) { 
		if(a[j].fio[l]==32) p++; // ищем пробел, если он будет, то начинаем делать все буквы заглавными, дабы не мучить шифт или капс
         // + считываем положение указателя (Чтобы выводилась уже введёная информация)
		l++;
		}
	
	
	if(b==19) break; // При нажатии на Ctrl+S сохраняем структуру и выходим из цикла ввода
	if(b==27) {a[j].fio[0]=NULL; break;} // При нажатии на ESC чистим элемент структуры и выходим из цикла ввода
	if(i==0 && (b<65 || b>90) && (b<97 || b>122) && b!=13) {

	printf("Vvedite Familiyu I.O.\n\n");
	printf("%s_\n\nBukv ostalos' %u",a[j].fio,maxf-i-1);
	printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	printf("\n\n\nNEDPOUSTIMYI SIMVOL! Doljna byt bukva!"); continue;
	}
	if((b<65 || b>90) && (b<97 || b>122) && b!=46 && b!=13 && b!=32 && b!=8) { // если вводим букву, а не перенос строки, пробел и бэкспейс
	printf("Vvedite Familiyu I.O.\n\n");
	printf("%s_\n\nBukv ostalos' %u",a[j].fio,maxf-i-1);
	printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	printf("\n\nNEDPOUSTIMYI SIMVOL!"); i--; continue;
	}


	if (b!=13) {
	if(i==0 && b>96 && b<123) b-=32;
		if(p>0 && b>96 && b<123) b-=32;

		a[j].fio[i]=b; a[j].fio[i+1]=NULL;} else {a[j].fio[i]=NULL; break;}

		if (b==8) {a[j].fio[i-1]=NULL; i-=2; 
		i++;
		system("cls");
		printf("Vvod zapisi #%u\n\n",j+1);
		printf("Vvedite Familiyu I.O.\n\n");
		printf("%s_\n\nBukv ostalos' %u",a[j].fio,maxf-i-1);
		printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	 } else {
		i++;
		printf("Vvedite Familiyu I.O.\n\n");
		printf("%s_\n\nBukv ostalos' %u",a[j].fio,maxf-i-1);
		printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
		}

		if(i>100) i=0;
}

if(b!=19 && b!=27 && strlen(a[j].fio)!=0) {

if(i==maxf-1) a[j].fio[i]=NULL;

printf("\nFamilia: %s\n",a[j].fio);

printf("\nVvedite kol-vo ocenok (max 5)\n");
scanf("%u",&a[j].c);
if(a[j].c>5) a[j].c=5;

if(a[j].c>0) {
a[j].bals=(unsigned *)malloc(a[j].c*sizeof(unsigned));
printf("Vvedite ocenki\n");
for (i=0;i<a[j].c;i++) { scanf("%u",&a[j].bals[i]);
s+=a[j].bals[i]; 
}
a[j].sbal=(float)s/a[j].c; // средний балл
} else {
a[j].bals=(unsigned *)malloc(1*sizeof(unsigned));
a[j].bals[0]=0;
a[j].sbal = 0;
}
}
vivoda(a);
cvetu(); printf("\n\tZapis' soharnena!\n"); cvetn();
}
}

}

void redakt(struct klass *a) { // Редактирование определённой записи
	unsigned i=0,s=0,l,p,n;
char b;

printf("\n\tVvedite nomer zapisi kotoruyu vi hotite otredaktirovat': ");
scanf("%u",&n);
system("cls");

if(n<=maxf && n>0) { // чтобы не выходить за предел массива структур
n--; // уменьшаем тк отсчёт с 0 )
	
printf("Redaktirovanie zapisi #%u\n\nVvedite Familiyu I.O.\n\n%s_\n\nBukv ostalos' %d",n+1,a[n].fio,maxf-strlen(a[n].fio)-1);
printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");

while(1) {
	l=0;p=0;
	b = getch();
		system("cls");
		printf("Redaktirovanie zapisi #%u\n\n",n+1);

		while(a[n].fio[l]!=NULL) { 
		if(a[n].fio[l]==32) p++; // ищем пробел, если он будет, то начинаем делать все буквы заглавными, дабы не мучить шифт или капс
	 // + считываем положение указателя (Чтобы выводилась уже введёная информация)
		l++;
		}

if(i==0 && (a[n].fio[0]>64 || a[n].fio[0]<91)) i=l; // если оказываемся в цикле "первый раз", то ставим указатель ввода в крайнее правое положение

	if(b==19) break; // При нажатии на Ctrl+S сохраняем структуру и выходим из цикла ввода
	if(b==27) {a[n].fio[0]=NULL; break;} // При нажатии на ESC чистим структуру и выходим из цикла ввода
	if(i==0 && (b<65 || b>90) && (b<97 || b>122) && b!=13) { // если первый символ буква и не конец ввода
	printf("Vvedite Familiyu I.O.\n\n");
	printf("%s_\n\nBukv ostalos' %u",a[n].fio,maxf-i-1);
	printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	printf("\n\n\nNEDPOUSTIMYI SIMVOL! Doljna byt bukva!"); continue;	
	}
	if((b<65 || b>90) && (b<97 || b>122) && b!=46 && b!=13 && b!=32 && b!=8) { // последующие возможные символы
	printf("Vvedite Familiyu I.O.\n\n");
	printf("%s_\n\nBukv ostalos' %u",a[n].fio,maxf-i-1);
	printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	printf("\n\nNEDPOUSTIMYI SIMVOL!"); i--; continue;
	}


	if (b!=13) { // если ещё вводим данные
	if(i==0 && b>96 && b<123) b-=32; // если первая буква маленькая вводится Ф. - делаем её большой
		if(p>0 && b>96 && b<123) b-=32; // если есть пробел, значит водится И.О. - делаем буквы большими
			if(i<maxf-1)  a[n].fio[i]=b; // если не выходим за рамки строки
			a[n].fio[i+1]=NULL; // делаем последущий символ концом строки
	} else {a[n].fio[i]=NULL; break;} // если перестали вводить данные - то делаем символ концом строки и выходим из цикла ввода

		if (b==8) {i--; a[n].fio[i]=NULL;   //  сдвигаем указатель назад, удаляем уже введёный символ - делаем его концом строки
		system("cls"); // далее обновляем экран
		printf("Redaktirovanie zapisi #%u\n\n",n+1);
		printf("Vvedite Familiyu I.O.\n\n");
		printf("%s_\n\nBukv ostalos' %u",a[n].fio,maxf-1-i); // размер строки минус знак конца строки минус текущее положения указателя
		printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
	 } else {
		i++;
	    if(i>=maxf-1) {i=29; a[n].fio[i+1]=NULL;} // если выходим за рамки строки - ставим указатель на последнюю букву
		printf("Vvedite Familiyu I.O.\n\n");
		printf("%s_\n\nBukv ostalos' %u",a[n].fio,maxf-1-i); 
		printf("\nVihod iz rezhima zapisi bez sohraneniya tekuschei zapisi - Esc\nVihod iz rezhima zapisi s sohraneniem tekuschih dannih - Ctrl+S");
		}
		if(i>99) i=0; // если уходим в "минус", то возвращаем укзаатель на 0
}

if(b!=19 && b!=27 && strlen(a[n].fio)!=0) { // если не закончили вводить и фамилия не пуста, то переходим к вводу оценок

printf("\nFamilia: %s\n",a[n].fio);
printf("\nVvedite kol-vo ocenok (max 5)\n");
scanf("%u",&a[n].c);
if(a[n].c>5) a[n].c=5;

if(a[n].c>0) { // если оценки есть, то вводим их и высчитываем ср. балл
a[n].bals=(unsigned *)malloc(a[n].c*sizeof(unsigned));
printf("Vvedite ocenki\n");
for (i=0;i<a[n].c;i++) {scanf("%u",&a[n].bals[i]);
s+=a[n].bals[i];
}
a[n].sbal=(float)s/a[n].c;
} else {
a[n].bals=(unsigned *)malloc(1*sizeof(unsigned));
a[n].bals[0]=0;
a[n].sbal = 0;
}
}
}

vivoda(a);
cvetu(); printf("\n\tZapis' otredaktirovana!\n"); cvetn();
}

void del(struct klass *a) { // удаление записи
unsigned i;
printf("\n\tVvedite nomer zapisi kotoruyu vi hotite udalit': ");
scanf("%u",&i); 
if(i<=maxf && i>0) { // чтобы не выходить за предел массива структур
i--; 
for(;i<maxf-1;i++) {
a[i]=a[i+1];
}

vivoda(a);
cvetu(); printf("\n\tZapis' udalena!\n"); cvetn();
} else { cvete(); printf("\n\tNomer zapisi vihodit za ramki jurnala!\n"); cvetn();}
}

void poisksv(struct klass *a) { // - поиск свободной структурированной переменной;
unsigned j=0,i=0,s=0;

for(i=0;i<maxf;i++) {
if(a[i].fio[0]<65 || a[i].fio[0]>90) {
s++;
if(s==1) printf("\nSvobodnie stroki:");
cvetu();
printf(" %d",i+1); 
}
}
cvetn();
printf("\n");
}

void poiskminsr(struct klass *a) { // поиск записей с минимальным средним баллом
unsigned j=0,i=0,s=0;
float min=5;

for(;i<maxf-1;i++) {
if(a[i].fio[0]>65 && a[i].fio[0]<91 && a[i].c>0) if(a[i].sbal<min) min=a[i].sbal;
}

cvetu();  printf("\nMinimalniy srednii ball:\n");  cvetn(); 
printf("+-----------------------------------------------------------------+\n");
printf("| #. Familia I.O.        | Ocenok |        Ocenki       | Sr. bal |\n");
printf("|-----------------------------------------------------------------|\n");
printf("|                        |        |                     |         |\n");

for(i=0;i<maxf;i++) {
if(a[i].fio[0]>65 && a[i].fio[0]<91 && a[i].sbal==min) {
printf("| %u. %s ",i+1,a[i].fio);
if(i+1>=10) for (j=0;j<18-strlen(a[i].fio);j++) printf(" "); else for (j=0;j<19-strlen(a[i].fio);j++) printf(" ");
printf("|   %u    |",a[i].c);

if(a[i].c>0) {
for (j=0;j<a[i].c;j++) printf("  %u ",a[i].bals[j]);
for (j=0;j<5-a[i].c;j++) printf("    ");

printf(" |   %.1f   |\n",a[i].sbal);
printf("|                        |        |                     |         |\n");
} else {
printf("  -   -   -   -   -  |    -    |\n");
printf("|                        |        |                     |         |\n");
}
}
}

printf("+-----------------------------------------------------------------+\n");
}

void srbal(struct klass *a) { // вывод среднего балла по всем оценкам
unsigned j,i=0,s=0,c=0;
float min=5;
for(;i<maxf-1;i++) {
for(j=0;j<a[i].c;j++){
	if(a[i].fio[0]>65 && a[i].fio[0]<91 && a[i].c>0) {s+=a[i].bals[j];c++;}
}
}
cvetu(); printf("\n\tSredniy ball po vsem ocenkam = %.1f\n",(float)s/c);  cvetn(); 
}

void ochis(struct klass *a) { // полный вывод всего списка
unsigned i;
printf("\n\tVvedite nomer zapisi kotoruyu vi hotite ochistit': ");
scanf("%u",&i);
if(i<=maxf && i>0) { // чтобы не выходить за предел массива структур
i--;
if(a[i].fio[0]>64 && a[i].fio[0]<91) a[i].fio[0]+=32; else a[i].fio[0]=0;
vivoda(a);
cvetu(); printf("\n\tOchistka zapisi proshla uspeshno!\n\n"); cvetn();
} else {
cvete(); printf("\n\n\tNomer zapisi vihodit za ramki jurnala!\n"); cvetn();
}
}

void poisk(struct klass *a) { // поиск по фамилии заданного текста
	unsigned l=1,i,j,mas[maxf]={0},max,p=0;
char str[maxf];

printf("\nVvedite tekst dlya poiska: ",str); 
cvetu();

    for (i=0;i<maxf-1;i++) { 
	str[i] = getch();
	str[i+1]=0;
	printf("%c",str[i]);
	if (str[i]==13) {str[i]='\0'; break;}	
	}
	cvetn();
	
for(i=0;i<maxf;i++) { // цикл по записям
if(a[i].fio[0]>64 && a[i].fio[0]<91) {
	
for(j=0;j<strlen(a[i].fio)-1;j++) { // цикл по фамилии
	//if(mas[i] == strlen(str)) break; // если уже нашли один раз полностью кусок, то прерываем поиск по данной записи
p=j;

for(l=0;l<strlen(str);l++) { // цикл по строке поиска

	if(str[l]==a[i].fio[p]) { // если символы совпадают...
	if(mas[i] == strlen(str)) break; // если уже нашли один раз полностью кусок, то прерываем поиск по данной записи
	mas[i]++; p++; // увеличиваем счётчик, смещаем укзаатель строки в которой ищем
    if(l==0) mas[i]=1; // если начинаем с первой буквы, то счётчик должен быть равен 1, чтобы не накручивался за повторы
	} else {
	  if(str[l-1]==a[i].fio[p-1] && l!=0) p-=2; // если шли шли и облом - возвращаем указатель назад, дабы начать с пропущенного до этого символа
	  break;
	}
	}
}
}

}

max=mas[0];
for(i=0;i<maxf-1;i++) if(mas[i]>max) max=mas[i];
if (max>0) {
printf("\n\nMaksimalno pohojii tekst v zapisyah:\n\n");
printf("+-----------------------------------------------------------------+\n");
printf("| #. Familia I.O.        | Ocenok |        Ocenki       | Sr. bal |\n");
printf("|-----------------------------------------------------------------|\n");
printf("|                        |        |                     |         |\n");

for(i=0;i<maxf-1;i++) {
if(mas[i]==max) {
printf("| %u. %s ",i+1,a[i].fio);
if(i+1>=10) for (j=0;j<18-strlen(a[i].fio);j++) printf(" "); else for (j=0;j<19-strlen(a[i].fio);j++) printf(" ");
printf("|   %u    |",a[i].c);

if(a[i].c>0) {
for (j=0;j<a[i].c;j++) printf("  %u ",a[i].bals[j]);
for (j=0;j<5-a[i].c;j++) printf("    ");

printf(" |   %.1f   |\n",a[i].sbal);
printf("|                        |        |                     |         |\n");
} else {
printf("  -   -   -   -   -  |    -    |\n");
printf("|                        |        |                     |         |\n");
}
}
}
printf("+-----------------------------------------------------------------+\n");
} else {vivoda(a); cvete(); printf("\n\nNe naideno ni odnogo sovpadenia!"); cvetn();}

}


void sort(struct klass *a) { // сортировка по возрастанию строки Ф.И.О
 unsigned i,j,c,n=0,k=0,g;
 int mas[maxf]={0};
 struct klass spis1[maxf];
 for(i=0;i<maxf-1;i++) if(a[i].fio[0]>64 && a[i].fio[0]<91) n++; // находим кол-во не пустых элементов для счётчика сортировки
 while(k<n-1){ // сортировка должна продолжаться пока все элементы не встанут на своё место
  if(n==1) break;
  
  for(i=0;i<n;i++){	// цикл прохода по элементам	
   if(a[i].fio[0]>64 && a[i].fio[0]<91){ // если сравниваемые элементы не "пустые"
    for(j=0;j<strlen(a[i].fio);j++){ // цикл прохода по символам текущей строки
     c=0; // сбрасываем счётчик совпавших до этого символа символов
     for(g=0;g<=j;g++) if(a[i].fio[g]==a[i+1].fio[g]) c++; // подсчитываем число совпавших до этого символа символов и если они совападают можно сравнивать!
     if(c==j && i+1<n){ // если до этого символа все символы совпали и мы не находимся на последней строке
      if(a[i].fio[j]<=a[i+1].fio[j] && a[i].fio[j]!=0) k++; // если строки равны либо стоят как надо, то увеличиваем счётчик отсортированности
       else { // иначе меняем элементы местами  
        k=0; //  сбрасываем счётчик подсчёта элементов на своих местах
        spis1[0]=a[i];	 // меняем элементы местами используя одну дополнительную ячейку такой же структуры
        a[i]=a[i+1]; 	 // меняем элементы местами используя одну дополнительную ячейку такой же структуры
        a[i+1]=spis1[0]; // меняем элементы местами используя одну дополнительную ячейку такой же структуры
	  }
	 }		
    }
   }
  }
 }
 vivoda(a); cvetu(); printf("\n\tZapisi otsortirovany!\n"); cvetn(); // показываем что отсортировали
}


void main5345335() {
	int i=0;
	char b;
	unsigned count=0;
    struct klass spis[maxf];

   /* Ниже не понятные пока мне штуки для увеличения окна консоли, для оптимальной работы со списоком */

	SMALL_RECT windowSize = {0, 0, 79, 50};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
  	SetConsoleTitle(TEXT("Laba 2: 'Rabota s massivom structur'"));

cvetn(); // ставим цвет интерефейса
system("cls");

srand(time(NULL)); // семя случайности будет зависеть от текущего времени

for(i=0;i<maxf;i++) { // заполняем все записи пустотами для хорошего тона)
	spis[i].fio[0]=0;
	spis[i].c=0;
	spis[i].sbal=0;
}

rvvod(spis,15); // вводим 15 случайных записей

vivoda(spis); // выводим их

printf("\nO - Ochistka zapisi"); // выводим подсказки для управления записями
printf("\t\t\tZ - Zapolnenie pustih zapisei"); 

printf("\nD - Udalenie zapisi"); 
printf("\t\t\tE - Vivod nomerov svobodnih zapisei");

printf("\nA - Vivod vseh zapisei");
printf("\t\t\tS - Sortirovka zapisei po familiam");

printf("\nR - Redaktirovanie zapisi");
printf("\t\tB - Vivod srednego balla po vsem ocenkam");

printf("M - Vivod zapisi s minimalnim srednim balom");
printf("\nF - Poisk naibolee blizkogo znachenia po familii");

while(b = getch()) { // отслеживаем нажатие клавиши и в соответсвии с этим делаем что хочет пользователь)

vivoda(spis);

if(b == 122 || b == 90) vvod(spis); // буквы Z z - начинает вводим все пустые записи в цикле
if(b == 100 || b == 68) del(spis); // буквы D d - удаляем выбранную нами запись
if(b == 114 || b == 82) redakt(spis); // буквы R r - редактируем выбранную нами запись
if(b == 101 || b == 69) poisksv(spis); // буквы E e - вывод номеров свободных записей
if(b == 109 || b == 77) poiskminsr(spis); // буквы M m - вывод записей с минимальным средним баллом
if(b == 98  || b == 66) srbal(spis); // буквы B b - вывод среднего балла по всем оценкам таблицы
if(b == 111 || b == 79) ochis(spis); // буквы O o - очистка определённой записи
if(b == 102 || b == 70) poisk(spis); // буквы F f - регистрозависимый поиск графе Фамилия И.О.
if(b == 115 || b == 83) sort(spis); // буквы S s - сортировка по возрастанию графы Фамилия И.О.

if(b == 112|| b == 80) vivp(spis); // буквы P p - вывод ВСЕХ записей (даже пустых, для отладки))

if(b == 27) exit(0); // Выход из программы по искейпу)

printf("\nO - Ochistka zapisi"); // выводим подсказки для управления записями
printf("\t\t\tZ - Zapolnenie pustih zapisei"); 

printf("\nD - Udalenie zapisi"); 
printf("\t\t\tE - Vivod nomerov svobodnih zapisei");

printf("\nA - Vivod vseh zapisei");
printf("\t\t\tS - Sortirovka zapisei po familiam");

printf("\nR - Redaktirovanie zapisi");
printf("\t\tB - Vivod srednego balla po vsem ocenkam");

printf("M - Vivod zapisi s minimalnim srednim balom");
printf("\nF - Poisk naibolee blizkogo znachenia po familii");


}
}

