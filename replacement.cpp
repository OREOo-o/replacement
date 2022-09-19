#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void JiaMi(char ZhiHuan[]); //加密函数
void JieMi(char ZhiHuan[]); //解密函数
void setZhiHuan(char ZhiHuan[],char fanZhiHuanBiao[]); //设置置换表函数

int main()
{
	int m; //确定是加密或解密？加密为1，解密为2
	char ZhiHuanBiao['z'+1]; //正向置换表，加密时用
	char fanZhiHuanBiao['Z'+1]; //反向置换表，解密时用
	cout<<"请确认你想使用的功能："<<endl;
	cout<<"1：加密  2：解密"<<endl;
	cin>>m; //读入m
	setZhiHuan(ZhiHuanBiao, fanZhiHuanBiao); //设置置换表
	switch(m) //判断m值，执行相应的功能
	{
	case 1: JiaMi(ZhiHuanBiao);break;
    case 2: JieMi(fanZhiHuanBiao);break;
    default:break;
	}
	return 0;
}

void JiaMi(char ZhiHuan[]) //加密
{
	string MingWen; //保存明文
	cout<<endl<<"请输入明文："<<endl;\
	cin>>MingWen; //读入明文
	cout<<"密文："<<endl;
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
	string MiWen; //保存密文
	cout<<endl<<"请输入密文：";
	cin>>MiWen; //读入密文
	cout<<"明文："<<endl;
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
	int i; //i和j是循环变量，除此之外没有任何意义
	char j;
	string s; //密钥
	cout<<"请输入密钥（大写）：";
	cin>>s; //读入密钥
	cout<<"置换表："<<endl;
	string s1;
	for(i = 0 ; i < s.length();i++) //对密钥进行处理(去掉空格和重复的字符)
	{
		bool sign =0; //标志变量
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
    for( i = 'a' ;i <= 'z'; i++) //该循环利用密钥得到置换表
    {
	    if(i < 'a' + s1.length()) //前面直接用s1代替
	    {
		    ZhiHuanBiao[i] = s1[i-'a'];
	    }
	    else //后面将剩下的"贴"上去
	    {
		    for(int j = 'a'; j < 'a' + s1.length(); j++)
		    {
			    if(ch == ZhiHuanBiao[j])
			    {
			    	ch++;
				    j= 'a'; //每次都从头开始搜索
			    	continue;
			     }
		    }
		    ZhiHuanBiao[i] = ch;
		    ch++;
	    }
	    cout<<ZhiHuanBiao[i]<<" ";
    }
    cout<<endl;
    for( i='a'; i<= 'z'; i++) //该循环利用置换表得到反置换表
    {
    	fanZhiHuanBiao[ ZhiHuanBiao[i] ] = i;
    }
	for( i='A'; i<= 'Z'; i++) //输出反置换表
	{
		cout<< fanZhiHuanBiao[i] <<" ";
	}
	cout<<endl;
}
