#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

//�P�_�O�_���� 
bool Ending(int map[])
{
     if((map[0]==map[1]&&map[1]==map[2]&&map[0]!=0)||(map[3]==map[4]&&map[4]==map[5]&&map[3]!=0)||(map[6]==map[7]&&map[7]==map[8]&&map[6]!=0)||(map[0]==map[3]&&map[3]==map[6]&&map[0]!=0)||(map[1]==map[4]&&map[4]==map[7]&&map[1]!=0)||(map[2]==map[5]&&map[5]==map[8]&&map[2]!=0)||(map[0]==map[4]&&map[4]==map[8]&&map[0]!=0)||(map[2]==map[4]&&map[4]==map[6]&&map[2]!=0))
     {
           return true;                                                                                                                                                                                                                                                                                   
     }
     return false;
}
int main()
{
     Tree abc;
     srand (time(NULL));
     int x,y;
     int xran;
     int k=0;
     int a;
     int map[9]={};
     cout<<"��m�ܷN�ϡ�\n";
     cout<<"�@������\n";
     cout<<"��\n";
     cout<<"��\n";
     cout<<"��\n";
     cout<<"1���U  2��U\n";
     cin>>a;
     
     if(a==1)
     {
       while(k<=8)
       {
          //���a 
          cout<<"X Y\n";
          cin>>x>>y;
          while(map[x+3*y]!=0)
          {
               cout<<"����m�w�e�L�εL����,�п��L��m\n"; 
               cin>>x>>y;
               if(map[x+3*y]==0)
               {
                    map[x+3*y]=1;
                    break;
               }
          }
          //�e�� 
          map[x+3*y]=1;
          for(int i=0;i<=8;i++)
          {
                    if(map[i]==0)
                    {
                         cout<<"�@";     
                    }else if(map[i]==1)
                    {
                         cout<<"��";
                    }else if(map[i]==2)
                    {
                         cout<<"��";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
          }
          //�P�_�ӱ� 
          if(Ending(map))
          {
                         cout<<"�ݡ@win\n";
                         break;
          }
          system("pause");
          
          k++;
          //�P�_�O�_�U�� 
          if(k==9)
          {
                 cout<<"����\n";
                 break;
          }
          //�������� 
          for(int i=0;i<1000;i++)
          {
                  abc.select(map);
          }
          
          abc.V(map);
          //���l�� 
          abc.initial();
          //�P�_�ӱ� 
          if(Ending(map))
          {
                         cout<<"��@win\n";
                         break;
          }
          k++;

        }
     }else if(a==2)
     {
        while(k<=8)
        {
          if(k==0)
          {
                  xran=rand()%8;
                  map[xran]=2;
                  k++;
                  for(int i=0;i<=8;i++)
                  {
                    if(map[i]==0)
                    {
                         cout<<"�@";     
                    }else if(map[i]==1)
                    {
                         cout<<"��";
                    }else if(map[i]==2)
                    {
                         cout<<"��";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
                  }
                  system("pause");
          }
          //���a 
          cout<<"X Y\n";
          cin>>x>>y;
          while(map[x+3*y]!=0)
          {
               cout<<"����m�w�e�L�εL����,�п��L��m\n"; 
               cin>>x>>y;
               if(map[x+3*y]==0)
               {
                    map[x+3*y]=1;
                    break;
               }
          }
          //�e�� 
          map[x+3*y]=1;
          for(int i=0;i<=8;i++)
          {
                    if(map[i]==0)
                    {
                         cout<<"�@";     
                    }else if(map[i]==1)
                    {
                         cout<<"��";
                    }else if(map[i]==2)
                    {
                         cout<<"��";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
          }
          //�P�_�ӱ� 
          if(Ending(map))
          {
                         cout<<"�ݡ@win\n";
                         break;
          }
          system("pause");
          
          k++;
          //�������� 
          for(int i=0;i<1000;i++)
          {
                  abc.select(map);
          }
          
          abc.V(map);
          //���l�� 
          abc.initial();
          //�P�_�ӱ� 
          if(Ending(map))
          {
                         cout<<"��@win\n";
                         break;
          }
          k++; 
          //�P�_�O�_�U�� 
          if(k==9)
          {
                 cout<<"����\n";
                 break;
          }        
        }   
     }
     system("pause");   
     return 0;
}
