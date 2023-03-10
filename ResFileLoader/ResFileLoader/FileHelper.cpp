#include "FileHelper.h"
#include <vector>

int ReadInt(std::ifstream& in, bool flipEndianness) {
	std::vector<char> bbuffer;

	char b1, b2, b3, b4;
	in.read(&b1, 1);
	in.read(&b2, 1);
	in.read(&b3, 1);
	in.read(&b4, 1);

	if (flipEndianness) {
		bbuffer.push_back(b4);
		bbuffer.push_back(b3);
		bbuffer.push_back(b2);
		bbuffer.push_back(b1);
	}
	else {
		bbuffer.push_back(b1);
		bbuffer.push_back(b2);
		bbuffer.push_back(b3);
		bbuffer.push_back(b4);
	}
	return *((int*)&bbuffer[(bbuffer.size() - 4)]);

}

void ReadBytes(std::ifstream& in, std::vector<char>& bbuffer, bool flipEndianness) {

	char b1, b2, b3, b4;
	in.read(&b1, 1);
	in.read(&b2, 1);
	in.read(&b3, 1);
	in.read(&b4, 1);

	if (flipEndianness) {
		bbuffer.push_back(b4);
		bbuffer.push_back(b3);
		bbuffer.push_back(b2);
		bbuffer.push_back(b1);
	}
	else {
		bbuffer.push_back(b1);
		bbuffer.push_back(b2);
		bbuffer.push_back(b3);
		bbuffer.push_back(b4);
	}
}