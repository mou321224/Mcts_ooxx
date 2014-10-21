#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

class Tree
{
      public:
             Tree()
             {
                   root=NULL;
             }
             ~Tree(){};
             
             //選擇 
             void select(int map[])
             {
                  
                  Tree *Now;
                  //建立樹根 
                  // ↓沒樹根 
                  if(root==NULL)
                  {
                                root=new Tree;
                                root->visit=0;
                                root->leaf=true;
                                for(int i=0;i<=8;i++)
                                {
                                        root->child[i]=NULL;
                                        root->data[i]=map[i];
                                }
                                Now=root;
                  }
                  // ↓有樹根
                  else
                  {
                    Now=root;
                    //判斷是否到葉 
                    while(Now->leaf!=true)
                    {
                          //選value最大值                  
                          for(int i=0;i<=8;i++)
                          {
                                if(Now->child[i]!=NULL)
                                {
                                      maxvalue=Now->child[i]->value;
                                      maxchild=i;
                                      break;
                                }
                          }
                          for(int j=0;j<=8;j++)
                          {
                                if(Now->child[j]!=NULL&&Now->child[j]->value>maxvalue)
                                {                                                
                                      maxvalue=Now->child[j]->value;
                                      maxchild=j;
                                }
                          }
                          Now=Now->child[maxchild];     
                    }
                          
                  }
                  //進行探索 
                  expansion(Now);
                               
             }
             //把樹初始化 
             void initial()
             {
                  root=NULL;
             }
             //判斷是否結束 
              bool Ending(int map[])
             {
                   //判斷有沒有連線 
                  if((map[0]==map[1]&&map[1]==map[2]&&map[0]!=0)||(map[3]==map[4]&&map[4]==map[5]&&map[3]!=0)||(map[6]==map[7]&&map[7]==map[8]&&map[6]!=0)||(map[0]==map[3]&&map[3]==map[6]&&map[0]!=0)||(map[1]==map[4]&&map[4]==map[7]&&map[1]!=0)||(map[2]==map[5]&&map[5]==map[8]&&map[2]!=0)||(map[0]==map[4]&&map[4]==map[8]&&map[0]!=0)||(map[2]==map[4]&&map[4]==map[6]&&map[2]!=0))
                  {
                        return true;                                                                                                                                                                                                                                                                                   
                  }
                  //判斷是否還有空位可以下 
                  else if(map[0]!=0&&map[1]!=0&&map[2]!=0&&map[3]!=0&&map[4]!=0&&map[5]!=0&&map[6]!=0&&map[7]!=0&&map[8]!=0)
                  {
                        return true;
                  }
                  return false;
             }
             //擴展 
             void expansion(Tree *Now)
             {
                  int j;
                  k=0;           
                  l=0;
                  Tree *pa;
                  pa=Now;
                  //判斷是否連線或有沒有空位可以下 
                  if(!Ending(Now->data))
                  {
                       while(k!=9)
                       {
                          
                           //老爸兒子連接 
                           if(pa->data[k]==0)
                           {
                               Now=pa->child[k];        
                               Now=new Tree; 
                               for(int i=0;i<=8;i++)
                               {
                                       Now->data[i]=pa->data[i];
                               }
                               for(int i=0;i<=8;i++)
                               {
                                       if(Now->data[i]!=0)
                                       {
                                             l++;
                                       }
                               }
                               //判斷地圖下一步該下O或X
                               if(l%2==1)
                               {
                                         Now->data[k]=2;
                               }else
                               {
                                         Now->data[k]=1;
                               }
                               l=0;
                               Now->visit=0;
                               Now->leaf=true;
                               Now->value=1000;
                               Now->winning=0;
                               for(int i=0;i<=8;i++)
                               {
                                        Now->child[i]=NULL;
                               }
                               pa->child[k]=Now; 
                               pa->leaf=false;
                               Now->parent=pa;                                
                           }
                           k++;
                        }
                 
                        xran=rand()%9;
                        while(pa->child[xran]==NULL)
                        {
                             xran=rand()%9;
                        }
                        pa=pa->child[xran];
                     }
                     //進行模擬 
                     simulation(pa);  
             }
 
             
             //模擬 
             void simulation(Tree *Now)
             {
                  int map[9];
                  srand (time(NULL));
                  o=0;
                  x=0;
                  aaa=0;
                  for(int i=0;i<=8;i++)
                  {
                      map[i]=Now->data[i];
                  }
                  for(int i=0;i<=8;i++)
                  {
                          if(map[i]==1)
                          {
                                o++;
                                aaa++;
                          }
                          else if(map[i]==2)
                          {
                                x++;
                                aaa++;
                          }
                  }
                  //判斷該下O或X 
                  if(o>x)
                  {
                          step=0;
                  }
                  else
                  {
                          step=1;
                  }
                  while(aaa!=9)
                  {
                      aaa=0;
      
                      if(step%2==0)
                      {                             
                                  xran=rand()%9;
                                  if(map[xran]==0)
                                  {
                                               map[xran]=1;
                                               step++;
                                               //判斷是否勝出 
                                               if(Ending(map))
                                               {
                                                     Now->winning+=0;
                                                     Now->visit+=1;
                                                     break;                                                                                                                                                                                                                                                                                  
                                               }
                                  }
                      }else
                      {
                           
                                  xran=rand()%9;
                                  if(map[xran]==0)
                                  {
                                               map[xran]=2;
                                               step++;
                                               //判斷是否勝出
                                               if(Ending(map))
                                               {
                                                     Now->winning+=1;
                                                     Now->visit+=1;
                                                     break;                                                                                                                                                                                                                                                                                  
                                               }
                                  }                           
                      }
                      //判斷是否還有空位可以下 
                      for(int i=0;i<=8;i++)
                      {
                          if(map[i]!=0)
                          {
                                        aaa+=1;              
                          }
                      }
                  }
                  //平手局面 
                  if(aaa==9)
                  {
                       Now->winning+=0.5;
                       Now->visit+=1;
                  }
                  //進行回傳 
                  back(Now);
             }
             
             //回傳 
             void back(Tree *Now)
             {
                  parent=Now->parent;
                  //如果節點父為樹根 
                  if(parent==root)
                  {      
                            Now->parent->visit+=1;
                            Now->parent->winning=0;
                            for(int i=0;i<=8;i++)
                            {
                                    if(Now->parent->child[i]!=NULL)
                                    {
                                           Now->parent->winning+=Now->parent->child[i]->winning;
                                    }
                            }

                  }
                  //節點父不為樹根(回傳到樹根) 
                  while(parent!=root)
                  {       
                             Now->parent->visit+=1;
                             Now->parent->winning=0;
                             for(int i=0;i<=8;i++)
                             {
                                     if(Now->parent->child[i]!=NULL)
                                     {
                                           Now->parent->winning+=Now->parent->child[i]->winning;
                                     }
                             }
                             Now=Now->parent;
                             parent=Now->parent;
                             //如果到↑到樹根，樹根拜訪＋１ 
                             if(parent==root)
                             {
                                     root->visit++;
                             }
                             
                  }
                  //計算各點UCB值 
                  UCTValue(root);
             }
             //UCB值計算 
             void UCTValue(Tree *CalNode)
             {
                  int i;
                  //判斷是否該計算UCB值(沒拜訪節點和跟節點不用計算) 
                  if(CalNode!=root&&CalNode->visit!=0)
                  {
                        CalNode->value=(CalNode->winning)/(CalNode->visit)+sqrt(2*log(CalNode->parent->visit)/(CalNode->visit)); 
        
                  }
                  //向下計算UCB值 
                  for(i=0;i<=8;i++)
                  {
                        if(CalNode->child[i]!=NULL)
                        {
                         
                             UCTValue(CalNode->child[i]);
                        }          
                  }
                  
             }
             
             //比較UCB值大小，來決定下哪步 
             void V(int map[])
             {
                  for(int i=0;i<=8;i++)
                  {
                          if(root->child[i]!=NULL)
                          {
                                   cout<<i<<"VALUE="<<root->child[i]->value<<"\n";
                                   max=root->child[i]->value;
                          }
                  }
                  for(int i=0;i<=8;i++)
                  {
                          if(root->child[i]!=NULL)
                          {
                                   max=root->child[i]->value;
                                   break;
                          }
                  }
                  for(int i=0;i<=8;i++)
                  {
                          if(root->child[i]!=NULL&&root->child[i]->value>=max)
                          {
                                   max=root->child[i]->value;
                                   maxi=i;
                          }
                  }
                  cout<<maxi<<"maxVALUE="<<max<<"\n";
                  //畫地圖 
                  map[maxi]=2;
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
             }

             int maxi;
             double max;
             double visit;
             double value;
             double winning;
             double maxvalue;
             int maxchild;
             int xran;
             int data[9];
             int k,l,step;
             int o,x;
             int aaa;
             bool leaf;
             int times;
             Tree *root,*child[9],*parent;
};
