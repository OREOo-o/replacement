#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void JiaMi(char ZhiHuan[]); //���ܺ���
void JieMi(char ZhiHuan[]); //���ܺ���
void setZhiHuan(char ZhiHuan[],char fanZhiHuanBiao[]); //�����û�����

int main()
{
	int m; //ȷ���Ǽ��ܻ���ܣ�����Ϊ1������Ϊ2
	char ZhiHuanBiao['z'+1]; //�����û�������ʱ��
	char fanZhiHuanBiao['Z'+1]; //�����û�������ʱ��
	cout<<"��ȷ������ʹ�õĹ��ܣ�"<<endl;
	cout<<"1������  2������"<<endl;
	cin>>m; //����m
	setZhiHuan(ZhiHuanBiao, fanZhiHuanBiao); //�����û���
	switch(m) //�ж�mֵ��ִ����Ӧ�Ĺ���
	{
	case 1: JiaMi(ZhiHuanBiao);break;
    case 2: JieMi(fanZhiHuanBiao);break;
    default:break;
	}
	return 0;
}

void JiaMi(char ZhiHuan[]) //����
{
	string MingWen; //��������
	cout<<endl<<"���������ģ�"<<endl;\
	cin>>MingWen; //��������
	cout<<"���ģ�"<<endl;
	for(int i=0; i<MingWen.length();i++)
	{
		if(MingWen[i]>='a' && MingWen[i]<='z')
		{
			cout<<ZhiHuan[MingWen[i]];
		}
		else 
			cout<<MingWen[i];
	}
	cout<<endl;
}

void JieMi(char fanZhiHuan[])
{
	string MiWen; //��������
	cout<<endl<<"���������ģ�";
	cin>>MiWen; //��������
	cout<<"���ģ�"<<endl;
	for(int i=0; i<MiWen.length();i++)
	{
		if(MiWen[i]>='A' && MiWen[i]<='Z')
		{
			cout<<fanZhiHuan[MiWen[i]];
		}
		else
			cout<<MiWen[i];
	}
	cout<<endl;
}

void setZhiHuan(char ZhiHuanBiao[],char fanZhiHuanBiao[])
{
	int i; //i��j��ѭ������������֮��û���κ�����
	char j;
	string s; //��Կ
	cout<<"��������Կ����д����";
	cin>>s; //������Կ
	cout<<"�û���"<<endl;
	string s1;
	for(i = 0 ; i < s.length();i++) //����Կ���д���(ȥ���ո���ظ����ַ�)
	{
		bool sign =0; //��־����
		if(s[i] >= 'A' && s[i] <='Z')
		{
			for(int j = 0; j < s1.length();j++)
			{
				if(s[i] == s1[j])
				{
					sign = 1;
					break;
				}
			}
			if(sign == 0) s1 = s1 + s[i];
			else sign = 0;
		}
	}

    for( j ='a';j<='z';j++)cout<<j<<" ";cout<<endl;
    char ch='A';
    for( i = 'a' ;i <= 'z'; i++) //��ѭ��������Կ�õ��û���
    {
	    if(i < 'a' + s1.length()) //ǰ��ֱ����s1����
	    {
		    ZhiHuanBiao[i] = s1[i-'a'];
	    }
	    else //���潫ʣ�µ�"��"��ȥ
	    {
		    for(int j = 'a'; j < 'a' + s1.length(); j++)
		    {
			    if(ch == ZhiHuanBiao[j])
			    {
			    	ch++;
				    j= 'a'; //ÿ�ζ���ͷ��ʼ����
			    	continue;
			     }
		    }
		    ZhiHuanBiao[i] = ch;
		    ch++;
	    }
	    cout<<ZhiHuanBiao[i]<<" ";
    }
    cout<<endl;
    for( i='a'; i<= 'z'; i++) //��ѭ�������û���õ����û���
    {
    	fanZhiHuanBiao[ ZhiHuanBiao[i] ] = i;
    }
	for( i='A'; i<= 'Z'; i++) //������û���
	{
		cout<< fanZhiHuanBiao[i] <<" ";
	}
	cout<<endl;
}
