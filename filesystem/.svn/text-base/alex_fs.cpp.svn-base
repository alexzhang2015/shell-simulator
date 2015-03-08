/* 
 * AlexFS . 
 * 2010.08.18 by alex.
 */

#include "filesystem/alex_fs.h"

AlexFs::AlexFs(char *pwd_filename)
{
	SuperBlock super_tmp("",0,0);
	for (int i = 0; i < FILE_NUM; i++)
	{
		super.push_back(super_tmp);
	}
	file_num = FILE_NUM;

	this->pwd_filename = pwd_filename;

	/* Initialization the AlexFs. */
	init();
	
}

/*
*读取super块 ,content 块
*/
void AlexFs::init()
{
	/**
	 * 初始化时，若没有history 文件，则创建
	 */
	ifstream ifs(pwd_filename, ios::binary);
	if (!ifs.is_open())
	{
		/* Format the AlexFs. */
		format();
	}
	ifs.close();

	/* Read the superblock and the file_content to the buffer. */
	read_super();
	read_content();
}

void AlexFs::format()
{
	
	ofstream ofs(pwd_filename, ios::binary);
	if (ofs.is_open())
	{
		for (int i = 0; i < FILE_NUM; i++)
		{
			ofs << "alex" << " "
				<< i * 1000 + 40 * FILE_NUM << " "
				<< (i + 1) * 1000 + 40 * FILE_NUM << " "
				<< i - i + 1 << " "
				<< "\r\n";
		//	cout<<ofs.tellp()<<endl;
		}
	}
	else 
	{
		cout << "can't open history.img"
			 << endl;
	}
	ofs.close();
}

string AlexFs::get_content(int num)
{
	return content[num] ;
}

void AlexFs::read_super()
{

	ifstream ifs(pwd_filename, ios::binary);
	if(ifs.is_open())
	{
		writeable_file = 0;
		for (int i = 0; i < file_num; i++)
		{
			if (ifs.fail()!=0)
			{
				break;
			}
			super[i].read(ifs);
			if (super[i].get_tag() == 1)
			{
				writeable_file++;
			}
		}
	}
	else 
	{
		cout << "fail opening history.img"
			 << endl;
	}
	ifs.close();
}

void AlexFs::read_content()
{	
	char tmp_content[1001];
	char *tmp = tmp_content;
	ifstream ifs(pwd_filename, ios::binary);
	if (ifs.is_open())
	{
		for (int i = 0; i < file_num; i++)
		{
			if (super[i].get_tag() == 0)
			{
				ifs.seekg(super[i].get_start_point(), ios_base::beg );
				//ifs.readsome(content[i],super[i].get_end_point()-super[i].get_start_point());
				ifs.read(tmp,super[i].get_end_point() - super[i].get_start_point());
				content[i] = tmp;
			}
		}
	}
	else 
	{
		cout << "fail opening history.img"
			 << endl;
	}
	ifs.close();
}

/**
 * 按队列的方式存储，达到上限，自动删除首个结点
 */
bool AlexFs::write_file(string file_name, string input_content)
{
	//cout<<"writeable_file is:"<<writeable_file<<endl;
	if (writeable_file == 0)
	{
		/**
		 * Erase the first file,and insert a empty file end
		 */
		int start_point = (*super.begin()).get_start_point();
		//int end_point = (*super.begin()).get_end_point();
		super.erase(super.begin());
		/* 类似队列的方式从新存储在删除的结点处 */
		SuperBlock super_tmp("", start_point, start_point + 1000, 1);
		super.push_back(super_tmp);
		writeable_file++;
	}

	//for(int i = 0; i < file_num; i++)
	//{
	int i = 100 - writeable_file;
		if(super[i].get_tag() == 1)
		{
			/*cout<<"\ninput the file_name:";
			string file_name;
			cin>>file_name;
			while(check_file_name(file_name))
			{
				cout<<"\nfile_name conflict!\n";
				cout<<"\ninput the file_name:";
				cin.clear();
				cin.sync();
				cin>>file_name;
			}*/
			super[i].change_file_name(file_name);
		/*	cout<<"\ninput the content,the content must be ended at '.'\n";
			cin.clear();
			cin.sync();
			string input_content;
			getline(cin,input_content,'.');
			cin.clear();
			cin.sync();*/
			if (input_content.size() < 1000)
			{
				content[(super[i].get_start_point() - 40 * FILE_NUM) / 1000] = input_content;
				super[i].change_end_point(content[(super[i].get_start_point() - 40 * FILE_NUM) / 1000].size() + 1);
				super[i].change_tag(0);
				sync_to_harddisk();
				writeable_file--;
				//break;
			}
			else
			{
				cout << "\nthe content is too big!"
					 << endl;
				return false;
			}
			
		}
	/*}*/
	return true;
}

void AlexFs::list_file()
{
	for (int i=0;i < file_num; i++)
	{
		if (super[i].get_tag() != 1)
		{
			cout << "file_name: "
				 << super[i].get_file_name()
				 << ","
				 << "file_size: "
				 << super[i].get_end_point() - super[i].get_start_point()
				 << " "
				 << endl;
		}
	}
}

bool AlexFs::sync_to_harddisk()
{
	/*
	*使用 ios::app 方式，对于ofs.seekp(),失效。
	*/
	ofstream ofs(pwd_filename, ios::binary);
	if (ofs.is_open())
	{
		//cout<<"sync the super_block"<<endl;
		for (int i = 0; i < FILE_NUM; i++)
		{
			ofs << super[i].get_file_name()<<" "
				<< super[i].get_start_point()<<" "
				<< super[i].get_end_point()<<" "
				<< super[i].get_tag()<<" "
				<< "\r\n";
		//	cout<<ofs.tellp()<<endl;
		}

		for (int j = 0; j < file_num; j++)
		{
			if (super[j].get_tag() == 0)
			{
				//cout<<"sync the "<<super[j].get_file_name()<<endl;
				ofs.seekp(super[j].get_start_point(), ios_base::beg );
				ofs << content[(super[j].get_start_point() - 40 * FILE_NUM) / 1000] 
				    << '\0';
			}
		}
	}
	else 
	{
		cout << "can't open history.img"
			 << endl;
		return false;
	}
	ofs.close();
	return true;
}

bool AlexFs::read_file(string file_name, string &file_content)
{
	//cout<<"input the file_name:";
	//string file_name;
	//cin>>file_name;
	for(int i = 0; i < file_num; i++)
	{
		if (super[i].get_file_name() == file_name && super[i].get_tag() == 0)
		{
			//cout<<"file content:"<<content[i]<<endl;
			file_content = content[i];
			return true;
		}
	}
	//cout<<"can't find the file!"<<endl;
	return false;
}

bool AlexFs::delete_file(string file_name)
{
	//cout<<"input the file_name:";
	/*string file_name;
	cin>>file_name;*/

	for (int i = 0; i < file_num; i++)
	{
		if (super[i].get_file_name() == file_name && super[i].get_tag() == 0)
		{
			super[i].change_tag(1);
			writeable_file++;
			//cout<<"file :"<<super[i].get_file_name()<<"deleted!"<<endl;
			
			
		}
	}
	//cout<<"can't find the file!"<<endl;
	bool err;
	err = sync_to_harddisk();
	if (err)
	{
		return true;
	}
	else
		return false;
}

bool AlexFs::check_file_name (string file_name)
{
	for (int i = 0; i < file_num; i++)
	{
		if (super[i].get_file_name() == file_name && super[i].get_tag() == 0)
		{	
			return true;
		}
	}
	return false;
}

void AlexFs::read_all_file()
{
	for(int i = 0; i < file_num; i++)
	{
		if(super[i].get_tag() != 1)
		{
			cout << i+1
				 << " "
				 << content[(super[i].get_start_point() - 40 * FILE_NUM) / 1000]
				 << endl;
		}
	}
}