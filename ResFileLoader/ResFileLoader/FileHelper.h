#pragma once
#include <fstream>
#include <vector>

int ReadInt(std::ifstream& in, bool flipEndianness = true);

void ReadBytes(std::ifstream& in, std::vector<char>& bbuffer, bool flipEndianness = true);