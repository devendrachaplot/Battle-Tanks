int SaveScore()//This funtion writes the scores into file high.txt
{
int a;//This variable is used to write the values to the file.
//Declaring the file pointer and the required variables
FILE *FilePointer;
int i,s,filepos;
//Opening the file "high.txt"
FilePointer=fopen("high.txt","w");
if(FilePointer==NULL)
     { 
      cout<<"Error opening file \n";
       return 1;
      }
//The size of integer variable fed to variable s
s=sizeof(int);
//The value of High Scores from the array is written to the file
for( i=0;i<10;i++)
     {   
       a = HighScore[i];
       cout<<a;
       fwrite(&a,s,1,FilePointer);
      }
      
//De linking the file pointer
fclose(FilePointer);

return 0;

}
