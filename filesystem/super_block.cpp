/* AlexFS.
 * 2010.08.18 by alex.
 */

#include "filesystem/super_block.h"

SuperBlock::SuperBlock(string file_name,int start_point,int end_point)
{
	this->file_name=file_name;
	this->start_point=start_point;
	this->end_point=end_point;
}

SuperBlock::SuperBlock(string file_name, int start_point, int end_point, int tag)
{
	this->file_name=file_name;
	this->start_point=start_point;
	this->end_point=end_point;
	this->tag = tag;
}

string SuperBlock::get_file_name()
{
	return this->file_name;
}

int SuperBlock::get_start_point()
{
	return this->start_point;
}

int SuperBlock::get_end_point()
{
	return this->end_point;
}

void SuperBlock::read(ifstream &s)
{
	s>>file_name;
	s>>start_point;
	s>>end_point;
	s>>tag;
}

int SuperBlock::get_tag()
{
	return tag;
}

void SuperBlock::change_file_name(string file_name)
{
	this->file_name=file_name;
}

void SuperBlock::change_end_point(int file_size)
{
	this->end_point=this->start_point+file_size;
}

void SuperBlock::change_tag(int tag)
{
	this->tag=tag;
}