#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#define M 1000
int System();//���ѡ���� 
int System1();/*�û�����*/ 
int System2();/*�����߽���*/
int jiemian1();//�û����溯��
int jiemian2();//�����߽��溯�� 
int add();/* ͼ����Ϣ¼�� */ 
int scan();/* ͼ����Ϣ���*/ 
int search();/*ͼ����Ϣ��ѯ����*/ 
int borrow(); /*ͼ�����*/ 
int huan();/*ͼ�黹*/
int jie();/*ͼ���*/ 
int revise();/* �޸�ͼ����Ϣ*/
int san();/*ɾ��ͼ��*/
int out();/* �˳�ϵͳ*/
int cx();/*��ѯ*/
int px();/*����*/
void fz();//���ı��ĵ���������ݸ����ṹ�� 
void cp();//���� 
 
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


int n=0;//���������������� 

void cp()//����
{
	FILE *fp;
	int i=0;
	if((fp=fopen("1.txt","r+"))==NULL)
	{
		printf("�ļ��ǿյ�!");
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

void fz()//���ļ���������ݸ����ṹ�� 
{
	FILE *fp;
	int i=0;
	if((fp=fopen("1.txt","r+"))==NULL)
	{
		printf("�ļ��ǿյ�!");
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
	printf("                   **********************ͼ����Ϣ����ϵͳ***********************\n");
	printf("\n");
	printf("                               1.�û�\t    2.������\t     3.�˳�\n");
	printf("\n");
	printf("                   *************************************************************\n");
	printf("��ѡ��������(1-2):");
	scanf("%d",&i);
	return i;
}

int System1()	//�û�����
{
	int i;
	printf("                   **********************ͼ����Ϣ����ϵͳ***********************\n");
	printf("\t           1.ͼ����Ϣ���      "); 
	printf("                 2.ͼ����Ϣ��ѯ����\n");
	printf("\n");
	printf("\t           3.ͼ�����  ");
	printf("                         4.�˳�ϵͳ \n");
	printf("\n");
	printf("\t           5.����\n ");
	printf("                  *************************************************************\n");
	printf("��ѡ������Ҫ�Ĺ���(1-5):");
	scanf("%d",&i);
	return i;
}

int System2()//�����߽��� 
{
	int i;
	printf("                   **********************ͼ����Ϣ����ϵͳ***********************\n");
	printf("\t           1.ͼ����Ϣ¼��      "); 
	printf("                      2.ͼ����Ϣɾ��\n");
	printf("\n");
	printf("\t           3.ͼ����Ϣ�޸�  ");
	printf("                          4.�˳�ϵͳ \n");
	printf("\n");
	printf("\t           5.����\n  ");
	printf("                 *************************************************************\n");
	printf("��ѡ������Ҫ�Ĺ���(1-5):");
	scanf("%d",&i);
	return i;
}

int add()  //ͼ����Ϣ¼��//
{
	int i;
	int c=1;
	int k=0;
	fz();
	printf("������Ҫ¼���������");
	scanf("%d",&k); 
	for(i=0;i<k;i++)
	{
		printf("%d\n",c);
		printf("����������:");
		scanf("%s",&BK[i].book_name);
		printf("������������:");
		scanf("%s",&BK[i].book_author);
		printf("���������:"); 
		scanf("%s",&BK[i].number);
		printf("���������������:");
		scanf("%s",&BK[i].publisher);
		printf("������������:");
		scanf("%d",&BK[i].year);
		printf("������۸�:");
		scanf("%f",&BK[i].price); 
		printf("��������Ŀ��:");
		scanf("%d",&BK[i].k);
		
	}
	printf("%-12s","����");
	printf("%-12s","������");
	printf("%-15s","���");
	printf("%-15s","����������");
	printf("%-18s","���");
	printf("%-14s","�۸�");
	printf("%-14s\n","���");
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
	printf("¼��ɹ���");
	return 0;
}

int scan()//ͼ����� 
{
	int i;
	fz();
	printf("%-12s","����");
	printf("%-12s","������");
	printf("%-15s","���");
	printf("%-15s","����������");
	printf("%-18s","���");
	printf("%-14s","�۸�");
	printf("%-14s\n","���");
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

int cx()/*ͼ���ѯ  �������������硢�������������*/ 
{
	char a[20];
	int year[20];
	int i,j;
	fz();
	struct book temp[50];
	int h=0;
	for(;;)
	{
		printf("1.ͼ����\t2.������\t3.��������\t4.�������\n"); 
		printf("��ѡ����Ҫ��ѯ�ķ�ʽ(��������5ʱ���˳��˹���):");
		scanf("%d",&j);
		system("cls");
		switch(j)
		{
			case 1: printf("������ͼ�������:");
				 	scanf("%s",a);
				 	printf("*****************************************ͼ���ѯ*****************************************\n");
					printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���"); 
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
					
			case 2: printf("���������ߵ�����:");
				 	scanf("%s",a);
				 	printf("\n");
					printf("*****************************************ͼ���ѯ*****************************************\n");
					printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���"); 
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
					
			case 3:printf("�������������:");
				 	scanf("%s",a);
				 	printf("\n");
					printf("*****************************************ͼ���ѯ*****************************************\n"); 
					printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");					
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
					
			case 4:printf("������������:");
				 	scanf("%d",&year);
				 	printf("\n");
					printf("*****************************************ͼ���ѯ*****************************************\n"); 
					printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
			default:printf("��Ǹû���ҵ��Ȿ��!\n");
		}	
	}
	return 0;
}

int px()/*ͼ������*/
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
	printf("*****************************************ͼ������*****************************************\n"); 
	printf("%-12s","����");
	printf("%-12s","������");
	printf("%-15s","���");
	printf("%-15s","����������");
	printf("%-18s","���");
	printf("%-14s","�۸�");
	printf("%-14s\n","���");
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

int search()/*ͼ��Ĳ��Һ�����*/ 
{
	int i;
	for(;;)
	{
		printf("1.����\t2.��ѯ\t3.����\n");
		printf("��ѡ�����蹦�ܣ�");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
			case 1:px();break;
			case 2:cx();break;
			case 3:return 0;break;
			default:  printf("��������\n"); 
					  system("pause");
					  system("cls");
		}
	}
	return 0;	
}

int jie()//���� 
{
	int i;	
	int j;		 
	char a[20];
	char b[]={"out"};
	fz();
	for(;;)
	{
		printf("������Ҫ���ĵ��鼮(����out�˳��˹���):");
		scanf("%s",a);
		system("cls");
		for(i=0;i<n;i++)
		{
			if(strcmp(a,BK[i].book_name)==0)
			{
				printf("������Ҫ��ı�����");
				scanf("%d",&j);
				system("cls");
				if(BK[i].k!=0)
				{
					if(BK[i].k>j)
					{
						BK[i].k=BK[i].k-j;
						printf("%-12s","����");
						printf("%-12s","������");
						printf("%-15s","���");
						printf("%-15s","����������");
						printf("%-18s","���");
						printf("%-14s","�۸�");
						printf("%-14s\n","���");
						printf("%-12s",BK[i].book_name);
						printf("%-12s",BK[i].book_author);
						printf("%-15s",BK[i].number);
						printf("%-15s",BK[i].publisher);
						printf("%-18d",BK[i].year);
						printf("%-14f",BK[i].price);
						printf("%-14d\n",BK[i].k);
						printf("%s�Ѿ������\n",BK[i].book_name);
						printf("��滹ʣ%d��\n",BK[i].k);
						system("pause");
						system("cls");
						break;
					}
					else
					{
						printf("��治�㣡\n"); 
						system("pause");
						system("cls");
					}		
				}
				if(BK[i].k==0)
				{
					printf("�����Ѿ��������ˣ�");
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

int huan()//����
{
	int i;	
	int j;		 
	char a[20];
	fz();
	printf("������Ҫ�����鼮������:");
	scanf("%s",&a);
	printf("������Ҫ���صı���:");
	scanf("%d",&j);
	for(i=0;i<n;i++)
	{
		if(strcmp(a,BK[i].book_name)==0)
		{
			BK[i].k=BK[i].k+j;
			printf("%-12s","����");
			printf("%-12s","������");
			printf("%-15s","���");
			printf("%-15s","����������");
			printf("%-18s","���");
			printf("%-14s","�۸�");
			printf("%-14s\n","���");
			printf("%-12s",BK[i].book_name);
			printf("%-12s",BK[i].book_author);
			printf("%-15s",BK[i].number);
			printf("%-15s",BK[i].publisher);
			printf("%-18d",BK[i].year);
			printf("%-14f",BK[i].price);
			printf("%-14d\n",BK[i].k);
			printf("����ɹ���\n");
			system("pause");
			system("cls");
		}
	} 
	return 0;
}

int borrow()//ͼ�����
{
	int i;
	for(;;)
	{
		printf("1.����\t2.����\n");
		printf("��ѡ������Ĺ���(��3ʱ�������˵�):");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
			case 1:jie();break;
			case 2:huan();break;
			case 3:return 0;
			default:printf("��������"); 
		}
	}
	return 0;	
}

int revise()//�޸�ͼ����Ϣ
{
	int j; 
	int i;
	int y;
	int h=0;//ͳ����Ϣ�ڵ����� 
	fz();
	struct book temp[50];
	char a[20];
	for(;;)
	{
		printf("1.ͼ����\t2.������\t3.��������\t4.�������\n"); 
		printf("��ѡ����Ҫ��ѯ��Ϣ�ķ�ʽ(����5ʱ����):");
		scanf("%d",&j);
		system("cls");
		switch(j)
		{
			case 1: printf("\n������ͼ�������:");
				 	scanf("%s",a);
				 	printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
					
			case 2: printf("\n���������ߵ�����:");
				 	scanf("%s",a);
				 	printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
					
			case 3:printf("\n�������������:");
				 	scanf("%s",a);
				 	printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
					
			case 4:printf("������������:");
				 	scanf("%d",&y);
				 	printf("%-12s","����");
					printf("%-12s","������");
					printf("%-15s","���");
					printf("%-15s","����������");
					printf("%-18s","���");
					printf("%-14s","�۸�");
					printf("%-14s\n","���");
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
					default:printf("��Ǹû���ҵ��Ȿ��!\n");
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
			printf("\n1.����\t2.������\t3.���\t4.����������\t5.���\t6.�۸�\t7.���\n");
			printf("��ѡ����Ҫ�޸���Ϣ:");	
			scanf("%d",&p);
			switch(p)
			{
				case 1:  for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n');
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸�������֣�");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].book_name,s);
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
										printf("������Ҫ�޸�������֣�");
										scanf("%s",&s);
										system("cls");
										for(i=0;i<h;i++)
										{
											strcpy(temp[i].book_name,s);
										}
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
						printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y):");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("�޸ĳɹ�!!\n");
							return 0;
						}
					    break;
					    
				case 2:  for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸����ߵ�����:");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].book_author,s);
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸����ߵ�����:");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].book_name,s);
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
					printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
					getchar();
					scanf("%c",&b);
					if(b=='y'||b=='Y')
					{
						cp();
						printf("�޸ĳɹ�!!\n");
						return 0;
					}
					break;
						
				case 3:  for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸�ͼ���ISBN�ţ�");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].number,s);
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸�ͼ�����ţ�");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].number,s);
										
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
						printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("�޸ĳɹ�!!\n");
							return 0;
						}
						break;
						
				case 4: for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸ĳ��������ƣ�");
										scanf("%s",&s);
										system("cls");
										strcpy(temp[i].publisher,s);
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸ĳ���������:");  
								scanf("%s",&s);
								for(i=0;i<h;i++)
								{
										strcpy(temp[i].book_name,s);
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
					printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
					getchar();
					scanf("%c",&b);
					if(b=='y'||b=='Y')
					{
						cp();
						printf("�޸ĳɹ�!!\n");
						return 0;
					}
					break;
	
				case 5: for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸�ͼ�����ݣ�");
										scanf("%s",&y);
										system("cls");
										temp[i].year=y;
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸�ͼ�����ݣ�");
								scanf("%s",&s);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].year=y;		
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
						printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("�޸ĳɹ�!!\n");
							return 0;
						}
						break;
						
				case 6:for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸�ͼ��ļ۸�");
										scanf("%f",&f);
										system("cls");
										temp[i].price=f;
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸�ͼ��ļ۸�:");
								scanf("%f",&f);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].price=f;
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
						printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("�޸ĳɹ�!!\n");
							return 0;
						}					
						break;
						
				case 7:for(i=0;i<h;i++)
					    {
					    	printf("�Ƿ�ȫ���޸ģ�(y/n):");
					    	getchar();
					    	scanf("%c",&d);
					    	system("cls");
					    	if(d=='n')
							{
								printf("������������֣�");
								scanf("%c",&e);
								system("cls");
								for(i=0;i<h;i++)
								{
									if(strcmp(e,temp[i].book_name)==0)
									{
										printf("������Ҫ�޸�ͼ��Ŀ��:");
										scanf("%d",&c);
										system("cls");
										temp[i].k=c;
										printf("%-12s","����");
										printf("%-12s","������");
										printf("%-15s","���");
										printf("%-15s","����������");
										printf("%-18s","���");
										printf("%-14s","�۸�");
										printf("%-14s\n","���");
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
								printf("������Ҫ�޸�ͼ��Ŀ��:");
								scanf("%d",&c);
								system("cls");
								for(i=0;i<h;i++)
								{
									temp[i].k=c;
								}
								printf("%-12s","����");
								printf("%-12s","������");
								printf("%-15s","���");
								printf("%-15s","����������");
								printf("%-18s","���");
								printf("%-14s","�۸�");
								printf("%-14s\n","���");
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
						printf("�Ƿ�Ҫ�����޸ĵ���Ϣ��y/Y����");
						getchar();
						scanf("%c",&b);
						if(b=='y'||b=='Y')
						{
							cp();
							printf("�޸ĳɹ�!!\n");
							return 0;
						}					
						break;
				case 8:System1();break;
				default:printf("�޸�ʧ�ܣ�");break;
			}
		
		}
	}
	return 0;
} 

int san()//ɾ������ 
{
	int i;
	char a[20]; 
	int b;
	int f;
	fz();
	printf("\n");
	printf("����������,ѡ������Ҫɾ�����Ǳ���:");
	scanf("%s",a);
	system("cls");
	for(i=0;i<n;i++)
	{
		if(strcmp(a,BK[i].book_name)==0)
		{
			printf("%-12s","����");
			printf("%-12s","������");
			printf("%-15s","���");
			printf("%-15s","����������");
			printf("%-18s","���");
			printf("%-14s","�۸�");
			printf("%-14s\n","���");
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
	printf("�Ƿ�ɾ��������Ϣ:(y/Y):");
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
			printf("%-12s","����");
			printf("%-12s","������");
			printf("%-15s","���");
			printf("%-15s","����������");
			printf("%-18s","���");
			printf("%-14s","�۸�");
			printf("%-14s\n","���");
			printf("%-12s",BK[i].book_name);
			printf("%-12s",BK[i].book_author);
			printf("%-15s",BK[i].number);
			printf("%-15s",BK[i].publisher);
			printf("%-18d",BK[i].year);
			printf("%-14f",BK[i].price);
			printf("%-14d\n",BK[i].k);
		}
		cp();
		printf("ɾ���ɹ���\n");
		system("pause");
		system("cls");
	}
	return 0;
}

int out()//�˳�ϵͳ
{
	puts("�˳��ɹ�!"); 
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
			default:printf("����!");
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
			default:printf("����!");
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
