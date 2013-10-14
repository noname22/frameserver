#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>

class Program;
typedef std::shared_ptr<Program> ProgramPtr; 

class Program 
{
	public:
	virtual int Run(int argc, char** argv) = 0;
	static ProgramPtr Create();
};

#endif
