#pragma once
#include <string>
#include <vector>

class MacConvertedDataFile
{
public:
	MacConvertedDataFile(const std::string& path);
private:
	std::vector<char> m_data;
};

