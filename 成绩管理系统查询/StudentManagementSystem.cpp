#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>


using namespace std;            //�����ռ� std

class lesson                   //����γ�
{
public:
   float chinesegrade;          //�������ĳɼ�
   float englishgrade;          //����Ӣ��ɼ�
   float mathgrade;             //������ѧ�ɼ�
   float cgrade;				//����c++�ɼ�
};

class student       //����ѧ��
{
public:
   char   name [10]; //�������� char
   char   clas [20]; //����༶ char
   int    num;       //������� int
   float  sum;       //�����ܷ� float
   float  average;   //����ƽ���ɼ� float
   lesson less;      //����γ�
}
m [100];

int        n = 100;
static int e = 0;
void sort();                   //��������

void error()                   //���������Ϣ
{
   cout << "---������������������---" << endl;
   cout << "\n";
}


/*---��ӭ����---*/

void welcome()       //�����������ϵͳ����ӭ����
{
   char password [5];
   char num [5];

   strcpy(num, "123");
loopback3: printf(" \n\n\n\n\n\n\n\n");
   printf("\t\t\t��ӭʹ��ѧ���ɼ�����ϵͳ��\n");
   printf("\t\t\t\t����:");
   scanf("%s", &password);
   if (strcmp(password, num) == 0)
   {
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t��ӭʹ��ѧ���ɼ�����ϵͳ��");
   }
   else
   {
      printf("\t\t\t\t �������!");           //��������������
      system("cls");
      goto loopback3;
   }
}


/*---1.ѧ����Ϣ���---*/

void show()          //1.ѧ����Ϣ���
{
   system("cls");                  //����
   int i;
   cout << setiosflags(ios::left)  // �����
        << setw(2) << "ѧ��" << "  " // ������Ϊ 2
        << setw(10) << "����" << "  "
        << setw(12) << "�༶"
        << setw(8) << "����"
        << setw(8) << "Ӣ��"
        << setw(8) << "��ѧ"
		<< setw(8) << "C++"
        << setw(8) << "�ܷ�"
        << setw(10) << "ƽ����"
        << endl;                                    //��ʾ��һ�����
   for (i = 0; i < e; i++)
   {
      m [i].sum =
         (
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade +
			m [i].less.cgrade
         );                            //�ּܷ��㹫ʽ

      m [i].average =
         (
            m [i].sum / 4
         );                            //ƽ���ּ��㹫ʽ

      
      cout << setiosflags(ios::left)
           << setw(5) << m [i].num << "  "
           << setw(10) << m [i].name
           << setw(14) << m [i].clas
           << setw(8) << m [i].less.chinesegrade
           << setw(8) << m [i].less.englishgrade
           << setw(8) << m [i].less.mathgrade
		   << setw(8) << m [i].less.cgrade
           << setw(8) << m [i].sum
           << setw(10) << m [i].average << endl;
      if (m [i].num == 0)
      {
         break;                           //������
      }
   }
}


/*---2.ѧ����Ϣ¼��---*/

void input()         //2.ѧ����Ϣ¼��
{
   system("cls");    //����
   int a;
   cout << "-----¼��ѧ����Ϣ-----" << endl;
   cout << "��������Ϣ������0 ����¼��" << endl;
   cout << "��������:ѧ�� ���� �༶ ���� Ӣ�� ��ѧ C++" << endl;
   for (a = e; a < n; a++)
   {
      cin >> m [a].num;
      if (m [a].num == 0)
      {
         break;                                //����0�˳�
      }
      cin >> m [a].name >> m [a].clas >> m [a].less.chinesegrade
      >> m [a].less.englishgrade >> m [a].less.mathgrade >>m [a].less.cgrade;
      e++;                   //ѭ��
   }
}


/*---3.ѧ����Ϣɾ��---*/

void delate()        //3.ѧ����Ϣɾ��
{
   show();
   cout << "---����Ҫɾ����ѧ��ѧ��:---";
   int a;
   cin >> a;
   for (int i = 0; i < e; i++)
   {
      if (a == m [i].num)
      {
         int j;
         for (j = i; j < e - 1; j++)
         {
			m[j]=m[j+1];
         }


         for (i = 0; i < e - 1; i++)
         {
            cout << setw(5) << m [i].num
                 << setw(10) << m [i].name
                 << setw(15) << m [i].clas
                 << setw(10) << m [i].less.chinesegrade
                 << setw(10) << m [i].less.englishgrade
                 << setw(10) << m [i].less.mathgrade
                 << setw(10) << m [i].less.cgrade
                 << setw(8) << m [i].sum
                 << setw(10) << m [i].average<< endl;
         }

         cout << "---ѧ����Ϣɾ���ɹ�---" << endl;
         break;
      }
	//  else cout << "error!";
   }
}


/*---4.��ѧ�Ų��������Ϣ---*/

void numsearch()                //4.��ѧ�Ų��� �����Ϣ
{
   show();
   cout << "��������Ҫ���ҵ�ѧ��:" << endl;
   int a;
   cin >> a;
   int BOOL = 0;
   for (int i = 0; i < n; i++)
   {
      if (a == m [i].num)
      {
         cout << setiosflags(ios::left)
              << setw(2) << "ѧ��" << "   "
              << setw(10) << "����"
              << setw(10) << "�༶"
              << setw(10) << "����"
              << setw(10) << "Ӣ��"
              << setw(10) << "��ѧ" 
			  << setw(10) << "C++"<< endl;
         cout << setiosflags(ios::left)
              << setw(5) << m [i].num << "  "
              << setw(10) << m [i].name
              << setw(10) << m [i].clas
              << setw(10) << m [i].less.chinesegrade
              << setw(10) << m [i].less.englishgrade
              << setw(10) << m [i].less.mathgrade 
			  << setw(10) << m [i].less.cgrade<< endl;
         cout << endl;
         BOOL = 1;
      }
   }

   if (BOOL == 0)
   {
      cout << "---û����Ҫ��ѯ����Ϣ!---" << endl;
   }
}


/*---5.����������---*/

void namesearch()  //5.���������� �����Ϣ
{
   show();
   cout << "��������Ҫ���ҵ�����:" << endl;
   string a;
   cin >> a;
   int BOOL = 0;
   for (int i = 0; i < n; i++)
   {
      if (a == m [i].name)
      {
         cout << setiosflags(ios::left)
              << setw(2) << "ѧ��" << "   "
              << setw(10) << "����"
              << setw(10) << "�༶"
              << setw(10) << "����"
              << setw(10) << "Ӣ��"
			  << setw(10) << "��ѧ" 
              << setw(10) << "C++" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << m [i].num << "  "
              << setw(10) << m [i].name
              << setw(10) << m [i].clas 
			  << setw(10) << m [i].less.chinesegrade
              << setw(10) << m [i].less.englishgrade
			  << setw(10) << m [i].less.mathgrade
              << setw(10) << m [i].less.cgrade << endl;
         cout << endl;
         BOOL = 1;
      }
   }
   if (BOOL == 0)
   {
      cout << "---��Ǹû����Ҫ��ѯ����Ϣ---" << endl;
   }
}


/*---6.���γ̲���---*/

void lesssearch()  //6.���γ̲��� �����Ϣ
{
   show();
   cout << "---��������Ҫ���ҵĿγ�:---" << endl;
   cout << "1. ����" << endl;
   cout << "2. Ӣ��" << endl;
   cout << "3. ��ѧ" << endl;
   cout << "4. C++" << endl;
   string a;
   cin >> a;
   cout << setiosflags(ios::left)
        << setw(2)
        << setw(10) << "����"
        << setw(10) << "�ɼ���" << endl;
   int BOOL = 0;
   for (int i = 0; i < e; i++)
   {
      if (a == "1")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.chinesegrade << endl;
         BOOL = 1;
      }
      else if (a == "2")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.englishgrade << endl;
         BOOL = 1;
      }
      else if (a == "3")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.mathgrade << endl;
         BOOL = 1;
      }
	  else if (a == "4")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.cgrade << endl;
         BOOL = 1;
      }
   }
   if (BOOL == 0)
   {
      cout << "---û����Ҫ��ѯ����Ϣ!---" << endl;
   }
}


/*---7.1.��Ӣ��ɼ�����---*/

void sort1()   //7.1.��Ӣ��ɼ�����
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.englishgrade < m [j + 1].less.englishgrade)                      //ð������
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.cgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.cgrade		= t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.2.�����ĳɼ�����---*/

void sort2()   //7.2.�����ĳɼ�����
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.chinesegrade <= m [j + 1].less.chinesegrade)                     //ð������
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.cgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.cgrade		= t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.3.����ѧ�ɼ�����---*/

void sort3()   //7.3.����ѧ�ɼ�����
{
   int   j, i;
   char  t1 [20], t2 [20];
   float t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.mathgrade <= m [j + 1].less.mathgrade)        //ð������
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.mathgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.cgrade		= t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.4.��C++�ɼ�����---*/

void sort4()   //7.4.��C++�ɼ�����
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.cgrade < m [j + 1].less.cgrade)                      //ð������
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.cgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.cgrade		= t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.5.��ѧ������---*/

void sort5()   //7.5.��ѧ������
{
   int   j, i;
   char  t1 [20], t2 [20];
   float t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].num <= m [j + 1].num)                     //ð������
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.cgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.cgrade    = t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.6.���ܳɼ���С��������---*/

void sort6()   //7.6.���ܳɼ���С�������� ��ð������
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6, t7;
   float t8;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if ((m [j].less.chinesegrade + m [j].less.englishgrade + m [j].less.mathgrade + m [j].less.cgrade)
             >= (m [j + 1].less.chinesegrade + m [j + 1].less.englishgrade + m [j + 1].less.mathgrade + m [j + 1].less.cgrade))
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
			t7 = m [j].less.cgrade;
            t8 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
			m [j].less.cgrade		= m [j + 1].less.cgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
			m [j + 1].less.mathgrade    = t7;
            m [j + 1].num = t8;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}




/*---7.ѧ���ɼ����򹤾�---*/

void sort()   //7.ѧ���ɼ����򹤾�
{
   cout << " \n\n\n\n\n\n\n\t\t\t  ��ӭʹ��ѧ���ɼ����򹤾�" << endl;
   cout << "                          ##########################" << endl;
   cout << "                          * 1. ��Ӣ��ɼ�����      *" << endl;
   cout << "                          * 2. �����ĳɼ�����      *" << endl;
   cout << "                          * 3. ����ѧ�ɼ�����      *" << endl;
   cout << "                          * 4. ��C++�ɼ�����       *" << endl;
   cout << "                          * 5. ��ѧ������          *" << endl;
   cout << "                          * 6. ���ܳɼ���С��������*" << endl;
   cout << "                          * 7. �˳�����            *" << endl;
   cout << "                          ##########################" << endl;
   cout << "                          * ���롸1-7�������Ӧ����*" << endl;
   int r;
   cin >> r;
   switch (r)
   {
   case 1:
      sort1();
      break;

   case 2:
      sort2();
      break;

   case 3:
      sort3();
      break;

   case 4:
      sort4();
      break;

   case 5:
      sort5();
      break;

   case 6:
      sort6();
      break;

   case 7:
      cout << "---�˳�����ҳ---" << endl;
      return;

      break;

   default:
      error();
   }
}


/*---8.ѧ����Ϣͳ�ƹ���---*/

void statistics()    //8.ѧ����Ϣͳ�ƹ��ߣ�������߷֡���ͷ֡�ƽ����
{
   system("cls");    //ϵͳ����

   /*---���������Ϣ---*/

   float        sumc = 0, sume = 0, summ = 0, suml = 0;
   static float sum     = 0;
   static float average = 0;
   static float fangcha = 0;
   char         max_class [20],
                max_name [20],
                min_class [20],
                min_name [20];
   int   i, j, c = 0;
   float count1 = 0, count2 = 0, count3 = 0, count4 = 0;
   float maxc = m [0].less.chinesegrade,                        //�������ֵ
         minc = m [0].less.chinesegrade,                        //������Сֵ
         pc,
         maxe = m [0].less.englishgrade,                        //Ӣ�����ֵ
         mine = m [0].less.englishgrade,                        //Ӣ����Сֵ
         pe,
         maxm = m [0].less.mathgrade,                           //��ѧ���ֵ
         minm = m [0].less.mathgrade,                           //��ѧ��Сֵ
         pm,
		 maxl = m [0].less.cgrade,								//C++���ֵ
         minl = m [0].less.cgrade,								//C++��Сֵ
         pl,
         max_score        = maxc + maxe + maxm +maxl,                 //�ܷ����ֵ
         min_score        = minc + mine + minm +minl,                 //�ܷ���Сֵ
         max_chinesegrade = 0,
         max_englishgrade = 0,
         max_mathgrade    = 0,
		 max_cgrade		  = 0,
         max_num,
         min_chinesegrade = 0,
         min_englishgrade = 0,
         min_mathgrade    = 0,
		 min_cgrade		  = 0,
         min_num;

   /*---����ѧ������---*/

   for (i = 1; i < e; i++)         //���ֵ����Сֵ���ܷ�����ܷ���С��ѧ������
   {
      if (minc > m [i].less.chinesegrade)
      {
         minc = m [i].less.chinesegrade;
      }
      if (maxc < m [i].less.chinesegrade)
      {
         maxc = m [i].less.chinesegrade;
      }
      if (mine > m [i].less.englishgrade)
      {
         mine = m [i].less.englishgrade;
      }
      if (maxe < m [i].less.englishgrade)
      {
         maxe = m [i].less.englishgrade;
      }
      if (minm > m [i].less.mathgrade)
      {
         minm = m [i].less.mathgrade;
      }
      if (maxm < m [i].less.mathgrade)
      {
         maxm = m [i].less.mathgrade;
      }
	  if (minl > m [i].less.cgrade)
      {
         minl = m [i].less.cgrade;
      }
      if (maxl < m [i].less.cgrade)
      {
         maxl = m [i].less.cgrade;
      }

      /*---�������ֵ---*/

      if (max_score < (
             m [i].less.chinesegrade +
             m [i].less.englishgrade +
             m [i].less.mathgrade	 +
			 m [i].less.cgrade ))
      {
         max_score =
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade	+
			m [i].less.cgrade;
         max_num = m [i].num;
         strcpy(max_name, m [i].name);
         strcpy(max_class, m [i].clas);
         max_chinesegrade = m [i].less.chinesegrade;
         max_englishgrade = m [i].less.englishgrade;
         max_mathgrade    = m [i].less.mathgrade;
		 max_cgrade       = m [i].less.cgrade;
      }

      /*---������Сֵ---*/

      if (min_score > (
             m [i].less.chinesegrade +
             m [i].less.englishgrade +
             m [i].less.mathgrade	 +
			 m [i].less.cgrade))
      {
         min_score =
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade    +
			m [i].less.cgrade;
         min_num = m [i].num;
         strcpy(min_name, m [i].name);
         strcpy(min_class, m [i].clas);
         min_chinesegrade = m [i].less.chinesegrade;
         min_englishgrade = m [i].less.englishgrade;
         min_mathgrade    = m [i].less.mathgrade;
		 min_cgrade		  = m [i].less.cgrade;
      }
   }

   /*---���㼰����---*/

   for (j = 0; j < e; j++)
   {
      sumc = sumc + m [j].less.chinesegrade;
      if (m [j].less.chinesegrade >= 60)
      {
         ++count1;
      }                 //���ĳɼ�
      sume = sume + m [j].less.englishgrade;
      if (m [j].less.englishgrade >= 60)
      {
         ++count2;
      }                 //Ӣ��ɼ�
      summ = summ + m [j].less.mathgrade;
      if (m [j].less.mathgrade >= 60)
      {
         ++count3;
      }                 //��ѧ�ɼ�
	  suml = suml + m [j].less.cgrade;
      if (m [j].less.cgrade >= 60)
      {
         ++count4;
      }                 //C++�ɼ�
   }
   pc = count1;         //���ĳɼ���ֵ�� pc
   pe = count2;         //Ӣ��ɼ���ֵ�� pe
   pm = count3;         //��ѧ�ɼ���ֵ�� pm
   pl = count4;			//C++�ɼ���ֵ��  pl

   /*---��ʾ��ʾ---*/

   cout << "1. ����ĳѧ�����ܷ֡�ƽ����" << endl;
   cout << "2. ����ȫ���ܳɼ���Ϣ" << endl;

   /*---��ȡ����---*/

   int k;
   cin >> k;                //����һ�� k
   if (k == 1)              //��ʾĳ��ѧ�����ּܷ�ƽ����
   {
      cout << "������ѧ��ѧ��:" << endl;
      int t;
      cin >> t;
      for (i = 0; i < e; i++)
      {
         if (t == m [i].num)
         {
            sum = m [i].less.chinesegrade +
                  m [i].less.englishgrade +
                  m [i].less.mathgrade    +
				  m [i].less.cgrade;
            average = sum / 4;
            cout << "����:" << m [i].name
                 << "     �ܷ�:" << sum
                 << "     ƽ����:" << average
                 << endl;
            c++;
         }
      }
      if (c == 0)
      {
         error();
      }
   }
   else         //ÿ��ѧ�Ƶ�������ƽ��������
   {
      cout << "1. ���ĳɼ� " << endl;
      cout << "2. Ӣ��ɼ� " << endl;
      cout << "3. ��ѧ�ɼ� " << endl;
	  cout << "4. C++�ɼ� " << endl;
      cout << "5. ȫ��ɼ� " << endl;
      cout << "6. ����     " << endl;
      cout << "��������ţ�" << endl;
      int r;
      cin >> r;
      switch (r)
      {
      case 1:
         cout << "���ĳɼ���߷�:  " << maxc << endl;
         cout << "���ĳɼ���ͷ�:  " << minc << endl;
         cout << "����ȫ��ƽ����:  " << sumc / e << endl;
         cout << "���ļ�����:  " << pc / e << endl;
         break;

      case 2:
         cout << "Ӣ��ɼ���߷�:  " << maxe << endl;
         cout << "Ӣ��ɼ���ͷ�:  " << mine << endl;
         cout << "Ӣ��ȫ��ƽ����:  " << sume / e << endl;
         cout << "Ӣ�Ｐ����: " << pe / e << endl;
         break;

      case 3:
         cout << "��ѧ�ɼ���߷�:  " << maxm << endl;
         cout << "��ѧ�ɼ���ͷ�:  " << minm << endl;
         cout << "��ѧȫ��ƽ����:  " << summ / e << endl;
         cout << "��ѧ������:  " << pm / e << endl;
         break;

	  case 4:
         cout << "C++�ɼ���߷�:  " << maxl << endl;
         cout << "C++�ɼ���ͷ�:  " << minl << endl;
         cout << "C++ȫ��ƽ����:  " << suml / e << endl;
         cout << "C++������:  " << pl / e << endl;
         break;

      case 5:
         cout << "ȫ����߷�:  " << max_score << endl;
         cout << "������ϢΪ:  " << endl;
         cout << setiosflags(ios::left)
              << setw(2) << "ѧ��" << "   "
              << setw(10) << "����"
              << setw(10) << "�༶"
              << setw(10) << "����"
              << setw(10) << "Ӣ��"
			  << setw(10) << "��ѧ"
              << setw(10) << "C++" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << max_num << "  "
              << setw(10) << max_name
              << setw(10) << max_class
              << setw(10) << max_chinesegrade
              << setw(10) << max_englishgrade
			  << setw(10) << max_mathgrade
              << setw(10) << max_cgrade << endl;
         cout << "ȫ����ͷ�:  " << min_score << endl;
         cout << "������ϢΪ:  " << endl;
         cout << setiosflags(ios::left)
              << setw(2) << "ѧ��" << "   "
              << setw(10) << "����"
              << setw(10) << "�༶"
              << setw(10) << "����"
              << setw(10) << "Ӣ��"
			  << setw(10) << "��ѧ" 
              << setw(10) << "c++" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << min_num << "  "
              << setw(10) << min_name
              << setw(10) << min_class
              << setw(10) << min_chinesegrade
              << setw(10) << min_englishgrade
			  << setw(10) << min_mathgrade
              << setw(10) << min_cgrade << endl;
         break;

      case 6:
         cout << "---����---" << endl;
         return;

         break;

      default:
         error();
         break;
      }
   }
}


/*---9.ѧ����Ϣд���ļ�--*/

void save()    //9.ѧ����Ϣд���ļ�
{
   int      i;
   ofstream outfile("Student.dat", ios::out);

   if (!outfile)
   {
      cerr << "open Student.dat error!" << endl;
      exit(1);
   }
   outfile << e << endl;
   for (i = 0; i < e; i++)
   {
      outfile << m [i].num << ' ';
      outfile << m [i].name << ' ';
      outfile << m [i].clas << ' ';
      outfile << m [i].less.chinesegrade << ' ';
      outfile << m [i].less.englishgrade << ' ';
	  outfile << m [i].less.mathgrade << ' ';
      outfile << m [i].less.cgrade << ' ';
      outfile << m [i].sum << ' ';
      outfile << m [i].average << ' ';
      outfile << endl;
   }
   outfile.close();
   cout << endl;
   cout << "---�����ѳɹ�����---" << endl;
}


/*---���ؽ��� load---*/

void load()    //���ؽ��� load
{
   system("cls");
   cout << setiosflags(ios::left)
        << setw(2) << "ѧ��" << "   "
        << setw(10) << "����"
        << setw(10) << "�༶"
        << setw(10) << "����"
        << setw(10) << "Ӣ��"
		<< setw(10) << "��ѧ"
        << setw(10) << "C++" << endl;
   ifstream infile("Student.dat", ios::in);
   infile >> e;
   for (int i = 0; i < e; i++)
   {
      infile >> m [i].num;
      infile >> m [i].name;
      infile >> m [i].clas;
      infile >> m [i].less.chinesegrade;
      infile >> m [i].less.englishgrade;
      infile >> m [i].less.mathgrade;
	  infile >> m [i].less.cgrade;
      infile >> m [i].sum;
      infile >> m [i].average;
   }
}


/*---������ main---*/

int main(void)    //������ main
{
   system("cls");
   welcome();                             //���û�ӭ����
   load();                                //���ü��ؽ���
   for ( ; ;)
   {
//      system("cls");                                            //����
      cout << " \n\n\n\n\n\n\n\t\t\t  "
           << "#**************************#" << endl;
      cout << "                          # ��ӭʹ��ѧ���ɼ�����ϵͳ!#" << endl;
      cout << "                          #**************************#" << endl;
      cout << "                          #��1.���ѧ���ɼ���Ϣ������#" << endl;
      cout << "                          #��2.¼��ѧ���ɼ���Ϣ������#" << endl;
      cout << "                          #��3.ɾ��ѧ���ɼ���Ϣ������#" << endl;
      cout << "                          #��4.ѧ����Ϣ��ѯ�ɼ�������#" << endl;
      cout << "                          #��5.������Ϣ��ѯ�ɼ�������#" << endl;
      cout << "                          #��6.�γ���Ϣ��ѯ�ɼ�������#" << endl;
      cout << "                          #��7.ѧ���ɼ����򹤾ߡ�����#" << endl;
      cout << "                          #��8.ѧ���ɼ�ͳ�ƹ��ߡ�����#" << endl;
      cout << "                          #��9.ѧ���ɼ�д���ļ�������#" << endl;
      cout << "                          #��0.�˳�ѧ������ϵͳ������#" << endl;
      cout << "                          #**************************#" << endl;
      cout << "                           ���롸0-9�������Ӧ���� " << endl;
      int n;
      cin >> n;
      if ((n >= 0) && (n <= 9))                                 //���벻ͬ�Ĺ���
      {
         switch (n)
         {
         case 1:
            show();
            break;                      //���ѧ����Ϣ

         case 2:
            input();
            save();
            break;                      //����ѧ����Ϣ

         case 3:
            delate();
            break;                      //ɾ��ѧ����Ϣ

         case 4:
            numsearch();
            break;                      //ѧ�Ų�ѯ

         case 5:
            namesearch();
            break;                      //������ѯ

         case 6:
            lesssearch();
            break;                      //�γ̲�ѯ

         case 7:
            sort();
            break;                      //����

         case 8:
            statistics();
            break;                      //ͳ��

         case 9:
            save();
            break;                      //д���ļ�

         case 0:
            cout << "��ӭ����ʹ��" << endl;
            exit(0);                    //�˳�

         default:
            break;
         }
         cout << endl;
      }
   }
}