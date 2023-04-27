#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#define M 1000
int System();//身份选择函数 
int System1();/*用户界面*/ 
int System2();/*管理者界面*/
int jiemian1();//用户界面函数
int jiemian2();//管理者界面函数 
int add();/* 图书信息录入 */ 
int scan();/* 图书信息浏览*/ 
int search();/*图书信息查询排序*/ 
int borrow(); /*图书借阅*/ 
int huan();/*图书还*/
int jie();/*图书借*/ 
int revise();/* 修改图书信息*/
int san();/*删除图书*/
int out();/* 退出系统*/
int cx();/*查询*/
int px();/*排序*/
void fz();//将文本文档里面的数据赋给结构体 
void cp();//存盘 
 
struct book
{
	
	char book_name[20];
	char book_author[20];		
	char number[20];
	char publisher[20];
	int year;
	float price;	
	int k; 
}BK[M]; 


int n=0;//计算库里面书的总量 

void cp()//存盘
{
	FILE *fp;
	int i=0;
	if((fp=fopen("1.txt","r+"))==NULL)
	{
		printf("文件是空的!");
		exit(0);
	}
	while(!feof(fp))
	{
		fprintf(fp,"%s",&BK[i].book_name);
		fprintf(fp,"%s",&BK[i].book_author);
		fprintf(fp,"%s",&BK[i].number);
		fprintf(fp,"%s",&BK[i].publisher);
		fprintf(fp,"%d",&BK[i].year);
		fprintf(fp,"%f",&BK[i].price);
		fprintf(fp,"%d",&BK[i].k);  
		printf("\n");
		i++;
	}
	fclose(fp);
	
} 

void fz()//将文件里面的数据赋给结构体 
{
	FILE *fp;
	int i=0;
	if((fp=fopen("1.txt","r+"))==NULL)
	{
		printf("文件是空的!");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s",&BK[i].book_name);
		fscanf(fp,"%s",&BK[i].book_author);
		fscanf(fp,"%s",&BK[i].number);
		fscanf(fp,"%s",&BK[i].publisher);
		fscanf(fp,"%d",&BK[i].year);
		fscanf(fp,"%f",&BK[i].price);
		fscanf(fp,"%d",&BK[i].k);     
		i++;
	}
	fclose(fp);
	n=i;
}


int System()
{
	int i;
	printf("                   **********************图书信息管理系统***********************\n");
	printf("\n");
	printf("                               1.用户\t    2.管理者\t     3.退出\n");
	printf("\n");
	printf("                   *************************************************************\n");
	printf("请选择你的身份(1-2):");
	scanf("%d",&i);
	return i;
}

int System1()	//用户界面
{
	int i;
	printf("                   **********************图书信息管理系统***********************\n");
	printf("\t           1.图书信息浏览      "); 
	printf("                 2.图书信息查询排序\n");
	printf("\n");
	printf("\t           3.图书借阅  ");
	printf("                         4.退出系统 \n");
	printf("\n");
	printf("\t           5.返回\n ");
	printf("                  *************************************************************\n");
	printf("请选择所需要的功能(1-5):");
	scanf("%d",&i);
	return i;
}

int System2()//管理者界面 
{
	int i;
	printf("                   **********************图书信息管理系统***********************\n");
	printf("\t           1.图书信息录入      "); 
	printf("                      2.图书信息删除\n");
	printf("\n");
	printf("\t           3.图书信息修改  ");
	printf("                          4.退出系统 \n");
	printf("\n");
	printf("\t           5.返回\n  ");
	printf("                 *************************************************************\n");
	printf("请选择所需要的功能(1-5):");
	scanf("%d",&i);
	return i;
}

int add()  //图书信息录入//
{
	int i;
	int c=1;
	int k=0;
	fz();
	printf("请输入要录入的数量：");
	scanf("%d",&k); 
	for(i=0;i<k;i++)
	{
		printf("%d\n",c);
		printf("请输入书名:");
		scanf("%s",&BK[i].book_name);
		printf("请输入作者名:");
		scanf("%s",&BK[i].book_author);
		printf("请输入书号:"); 
		scanf("%s",&BK[i].number);
		printf("请输入出版社名称:");
		scanf("%s",&BK[i].publisher);
		printf("请输入书的年份:");
		scanf("%d",&BK[i].year);
		printf("请输入价格:");
		scanf("%f",&BK[i].price); 
		printf("请输入书的库存:");
		scanf("%d",&BK[i].k);
		
	}
	printf("%-12s","书名");
	printf("%-12s","作者名");
	printf("%-15s","书号");
	printf("%-15s","出版社名称");
	printf("%-18s","年份");
	printf("%-14s","价格");
	printf("%-14s\n","库存");
	for(i=0;i<k;i++)
	{
		printf("%-12s",BK[i].book_name);
		printf("%-12s",BK[i].book_author);
		printf("%-15s",BK[i].number);
		printf("%-15s",BK[i].publisher);
		printf("%-18d",BK[i].year);
		printf("%-14f",BK[i].price);
		printf("%-14d\n",BK[i].k);
		n++;
	}
	
	printf("\n");
	printf("录入成功！");
	return 0;
}

int scan()//图书浏览 
{
	int i;
	fz();
	printf("%-12s","书名");
	printf("%-12s","作者名");
	printf("%-15s","书号");
	printf("%-15s","出版社名称");
	printf("%-18s","年份");
	printf("%-14s","价格");
	printf("%-14s\n","库存");
	for(i=0;i<n;i++)
	{
		printf("%-12s",BK[i].book_name);
		printf("%-12s",BK[i].book_author);
		printf("%-15s",BK[i].number);
		printf("%-15s",BK[i].publisher);
		printf("%-18d",BK[i].year);
		printf("%-14f",BK[i].price);
		printf("%-14d\n",BK[i].k);
	}
	system("pause");
	system("cls");
	return 0;
}

int cx()/*图书查询  作者名、出版社、书名、出版年份*/ 
{
	char a[20];
	int year[20];
	int i,j;
	fz();
	struct book temp[50];
	int h=0;
	for(;;)
	{
		printf("1.图书名\t2.作者名\t3.出版社名\t4.出版年份\n"); 
		printf("请选择你要查询的方式(当你输入5时将退出此功能):");
		scanf("%d",&j);
		system("cls");
		switch(j)
		{
			case 1: printf("请输入图书的名字:");
				 	scanf("%s",a);
				 	printf("*****************************************图书查询*****************************************\n");
					printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存"); 
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].book_name)==0)
						{
							
							printf("%-12s",BK[i].book_name);
							printf("%-12s",BK[i].book_author);
							printf("%-15s",BK[i].number);
							printf("%-15s",BK[i].publisher);
							printf("%-18d",BK[i].year);
							printf("%-14f",BK[i].price);
							printf("%-14d\n",BK[i].k);
							printf("\n");
						}	
					}
					system("pause");
					system("cls");
					break;
					
			case 2: printf("请输入作者的名字:");
				 	scanf("%s",a);
				 	printf("\n");
					printf("*****************************************图书查询*****************************************\n");
					printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存"); 
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].book_author)==0)
						{
							printf("%-12s",BK[i].book_name);
							printf("%-12s",BK[i].book_author);
							printf("%-15s",BK[i].number);
							printf("%-15s",BK[i].publisher);
							printf("%-18d",BK[i].year);
							printf("%-14f",BK[i].price);
							printf("%-14d\n",BK[i].k);
							printf("\n");
						}
					}
					system("pause");
					system("cls");
					break;
					
			case 3:printf("请输入出版社名:");
				 	scanf("%s",a);
				 	printf("\n");
					printf("*****************************************图书查询*****************************************\n"); 
					printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");					
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].publisher)==0)
						{
							printf("%-12s",BK[i].book_name);
							printf("%-12s",BK[i].book_author);
							printf("%-15s",BK[i].number);
							printf("%-15s",BK[i].publisher);
							printf("%-18d",BK[i].year);
							printf("%-14f",BK[i].price);
							printf("%-14d\n",BK[i].k);
						}
					}
					system("pause");
					system("cls");
					break;
					
			case 4:printf("请输入出版年份:");
				 	scanf("%d",&year);
				 	printf("\n");
					printf("*****************************************图书查询*****************************************\n"); 
					printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)			
					{
						if(year[0]==BK[i].year)
						{
							printf("%-12s",BK[i].book_name);
							printf("%-12s",BK[i].book_author);
							printf("%-15s",BK[i].number);
							printf("%-15s",BK[i].publisher);
							printf("%-18d",BK[i].year);
							printf("%-14f",BK[i].price);
							printf("%-14d\n",BK[i].k);
						}
					}
					system("pause");
					system("cls");
					break;
					
			case 5:return 0;break;
			default:printf("抱歉没有找到这本书!\n");
		}	
	}
	return 0;
}

int px()/*图书排序*/
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(BK[j].k>BK[j+1].k)
			{
				struct book t;
				t = BK[j]; 
				BK[j]=BK[j+1];
				BK[j+1]=t;
			}
		}
	}
	printf("*****************************************图书排序*****************************************\n"); 
	printf("%-12s","书名");
	printf("%-12s","作者名");
	printf("%-15s","书号");
	printf("%-15s","出版社名称");
	printf("%-18s","年份");
	printf("%-14s","价格");
	printf("%-14s\n","库存");
	for(i=0;i<n;i++)
	{
		printf("%-12s",BK[i].book_name);
		printf("%-12s",BK[i].book_author);
		printf("%-15s",BK[i].number);
		printf("%-15s",BK[i].publisher);
		printf("%-18d",BK[i].year);
		printf("%-14f",BK[i].price);
		printf("%-14d\n",BK[i].k);
	}
	system("pause");
	system("cls");
	return 0;
}

int search()/*图书的查找和排序*/ 
{
	int i;
	for(;;)
	{
		printf("1.排序\t2.查询\t3.返回\n");
		printf("请选择所需功能：");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
			case 1:px();break;
			case 2:cx();break;
			case 3:return 0;break;
			default:  printf("输入有误！\n"); 
					  system("pause");
					  system("cls");
		}
	}
	return 0;	
}

int jie()//借书 
{
	int i;	
	int j;		 
	char a[20];
	char b[]={"out"};
	fz();
	for(;;)
	{
		printf("请输入要借阅的书籍(输入out退出此功能):");
		scanf("%s",a);
		system("cls");
		for(i=0;i<n;i++)
		{
			if(strcmp(a,BK[i].book_name)==0)
			{
				printf("请输入要借的本数：");
				scanf("%d",&j);
				system("cls");
				if(BK[i].k!=0)
				{
					if(BK[i].k>j)
					{
						BK[i].k=BK[i].k-j;
						printf("%-12s","书名");
						printf("%-12s","作者名");
						printf("%-15s","书号");
						printf("%-15s","出版社名称");
						printf("%-18s","年份");
						printf("%-14s","价格");
						printf("%-14s\n","库存");
						printf("%-12s",BK[i].book_name);
						printf("%-12s",BK[i].book_author);
						printf("%-15s",BK[i].number);
						printf("%-15s",BK[i].publisher);
						printf("%-18d",BK[i].year);
						printf("%-14f",BK[i].price);
						printf("%-14d\n",BK[i].k);
						printf("%s已经被借出\n",BK[i].book_name);
						printf("库存还剩%d本\n",BK[i].k);
						system("pause");
						system("cls");
						break;
					}
					else
					{
						printf("库存不足！\n"); 
						system("pause");
						system("cls");
					}		
				}
				if(BK[i].k==0)
				{
					printf("该书已经被借完了！");
					return 0; 
				}
				
			}
			if(strcmp(a,b)==0)
			{
				borrow();
				system("cls");
			}
		} 
    }
    return 0;
}

int huan()//还书
{
	int i;	
	int j;		 
	char a[20];
	fz();
	printf("请输入要还回书籍的名字:");
	scanf("%s",&a);
	printf("请输入要还回的本数:");
	scanf("%d",&j);
	for(i=0;i<n;i++)
	{
		if(strcmp(a,BK[i].book_name)==0)
		{
			BK[i].k=BK[i].k+j;
			printf("%-12s","书名");
			printf("%-12s","作者名");
			printf("%-15s","书号");
			printf("%-15s","出版社名称");
			printf("%-18s","年份");
			printf("%-14s","价格");
			printf("%-14s\n","库存");
			printf("%-12s",BK[i].book_name);
			printf("%-12s",BK[i].book_author);
			printf("%-15s",BK[i].number);
			printf("%-15s",BK[i].publisher);
			printf("%-18d",BK[i].year);
			printf("%-14f",BK[i].price);
			printf("%-14d\n",BK[i].k);
			printf("还书成功！\n");
			system("pause");
			system("cls");
		}
	} 
	return 0;
}

int borrow()//图书借阅
{
	int i;
	for(;;)
	{
		printf("1.借书\t2.还书\n");
		printf("请选择所需的功能(按3时返回主菜单):");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
			case 1:jie();break;
			case 2:huan();break;
			case 3:return 0;
			default:printf("输入有误！"); 
		}
	}
	return 0;	
}

int revise()//修改图书信息
{
	int j; 
	int i;
	int y;
	int h=0;//统计信息在的条数 
	fz();
	struct book temp[50];
	char a[20];
	for(;;)
	{
		printf("1.图书名\t2.作者名\t3.出版社名\t4.出版年份\n"); 
		printf("请选择你要查询信息的方式(输入5时返回):");
		scanf("%d",&j);
		system("cls");
		switch(j)
		{
			case 1: printf("\n请输入图书的名字:");
				 	scanf("%s",a);
				 	printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].book_name)==0)
						{
							temp[h]=BK[i];
							printf("%-12s",temp[h].book_name);
							printf("%-12s",temp[h].book_author);
							printf("%-15s",temp[h].number);
							printf("%-15s",temp[h].publisher);
							printf("%-18d",temp[h].year);
							printf("%-14f",temp[h].price);
							printf("%-14d\n",temp[i].k);
							h++;
						}
					}
					break;
					
			case 2: printf("\n请输入作者的名字:");
				 	scanf("%s",a);
				 	printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].book_author)==0)
						{
							temp[h]=BK[i];
							printf("%-12s",temp[h].book_name);
							printf("%-12s",temp[h].book_author);
							printf("%-15s",temp[h].number);
							printf("%-15s",temp[h].publisher);
							printf("%-18d",temp[h].year);
							printf("%-14f",temp[h].price);
							printf("%-14d\n",temp[i].k);
							h++;
						}
					}
					break;
					
			case 3:printf("\n请输入出版社名:");
				 	scanf("%s",a);
				 	printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)
					{
						if(strcmp(a,BK[i].publisher)==0)
						{
							temp[h]=BK[i];
							printf("%-12s",temp[h].book_name);
							printf("%-12s",temp[h].book_author);
							printf("%-15s",temp[h].number);
							printf("%-15s",temp[h].publisher);
							printf("%-18d",temp[h].year);
							printf("%-14f",temp[h].price);
							printf("%-14d\n",temp[i].k);
							h++;
						}
					}
					break;
					
			case 4:printf("请输入出版年份:");
				 	scanf("%d",&y);
				 	printf("%-12s","书名");
					printf("%-12s","作者名");
					printf("%-15s","书号");
					printf("%-15s","出版社名称");
					printf("%-18s","年份");
					printf("%-14s","价格");
					printf("%-14s\n","库存");
					for(i=0;i<n;i++)			
					{
						if(BK[i].year==y)
						{
							temp[h]=BK[i];
							printf("%-12s",temp[h].book_name);
							printf("%-12s",temp[h].book_author);
							printf("%-15s",temp[h].number);
							printf("%-15s",temp[h].publisher);
							printf("%-18d",temp[h].year);
							printf("%-14f",temp[h].price);
							printf("%-14d\n",temp[i].k);
							h++;	
						}
					}
					break;
					default:printf("抱歉没有找到这本书!\n");
			case 5:return 0;break;
		}
		for(;;)
		{
			int p;
			int i;
			float f;
			int y,c;
			char b;
			char d;
			char e[20];
			char s[20];
			printf("\n1.书名\t2.作者名\t3.书号\t4.出版社名称\t5.年份\t6.价格\t7.库存\n");
			printf("请选择你要修改信息:");	
			scanf("%d",&p);
			switch(p)
			{
				case 1:  for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n');
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改书的名字：");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].book_name,s);
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);
										break;
										
									}
									else
									{
										printf("请输入要修改书的名字：");
										scanf("%s",&s);
										system("cls");
										for(i=0;i<h;i++)
										{
											strcpy(temp[i].book_name,s);
										}
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										for(i=0;i<h;i++)
										{										
											printf("%-12s",temp[i].book_name);
											printf("%-12s",temp[i].book_author);
											printf("%-15s",temp[i].number);
											printf("%-15s",temp[i].publisher);
											printf("%-18d",temp[i].year);
											printf("%-14f",temp[i].price);
											printf("%-14d\n",temp[i].k);		
										}
								}
						}
						printf("是否要保存修改的信息（y/Y):");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("修改成功!!\n");
							return 0;
						}
					    break;
					    
				case 2:  for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改作者的姓名:");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].book_author,s);
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改作者的姓名:");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].book_name,s);
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
					}
					printf("是否要保存修改的信息（y/Y）：");
					getchar();
					scanf("%c",&b);
					if(b=='y'||b=='Y')
					{
						cp();
						printf("修改成功!!\n");
						return 0;
					}
					break;
						
				case 3:  for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改图书的ISBN号：");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].number,s);
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改图书的书号：");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].number,s);
										
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
						}
						printf("是否要保存修改的信息（y/Y）：");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("修改成功!!\n");
							return 0;
						}
						break;
						
				case 4: for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改出版社名称：");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].publisher,s);
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改出版社名称:");  
								scanf("%s",&s);
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].book_name,s);
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
					}
					printf("是否要保存修改的信息（y/Y）：");
					getchar();
					scanf("%c",&b);
					if(b=='y'||b=='Y')
					{
						cp();
						printf("修改成功!!\n");
						return 0;
					}
					break;
	
				case 5: for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改图书的年份：");
										scanf("%s",&y);
										system("cls");
										temp[i].year=y;
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);	
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改图书的年份：");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].year=y;		
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
						}
						printf("是否要保存修改的信息（y/Y）：");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("修改成功!!\n");
							return 0;
						}
						break;
						
				case 6:for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改图书的价格：");
										scanf("%f",&f);
										system("cls");
										temp[i].price=f;
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改图书的价格:");
								scanf("%f",&f);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].price=f;
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
						}
						printf("是否要保存修改的信息（y/Y）：");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("修改成功!!\n");
							return 0;
						}					
						break;
						
				case 7:for(i=0;i<h;i++)
					    {
					    	printf("是否全部修改？(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("请输入书的名字：");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("请输入要修改图书的库存:");
										scanf("%d",&c);
										system("cls");
										temp[i].k=c;
										printf("%-12s","书名");
										printf("%-12s","作者名");
										printf("%-15s","书号");
										printf("%-15s","出版社名称");
										printf("%-18s","年份");
										printf("%-14s","价格");
										printf("%-14s\n","库存");
										printf("%-12s",temp[i].book_name);
										printf("%-12s",temp[i].book_author);
										printf("%-15s",temp[i].number);
										printf("%-15s",temp[i].publisher);
										printf("%-18d",temp[i].year);
										printf("%-14f",temp[i].price);
										printf("%-14d\n",temp[i].k);	
										break;
									}
								}
							}
							else
							{
								printf("请输入要修改图书的库存:");
								scanf("%d",&c);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].k=c;
								}
								printf("%-12s","书名");
								printf("%-12s","作者名");
								printf("%-15s","书号");
								printf("%-15s","出版社名称");
								printf("%-18s","年份");
								printf("%-14s","价格");
								printf("%-14s\n","库存");
								for(i=0;i<h;i++)
								{
									printf("%-12s",temp[i].book_name);
									printf("%-12s",temp[i].book_author);
									printf("%-15s",temp[i].number);
									printf("%-15s",temp[i].publisher);
									printf("%-18d",temp[i].year);
									printf("%-14f",temp[i].price);
									printf("%-14d\n",temp[i].k);		
								}
							}
						}
						printf("是否要保存修改的信息（y/Y）：");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("修改成功!!\n");
							return 0;
						}					
						break;
				case 8:System1();break;
				default:printf("修改失败！");break;
			}
		
		}
	}
	return 0;
} 

int san()//删除函数 
{
	int i;
	char a[20]; 
	int b;
	int f;
	fz();
	printf("\n");
	printf("请输入书名,选择你想要删除的那本书:");
	scanf("%s",a);
	system("cls");
	for(i=0;i<n;i++)
	{
		if(strcmp(a,BK[i].book_name)==0)
		{
			printf("%-12s","书名");
			printf("%-12s","作者名");
			printf("%-15s","书号");
			printf("%-15s","出版社名称");
			printf("%-18s","年份");
			printf("%-14s","价格");
			printf("%-14s\n","库存");
			printf("%-12s",BK[i].book_name);
			printf("%-12s",BK[i].book_author);
			printf("%-15s",BK[i].number);
			printf("%-15s",BK[i].publisher);
			printf("%-18d",BK[i].year);
			printf("%-14f",BK[i].price);
			printf("%-14d\n",BK[i].k);
			f=i;
			break;
		}
	}
	printf("是否删除这条信息:(y/Y):");
	getchar();
	scanf("%c",&b);
	system("cls");
	if(b=='y'||b=='Y')
	{
		for(i=0;i<n-1;i++)
		{
			BK[i]=BK[i+1];
			n=n-1;		
		}
		for(i=0;i<n;i++)
		{
			printf("%-12s","书名");
			printf("%-12s","作者名");
			printf("%-15s","书号");
			printf("%-15s","出版社名称");
			printf("%-18s","年份");
			printf("%-14s","价格");
			printf("%-14s\n","库存");
			printf("%-12s",BK[i].book_name);
			printf("%-12s",BK[i].book_author);
			printf("%-15s",BK[i].number);
			printf("%-15s",BK[i].publisher);
			printf("%-18d",BK[i].year);
			printf("%-14f",BK[i].price);
			printf("%-14d\n",BK[i].k);
		}
		cp();
		printf("删除成功！\n");
		system("pause");
		system("cls");
	}
	return 0;
}

int out()//退出系统
{
	puts("退出成功!"); 
	exit(0);

} 

int jiemian1()
{
	int i;
	for(;;)
	{
		switch(i=ystem1())
		{
			case 1:system("cls");
				   scan();
				   break;
			case 2:system("cls");
			       search();
				   break;
			case 3:system("cls");
			       borrow();
				   break;
			case 4:system("cls");
			       out();
			       break;
			case 5:system("cls");
			       return 0;
			       break;
			default:printf("错误!");
		}
		system("cls");
	}
	return 0;
} 

int jiemian2()
{
	int i;
	for(;;)
	{
		switch(i=System2())
		{
			case 1: system("cls");
					add();
					break;
			case 2:system("cls");
			       san();
				   break;
			case 3:system("cls");
			       revise();
			       break;
			case 4:system("cls");
				   out();
			       break;
			case 5:system("cls");
				   return 0;
				   break;
			default:printf("错误!");
		}
	}
	return 0;
}
int main()
{

	int i;
	for(;;)
	{
	switch(i=System())
		{
			case 1: system("cls");
					jiemian1();
					break;
	
			case 2: system("cls");
				    jiemian2();
			        break;
			        
			case 3:system("cls");
				   out();
				   break;
		 
		}
		system("cls");
	}
	return 0;
}
