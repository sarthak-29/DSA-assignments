#include<iostream>
#include<fstream>
using namespace std;
class student{
public:
 char name[10];
 int roll;
 void getdata(){
  cout<<"\nEnter the roll no and name: ";
  cin>>roll>>name;
 }
 void putdata(){
  cout<<"\nThe roll no and name: ";
  cout<<roll<<" "<<name;
  }
};

class file{
  fstream fp;
public:
  void create(){
  char ans;
  student s;
  fp.open("stu.dat",ios::out);
   if(!fp){
    cout<<"\nError opening file for writing."<<endl;
   return;
  }
   do{
 s.getdata();
 fp.write((char*)&s,sizeof(s));
 cout<<"\nMore? (Y/y to continue): ";
 cin>>ans;
 }while(ans=='Y' || ans=='y');
 fp.close();
   }
 
void append(){
  char ans;
  student s;
  fp.open("stu.dat",ios::app);
  if(!fp){
    cout<<"\nError opening file for appending."<<endl;
   return;
  }
 do{
 s.getdata();
 fp.write((char*)&s,sizeof(s));
 cout<<"\nMore? (Y/y to continue): ";
 cin>>ans;
 }while(ans=='Y' || ans=='y');
 fp.close();
 }
  
 void display(){
   student s;
   fp.open("stu.dat",ios::in);
   if(!fp){
   cout<<"\nError opening file for reading."<<endl;
  return;
 }
  while(fp.read((char*)&s,sizeof(s))){
   s.putdata();
  }
  fp.close();
   }
   
void search(){
 student s;
 int flag=0;
 int r;
 cout<<"\nEnter roll to be searched: ";
 cin>>r;
 fp.open("stu.dat",ios::in);
 if(!fp){
 cout<<"\nError opening file for searching."<<endl;
 return;
}
 while(fp.read((char*)&s,sizeof(s))){
 if(s.roll==r){
 flag=1;
 s.putdata();
 break;
  }
}
if(flag==0){
cout<<"\nNot found!"<<endl;
}
fp.close();
}
void update(){
 int r;
 student s;
 int flag=0;
cout<<"\nEnter roll to be updated: ";
 cin>>r;
 fp.open("stu.dat",ios::in|ios::out);
 if(!fp){
 cout<<"\nError opening file for updating."<<endl;
 return;
}
 while(fp.read((char*)&s,sizeof(s))){
 if(s.roll==r){
 flag=1;
 cout<<"\nEnter new data: ";
 s.getdata();
 fp.seekp(-1*sizeof(s),ios::cur);
 fp.write((char*)&s,sizeof(s));
 break;
 }
}
 if(flag==0){
 cout<<"\nNot found!"<<endl;
 }
 fp.close();
 }
 void delete1(){
 student s;
 int flag=0;
 fstream fp1;
 int r;
 cout<<"\nEnter roll to be deleted: ";
 cin>>r;
 fp.open("stu.dat",ios::in);
 fp1.open("temp.dat",ios::out);
 if(!fp || !fp1){
 cout<<"\nError opening files."<<endl;
  return;
 }
 while(fp.read((char*)&s,sizeof(s))){
 if(s.roll!=r){
 fp1.write((char*)&s,sizeof(s));
 }else{
  flag=1;
  }
 }
 if(flag==0){
 cout<<"\nNot found!"<<endl;
  }else{
   remove("stu.dat");
 rename("temp.dat","stu.dat");
 cout<<"\nRecord deleted successfully."<<endl;
   } 
   
    fp.close();
   fp1.close();
  }
};
int main(){
  file f;
  int choice;
  do{
    cout<<"\n1. Create \n2. Display \n3. Search \n4. Append";
    cout<<"\n5. Update \n6. Delete";
    cout<<"\nEnter choice (0 to exit): ";
    cin>>choice;
    switch(choice){
       case 1:
          f.create();
          break;
       case 2:
          f.display();
           break;
      case 3:
          f.search();
           break;
     case 4:
          f.append();
           break;
    case 5:
          f.update();
           break;
    case 6:
         f.delete1();
           break;
    case 0:
         cout<<"\nExiting program."<<endl;
           break;
     default:
       cout<<"\nInvalid choice!"<<endl;
    }
  }while(choice!=0);
  return 0;
}

