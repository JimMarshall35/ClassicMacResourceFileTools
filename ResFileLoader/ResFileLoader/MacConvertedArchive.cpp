#include "MacConvertedArchive.h"


MacConvertedArchive::MacConvertedArchive(const std::string& dataFilePath, const std::string& offsetFilePath)
	:m_offsetsFile(offsetFilePath),
	m_dataFile(dataFilePath)
{
	
}
