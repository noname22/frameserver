#include "Program.h"
#include <vector>

#include "flog.h"

#include "PluginHandler.h"
#include "Platform.h"

class CProgram : public Program {
	public:

	int Run(int argc, char** argv){
		PluginHandlerPtr pluginHandler = PluginHandler::Create();
		PlatformPtr platform = Platform::Create();

		std::string dir = platform->GetWorkingDirectory();
		pluginHandler->AddPlugin("test.exe", Platform->CombinePath(dir, "VideoPlugins"));

		return 0;
	}
};

ProgramPtr Program::Create()
{
	return ProgramPtr(new CProgram);
}