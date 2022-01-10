#include <windows.h>
#include <iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<WinBase.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//头文件
using namespace std;
#pragma warning( disable : 4789)

#define MAXSTRING 1024//定义的最大字符串长度
#define wordnum 102//单词个数    
FILE* fp;//定义的用于登录的文本指针
FILE* fpp;//定义的用于排行的文本指针

//单词库
char words[102][40] = { "const", "string", "true", "new", "delete", "static", "sort","define", "stack", "queue", "namespace", "inline", "main","include", "void","while","for","if","true","int"
,"sizeof","continue","static", "struct","else","void","case","switch","float","short","nice","bank","black","word","love","phone","table","consult","fucky","sex","blood","vein","artery",
"capillary","nerve","marrow","lung","heart","diaphragm","organs","stomach","liver","address","pancreas","spleen","duodenum","intestine","large","caecum",
"appendix","rectum","anus","kidney","bladder","penis","testicle","scrotum","urethra","ovary","womb","vagina","brow","fingers","lips","eyebrows","shoulders","tongue","nose","chest",
"neck","stomach","face","hair","pupll","eyelip","head","armpit","navel","elbow","forearm","trunk","bottocks","calf","apparatus","mandible","vertebrae","clavicle","breast","backbone",
"pelvis","previld","phalanges" };

//保存这坐标的结构体
struct word
{
	int x = 0;
	int y = 0;
	char content[40];
};

//用户名和密码
typedef struct
{
	char user[20];
	char code[20];
	int highestscore;
	int highestlevel ;
	int problem[102];
}Users;
Users pe;

//保存这坐标的结构体
struct paihang
{
	char name[7][20];
	int score[7];
};
struct paihang rankk;

void estimate(double speed,int all);//判断函数，判断用户的打字能力
int opt1();//选择函数，选择测试时的单词长度
void welcom();//介绍的欢迎
void start();//开始，选择模式函数
int *opt();//选择速度和同时下落个数的函数
void practice(int a,int b);//基础的游戏练习函数
void exam(int a);//检测函数
void denglu();//登录
void write();//写入保存用户信息
void zhuce();//注册
void selfdefine();//自定义文本模式
int backmusic(char a);//背景音乐打开
void goodbey();//再见
int closemusic();//关闭音乐


#if 1//main
int main()
{
	//勿擦该代码为重新创建排行榜
	/*int a,n;
	a = fopen_s(&fpp,"paihangbang", "w");
	for (n = 0; n <= 6; n++)
	{
		rankk.score[n] = 0;
	}
	fwrite(&rankk, sizeof(paihang), 1, fpp);
	fclose(fpp);                        */
loop1:
	char ch;
	cout << "\t\t\t请选择\n\t\t\t1.注册or2.登录" << endl;
loop:
	ch = _getch();
	if (ch == '1')
	{
		zhuce();
		goto loop1;
	}
	else if (ch == '2')
	{
		denglu();
	}
	else
	{
		goto loop;
	}
	initgraph(1000, 600);//打开界面
	welcom();
	goodbey();
	closegraph();
	system("cls");
	cout << "\n\n\n\t\t\t按任意键退出" << endl;
	while (1)
	{
		if (_kbhit())
		{
			_getch();
			exit(0);
		}
	}
}
#elif 0
int main()//测试代码,测试序号1-5
{
	int a;
	char u[20]="李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	fclose(fp);                           //关闭文件防止错误操作
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	welcom();
	closegraph();
}
#elif 0
int main()//测试代码,测试序号6-10
{
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	start();
	closegraph();
}
#elif 0
int main()//测试代码,测试序号11-15
{
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	practice(2, 2);
	closegraph();
}
#elif 0
int main()//测试代码,测试序号16-20
{
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	exam(7);
	closegraph();
}
#elif 0
int main()//测试代码,测试序号21-25
{
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	selfdefine();
	closegraph();
}
#elif 0
int main()//测试代码,测试序号26-27
{
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	goodbey();
	closegraph();
}
#elif 0
int main()//测试代码,测试序号28-31
{
	int* p;
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	p = opt();
	if (p[0] == -1)//在选择时按了返回键optt[0]为-1
	{
		return;
	}
	practice(p[1], p[2]);//分别为速度和下落个数
	closegraph();
}
#elif 0
int main()//测试代码,测试序号32
{
	int l;
	int* p;
	int a;
	char u[20] = "李政廉";
	a = fopen_s(&fp, u, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息，即用户名和密码
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	l = opt1();
	if (l == -1)
	{
		return;
	}
	exam(l);
	closegraph();
}
#elif 0
int main()//测试代码,测试序号33-34
{
	backmusic('1');
	Sleep(5000);
	closemusic();
}
#elif 0
int main()//测试代码,测试序号35-39
{
	denglu();
}
#elif 0
int main()//测试代码,测试序号40-43
{
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	estimate(1,1);
	closegraph();
	initgraph(1000, 600);//打开界面
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	estimate(0,0);
	closegraph();
}
#elif 0
int main()//测试代码,测试序号44-49
{
	zhuce();
}
#endif 
//测试代码


void estimate(double speed ,int all)//用于评价的函数
{
	char *value=NULL;
	char *value_=NULL;
	//评价语句库
	char value1[] = "这可针不戳！！！这速度可针不戳！！！";
	char value0[] = "芜湖直接起飞！！！！！！！！！！！！";
	char value2[] = "我大意了啊，没闪啊，现在的软件不讲武德！！";
	char value3[] = "打字都能卷起来，我愿称你为卷王之王！！";
	char value4[] = "我认为这软件很棒所以多练练（nice！）";
	char value5[] = "你就这点数量我很难替你办事啊！！！";
	char value6[] = "你搁这儿没练就测呢！玩儿吗！！！";
	if (all>150)
	{
		value = value3;
	}
	else if(all <= 150 && all > 30)
	{ 
		value = value4;
	}
	else if (all <30)
	{
		value = value5;
	}
	if (speed<0.3&&speed>0)
	{
		value_ = value0;
	}
	else if (speed ==0)
	{
		value_ = value6;
	}
	else if (speed <= 0.8 && all >= 0.3)
	{
		value_ = value1;
	}
	else if (speed>=0.8)
	{
		value_= value2;
	}
	char ch;
	cleardevice();
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background2.jpg");
	putimage(0, 0, &img);
	settextstyle(40, 0,"华文行楷");//设置字体大小和字体样式(字号 风格 字体)
	outtextxy(200, 150, "你的速度为：");
	outtextxy(10, 565, "键入eas退出");
	outtextxy(700, 150, "秒/个字母");
	char strspeed[20];
	sprintf_s(strspeed, "%lf", speed);//输出
	outtextxy(450, 150, (TCHAR)strspeed);
	outtextxy(200, 350, "你完整输入的数量为：");
	outtextxy(700, 350, "个");
	char strall[20];
	sprintf_s(strall, "%d", all);//输出
	outtextxy(600, 350, (TCHAR)strall);
	outtextxy(240, 225, (TCHAR)value_);
	outtextxy(240, 425,(TCHAR)value);
	mciSendString("open .\\新建文件夹\\成功.mp3", NULL, 0, NULL);
	mciSendString("play .\\新建文件夹\\成功.mp3 ", NULL, 0, NULL);
	while (1)
	{
		//输出界面信息等
		BeginBatchDraw();
		settextstyle(40, 0, "华文行楷");//设置字体大小和字体样式(字号 风格 字体)
		outtextxy(200, 150,"你的速度为：" );
		outtextxy(10, 565, "键入eas退出");
		outtextxy(700, 150, "秒/个字母");
		char strspeed[20];
		sprintf_s(strspeed, "%lf", speed);//输出
		outtextxy(450, 150, (TCHAR)strspeed);
		outtextxy(200, 350, "你完整输入的数量为：");
		outtextxy(700, 350, "个");
		char strall[20];
		sprintf_s(strall, "%d", all);//输出
		outtextxy(600,350 , (TCHAR)strall);
		outtextxy(240, 225, (TCHAR)value_);
		outtextxy(240, 425, (TCHAR)value);
		EndBatchDraw();
		if (_kbhit())
		{
			ch = _getch();
			if (ch = 27)
			{
				cleardevice();//清屏
				mciSendString("close .\\新建文件夹\\成功.mp3 ", NULL, 0, NULL);
				return;
			}
		}
	}
}



void welcom()//介绍
{
	int musicopen = 0;//用于判断bgm是否开启的数
	mciSendString("open .\\新建文件夹\\登录.mp3", NULL, 0, NULL);
	mciSendString("play .\\新建文件夹\\登录.mp3 ", NULL, 0, NULL);
loop://使返回后能够再次显示界面
	setbkmode(TRANSPARENT);//使背景窗口透明
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background.jpg");
	putimage(0, 0, &img);
	settextcolor(RED);
	settextstyle(32, 0, "宋体");//设置字体大小和字体样式(字号 风格 字体)
	outtextxy(200, 250, "欢迎进入该打字软件");
	settextstyle(32, 0, "华文行楷");
	outtextxy(750, 40,"输入1~9选择BGM");
	outtextxy(750, 90, "输入Tab关闭BGM");
	outtextxy(200, 350, "该软件开发用于练习打字速度，想来玩玩吗来吧！");
	settextstyle(26, 0, "华文行楷");
	outtextxy(200, 460, "按enter进入");
	outtextxy(200, 500, "输入eas退出");
	char a;
	int color = 255;
	settextstyle(26, 0, "华文行楷");
	while (true)
	{
		setcolor(RGB(color, 0, 0));
		color -= 10;//颜色越来越暗 出现闪烁效果
		if (color < 0)
			color = 255;//红色
		outtextxy(200, 460, "按enter进入");
		outtextxy(200, 500, "输入eas退出");
		Sleep(50);
		if (_kbhit())//有按键
		{
			a = _getch();
			if (a == '\r')
			{
				cleardevice();//清屏 准备进入游戏界面
				mciSendString("close .\\新建文件夹\\登录.mp3 ", NULL, 0, NULL);
				start();
				goto loop;
			}
			else if (a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')//打开bgm
			{
				if(musicopen==0)
				musicopen=backmusic(a);
			}
			else if (a == 9)//关闭bgm
			{
				if(musicopen==1)
				musicopen=closemusic();
			}
			else if(a==27)//退出
			{
				cleardevice();
				mciSendString("close .\\新建文件夹\\登录.mp3 ", NULL, 0, NULL);
				return;
			}
		}
	}
}



void start()//开始的函数
{
	int n;
	int p;
loop://使返回后能够再次选择
	p = fopen_s(&fp, pe.user, "r+");
	fread(&pe, sizeof(Users), 1, fp); //读取用户信息
	fclose(fp);//关闭保存文件
	p = fopen_s(&fpp, "paihangbang", "r+");
	fread(&rankk, sizeof(paihang), 1, fpp); //读取用户信息
	fclose(fpp);//关闭保存文件
	int length;//选择的单词长度
	int*optt;//用于存放opt函数返回的指针
	int color = 0;
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background.jpg");
	putimage(0, 0, &img);
	settextcolor(CYAN);
	settextstyle(50, 0, "华文行楷");
	outtextxy(550, 30, "用户:");
	settextstyle(50, 0, "华文行楷");
	outtextxy(680, 30, pe.user);
	settextstyle(50, 0,"华文行楷");
	settextcolor(BLUE);
	outtextxy(550, 220, "目前最高分排行榜！");
	settextstyle(30, 0, "华文行楷");
	char strpaihangscore[7][20];
	settextcolor(MAGENTA);
	for (n = 0; n <= 6; n++)
	{
		sprintf_s(strpaihangscore[n], "%d", rankk.score[n]);//输出score
	}
	outtextxy(650, 300, rankk.name[0]);
	if(rankk.score[0]!=0)
	outtextxy(800, 300, strpaihangscore[0]);
	outtextxy(650, 340, rankk.name[1]);
	if (rankk.score[1] != 0)
	outtextxy(800, 340, strpaihangscore[1]);
	outtextxy(650, 380, rankk.name[2]);
	if (rankk.score[2] != 0)
	outtextxy(800, 380, strpaihangscore[2]);
	outtextxy(650, 420, rankk.name[3]);
	if (rankk.score[3] != 0)
	outtextxy(800, 420, strpaihangscore[3]);
	outtextxy(650, 460, rankk.name[4]);
	if (rankk.score[4] != 0)
	outtextxy(800, 460, strpaihangscore[4]);
	outtextxy(650, 500, rankk.name[5]);
	if (rankk.score[5] != 0)
	outtextxy(800, 500, strpaihangscore[5]);
	outtextxy(650, 540, rankk.name[6]);
	if (rankk.score[6] != 0)
	outtextxy(800, 540, strpaihangscore[6]);
	outtextxy(700, 100, "历史最高分：");
	char strhighestscore[20];
	sprintf_s(strhighestscore, "%d", pe.highestscore);//输出score
	outtextxy(940,100, strhighestscore);
	outtextxy(700, 130, "历史最等级：");
	char strhighestlevel[20];
	sprintf_s(strhighestlevel, "%d", pe.highestlevel);//输出level
	outtextxy(940, 130, strhighestlevel);
	outtextxy(550, 160, "只有练习模式的等级0计入历史！！");
	settextstyle(40, 0, "华文行楷");
	while (true)
	{
		char moshi;//模式选择
		setcolor(RGB(color, 0, 0));
		color += 10;//颜色越来越暗 出现闪烁效果
		if (color >255)
			color = 0;//红色
		outtextxy(100, 100, "选择模式");
		outtextxy(100,200 , "练习模式，请输入1");
		outtextxy(100, 300, "测试模式，请输入2");
		outtextxy(100, 400, "自定义文档，请输入3");
		outtextxy(100, 500, "返回，请键入esc");
		Sleep(50);
		if (_kbhit())//有按键
		{
			moshi = _getch();
			if (moshi == '1')
			{
				cleardevice();//清屏 准备进入游戏界面
				optt = opt();
				if (optt[0] == -1)//在选择时按了返回键optt[0]为-1
				{
					goto loop;
				}
				practice(optt[1],optt[2]);//分别为速度和下落个数
				goto loop;
			}
			else if (moshi == '2')
			{
				cleardevice();//清屏 准备进入游戏界面
				length = opt1();
				if (length == -1)
				{
					goto loop;
				}
				exam(length);
				goto loop;
			}
			else if (moshi == '3')
			{
				cleardevice();//清屏 准备进入游戏界面
				selfdefine();
				mciSendString("close .\\新建文件夹\\成功.mp3 ", NULL, 0, NULL);
				goto loop;
			}
			else if(moshi==27)//返回
			{
				cleardevice();//清屏 
				return;
			}
		}
	}
}



void practice(int a,int num)//游戏练习函数
{
	double rate=0;//成功率
	int all=0;
	int suc=0;
	int highscore=0;
	int o;
	char shuru[20];
	for (o = 0; o <= 19; o++)
		shuru[o] = '\0';
	int max=0;
	int ww;
	for (ww = 1; ww<= 101; ww++)//读取用户错误最多的单词序号
	{
		if (pe.problem[max] < pe.problem[ww])
		{
			max = ww;
		}
	}
	int kk;
	int pro[5];
	int nn;
	int p, p_,p3,p4;//用于检测文本的打开
	int nofin;//记录一组中有多少啊单词没打完
	int k;
	int w=0;//用于一组中全部单词打完后的退出
	int xiaoshi[5] = {1,1,1,1,1};//初始化使一组单词为“输入完成”.0：未完成，1：完成
	int n;
	short target;//目标单词序号
	struct word danci[5];
	for (n=0;n<=4;n++)//初始化纵坐标
	{
		danci[n].y = 1;
	}
	srand(time(0));//设置时间种子
	int score = 0;
	int level = a;
	int miss = 0;
	while (true)
	{
		for (n = 0; n <= num - 1; n++)//使一组单词的状态为“未完成”
		{
			xiaoshi[n] = 0;
		}
		int panduan = 0;
		for (n = 0; n <= num-1 ; n++)
		{
		loop:
			target = rand() % wordnum;//随机生成单词序号
			if (pe.problem[max] != 0)
			{
				kk = rand() % 5;
				if (kk ==2)
				{
					target = max;
				}
			}
			if (n>0)
			{
				k = 0;
				for (; k <= n-1; k++)
				{
					if (words[target][0] == danci[k].content[0])//使每个单词的首字母不同
					{
						goto loop;
					}
				}
			}
			strcpy_s(danci[n].content, words[target]);
			pro[n] = target;
		}
		for (n = 0; n <= num-1; n++)
		{
			danci[n].x = rand() % 700 + 150;//随机生成产生单词的位置
			danci[n].y = 5+(n)*30;//y不同
		}
		setfillcolor(getbkcolor());//以背景色填充
		//让该字母从最顶上面往下落
		short i = 0;
		int flag = 0;
		char shuru[20];
		for (o = 0; o <= 19; o++)
			shuru[o] = '\0';
		for (;1;)
		{
			setcolor(BLACK);
			BeginBatchDraw();
			IMAGE img,src, mask;
			loadimage(&img, ".\\新建文件夹\\background1.jpg");
			loadimage(&src, ".\\新建文件夹\\Carota.jpg");
			loadimage(&mask,".\\新建文件夹\\Carota_Zhao.jpg");
			putimage(0, 0, &img);
			settextstyle(25, 0, "黑体");
			for (n = 0; n <= num-1 ; n++)//若单词状态为0，则显示
			{
				if (xiaoshi[n] == 0)
				{
					putimage(danci[n].x-35, danci[n].y-10, &mask,SRCPAINT);//消除黑面
					putimage(danci[n].x-35, danci[n].y-10, &src, SRCAND);
					setbkmode(TRANSPARENT);
				}
			}
			for (n = 0; n <= num - 1; n++)//若单词状态为0，则显示
			{
				if (xiaoshi[n] == 0)
				{
					outtextxy(danci[n].x, danci[n].y ,danci[n].content);
				}
			}
			Sleep(25-level);
			setcolor(RED);
			if (_kbhit())//有按键
			{
				int ch = _getch();
				if (ch == 27)//'esc'--> exit
				{
					EndBatchDraw();
					if (a == 0)
					{
						p = fopen_s(&fpp, "paihangbang", "r+");
						p4 = fread(&rankk, sizeof(paihang), 1, fpp); //读取用户信息
						fclose(fpp);
						for (n = 0; n <= 6; n++)
						{
							if (highscore > rankk.score[n])
							{
								break;
							}
						}
						for (nn = 6; nn >= n; nn--)
						{
							strcpy_s(rankk.name[nn], rankk.name[nn - 1]);
							rankk.score[nn] = rankk.score[nn - 1];
						}
						strcpy_s(rankk.name[n], pe.user);
						rankk.score[n] = highscore;
						p3 = fopen_s(&fpp, "paihangbang", "w");
						p_ = fwrite(&rankk, sizeof(paihang), 1, fpp);
						fclose(fpp);//关闭保存文件
						if (p != 0 || p3 != 0 || p_ != 1 || p4 != 1)
						{
							cleardevice;
							while (1)
							{
								BeginBatchDraw();
								IMAGE img;
								loadimage(&img, ".\\新建文件夹\\background1.jpg");
								putimage(0, 0, &img);
								settextstyle(70, 0, "宋体");
								outtextxy(300, 200, "排行榜保存错误");
								settextstyle(25, 0, "华文行楷");
								outtextxy(10, 570, "任意键退出");
								EndBatchDraw();
								if (_kbhit())
								{
									_getch();
									return;
								}
							}
						}
					}
				cleardevice;
				return;
				}
				for (n = 0; n <= num - 1; n++)//每个单词都检测一遍
				{
					if (ch == danci[n].content[i] && (panduan == n+1 || panduan == 0)&&xiaoshi[n]==0)
					{
						shuru[i] = ch;
						w = 1;
						i++;
						panduan = n+1;//使后续能以该词为目标
						if (i == strlen(danci[n].content))//这个单词打对了
						{
							all++;
							suc++;
							rate = ((double)suc /(double) all);
							setcolor(RED);
							strcpy_s(shuru, danci[n].content);
							settextstyle(26, 0, "无衬线");
							BeginBatchDraw();
							outtextxy(10, 300, "当前的输入:");
							settextstyle(30, 0, "无衬线");
							outtextxy(10, 330, shuru);
							settextstyle(16, 0, "无衬线");
							outtextxy(10, 30, "当前分数：");
							char strscore[20];
							sprintf_s(strscore, "%d", score);//输出score
							outtextxy(100, 30, strscore);
							outtextxy(10, 50, "miss次数：");
							char strmiss[20];
							sprintf_s(strmiss, "%d", miss);//输出
							outtextxy(100, 50, strmiss);
							outtextxy(10, 70, "难度等级：");
							char strlevel[20];
							sprintf_s(strlevel, "%d", level);//输出
							outtextxy(100, 70, strlevel);
							outtextxy(10, 90, "正确率：");
							char strrate[20];
							sprintf_s(strrate, "%.4lf", rate);//输出
							outtextxy(100, 90, strrate);
							outtextxy(10, 520, "eas返回到选择层");
							outtextxy(10, 540, "输错，从头输入");
							outtextxy(10, 560, "miss一个扣两分");
							outtextxy(10, 580, "对一个加一分");
							settextstyle(26, 0, "无衬线");
							outtextxy(10, 300, "当前的输入:");
							settextstyle(30, 0, "无衬线");
							outtextxy(10, 330, shuru);
							EndBatchDraw();
							for (o = 0; o <= 19; o++)
								shuru[o] = '\0';
							mciSendString("close .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
							mciSendString("open .\\新建文件夹\\正确.mp3", NULL, 0, NULL);
							mciSendString("play .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
							score++;
							if (score > highscore)
							{
								highscore = score;
							}
							i = 0;
							if (score % 10 == 0)
							{
								if (a == 0)
								{
									level++;
									mciSendString("close .\\新建文件夹\\升级.mp3 ", NULL, 0, NULL);
									mciSendString("open .\\新建文件夹\\升级.mp3", NULL, 0, NULL);
									mciSendString("play .\\新建文件夹\\升级.mp3 ", NULL, 0, NULL);
								}
							}
							xiaoshi[n] = 1;
							if (a == 0)
							{
								p = fopen_s(&fp, pe.user, "r+");
								p4 = fread(&pe, sizeof(Users), 1, fp); //读取用户信息
								fclose(fp);
								if (pe.highestlevel < level)
									pe.highestlevel = level;
								if (pe.highestscore < score)
									pe.highestscore = score;
								p3 = fopen_s(&fp, pe.user, "w");
								p_ = fwrite(&pe, sizeof(Users), 1, fp);
								fclose(fp);//关闭保存文件
								if (p != 0 || p3 != 0 || p_ != 1 || p4 != 1)
								{
									cleardevice;
									while (1)
									{
										BeginBatchDraw();
										IMAGE img;
										loadimage(&img, ".\\新建文件夹\\background1.jpg");
										putimage(0, 0, &img);
										settextstyle(70, 0, "宋体");
										outtextxy(300, 200, "数据保存错误");
										settextstyle(25, 0, "华文行楷");
										outtextxy(10, 570, "任意键退出");
										EndBatchDraw();
										if (_kbhit())
										{
											_getch();
											return;
										}
									}
								}
							}
							if (xiaoshi[0] == 1 && xiaoshi[1] == 1 && xiaoshi[2] == 1 && xiaoshi[3] == 1 && xiaoshi[4] == 1)//全部单词状态都为1（完成）
							{
								flag = 1;
								panduan = 0;
								break;
							}
							p = fopen_s(&fp, pe.user, "r+");
							p4 = fread(&pe, sizeof(Users), 1, fp); //读取用户信息
							fclose(fp);
							pe.problem[pro[panduan - 1]]--;
							if (pe.problem[pro[panduan - 1]] < 0)
							{
								pe.problem[pro[panduan - 1]] = 0;
							}
							p3 = fopen_s(&fp, pe.user, "w");
							p_ = fwrite(&pe, sizeof(Users), 1, fp);
							fclose(fp);//如果单词对了，该玩家该单词的错误次数减一;
							panduan = 0;
							break;
						}
					}
				}
				if (w==0)//输错
				{
					for (o = 0; o <= 19; o++)
						shuru[o] = '\0';
					if (panduan != 0)
					{
						p = fopen_s(&fp, pe.user, "r+");
						p4 = fread(&pe, sizeof(Users), 1, fp); //读取用户信息
						fclose(fp);
						pe.problem[pro[panduan - 1]]++;
						p3 = fopen_s(&fp, pe.user, "w");
						p_ = fwrite(&pe, sizeof(Users), 1, fp);
						fclose(fp);//关闭保存文件
					}
					mciSendString("close .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
					mciSendString("open .\\新建文件夹\\错误2.mp3", NULL, 0, NULL);
					mciSendString("play .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
					i = 0;//一旦打错 必须从头开始打这个单词
					panduan = 0;
				}
				w = 0;
				if (flag == 1)
				{
					break;
				}
			}
			settextstyle(16, 0, "无衬线");
			outtextxy(10, 30, "当前分数：");
			char strscore[20];
			sprintf_s(strscore, "%d", score);//输出score
			outtextxy(100, 30, strscore);


			outtextxy(10, 50, "miss次数：");
			char strmiss[20];
			sprintf_s(strmiss, "%d", miss);//输出
			outtextxy(100, 50, strmiss);


			outtextxy(10, 70, "难度等级：");
			char strlevel[20];
			sprintf_s(strlevel, "%d", level);//输出
			outtextxy(100, 70, strlevel);


			outtextxy(10, 90, "正确率：");
			char strrate[20];
			sprintf_s(strrate, "%.4lf", rate);//输出
			outtextxy(100, 90, strrate);


			outtextxy(10, 520, "eas返回到选择层");


			outtextxy(10, 540, "输错，从头输入");


			outtextxy(10, 560, "miss一个扣两分");
			

			outtextxy(10, 580, "对一个加一分");

			settextstyle(26, 0, "无衬线");
			outtextxy(10, 300, "当前的输入:");
			settextstyle(30, 0, "无衬线");
			outtextxy(10, 330, shuru);

			EndBatchDraw();
			for (n = 0; n <= num - 1; n++)//y坐标增加
			{
				if (xiaoshi[n] == 0)
				{
					danci[n].y += sqrt(level * 2);
				}
			}
			if (danci[0].y >= 600 || danci[1].y >= 600 || danci[2].y >= 600 || danci[3].y >= 600 || danci[4].y >= 600)
			{
				break;
			}
		}
		nofin = 0;
		for(n=0;n<=num-1;n++)//查看没打完的单词数
		{
			if (xiaoshi[n] == 0)
			{
				nofin++;
			}
		}
		if (danci[0].y  >= 600|| danci[1].y>=600|| danci[2].y >=600|| danci[3].y >=600|| danci[4].y >=600 )
		{
			all =all+ nofin;
			rate = ((double)suc/(double)all);
			mciSendString("close .\\新建文件夹\\错误.mp3 ", NULL, 0, NULL);
			mciSendString("open .\\新建文件夹\\错误.mp3",NULL, 0, NULL);
			mciSendString("play .\\新建文件夹\\错误.mp3 ", NULL, 0, NULL);
			score -=nofin*2;
			if (a == 0)
			{
				if ((double)score / 10 - level <= 0)
				{
					level = score / 10;
				}
			}
			if (score <= 0)//使分数不减为负数
			{
				score = 0;
			}
			miss=miss+nofin;
		}
		Sleep(250-10*level);
	}
}



void exam(int a)//测试函数a为单词长度
{
	double speed=0;
	double alltime = 0;
	int all = 0;//正确的个数和总个数
	long t=0;//暂放的时间
	long TIME=0;//暂放的时间
	char array[100];//输出的字符串
	char array1[100];//输入的字符串
	char* string = array;
	char* string1 = array1;
	int flag, i;
	srand((unsigned)time(NULL));//加种子
	while (true)
	{
		t = GetTickCount();//取当前时间
		TIME = t;//毫秒
		for (i = 0; i <= a - 1; i++)
		{
			flag = rand() % 2;//随机执行以下步骤
			switch (flag)
			{
			case 0:
				string[i] = 'A' + rand() % 26;
				break;
			case 1:
				string[i] = 'a' + rand() % 26;
				break;
			default:
				string[i] = 'x';
				break;
			}
		}
		string[i] = '\0';
		int ii;
		for (ii = 0; ii <= a-1 ; ii++)//使之一开始全部为空
		{
			string1[ii] = ' ';
		}
		string1[a] = '\0';
		setfillcolor(getbkcolor());//以背景色填充
		i = 0;
		for (; 1; )
		{
			BeginBatchDraw();
			IMAGE img;
			loadimage(&img, ".\\新建文件夹\\background2.jpg");
			putimage(0, 0, &img);
			settextstyle(60, 0, "宋体");
			outtextxy(700 - (a * 10), 100, string);//输出的字符
			outtextxy(700 - (a * 10), 300, string1);//输入的字符
			settextstyle(25, 0, "华文行楷");
			outtextxy(800, 535, "字母均速：");
			outtextxy(980, 535, "秒");
			char strspeed[20];
			sprintf_s(strspeed, "%.3lf", speed);//输出
			outtextxy(920,535, strspeed);//速度
			outtextxy(800, 555, "目前的个数：");
			outtextxy(980, 555, "个");
			char strall[20];
			sprintf_s(strall, "%d", all);//输出
			outtextxy(940,555, strall);//数量
			outtextxy(10, 555, "键入eas退出");
			outtextxy(10, 575, "键入enter进入检测");
			settextstyle(60, 0, "华文行楷");
			outtextxy(250, 100, "输入目标：");
			outtextxy(250, 300, "你的输入：");
			EndBatchDraw();
			if (_kbhit())//一直有按键
			{
				int ch = _getch();
				if (ch=='\r')
				{
					estimate(speed,all);
					return;
				}
				if (ch == 27)//'esc'--> exit
				{
					return;
				}
				if (ch == string[i])//字母大小写
				{
					string1[i] = string[i];
					t = GetTickCount();//取当前时间
					alltime += (t - TIME) / 1000.0;
					speed = alltime / ((all * a) + i + 1);//计算速度
					TIME = t;//毫秒
					++i;
					if (i == strlen(string))//这个单词打对了
					{
						mciSendString("close .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
						mciSendString("open .\\新建文件夹\\正确.mp3", NULL, 0, NULL);
						mciSendString("play .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
						settextstyle(60, 0, "宋体");
						outtextxy(700 - (a * 10), 300, string1);
						Sleep(500);//避免最后输出的一个字母无法被用户看见;
						all++;
						break;
					}
				}
				else
				{
					mciSendString("close .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
					mciSendString("open .\\新建文件夹\\错误2.mp3", NULL, 0, NULL);
					mciSendString("play .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
				}
			}
		}
	}
}



void selfdefine()//自定文本
{
	char* define=NULL;
	char* define1=NULL;
	int a;
	int num=0;//记录读入的文本行数
	char zanfang[400][49];//目标字符串
	char zanfang_[49];//输入的字符串
	define1 = zanfang_;
	int i = 0;
	int ii = 0;
	int iii;
	FILE* pf1;
	a = fopen_s(&pf1, ".\\selfdefinetext.txt", "r");
	if (a != 0)//打开失败
	{
		while (1)
		{
			BeginBatchDraw();
			IMAGE img;
			loadimage(&img, ".\\新建文件夹\\background3.jpg");
			putimage(0, 0, &img);
			settextstyle(100, 0, "华文行楷");
			settextcolor(RED);
			outtextxy(500,250,"error");//输出的字符
			outtextxy(500, 450, "无法打开文件");//输出的字符
			settextstyle(30, 0, "华文行楷");
			outtextxy(10, 570, "键入eas返回");//输出的字符
			if (_kbhit())//一直有按键
			{
				int ch = _getch();
				if (ch == 27)
				{
					return;
				}
			}
			EndBatchDraw();
		}
	}
	do//读取文本内容
	{
		fgets(zanfang[i], 49, pf1);
		if (zanfang[i][strlen(zanfang[i])-1] == '\n')
		{
			zanfang[i][strlen(zanfang[i])-1] = '\0';
		}
		i++;
		num++;
	} while (!feof(pf1));//知道文本结束
	i = 0;
	while (1)
	{
		ii = 0;
		iii = 0;
		define = zanfang[i];
		if (i==num)//若全部完成
		{
			mciSendString("close .\\新建文件夹\\成功.mp3 ", NULL, 0, NULL);
			mciSendString("open .\\新建文件夹\\成功.mp3", NULL, 0, NULL);
			mciSendString("play .\\新建文件夹\\成功.mp3 ", NULL, 0, NULL);
			while (1)
			{
				BeginBatchDraw();
				IMAGE img;
				loadimage(&img, ".\\新建文件夹\\background3.jpg");
				putimage(0, 0, &img);
				settextstyle(60, 0, "华文行楷");
				settextcolor(RED);
				outtextxy(400, 150, "恭喜您！！");
				outtextxy(400, 400, "顺利完成目标！！");
				settextstyle(30, 0, "华文行楷");
				outtextxy(10, 570, "键入eas返回");
				EndBatchDraw();
				if (_kbhit())//一直有按键
				{
					int ch = _getch();
					if (ch == 27)
					{
						return;
					}
				}
			}
		}
		i++;
		while (iii <= 48)//使一开始输入是空
		{
			define1[iii] = '\0';
			iii++;
		}
		for (; 1; )
		{
			if (_kbhit())//一直有按键
			{
				int ch = _getch();
				if (ch == 27)//'esc'--> exit
				{
					return;
				}
				if (ch == define[ii])//字母大小写
				{
					define1[ii] = define[ii];
					ii++;
					if (ii == strlen(define))//这句话打对了
					{
						mciSendString("close .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
						mciSendString("open .\\新建文件夹\\正确.mp3", NULL, 0, NULL);
						mciSendString("play .\\新建文件夹\\正确.mp3 ", NULL, 0, NULL);
						BeginBatchDraw();
						IMAGE img;
						loadimage(&img, ".\\新建文件夹\\background3.jpg");
						putimage(0, 0, &img);
						settextstyle(40, 0, "黑体");
						settextcolor(BLACK);
						outtextxy(10, 100, define);//输出的字符
						settextcolor(RED);
						outtextxy(10, 300, define1);//输出的字符
						settextcolor(BLACK);
						settextstyle(25, 0, "华文行楷");
						outtextxy(10, 565, "键入eas退出");//输出的字符
						outtextxy(10, 480, "目标字符个数：");//输出的字符
						char strnum[20];
						sprintf_s(strnum, "%d", strlen(define));//输出
						outtextxy(200, 480, strnum);
						outtextxy(10, 530, "输入字符个数：");//输出的字符
						char strnum_[20];
						sprintf_s(strnum_, "%d", ii);//输出
						outtextxy(200, 530, strnum_);
						EndBatchDraw();
						Sleep(500);//避免最后输出的一个字母后无法被用户看见
						break;
					}
				}
				else
				{
					mciSendString("close .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
					mciSendString("open .\\新建文件夹\\错误2.mp3", NULL, 0, NULL);
					mciSendString("play .\\新建文件夹\\错误2.mp3 ", NULL, 0, NULL);
				}
			}
			BeginBatchDraw();//打出画面信息
			IMAGE img;
			loadimage(&img, ".\\新建文件夹\\background3.jpg");
			putimage(0, 0, &img);
			settextstyle(40, 0, "黑体");
			settextcolor(BLACK);
			outtextxy(10, 100, define);
			settextcolor(RED);
			outtextxy(10, 300, define1);
			settextcolor(BLACK);
			settextstyle(25, 0, "华文行楷");
			outtextxy(10, 565, "键入eas退出");
			outtextxy(10, 480, "目标字符个数：");
			char strnum[20];
			sprintf_s(strnum, "%d", strlen(define));
			outtextxy(200, 480, strnum);
			outtextxy(10, 530, "输入字符个数：");
			char strnum_[20];
			sprintf_s(strnum_, "%d", ii);
			outtextxy(200, 530, strnum_);
			EndBatchDraw();
		}
	}
}



void goodbey()//再见函数
{
	closemusic();//关闭背景音乐
	mciSendString("open .\\新建文件夹\\再见.mp3", NULL, 0, NULL);
	mciSendString("play .\\新建文件夹\\再见.mp3", NULL, 0, NULL);
	int color = 260;
	cleardevice();
	int change = 0;//用于切换变色顺序
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background.jpg");
	putimage(0, 0, &img);
	while (true)
	{
		settextstyle(26, 0, "华文行楷");
		settextcolor(RED);
		setcolor(RGB(color, 0, 0));
		if (change == 0)
		{
			color -= 10;//颜色越来越暗 出现闪烁效果
		}
		else
		{
			color += 10;//变亮
		}
		if (color == 0)//切换为从暗变亮（亮变暗）
		{
			change = 1;
		}
		else if (color ==250)
		{
			change = 0;
		}
		outtextxy(140, 150, "goodbye，开发者：李政廉、邓嘉轩真诚感谢你的使用");
		outtextxy(100, 300, "如发现bug请打电话到10086（滑稽）（发现了也没用了不想改了累了emmmmm）");
		settextstyle(60, 0, "华文行楷");
		outtextxy(125, 420, "软件针不戳！！！");
		settextstyle(35, 0, "华文行楷");
		outtextxy(350, 550, "按任意键退出");
		Sleep(200);//使变色慢下来
		if (_kbhit())//有按键
		{
			_getch();
			mciSendString("close .\\新建文件夹\\再见", 0, 0, 0);
			return;
		}
	}
}



int *opt()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background1.jpg");
	putimage(0, 0, &img);
	settextstyle(60, 0, "宋体");
	settextcolor(BLACK);
	outtextxy(300, 150, "选择难度");
	settextstyle(30, 0, "黑体");
	outtextxy(175, 275, "选择速度：9~1 or 0（自动无限递增、每10个加速一次）");
	outtextxy(300, 380, "为0时一开始单词不会下落！");
	outtextxy(10, 550, "键入eas返回");
	int *a;
	int aa[3] = { 10,10,10 };//初始化aa，其中10无意义
	a = aa;
	for (; 1;)
	{
		a[1] = _getch();
		if(a[1]<='9'&&a[1]>='0')//选择速度
		{
			a[1] = a[1] - 48;
			cleardevice();
			break;
		}
		else if (a[1] == 27)
		{
			cleardevice();
			a[0] = -1;
			break;
		}
	}
	if (a[0] == -1)//返回
	{
		return a;
	}
	putimage(0, 0, &img);
	settextstyle(60, 0, "宋体");
	settextcolor(BLACK);
	outtextxy(300, 150, "选择数量");
	settextstyle(30, 0, "黑体");
	outtextxy(375, 275, "选择数量：5~1");
	outtextxy(10, 550, "键入eas返回");
	for (;1;)
	{
		a[2] = _getch();
		if (a[2] <= '5' && a[2] >= '1')//选择单词数
		{
			a[2] = a[2]-48;
			cleardevice();
			break;
		}
		else if (a[2] == 27)//返回
		{
			cleardevice();
			a[0] = -1;//a[0]为-1时start函数重新选择模式
			break;
		}
	}
	return a;
}



int opt1()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, ".\\新建文件夹\\background2.jpg");
	putimage(0, 0, &img);
	settextstyle(60, 0, "宋体");
	settextcolor(BLACK);
	outtextxy(250, 150, "请测试的长度选择长度");
	settextstyle(30, 0, "华文行楷");
	outtextxy(250, 300, "选择长度：9~~~~~~~~~~~~~~~~~1");
	outtextxy(350, 450, "注意本次有大小写之分！！！");
	outtextxy(10, 550, "键入eas返回");
	int a;
	for (; 1;)
	{
		a = _getch();
		if (a <= '9' && a >= '1')//选择每个字符串长度
		{
			a = a - 48;
			cleardevice();
			return (a);
		}
		else if (a == 27)
		{
			cleardevice();
			return(-1);//判断是否返回
		}
	}
}


//9个bgm
int backmusic(char a)
{
	if (a == '1')
	{
		mciSendString("open .\\新建文件夹\\处处吻.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\处处吻.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '2')
	{
		mciSendString("open .\\新建文件夹\\年少有为.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\年少有为.mp3 repeat", NULL, 0, NULL);
	}	
	else if (a == '3')
	{
		mciSendString("open .\\新建文件夹\\music_1.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_1.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '4')
	{
		mciSendString("open .\\新建文件夹\\music_2.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_2.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '5')
	{
		mciSendString("open .\\新建文件夹\\music_3.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_3.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '6')
	{
		mciSendString("open .\\新建文件夹\\music_4.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_4.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '7')
	{
		mciSendString("open .\\新建文件夹\\music_5.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_5.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '8')
	{
		mciSendString("open .\\新建文件夹\\music_6.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_6.mp3 repeat", NULL, 0, NULL);
	}
	else if (a == '9')
	{
		mciSendString("open .\\新建文件夹\\music_7.mp3", NULL, 0, NULL);
		mciSendString("play .\\新建文件夹\\music_7.mp3 repeat", NULL, 0, NULL);
	}
	return 1;
}



int closemusic()
{	
	mciSendString("close .\\新建文件夹\\处处吻.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\年少有为.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_1.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_2.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_3.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_4.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_5.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_6.mp3", 0, 0, 0);
	mciSendString("close .\\新建文件夹\\music_7.mp3", 0, 0, 0);
	return 0;
}



void zhuce()
{
	char yon;//yes or no
	int a;
	char temp[20], txt[1024], cha;        //定义两个数组，一个存放键盘输入的用户名和密码一个存放用户手册
	do
	{
		printf("\t\t\t\t用户注册");
		printf("\n\t\t任意键.直接注册            enter.阅读用户手册");
		cha = _getch();
		if (cha == '\r')
		{
			if ((a = fopen_s(&fp,"使用说明.txt", "r")) != 0)
			{
				printf("\n\t\t打开失败");
				exit(0);
			}
			fgets(txt,1024, fp);
			printf("\n\n\n\t\t%s\n\n", txt);
			fclose(fp);//关闭保存文件
		}
		printf("\n\t\t按任意键继续");
		_getch();
		system("cls");
		/*以上部分用于打开用户手册，用户手册内容可修改*/
		loop:
			printf("\t\t\t\t用户注册");
			printf("\n\t\t用户名:");
			cin >> pe.user;//输入用户名
			a = fopen_s(&fp,pe.user, "r");
			/*判断用户名是否重复*/
			if (a == 0)//重复
			{
				printf("\n\t该用户名已存在");
				fclose(fp);
				printf("\n\t继续注册?(Y/N)");
				while (1)
				{
					yon = _getch();
					if (yon == 'Y')
					{
						goto loop;
					}
					else if (yon=='N')
					{
						return;
					}
				}
			}
			/*确认两次密码输入是否一致*/
			printf("\n\t\t密  码:");
			cin >> pe.code;
			printf("\n\t\t确认密码:");
			cin >> temp;
			if (strcmp(pe.code, temp) != 0)
				printf("\n\t\t两次密码不一致,请重新输入");
	}while (strcmp(pe.code, temp) != 0);
		/*用户名密码无误，写入文档储存用户信息*/
		a = fopen_s(&fp,pe.user, "w");
		if (a != 0)
		{
			printf("\n\t注册失败\n");
			exit(0);
		}
		else
		{
			system("cls");
			printf("\n\t注册成功\n");
			cout << "按任意键返回" << endl;
			write();               //用户信息写入函数
			_getch();
			system("cls");
			return;
		}
	}



void write()
{
	int i;
	pe.highestlevel = 0;
	pe.highestscore = 0;//初始化得分
	for(i=0;i<=102;i++)
	pe.problem[i] = 0;
	if (fwrite(&pe, sizeof(Users), 1, fp) != 1)
	{
		printf("\n\t\t写入文件错误");
		exit(0);                     //写入错误则退出程序
	}
	fclose(fp);//关闭保存文件
}



void denglu()
{
	int a;
	char u[20], c[20], temp[20];      //定义两个数组，存放键盘输入的用户名和密码
	printf("\n\t\t\t\t用户登录");
	printf("\n\t\t用户名:");
	cin >> u;
	/*判断用户名是否存在*/
	a = fopen_s(&fp,u, "r+");
	temp[0] = '0';
	if (a !=0 )
	{
		printf("\n\t\t用户不存在,请注册");
		printf("\n\t\t1.注册   2.重新登陆");
		temp[0] = _getch();
		if (temp[0] == '1')
		{
			system("cls");
			zhuce();//返回到注册
		}
		else return denglu();//返回 到登录
	}
	/*验证密码是否正确*/
	do
	{
		fread(&pe,sizeof(Users),1,fp); //读取用户信息，即用户名和密码
		printf("\t\t密  码:");
		cin>>c;
		if (strcmp(pe.code, c) != 0)                      //对比输入的密码和读取的密码
		{
			printf("\n\t\t密码错误(任意键.退出 2.重新输入)");
			temp[0] = _getch();
			printf("\n");
			if (temp[0] != '2')
			{
				fclose(fp);                           //关闭文件防止错误操作
				exit(-1);
			}
		}
		else
		{
			break;
		}
	} while (temp[0] == '2');
	cout << "按任意键进入" << endl;
	fclose(fp);                           //关闭文件防止错误操作
	_getch();
	//这里可以设置跳转到操作界面
}