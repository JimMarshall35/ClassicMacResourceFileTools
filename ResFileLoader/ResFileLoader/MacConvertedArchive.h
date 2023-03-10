#pragma once
#include <string>
#include <vector>
#include "MacConvertedOffsetsFile.h"
#include "MacConvertedDataFile.h"

class MacConvertedArchive
{
public:
	MacConvertedArchive(const std::string& dataFilePath, const std::string& OffsetFilePath);
private:
	std::vector<char> m_data;
	MacConvertedOffsetsFile m_offsetsFile;
	MacConvertedDataFile m_dataFile;
};

