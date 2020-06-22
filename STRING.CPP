#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
class String{
private :
	int size,length;
	char *str;
public:
	String(char *txt);
	String(String &s);
	~String();
	static String upperCase(String &s);
	static String lowerCase(String &s);
	int equals(String &s);
	int equals(char * c);
	int equalsIgnore(String &s);
	int equalsIgnore(char *s);
	int indexOf(char ch);
	int indexOf(char ch,int ofset);
	int stringLength();
	char charAt(int index);
	String concat(String &s);
	String subString(int start);
	String subString(int start , int end);
	String replaceText(String &s ,int start , int end);
	String insertText(String &s ,int start);
	String operator+(String &s);
	String & operator+=(String &s);
	String & operator=(String &s);
	String & operator=(char *s);
	friend ostream & operator<<(ostream &out , String &c);
	friend istream & operator>>(istream &in,String &c);
	void print();
	int getLength();
	int getSize();
	char * getStr();
};
String :: String(char *txt){
	cout<<"\nobject created";
	for(length = 0 ; txt[length] !='\0';length++);
	size =length + 1;
	str = new char[size];
	for(int i = 0 ; i <length; i++){
		str[i]=txt[i];
	}
	str[length] = '\0';
}
String :: String(String &s){
	cout<<"\ncopy object created";
	length = s.length;
	size = s.size;
	str = new char[size];
	for(int i =0 ; i <length ; i ++){
		str[i] =s.str[i];
	}
	str[length] ='\0';
}
String ::~String(){
	delete[] str;
}

String String ::upperCase(String &s){
	String temp(s);
	for(int i = 0 ;i<temp.length;i++ )
	{
		if(temp.str[i]>='a'&& temp.str[i]<='z'){
			temp.str[i]=temp.str[i]-32;
		}
	}
	return temp;
}

String String ::lowerCase(String &s){
	String temp(s);
	for(int i = 0 ;i<temp.length;i++ )
	{
		if(temp.str[i]>='A'&& temp.str[i]<='Z'){
			temp.str[i]=temp.str[i]+32;
		}
	}
	return temp;
}
int String :: equals(String &s){
	if(!(size == s.size) &&!(length ==s.length)){
	   return 0;
	}else{

		for(int i =0 ; i<length ; i++){
			if(!(str[i]==s.str[i])){
				  return 0;
			}
		}
			 return 1;
	}

}
int String ::equals(char *c){

	String s(c);
	return this->equals(s);

}
int String ::equalsIgnore(String & s){
	String s1 = upperCase(s);
	String s2 = upperCase(*this);
	return s2.equals(s1);

}
int String ::equalsIgnore(char * c){
	String s(c);
	String s1 = upperCase(s);
	String s2 = upperCase(*this);
	return s2.equals(s1);
}
int String ::indexOf(char c){

	for(int i = 0 ; i<=length ; i++){
		if(str[i]==c){
			return i ;
		}
	}
	return -1 ;
}
int String ::indexOf(char ch,int ofset){
	if(ofset<=length && ofset>=0){
			for(int i = 0 ; i <=length-ofset;i++){
					if(str[i+ofset]==ch){
						return i+ofset;
					}
			}
	}
	return -1;
}
int String ::stringLength(){
	return length;
}
char String ::charAt(int index){
	if(length>0 && length >=index){
		return str[index];
	}
	return '\0';
}
String String ::concat(String &s){

	int l = length+s.length;
	char * ptr = new char[l + 1];

	for(int i =0 ; i <length ; i++){
		ptr[i]=str[i];
	}

	for(int j = 0 ; j <s.length ; j++){
		ptr[j+length]=s.str[j];
	}

	ptr[l] ='\0';
	String s1(ptr);

	delete[]ptr;

	return s1;

}
String String ::subString(int start){
	return this->subString(start,length);
}

String String ::subString(int start , int end){

	if(start<length){
		int i;
		char * ptr =new char[size +start -end];
		if((start +end)>length){
			end =(length - start);
		}
		for( i = 0 ; i <end ; i++){
		   ptr[i]=str[start+i];
		}
		ptr[i]='\0';
	 return String(ptr);
	}
	return "";
}
String String ::replaceText(String &s,int start , int end){

	String s1 =this->subString(0,start);
	String s2 =this->subString(end);
	String s3 = s1.concat(s);
	s3 =s3.concat(s2);

	return s3;
}
String String ::insertText(String &s , int start){
	String s1 = this->subString(0,start);
	String s2 = this->subString(start);
	String s3 = s1.concat(s);
	return s3.concat(s2);

}
ostream & operator <<(ostream &out , String &c){
   c.print();
 return out;
}
void String :: print(){
	for(int i=0 ; i<length;i++){
		cout<<str[i];
	}
}
String & String ::operator=(String &s){
   length = s.length;
   size = s.size;
   str = new char[size];
   for(int i =0 ; i <length ; i ++){
	str[i] =s.str[i];
   }
   return *this;
}
String & String ::operator=(char * txt){
	for(length = 0 ; txt[length] !='\0';length++);
	size =length + 1;
	str = new char[size];
	for(int i = 0 ; i <length; i++){
		str[i]=txt[i];
	}
	str[length] = '\0';
	return *this;
}
String String ::operator+(String &s){
   return this->concat(s);
}
String & String ::operator+=(String &s){
   char * ptc = new char[size +s.size];
   for(int i = 0 ; i<length ; i++){
		ptc[i]=str[i];
   }
   for(int j = 0 ; j<s.length ; j++){
		ptc[length +j]=s.str[j];
   }
   length +=s.length;

   size +=s.size;

   ptc[length]='\0';

   delete []str;

   str = ptc;

   return *this;
}
int String ::getLength(){
	return length;
}
int String ::getSize(){
	return size;
}
char * String :: getStr(){
	return str;
}
class Myapp{

	public:
	static char arr[23][90];
	Myapp();
	void printMenu();
	void printSubMenuHeader(char * header);
	void printA(char * header);
	void printB(char * header);
	void printC(char * header);
	void printD(char * header);
	void printE(char * header);
	void printF(char * header);
	void printG(char * header);
	void printH(char * header);
	void printI(char * header);
	void printJ(char * header);
	void printK(char * header);
	void printL(char * header);
	void printM(char * header);
	void printN(char * header);
	void printO(char * header);
	void printP(char * header);
	void printQ(char * header);
	void printR(char * header);
	void printS(char * header);
	void printT(char * header);
};
Myapp ::Myapp(){
	clrscr();
	printMenu();

}
char Myapp::	arr[23][90]={"a- String upperCase(String &s)",
						"b- String lowerCase(String &s)",
						"c- int equals(String &s)"      ,
						"d- int equals(char * c)"       ,
						"e- int equalsIgnore(String &s)",
						"f- int equalsIgnore(char *s)"  ,
						"g- int indexOf(char ch)"       ,
						"h- int indexOf(char ch,int ofset)"                    ,
						"i- int stringLength()"         ,
						"j- char charAt(int index)"     ,
						"k- String concat(String &s)"   ,
						"l- String subString(int start)",
						"m- String subString(int start , int end)"             ,
						"n- String replaceText(String &s ,int start , int end)",
						"o- String insertText(String &s ,int start)"           ,
						"p- String operator+(String &s)"                       ,
						"q- String & operator+=(String &s)"                    ,
						"r- String & operator=(String &s)"                     ,
						"s- String & operator=(char *s)",
						"x- exit"
						} ;
void Myapp :: printMenu(){

	char option;

	clrscr();

	gotoxy(1,1);
	cout<<"\t\tWelcome to our program";
	cout<<"\n please enter the write char to test the selected operation";

	for(int i = 1 ; i <24 ; i++){
		gotoxy(2,2+i);
		cout<<arr[i-1];
	}
	option = getch();
	switch(option){

		case 'a' :
			printA(arr[0]);
			printMenu();
			break;
		case 'b' :
			printB(arr[1]);
			printMenu();
			break;
		case 'c' :
			printC(arr[2]);
			printMenu();
			break;
		case 'd' :
			printD(arr[3]);
			printMenu();
			break;
		case 'e' :
			printE(arr[4]);
			printMenu();
			break;
		case 'f':
			printF(arr[5]);
			printMenu();
			break;
		case 'g':
			printG(arr[6]);
			printMenu();
			break;
		case 'h':
			printH(arr[7]);
			printMenu();
			break;
		case 'i':
			printI(arr[8]);
			printMenu();
			break;
		case 'j':
			printJ(arr[9]);
			printMenu();
			break;
		case 'k':
			printK(arr[10]);
			printMenu();
			break;
		case 'l':
			printL(arr[11]);
			printMenu();
			break;
		case 'm':
			printM(arr[12]);
			printMenu();
			break;
		case 'n':
			printN(arr[13]);
			printMenu();
			break;
		case 'o':
			printO(arr[14]);
			printMenu();
			break;
		case 'p':
			printP(arr[15]);
			printMenu();
			break;
		case 'q':
			printQ(arr[16]);
			printMenu();
			break;
		case 'r':
			printR(arr[17	]);
			printMenu();
			break;
		case 's':
			printS(arr[18]);
			printMenu();
			break;
		case 'x' :
			clrscr();
			exit(0);
		default :
			printMenu();
	}
}

void Myapp :: printSubMenuHeader(char * header){
	clrscr();
	gotoxy(30,1);
	cout<<header <<"\n";
}
void Myapp ::printA(char * header){
	printSubMenuHeader(header);
	char * ptr;
	cout<<"\nplease enter the string to upper:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	String upper = String ::upperCase(s);
	cout<<"\nupper case :\t"<<upper;
	getch();
}
void Myapp ::printB(char * header){
	printSubMenuHeader(header);

	char * ptr;
	cout<<"\nplease enter the string to lower:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
  	String lower = String ::lowerCase(s);
	cout<<"\nlower case :\t"<<lower;
	getch();
}
void Myapp ::printC(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"please enter the first word to check:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s(ptr1);
	cout<<"please enter the socound word :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s1(ptr2);
	if(s.equals(s1)){
		cout<<"\nequals ";
	}else{
		cout<<"\n not equals";
	}
	getch();
}
void Myapp ::printD(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter array of char to test on :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	cout<<"\nplease enter the string to test on :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s(ptr2);
  	if(s.equals(ptr1)){
		cout<<"\nequals ";
	}else{
		cout<<"\n not equals";
	}
	getch();
}
void Myapp ::printE(char * header){
	printSubMenuHeader(header);
	char * ptr1 ;
	char * ptr2;
	cout<<"\nplease enter the first string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	cout<<"\nplease enter the scound string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s1(ptr1);
	String s2(ptr2);
  	if(s1.equalsIgnore(s2)){
		cout<<"\nequals ";
	}else{
		cout<<"\n not equals";
	}
	getch();
}
void Myapp ::printF(char * header){
	printSubMenuHeader(header);

	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter array of char to test on :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);

	if(s2.equalsIgnore(ptr1)){
		cout<<"\nequals ";
	}else{
		cout<<"\n not equals";
	}
	getch();
}
void Myapp ::printG(char * header){
	printSubMenuHeader(header);
	char * ptr;

	char c;
	cout<<"\nplease enter the string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	cout<<"please enter  char to get index :";
	cin>>c;
	cout<<s.indexOf(c);
	getch();
}
void Myapp ::printH(char * header){
	printSubMenuHeader(header);
	char * ptr;
	char c;
	int i;
	cout<<"please enter the string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	cout<<"please enter  char  :";
	cin>>c;
	cout<<"please enter the ofset :";
	cin>>i;
	cout<<s.indexOf(c,i);
	getch();
}
void Myapp ::printI(char * header){
	printSubMenuHeader(header);
	char * ptr;
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	cout<<"string length  :\t"<<s.stringLength();
	getch();
}
void Myapp ::printJ(char * header){
	printSubMenuHeader(header);
	char * ptr;
	cout<<"\nplease enter the string:\n";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	int index;
	cout<<"\nplease enter the index :\t";
	cin>>index;
	cout<<"\nchar at index  :\t"<<s.charAt(index);
	getch();
}
void Myapp ::printK(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter the first string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	cout<<"\nplease enter the scound string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s1(ptr1);
	String s2(ptr2);
	cout<<"\nstring concat:\t";
	cout<<s1.concat(s2);
	getch();
}
void Myapp ::printL(char * header){
	printSubMenuHeader(header);
	char * ptr;
	int start;
	cout<<"\nplease enter the string:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	cout<<"\nplease enter the start:\t";
	cin>>start;
	String s(ptr);
	cout<<"subString:\t";
	cout<<s.subString(start);
	getch();
}
void Myapp ::printM(char * header){
	printSubMenuHeader(header);
	char * ptr;

	int start,end;
	cout<<"\n please enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr,1024);
	String s(ptr);
	cout<<"\n please enter the start :\t";
	cin>>start;
	cout<<"\n please enter the end:\t ";
	cin>>end;
	cout<<"subString:\t";
	cout<<s.subString(start,end);
	getch();
}
void Myapp ::printN(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	int start,end;
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the string to replace:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);
	cout<<"\n please enter the start :\t";
	cin>>start;
	cout<<"\n please enter the end:\t ";
	cin>>end;
	cout<<"text after replace:\t";
	cout<<s1.replaceText(s2,start,end);
	getch();
}
void Myapp ::printO(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	int start;
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the string to insert:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);
	cout<<"\n please enter the index to insert:\t";
	cin>>start;
	cout<<"text after inserting:\t";
	cout<<s1.insertText(s2,start);

	getch();
}
void Myapp ::printP(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the string to +:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);
	cout<<"text after +:\t";
	cout<<s1+s2;
	getch();
}
void Myapp ::printQ(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter the string :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the string to after +:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);
	cout<<"text after +=:\t";
	s1+=s2;
	cout<<s1;
	getch();
}
void Myapp ::printR(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter the firt string to = :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the scound string to after =:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	String s2(ptr2);
	cout<<"text after =:\t";
	s1=s2;
	cout<<s1;
	getch();
}
void Myapp ::printS(char * header){
	printSubMenuHeader(header);
	char * ptr1;
	char * ptr2;
	cout<<"\nplease enter the firt string to = :\t";
	cin.ignore(0,'\n');
	cin.getline(ptr1,1024);
	String s1(ptr1);
	cout<<"\nplease enter the char * to after =:\t";
	cin.ignore(0,'\n');
	cin.getline(ptr2,1024);
	cout<<"text after =:\t";
	s1=ptr2;
	cout<<s1;
	getch();
}
int main(){
	Myapp m;
     clrscr();
     /*
	String s1="hello";
	String s2="hello";
	String::upperCase(s2);
	getch();*/
	return 0;
}
