#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

 int a;

int main()
{FILE *fp;int i,s,filepos;
fp=fopen("high.txt","w");
if(fp==NULL)
{
  cout<<"Error opening file \n";
  return 1;
}
s=sizeof(int);
cout<<"\n"<<s<<endl;
for( i=0;i<10;i++)
{

cout<<"\n Enter score ";
cin>>a;
fwrite(&a,s,1,fp);
}
fclose(fp);

cout<<"\nDetails fed into file"<<endl;

fp=fopen("high.txt","r");
filepos=0;
for(i=0;i<10;i++)
{filepos=i*s;
 fseek(fp,filepos,SEEK_SET);
 fread(&a,s,1,fp);
 cout<<a<<endl;
}
fclose(fp);
return 0;
}
