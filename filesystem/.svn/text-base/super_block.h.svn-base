/* 
 * AlexFS .
 * 2010.08.18 by alex.
 */

#ifndef FILESYSTEM_SUPER_BLOCK_H_
#define FILESYSTEM_SUPER_BLOCK_H_

#include <string>
#include <fstream>
using namespace std;

/*
 * superblock 留了 40*FILE_NUM! 每一个super 最长40字节，
 * 每一个结点最大 1000字节长。
 */
class SuperBlock{
public:
	SuperBlock(string file_name,int start_point,int end_point);
	SuperBlock(string file_name, int start_point, int end_point, int tag);
	string get_file_name();
	int get_start_point();
	int get_end_point();
	void read(ifstream &s);
	int get_tag();
	void change_file_name(string file_name);
	void change_end_point(int file_size);
	void change_tag(int tag);
private:
	string file_name;
	int start_point;
	int end_point;
	int tag;  //标识是否可写,1 可写 ，0 不可写
};

#endif /* FILESYSTEM_SUPER_BLOCK_H_ */