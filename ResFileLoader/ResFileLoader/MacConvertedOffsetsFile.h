#pragma once
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
using FourLetterCode = uint32_t;
class MacConvertedOffsetsFile
{
public:
	MacConvertedOffsetsFile(const std::string& path);
private:
	void MakeTypeMap();
	std::string FourLetterCodeToString(FourLetterCode code);
private:
	struct MacConvertedResourceInfo
	{
		int32_t offset;
		int32_t size;
		int32_t id;
		FourLetterCode type;
	};

	std::vector<MacConvertedResourceInfo> m_resourceInfos;
	std::map<std::string, std::vector<const MacConvertedResourceInfo*>> m_resourceTypeMap;

};

