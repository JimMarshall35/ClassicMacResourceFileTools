#include <fstream>

#include "MacConvertedOffsetsFile.h"
#include "FileHelper.h"

MacConvertedOffsetsFile::MacConvertedOffsetsFile(const std::string& path)
{
	std::ifstream in(path, std::ifstream::binary);
	int begin = in.tellg();
	in.seekg(0, in.end);
	int end = in.tellg();
	in.seekg(0, in.beg);
	int length = end - begin;

	int floatBufferSize = length / sizeof(MacConvertedResourceInfo);
	unsigned int word = 0;
	unsigned int rword = 0;

	for (int i = 0; i < floatBufferSize; i++) {
		auto info = MacConvertedResourceInfo();
		info.offset = ReadInt(in);
		info.size = ReadInt(in);
		info.id = ReadInt(in);
		info.type = ReadInt(in);

		m_resourceInfos.push_back(info);
	}
	MakeTypeMap();
}

void MacConvertedOffsetsFile::MakeTypeMap()
{
	for (const auto& info : m_resourceInfos) {
		auto asString = FourLetterCodeToString(info.type);
		m_resourceTypeMap[asString].push_back(&info);
	}
}

std::string MacConvertedOffsetsFile::FourLetterCodeToString(FourLetterCode code)
{
	auto r = std::string();
	r += ((code >> 24) & 0xff);
	r += ((code >> 16) & 0xff);
	r += ((code >> 8) & 0xff);
	r += (code & 0xff);
	return r;
}
