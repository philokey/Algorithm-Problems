#include"init.h"

extern vector<Book> book;
extern vector<Reader> reader;
extern vector<Administrator> admin;
extern vector<TYPE> T;
extern vector<Pub> P;
extern int c_reader;//记录当前用户
extern Date now;
bool Init()
{	
	wchar_t ch;
	double price,debt;
	int state,Borrow_times;
	bool type;
	wstring mediate;//中间变量
	Book IFMbook;
	Reader IFMreader;
	Administrator IFMadmin;
	TYPE type1;
	Pub pub1;

	c_reader = -1;
	//从文件中读取书籍信息
	wifstream file;
	file.open("Book.txt",ios::in);
	file.imbue(std::locale("chs"));
	if(!file.is_open())
	{
		cerr<<"Open error1!"<<endl;
	}
	file>>now.year;
	file>>now.month;
	file>>now.day;
	ch=file.get();
	while(!file.eof())
	{
		file>>IFMbook.borrow_time.year;
		file>>IFMbook.borrow_time.month;
		file>>IFMbook.borrow_time.day;
		ch=file.get();
		getline(file,mediate);
		IFMbook.modify_name(mediate);
		getline(file,mediate);
		IFMbook.modify_pub(mediate);
		getline(file,mediate);
		IFMbook.modify_ID(mediate);
		getline(file,mediate);
		IFMbook.modify_author(mediate);
		getline(file,IFMbook.reader_id);
		getline(file,IFMbook.book_reader_id);
		file>>price;
		IFMbook.modify_price(price);
		file>>state;
		IFMbook.state=state;
		file>>IFMbook.buy_time.year;
		file>>IFMbook.buy_time.month;
		file>>IFMbook.buy_time.day;
		ch=file.get();
		
		book.push_back(IFMbook);
	}
	file.close();


	//从文件中读取借书者信息
	file.open("user.txt",ios::in);
	file.imbue(std::locale("chs"));
	if(!file.is_open())
	{
		cerr<<"Open error!2"<<endl;
		//exit(0);
	}
	while(!file.eof())
	{
		file>>Borrow_times;
		IFMreader.borrow_times=Borrow_times;
		file>>state;
		IFMreader.state=state;
		file>>type;
		IFMreader.modify_type(type);
		file>>debt;
		IFMreader.debt=debt; 
		getline(file,mediate);//需要多读一次，将回车读入
		getline(file,IFMreader.college);
		getline(file,mediate);
		IFMreader.modify_ID(mediate);
		getline(file,mediate);
		IFMreader.modify_name(mediate);
		getline(file,mediate);
		IFMreader.modify_key(mediate);
		getline(file,mediate);
		while(mediate[0]!='*')
		{
			IFMreader.has_book.push_back(mediate);
			getline(file,mediate);
		}
		getline(file,mediate);
		while(mediate[0]!='-')
		{
			IFMreader.app_book.push_back(mediate);
			getline(file,mediate);
		}

		reader.push_back(IFMreader);
		IFMreader.Clear();
	}
	file.close();


	//从文件中读取管理者信息
	//wifstream file("administrator.txt",ios::in);
	file.open("administrator.txt",ios::in);
	file.imbue(std::locale("chs"));
	if(!file.is_open())
	{
		cerr<<"Open error!"<<endl;
		//exit(0);
	}
	while(!file.eof())
	{
		getline(file,mediate);
		IFMadmin.modify_ID(mediate);
		getline(file,mediate);
		IFMadmin.modify_key(mediate);
		getline(file,mediate);
		IFMadmin.modify_name(mediate);

		admin.push_back(IFMadmin);
	}
	file.close();

	file.open("type.txt",ios::in);
	file.imbue(std::locale("chs"));
	if(!file.is_open())
		cerr<<"Open error!"<<endl;
	while(!file.eof())
	{
		getline(file,type1.type);
		file>>type1.num;
		ch=file.get();
		T.push_back(type1);
	}
	file.close();

	file.open("pub.txt",ios::in);
	file.imbue(std::locale("chs"));
	if(!file.is_open())
		cerr<<"Open error!"<<endl;
	while(!file.eof())
	{
		getline(file,pub1.pub);
		file>>pub1.num;
		ch=file.get();
		P.push_back(pub1);
	}
	file.close();

	return 1;
}


void Closed()
{
	int i,j;
	
	//将书籍信息从内存写入文件
	wofstream file("Book.txt",ios::out);
	file.imbue(std::locale("chs"));
	if(!file)
	{
		cerr<<"Open error!"<<endl;
		exit(0);
	}
	cout<<now.day<<"!!!!!!!!!!!!"<<endl;
	file<<now.year<<' '<<now.month<<' '<<now.day<<endl;
	for(i=0;i<(int)book.size();i++)
	{
		file<<book[i].borrow_time.year<<' '<<book[i].borrow_time.month<<' '<<book[i].borrow_time.day<<endl;
		file<<book[i].get_name()<<endl;
		file<<book[i].get_pub()<<endl;
		file<<book[i].get_ID()<<endl;
		file<<book[i].get_author()<<endl;
		file<<book[i].reader_id<<endl;
		file<<book[i].book_reader_id<<endl;
		file<<book[i].get_price()<<endl;
		file<<book[i].state<<endl;
		if(i==book.size()-1)
			file<<book[i].buy_time.year<<' '<<book[i].buy_time.month<<' '<<book[i].buy_time.day;
		else
			file<<book[i].buy_time.year<<' '<<book[i].buy_time.month<<' '<<book[i].buy_time.day<<endl;
	}
	file.close();
	book.clear();

	//将借书者信息从内存写入文件
	wofstream File;
	File.open("user.txt",ios::out);
	File.imbue(std::locale("chs"));
	if(!File.is_open())
	{
		cerr<<"Open error!"<<endl;
		exit(0);
	}
	for(i=0;i<(int)reader.size();i++)
	{
		File<<reader[i].borrow_times<<endl;
		File<<reader[i].state<<endl;
		File<<reader[i].get_type()<<endl;
		File<<reader[i].debt<<endl;
		File<<reader[i].college<<endl;
		File<<reader[i].get_ID()<<endl;
		File<<reader[i].get_name()<<endl;
		File<<reader[i].get_key()<<endl;
		//File<<reader[i-1].has_book.size()<<endl;
		for(j=0;j<(int)reader[i].has_book.size();j++)
			File<<reader[i].has_book[j]<<endl;
		File<<"****"<<endl;
		for(j=0;j<(int)reader[i].app_book.size();j++)
			File<<reader[i].app_book[j]<<endl;
		if(i==reader.size()-1)
			File<<"----";
		else
			File<<"----"<<endl;
	}
	File.close();
	reader.clear();

	//将管理者信息从内存写入文件
	File.open("administrator.txt",ios::out);
	File.imbue(std::locale("chs"));
	if(!File.is_open())
	{
		cerr<<"Open error!"<<endl;
		exit(0);
	}
	for(i=0;i<(int)admin.size();i++)
	{
		File<<admin[i].get_ID()<<endl;
		File<<admin[i].get_key()<<endl;
		if(i==admin.size()-1)
			File<<admin[i].get_name();
		else
			File<<admin[i].get_name()<<endl;
	}
	File.close();
	admin.clear();

	File.open("type.txt",ios::out);
	File.imbue(std::locale("chs"));
	if(!File.is_open())
	{
		cerr<<"Open error!"<<endl;
		exit(0);
	}
	for(i=0;i<(int)T.size();i++)
	{
		File<<T[i].type<<endl;
		if(i==T.size()-1)
			File<<T[i].num;
		else
			File<<T[i].num<<endl;
	}
	File.close();
	T.clear();

	File.open("pub.txt",ios::out);
	File.imbue(std::locale("chs"));
	if(!File.is_open())
	{
		cerr<<"Open error!"<<endl;
		exit(0);
	}
	for(i=0;i<(int)P.size();i++)
	{
		File<<P[i].pub<<endl;
		if(i==P.size()-1)
			File<<P[i].num;
		else
			File<<P[i].num<<endl;
	}
	File.close();
	P.clear();
}