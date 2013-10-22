#include "CommandLine.h"
#include "Platform.h"
#include "IpcMessageQueue.h"
#include "flog.h"

int main(int argc, char** argv)
{
	CommandLine::Start();
	PlatformPtr platform = Platform::Create();
	IpcMessageQueuePtr messageQueue = IpcMessageQueue::Create("test", true);

	bool done = false;

	try {
		while(!done){
			platform->Sleep(1);

			auto cmd = CommandLine::GetCommand();
			if(cmd.size() > 0){
				FlogExpD(cmd[0]);

				if(cmd[0] == "exit")
					done = true;

				messageQueue->WriteMessage(cmd[0], cmd.size() > 1 ? cmd[1] : "");
			}

			std::string type;
			const char* buffer;
			size_t size;

			bool gotResult = messageQueue->GetReadBuffer(type, &buffer, &size, 1);
			if(gotResult){
				FlogExpD(type);
				auto sType = Tools::Split(type);
				if(sType.size() == 2 && sType[0] == "results"){
					FlogI("results from: " << sType[1] << " with size: " << size);
				}
		
				messageQueue->ReturnReadBuffer(&buffer);
			}
		}
	}

	catch (ExBase ex) {
		FlogF("unhandled exception: " << ex.GetMsg());
		return 1;
	}
	

	return 0;
}