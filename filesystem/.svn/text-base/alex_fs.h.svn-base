/* 
 * AlexFS . 
 * 2010.08.18 by alex.
 */

#ifndef FILESYSTEM_ALEX_FS_H_
#define FILESYSTEM_ALEX_FS_H_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "filesystem/super_block.h"

using namespace std;

#define FILE_NUM 100

class AlexFs{
public:
	explicit AlexFs(char *pwd_filename);
	void init();
	void format();
	string get_content(int num);
	bool write_file(string file_name, string content);	
	void list_file();
	bool read_file(string file_name, string &file_content);
	bool delete_file(string file_name);
	void read_all_file();
private:
	void read_super();
	void read_content();
	bool sync_to_harddisk();
	bool check_file_name(string file_name);
	vector<SuperBlock> super;
	int file_num;
	int writeable_file;
	string content[FILE_NUM];

	char *pwd_filename;
};

#endif /* FILESYSTEM_ALEX_FS_H_ */