#include <fstream>
#include <iostream>

#include "MacConvertedDataFile.h"
#include "FileHelper.h"

MacConvertedDataFile::MacConvertedDataFile(const std::string& path)
{
	std::ifstream in(path, std::ifstream::binary);
	int begin = in.tellg();
	in.seekg(0, in.end);
	int end = in.tellg();
	in.seekg(0, in.beg);
	int length = end - begin;

	if (length % 4 != 0) {
		std::cout << "something wrong \n";
	}
	for (int i = 0; i < length; i += 4) {
		ReadBytes(in, m_data);
	}
}
