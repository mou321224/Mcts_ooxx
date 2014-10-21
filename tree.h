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
             
             //��� 
             void select(int map[])
             {
                  
                  Tree *Now;
                  //�إ߾�� 
                  // ���S��� 
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
                  // �������
                  else
                  {
                    Now=root;
                    //�P�_�O�_�츭 
                    while(Now->leaf!=true)
                    {
                          //��value�̤j��                  
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
                  //�i�汴�� 
                  expansion(Now);
                               
             }
             //����l�� 
             void initial()
             {
                  root=NULL;
             }
             //�P�_�O�_���� 
              bool Ending(int map[])
             {
                   //�P�_���S���s�u 
                  if((map[0]==map[1]&&map[1]==map[2]&&map[0]!=0)||(map[3]==map[4]&&map[4]==map[5]&&map[3]!=0)||(map[6]==map[7]&&map[7]==map[8]&&map[6]!=0)||(map[0]==map[3]&&map[3]==map[6]&&map[0]!=0)||(map[1]==map[4]&&map[4]==map[7]&&map[1]!=0)||(map[2]==map[5]&&map[5]==map[8]&&map[2]!=0)||(map[0]==map[4]&&map[4]==map[8]&&map[0]!=0)||(map[2]==map[4]&&map[4]==map[6]&&map[2]!=0))
                  {
                        return true;                                                                                                                                                                                                                                                                                   
                  }
                  //�P�_�O�_�٦��Ŧ�i�H�U 
                  else if(map[0]!=0&&map[1]!=0&&map[2]!=0&&map[3]!=0&&map[4]!=0&&map[5]!=0&&map[6]!=0&&map[7]!=0&&map[8]!=0)
                  {
                        return true;
                  }
                  return false;
             }
             //�X�i 
             void expansion(Tree *Now)
             {
                  int j;
                  k=0;           
                  l=0;
                  Tree *pa;
                  pa=Now;
                  //�P�_�O�_�s�u�Φ��S���Ŧ�i�H�U 
                  if(!Ending(Now->data))
                  {
                       while(k!=9)
                       {
                          
                           //�Ѫ���l�s�� 
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
                               //�P�_�a�ϤU�@�B�ӤUO��X
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
                     //�i����� 
                     simulation(pa);  
             }
 
             
             //���� 
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
                  //�P�_�ӤUO��X 
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
                                               //�P�_�O�_�ӥX 
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
                                               //�P�_�O�_�ӥX
                                               if(Ending(map))
                                               {
                                                     Now->winning+=1;
                                                     Now->visit+=1;
                                                     break;                                                                                                                                                                                                                                                                                  
                                               }
                                  }                           
                      }
                      //�P�_�O�_�٦��Ŧ�i�H�U 
                      for(int i=0;i<=8;i++)
                      {
                          if(map[i]!=0)
                          {
                                        aaa+=1;              
                          }
                      }
                  }
                  //���⧽�� 
                  if(aaa==9)
                  {
                       Now->winning+=0.5;
                       Now->visit+=1;
                  }
                  //�i��^�� 
                  back(Now);
             }
             
             //�^�� 
             void back(Tree *Now)
             {
                  parent=Now->parent;
                  //�p�G�`�I������� 
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
                  //�`�I���������(�^�Ǩ���) 
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
                             //�p�G������ڡA��ګ��X�Ϣ� 
                             if(parent==root)
                             {
                                     root->visit++;
                             }
                             
                  }
                  //�p��U�IUCB�� 
                  UCTValue(root);
             }
             //UCB�ȭp�� 
             void UCTValue(Tree *CalNode)
             {
                  int i;
                  //�P�_�O�_�ӭp��UCB��(�S���X�`�I�M��`�I���έp��) 
                  if(CalNode!=root&&CalNode->visit!=0)
                  {
                        CalNode->value=(CalNode->winning)/(CalNode->visit)+sqrt(2*log(CalNode->parent->visit)/(CalNode->visit)); 
        
                  }
                  //�V�U�p��UCB�� 
                  for(i=0;i<=8;i++)
                  {
                        if(CalNode->child[i]!=NULL)
                        {
                         
                             UCTValue(CalNode->child[i]);
                        }          
                  }
                  
             }
             
             //���UCB�Ȥj�p�A�ӨM�w�U���B 
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
                  //�e�a�� 
                  map[maxi]=2;
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
