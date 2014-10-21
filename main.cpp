#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

//判斷是否結束 
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
     cout<<"位置示意圖↓\n";
     cout<<"　０１２\n";
     cout<<"０\n";
     cout<<"１\n";
     cout<<"２\n";
     cout<<"1先下  2後下\n";
     cin>>a;
     
     if(a==1)
     {
       while(k<=8)
       {
          //玩家 
          cout<<"X Y\n";
          cin>>x>>y;
          while(map[x+3*y]!=0)
          {
               cout<<"此位置已畫過或無此位,請選其他位置\n"; 
               cin>>x>>y;
               if(map[x+3*y]==0)
               {
                    map[x+3*y]=1;
                    break;
               }
          }
          //畫圖 
          map[x+3*y]=1;
          for(int i=0;i<=8;i++)
          {
                    if(map[i]==0)
                    {
                         cout<<"　";     
                    }else if(map[i]==1)
                    {
                         cout<<"Ｏ";
                    }else if(map[i]==2)
                    {
                         cout<<"Ｘ";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
          }
          //判斷勝敗 
          if(Ending(map))
          {
                         cout<<"Ｏ　win\n";
                         break;
          }
          system("pause");
          
          k++;
          //判斷是否下滿 
          if(k==9)
          {
                 cout<<"平手\n";
                 break;
          }
          //模擬次數 
          for(int i=0;i<1000;i++)
          {
                  abc.select(map);
          }
          
          abc.V(map);
          //樹初始化 
          abc.initial();
          //判斷勝敗 
          if(Ending(map))
          {
                         cout<<"Ｘ　win\n";
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
                         cout<<"　";     
                    }else if(map[i]==1)
                    {
                         cout<<"Ｏ";
                    }else if(map[i]==2)
                    {
                         cout<<"Ｘ";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
                  }
                  system("pause");
          }
          //玩家 
          cout<<"X Y\n";
          cin>>x>>y;
          while(map[x+3*y]!=0)
          {
               cout<<"此位置已畫過或無此位,請選其他位置\n"; 
               cin>>x>>y;
               if(map[x+3*y]==0)
               {
                    map[x+3*y]=1;
                    break;
               }
          }
          //畫圖 
          map[x+3*y]=1;
          for(int i=0;i<=8;i++)
          {
                    if(map[i]==0)
                    {
                         cout<<"　";     
                    }else if(map[i]==1)
                    {
                         cout<<"Ｏ";
                    }else if(map[i]==2)
                    {
                         cout<<"Ｘ";
                    }
                    if(i==2||i==5||i==8)
                    {      
                         cout<<"\n";
                    }
          }
          //判斷勝敗 
          if(Ending(map))
          {
                         cout<<"Ｏ　win\n";
                         break;
          }
          system("pause");
          
          k++;
          //模擬次數 
          for(int i=0;i<1000;i++)
          {
                  abc.select(map);
          }
          
          abc.V(map);
          //樹初始化 
          abc.initial();
          //判斷勝敗 
          if(Ending(map))
          {
                         cout<<"Ｘ　win\n";
                         break;
          }
          k++; 
          //判斷是否下滿 
          if(k==9)
          {
                 cout<<"平手\n";
                 break;
          }        
        }   
     }
     system("pause");   
     return 0;
}
